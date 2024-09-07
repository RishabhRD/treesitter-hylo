module.exports = grammar({
  name: "hylo",
  externals: (_) => [],
  extras: (_) => [],
  rules: {
    source_file: ($) =>
      seq(
        repeat($._whitespace),
        optional(seq($._module_scope_stmt_list, $._stmt_separator)),
      ),

    boolean_literal: ($) => choice("true", "false"),

    integer_literal: ($) =>
      choice(
        $._binary_literal,
        $._octal_literal,
        $._decimal_literal,
        $._hexadecimal_literal,
      ),

    _binary_digit: ($) => choice("0", "1", "_"),
    _binary_literal: ($) => seq("0b", repeat1($._binary_digit)),

    _octal_digit: ($) => choice("0", "1", "2", "3", "4", "5", "6", "7", "_"),
    _octal_literal: ($) => seq("0o", repeat1($._octal_digit)),

    _decimal_digit_head: ($) =>
      choice("0", "1", "2", "3", "4", "5", "6", "7", "8", "9"),
    _decimal_digit: ($) =>
      choice("0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "_"),
    _decimal_literal: ($) => repeat1($._decimal_digit),

    _hexadecimal_digit: ($) =>
      choice(
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "a",
        "b",
        "c",
        "d",
        "e",
        "f",
        "A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "_",
      ),
    _hexadecimal_literal: ($) => seq("0x", repeat1($._hexadecimal_digit)),

    floating_point_literal: ($) =>
      choice(
        seq($._decimal_fractional_constant, optional($._exponent)),
        seq($._decimal_literal, $._exponent),
      ),
    _decimal_fractional_constant: ($) =>
      seq($._decimal_literal, ".", $._floating_point_suffix),
    _exponent: ($) =>
      choice(
        seq("e", optional($._exponent_sign), $._floating_point_suffix),
        seq("E", optional($._exponent_sign), $._floating_point_suffix),
      ),
    _exponent_sign: ($) => choice("+", "-"),
    _floating_point_suffix: ($) =>
      seq($._floating_point_suffix_head, optional($._decimal_literal)),
    _floating_point_suffix_head: ($) => /[0-9]/,

    unicode_scalar_literal: ($) =>
      choice(seq("'", $._escape_char, "'"), seq("'", $._c_char, "'")),
    _escape_char: ($) => choice($._simple_escape, $._unicode_escape),
    _simple_escape: ($) => choice("\\0", "\\t", "\\n", "\\r", "\\'", '\\"'),
    _unicode_escape: ($) => seq("\\u", repeat($._hexadecimal_digit)),
    _c_char: ($) => /[^']/,

    string_literal: ($) => choice($._simple_string, $._multiline_string),
    _simple_string: ($) => seq('"', repeat($._simple_quoted_text_item), '"'),
    _simple_quoted_text_item: ($) => choice($._escape_char, $._s_char),
    _s_char: ($) => /[^"\x0a\x0d]/,
    _multiline_string: ($) =>
      seq('"""', repeat($._multiline_quoted_text_item), '"""'),
    _multiline_quoted_text_item: ($) => choice($._escape_char, $._m_char),
    _m_char: ($) => choice(/[^\"]/, seq('"', /[^"]/), seq('"', '"""')),

    identifier: ($) => choice($._identifier_token, $._contextual_keyword),
    _identifier_token: ($) =>
      choice(
        seq($._identifier_head, repeat($._identifier_tail)),
        seq("`", repeat($._bq_char), "`"),
      ),
    _identifier_head: ($) => /[_\p{Lu}\p{Ll}\p{Lt}\p{Lm}\p{Lo}\p{Nl}]/,
    _identifier_tail: ($) =>
      /[_\p{Lu}\p{Ll}\p{Lt}\p{Lm}\p{Lo}\p{Mn}\p{Mc}\p{Nl}\p{Nd}\p{Pc}]/,
    _bq_char: ($) => /[^`\x0a\x0d]/,
    _contextual_keyword: ($) => choice("mutating", "size", "any", "in"),

    _raw_operator: ($) => /[-*/^%&!?\p{Sm}]/,

    _whitespace: ($) => choice($._horizontal_space, $._newline),
    _horizontal_space: ($) =>
      choice($._hspace, $._single_line_comment, $._block_comment),
    _hspace: ($) => " ",
    _single_line_comment: ($) => /\/\/.*/,
    _block_comment: ($) => seq($._block_comment_open, "*/"),
    _block_comment_open: ($) => /[*](?:[^*/]+|(?:[/]+|[*]+)[^*/])*/,
    _newline: ($) => /\r?\n/,
    _stmt_separator: ($) =>
      seq(
        repeat($._horizontal_space),
        repeat1(seq(choice($._newline, ";"), repeat($._horizontal_space))),
      ),
    _module_scope_stmt_list: ($) =>
      choice(
        $._module_scope_stmt,
        seq($._module_scope_stmt_list, $._stmt_separator, $._module_scope_stmt),
      ),
    _module_scope_stmt: ($) => choice($.import_decl, $._module_scope_decl),
    _module_scope_decl: ($) =>
      choice(
        $.namespace_decl,
        $.trait_decl,
        $.type_alias_decl,
        $.product_type_decl,
        $.extension_decl,
        $.conformance_decl,
        $.binding_decl,
        $.function_decl,
        $.subscript_decl,
        $.operator_decl,
      ),
    import_decl: ($) => seq("import", repeat1($._whitespace), $.identifier),
    attribute_decl: ($) =>
      seq($.attribute_name, optional($.attribute_argument_list)),
    attribute_name: ($) => seq("@", $.identifier),
    attribute_argument_list: ($) =>
      seq(
        "(",
        $.attribute_argument,
        repeat(seq(",", $.attribute_argument)),
        ")",
      ),
    attribute_argument: ($) => choice($._simple_string, $.integer_literal),

    // Modifiers
    access_modifier: ($) => "public",
    member_modifier: ($) => choice($._receiver_modifier, $._static_modifier),
    _receiver_modifier: ($) => choice("sink", "inout", "yielded"),
    _static_modifier: ($) => "static",
    _conformance_list: ($) =>
      seq(":", $._name_type_expr, repeat(seq(",", $._name_type_expr))),
    _generic_clause: ($) =>
      seq("<", $._generic_parameter_list, optional($._where_clause), ">"),
    _generic_parameter_list: ($) =>
      repeat1(seq($._generic_parameter, ",", $._generic_parameter)),
    _generic_parameter: ($) =>
      choice($._generic_type_parameter, $._generic_value_parameter),
    _generic_type_parameter: ($) =>
      seq(
        optional("@type"),
        $.identifier,
        optional("..."),
        optional($._trait_annotation),
        optional(seq("=", $._type_expr)),
      ),
    _trait_annotation: ($) => seq(":", $._trait_composition),
    _generic_value_parameter: ($) =>
      seq(
        "@value",
        $.identifier,
        ":",
        $._type_expr,
        optional(seq("=", $._expr)),
      ),

    // Where clauses
    _where_clause: ($) => seq("where", $._where_clause_constraint_list),
    _where_clause_constraint_list: ($) =>
      repeat1(seq($._where_clause_constraint, ",", $._where_clause_constraint)),
    _where_clause_constraint: ($) =>
      choice(
        $._equality_constraint,
        $._conformance_constraint,
        $._value_constraint_expr,
      ),
    _equality_constraint: ($) => seq($._name_type_expr, "==", $._type_expr),
    _conformance_constraint: ($) =>
      seq($._name_type_expr, ":", $._trait_composition),
    _value_constraint_expr: ($) => seq("@value", $._expr),
    _trait_composition: ($) =>
      seq($._name_type_expr, repeat(seq("&", $._name_type_expr))),
    namespace_decl: ($) => seq($._namespace_head, $._namespace_body),
    _namespace_head: ($) =>
      seq(optional($.access_modifier), "namespace", $.identifier),
    _namespace_body: ($) => seq("{", optional($._namespace_member_list), "}"),
    _namespace_member_list: ($) =>
      repeat1(
        seq(
          $._namespace_member,
          repeat($._stmt_separator),
          $._namespace_member,
        ),
      ),
    _namespace_member: ($) =>
      choice(
        $.namespace_decl,
        $.trait_decl,
        $.type_alias_decl,
        $.product_type_decl,
        $.extension_decl,
        $.conformance_decl,
        $.binding_decl,
        $.function_decl,
        $.subscript_decl,
      ),

    // Trait declarations

    trait_decl: ($) => seq($._trait_head, $._trait_body),
    _trait_head: ($) =>
      seq(
        optional($.access_modifier),
        "trait",
        $.identifier,
        optional($._trait_refinement_list),
      ),
    _trait_refinement_list: ($) =>
      seq(":", $._name_type_expr, repeat(seq(",", $._name_type_expr))),
    _trait_body: ($) =>
      seq("{", repeat(choice($._trait_requirement_decl, ";")), "}"),
    _trait_requirement_decl: ($) =>
      choice(
        $._associated_decl,
        $.function_decl,
        $.subscript_decl,
        $._property_decl,
      ),
    _associated_decl: ($) =>
      choice($._associated_type_decl, $._associated_value_decl),
    _associated_type_decl: ($) =>
      seq(
        $._associated_type_head,
        optional($._associated_type_constraints),
        optional(seq("=", $._type_expr)),
      ),
    _associated_type_head: ($) => seq("type", $.identifier),
    _associated_type_constraints: ($) =>
      choice($._conformance_list, seq($._conformance_list, $._where_clause)),
    _associated_value_decl: ($) =>
      seq(
        $._associated_value_head,
        optional($._where_clause),
        optional(seq("=", $._expr)),
      ),
    _associated_value_head: ($) => seq("value", $.identifier),
    product_type_decl: ($) => seq($._product_type_head, $._product_type_body),
    _product_type_head: ($) =>
      seq(
        optional($.access_modifier),
        "type",
        $.identifier,
        optional($._generic_clause),
        optional($._conformance_list),
      ),
    _product_type_body: ($) =>
      seq("{", repeat(choice($._product_type_member_decl, ";")), "}"),
    _product_type_member_decl: ($) =>
      choice(
        $.function_decl,
        $._deinit_decl,
        $.subscript_decl,
        $._property_decl,
        $.binding_decl,
        $.product_type_decl,
        $.type_alias_decl,
      ),

    // Type alias declarations

    type_alias_decl: ($) => seq($._type_alias_head, "=", $._type_expr),
    _type_alias_head: ($) =>
      seq(
        optional($.access_modifier),
        "typealias",
        $.identifier,
        optional($._generic_clause),
      ),
    _union_decl: ($) =>
      seq($.product_type_decl, repeat(seq("|", $.product_type_decl))),

    // Extension declarations
    extension_decl: ($) => seq($._extension_head, $._extension_body),
    _extension_head: ($) =>
      seq(
        optional($.access_modifier),
        "extension",
        $._type_expr,
        optional($._where_clause),
      ),
    _extension_body: ($) =>
      seq("{", repeat(choice($._extension_member_decl, ";")), "}"),
    _extension_member_decl: ($) =>
      choice(
        $.function_decl,
        $.subscript_decl,
        $.product_type_decl,
        $.type_alias_decl,
      ),

    // Conformance declarations
    conformance_decl: ($) => seq($._conformance_head, $._conformance_body),
    _conformance_head: ($) =>
      seq(
        optional($.access_modifier),
        "conformance",
        $._type_expr,
        $._conformance_list,
        optional($._where_clause),
      ),
    _conformance_body: ($) =>
      seq("{", repeat(choice($._conformance_member_decl, ";")), "}"),
    _conformance_member_decl: ($) =>
      choice(
        $.function_decl,
        $.subscript_decl,
        $.product_type_decl,
        $.type_alias_decl,
      ),

    // Binding declarations
    binding_decl: ($) => seq($._binding_head, optional($._binding_initializer)),
    _binding_head: ($) =>
      seq(
        optional($.access_modifier),
        repeat($.member_modifier),
        $._binding_pattern,
      ),
    _binding_initializer: ($) => seq("=", $._expr),

    // Function declarations
    function_decl: ($) =>
      choice(
        $._memberwise_init_decl,
        seq(
          $._function_head,
          $._function_signature,
          optional($._function_body),
        ),
      ),
    _memberwise_init_decl: ($) =>
      seq(optional($.access_modifier), "memberwise", "init"),
    _function_head: ($) =>
      seq(
        optional($.access_modifier),
        repeat($.member_modifier),
        $.function_decl_identifier,
        optional($._generic_clause),
        optional($._capture_list),
      ),
    function_decl_identifier: ($) =>
      choice(
        "init",
        seq("fun", $.identifier),
        seq("fun", $._operator_notation, $._operator),
      ),
    _function_body: ($) => choice($._method_bundle_body, $._brace_stmt),
    _method_bundle_body: ($) => seq("{", repeat($._method_impl), "}"),
    _operator: ($) => seq($._raw_operator, repeat($._raw_operator)),

    // Function signatures
    _function_signature: ($) =>
      seq(
        "(",
        optional($._parameter_list),
        ")",
        optional($._receiver_effect),
        optional(seq("->", $._type_expr)),
        optional($._type_aliases_clause),
      ),
    _type_aliases_clause: ($) =>
      seq(
        "where",
        $._type_aliases_clause_item,
        repeat(seq(",", $._type_aliases_clause_item)),
      ),
    _type_aliases_clause_item: ($) =>
      seq("typealias", $.identifier, "=", $._type_expr),
    _method_impl: ($) => seq($._method_introducer, optional($._brace_stmt)),
    _method_introducer: ($) => choice("let", "sink", "inout", "set"),

    // Subscript declarations
    subscript_decl: ($) =>
      seq($._subscript_head, $._subscript_signature, $._subscript_body),
    _subscript_head: ($) =>
      seq(
        optional($.access_modifier),
        repeat($.member_modifier),
        "subscript",
        optional($.identifier),
        optional($._generic_clause),
        optional($._capture_list),
      ),
    _subscript_identifier: ($) => seq("subscript", $.identifier),
    _subscript_body: ($) => seq("{", repeat($._subscript_impl), "}"),
    _subscript_signature: ($) =>
      seq(
        "(",
        optional($._parameter_list),
        ")",
        optional($._receiver_effect),
        ":",
        optional("var"),
        $._type_expr,
      ),
    _subscript_impl: ($) =>
      seq($._subscript_introducer, optional($._brace_stmt)),
    _subscript_introducer: ($) => choice("let", "sink", "inout", "set"),

    // Property declarations
    _property_decl: ($) =>
      seq($._property_head, $._property_annotation, $._subscript_body),
    _property_head: ($) =>
      seq(repeat($.member_modifier), "property", $.identifier),
    _property_annotation: ($) => seq(":", $._type_expr),

    // Parameter lists
    _parameter_list: ($) =>
      repeat1(seq($._parameter_decl, ",", $._parameter_decl)),
    _parameter_decl: ($) =>
      seq(
        choice($.identifier, "_"),
        optional($.identifier),
        optional(seq(":", $._parameter_type_expr)),
        optional(seq("=", $._expr)),
      ),
    _default_value: ($) => seq("=", $._expr),
    _stmt: ($) =>
      choice(
        $._brace_stmt,
        $._discard_stmt,
        $._loop_stmt,
        $._jump_stmt,
        $._decl_stmt,
        $._expr,
      ),
    _brace_stmt: ($) => seq("{", optional($._stmt_list), "}"),
    _stmt_list: ($) =>
      repeat1(seq($._stmt, repeat($._stmt_separator), $._stmt)),
    _discard_stmt: ($) => seq("_", "=", $._expr),
    _loop_stmt: ($) => choice($._do_while_stmt, $._while_stmt, $._for_stmt),
    _do_while_stmt: ($) => seq("do", $._brace_stmt, "while", $._expr),
    _while_stmt: ($) => seq("while", $._while_condition_list, $._brace_stmt),
    _while_condition_list: ($) =>
      repeat1(seq($._while_condition_item, ",", $._while_condition_item)),
    _while_condition_item: ($) =>
      choice(seq($._binding_pattern, "=", $._expr), $._expr),
    _for_stmt: ($) =>
      seq($._for_head, $._for_range, optional($._for_filter), $._brace_stmt),
    _for_head: ($) => seq("for", $.binding_decl),
    _for_range: ($) => seq("in", $._expr),
    _for_filter: ($) => seq("where", $._expr),
    _jump_stmt: ($) =>
      choice(
        $._conditional_binding_stmt,
        seq("return", optional(seq($._horizontal_space, $._expr))),
        seq("yield", $._horizontal_space, $._expr),
        "break",
        "continue",
      ),
    _conditional_binding_stmt: ($) =>
      seq($._binding_pattern, "else", $._cond_binding_fallback),
    _cond_binding_fallback: ($) => choice($._jump_stmt, $._brace_stmt, $._expr),
    _decl_stmt: ($) =>
      choice(
        $.type_alias_decl,
        $.product_type_decl,
        $.extension_decl,
        $.conformance_decl,
        $.function_decl,
        $.subscript_decl,
        $.binding_decl,
      ),

    // Expressions
    _expr: ($) => seq($._infix_expr_head, repeat($._infix_expr_tail)),
    _infix_expr_head: ($) =>
      choice($._async_expr, $._await_expr, $._unsafe_expr, $._prefix_expr),
    _infix_expr_tail: ($) =>
      choice($._type_casting_tail, $._infix_operator_tail),
    _type_casting_tail: ($) => seq($._type_casting_operator, $._type_expr),
    _infix_operator_tail: ($) => seq($._infix_operator, $._prefix_expr),
    _infix_operator: ($) =>
      choice($._operator, "=", "==", "<", ">", "..<", "..."),
    _prefix_expr: ($) => seq(optional($._prefix_operator), $._postfix_expr),
    _prefix_operator: ($) =>
      seq($._prefix_operator_head, repeat($._raw_operator)),
    _prefix_operator_head: ($) => choice(/[^<-]/, seq("-", /[^*/^%&!?\p{Sm}]/)),
    _postfix_expr: ($) =>
      seq(
        $._compound_expr,
        optional(seq($._postfix_expr, $._postfix_operator)),
      ),
    _postfix_operator: ($) =>
      seq($._postfix_operator_head, repeat($._raw_operator)),
    _postfix_operator_head: ($) =>
      choice(/[^>-]/, seq("-", /[^*/^%&!?\p{Sm}]/)),

    // Primary expressions
    _primary_expr: ($) =>
      choice(
        $._scalar_literal,
        $._compound_literal,
        $._primary_decl_ref,
        $._implicit_member_ref,
        $._lambda_expr,
        $._selection_expr,
        $._inout_expr,
        $._tuple_expr,
        "nil",
      ),

    // Asynchronous expressions
    _async_expr: ($) =>
      choice(
        seq($._async_expr_head, $._expr),
        seq($._async_expr_head, "->", $._type_expr, $._brace_stmt),
      ),
    _async_expr_head: ($) => seq("async", optional($._capture_list)),
    _await_expr: ($) => seq("await", $._expr),
    _unsafe_expr: ($) => seq("unsafe", $._expr),
    _scalar_literal: ($) =>
      choice(
        $.boolean_literal,
        $.integer_literal,
        $.floating_point_literal,
        $.string_literal,
        $.unicode_scalar_literal,
      ),

    // Compound literals
    _compound_literal: ($) => choice($._buffer_literal, $._map_literal),

    // Buffer literals
    _buffer_literal: ($) => seq("[", optional($._buffer_component_list), "]"),
    _buffer_component_list: ($) => repeat1(seq($._expr, ",", $._expr)),
    _buffer_component: ($) => $._expr,

    // Map literals
    _map_literal: ($) =>
      choice(seq("[", $._map_component_list, "]"), seq("[", ":", "]")),
    _map_component_list: ($) =>
      repeat1(seq($._map_component, ",", $._map_component)),
    _map_component: ($) => seq($._expr, ":", $._expr),

    // Primary declaration references
    _primary_decl_ref: ($) =>
      seq($._identifier_expr, optional($._static_argument_list)),
    _static_argument_list: ($) =>
      seq("<", $._static_argument, repeat(seq(",", $._static_argument)), ">"),
    _static_argument: ($) =>
      seq(optional(seq($.identifier, ":")), choice($._expr, $._type_expr)),

    // Implicit member references
    _implicit_member_ref: ($) => seq(".", $._primary_decl_ref),

    // Identifier expressions
    _identifier_expr: ($) =>
      seq($._entity_identifier, optional($._impl_identifier)),
    _entity_identifier: ($) =>
      choice(
        $.identifier,
        $._function_entity_identifier,
        $._operator_entity_identifier,
      ),
    _function_entity_identifier: ($) =>
      seq($.identifier, "(", $._argument_label_list, ")"),
    _operator_entity_identifier: ($) => seq($._operator_notation, $._operator),
    _argument_label: ($) => seq($.identifier, ":"),
    _impl_identifier: ($) => seq(".", $._method_introducer),

    // Inout expressions
    _inout_expr: ($) => seq("&", $._expr),

    // Tuple expressions
    _tuple_expr: ($) => seq("(", optional($._tuple_expr_element_list), ")"),
    _tuple_expr_element_list: ($) =>
      repeat1(seq($._tuple_expr_element, ",", $._tuple_expr_element)),
    _tuple_expr_element: ($) => seq(optional(seq($.identifier, ":")), $._expr),

    // Compound expressions
    _compound_expr: ($) =>
      choice(
        $._value_member_expr,
        $._static_value_member_expr,
        $._function_call_expr,
        $._subscript_call_expr,
        $._primary_expr,
      ),

    // Value member expressions
    _value_member_expr: ($) =>
      choice($._labeled_member_expr, $._indexed_member_expr),
    _labeled_member_expr: ($) => seq($._primary_expr, ".", $._primary_decl_ref),
    _indexed_member_expr: ($) => seq($._primary_expr, ".", $._member_index),
    _member_index: ($) => repeat1($._decimal_digit_head),

    // Static value member expressions
    _static_value_member_expr: ($) =>
      seq($._type_expr, ".", $._primary_decl_ref),

    // Function call expressions
    _function_call_expr: ($) =>
      seq($._function_call_head, optional($._call_argument_list), ")"),
    _function_call_head: ($) => seq($._primary_expr, "("),
    _call_argument_list: ($) =>
      repeat1(seq($._call_argument, ",", $._call_argument)),
    _call_argument: ($) => seq(optional(seq($.identifier, ":")), $._expr),

    // Subscript call expressions
    _subscript_call_expr: ($) =>
      seq($._subscript_call_head, optional($._call_argument_list), "]"),
    _subscript_call_head: ($) => seq($._primary_expr, "["),
    _selection_expr: ($) => choice($._conditional_expr, $._match_expr),
    _conditional_expr: ($) =>
      seq(
        "if",
        $._conditional_clause,
        $._brace_stmt,
        optional($._conditional_tail),
      ),
    _conditional_clause: ($) =>
      repeat1(seq($._conditional_clause_item, ",", $._conditional_clause_item)),
    _conditional_clause_item: ($) =>
      choice(seq($._binding_pattern, "=", $._expr), $._expr),
    _conditional_tail: ($) =>
      choice(seq("else", $._conditional_expr), "else", $._brace_stmt),
    _match_expr: ($) => seq("match", $._expr, "{", repeat($._match_case), "}"),
    _match_case: ($) =>
      seq($._match_case_head, optional(seq("where", $._expr)), $._brace_stmt),
    _match_case_head: ($) => $.binding_decl,

    // Type expressions
    _type_expr: ($) =>
      choice(
        $._async_type_expr,
        $._conformance_lens_type_expr,
        $._existential_type_expr,
        $._opaque_type_expr,
        $._indirect_type_expr,
        $._lambda_type_expr,
        $._name_type_expr,
        $._stored_projection_type_expr,
        $._tuple_type_expr,
        $._union_type_expr,
        $._wildcard_type_expr,
        seq("(", $._type_expr, ")"),
      ),
    _async_type_expr: ($) => seq("async", $._type_expr),
    _conformance_lens_type_expr: ($) =>
      seq($._type_expr, "::", $._type_identifier),
    _existential_type_expr: ($) =>
      seq("any", $._trait_composition, optional($._where_clause)),
    _opaque_type_expr: ($) =>
      choice(
        seq("some", $._trait_composition, optional($._where_clause)),
        "some",
        "_",
      ),
    _indirect_type_expr: ($) => seq("indirect", $._type_expr),
    _lambda_type_expr: ($) =>
      seq(
        optional($._lambda_environment),
        "(",
        optional($._lamda_parameter_list),
        ")",
        optional($._receiver_effect),
        "->",
        $._type_expr,
      ),
    _lambda_environment: ($) => choice("thin", seq("[", $._type_expr, "]")),
    _lamda_parameter_list: ($) =>
      repeat1(seq($._lambda_parameter, ",", $._lambda_parameter)),
    _lambda_parameter: ($) =>
      seq(optional(seq($.identifier, ":")), $._type_expr),
    _receiver_effect: ($) => choice("inout", "sink"),
    _name_type_expr: ($) =>
      seq(optional(seq($._type_expr, ".")), $._primary_type_decl_ref),
    _primary_type_decl_ref: ($) =>
      seq($._type_identifier, optional($._type_argument_list)),
    _type_identifier: ($) => $.identifier,
    _parameter_type_expr: ($) =>
      seq(optional($._parameter_passing_convention), $._type_expr),
    _parameter_passing_convention: ($) =>
      choice("let", "inout", "sink", "yielded"),
    _stored_projection_type_expr: ($) =>
      seq("[", $._stored_projection_capability, $._type_expr, "]"),
    _stored_projection_capability: ($) => choice("let", "inout", "yielded"),
    _tuple_type_expr: ($) =>
      seq("{", optional($._tuple_type_element_list), "}"),
    _tuple_type_element_list: ($) =>
      repeat1(seq($._tuple_type_element, ",", $._tuple_type_element)),
    _tuple_type_element: ($) =>
      seq(optional(seq($.identifier, ":")), $._type_expr),
    _union_type_expr: ($) => seq($._type_expr, repeat(seq("|", $._type_expr))),
    _wildcard_type_expr: ($) => "_",
    _lambda_expr: ($) =>
      seq(
        "fun",
        optional($._capture_list),
        $._function_signature,
        $._lambda_body,
      ),

    _capture_list: ($) => seq("[", $.binding_decl_list, "]"),
    binding_decl_list: ($) => repeat1(seq($.binding_decl, ",", $.binding_decl)),
    binding_decl: ($) =>
      seq(
        optional($.access_modifier),
        repeat($.member_modifier),
        $._binding_pattern,
        optional(seq("=", $._expr)),
      ),

    _function_signature: ($) =>
      seq(
        "(",
        optional($._parameter_list),
        ")",
        optional($._receiver_effect),
        optional(seq("->", $._type_expr)),
        optional($._type_aliases_clause),
      ),

    _lambda_body: ($) => $._brace_stmt,
    _lambda_expr: ($) =>
      seq(
        "fun",
        optional($._capture_list),
        $._function_signature,
        $._lambda_body,
      ),

    _capture_list: ($) => seq("[", $.binding_decl_list, "]"),
    binding_decl_list: ($) => repeat1(seq($.binding_decl, ",", $.binding_decl)),
    binding_decl: ($) =>
      seq(
        optional($.access_modifier),
        repeat($.member_modifier),
        $._binding_pattern,
        optional(seq("=", $._expr)),
      ),

    _function_signature: ($) =>
      seq(
        "(",
        optional($._parameter_list),
        ")",
        optional($._receiver_effect),
        optional(seq("->", $._type_expr)),
        optional($._type_aliases_clause),
      ),

    _lambda_body: ($) => $._brace_stmt,

    // Pattern rules
    _pattern: ($) =>
      choice(
        $._binding_pattern,
        $._expr_pattern,
        $._tuple_pattern,
        $._wildcard_pattern,
      ),

    _binding_pattern: ($) =>
      seq(
        $._binding_introducer,
        choice($._tuple_pattern, $._wildcard_pattern, $.identifier),
        optional($._binding_annotation),
      ),

    _binding_introducer: ($) => choice("let", "var", "sink", "inout"),

    _binding_annotation: ($) => seq(":", $._type_expr),

    _expr_pattern: ($) => $._expr,

    _tuple_pattern: ($) => seq("(", $._tuple_pattern_element_list, ")"),

    _tuple_pattern_element_list: ($) =>
      repeat1(seq($._tuple_pattern_element, ",", $._tuple_pattern_element)),

    _tuple_pattern_element: ($) =>
      seq(optional(seq($.identifier, ":")), $._pattern),

    _wildcard_pattern: ($) => "_",
    operator_decl: ($) =>
      seq(
        "operator",
        $._operator_notation,
        $._operator,
        optional(seq(":", $._precedence_group)),
      ),
    _expr: ($) => seq($._infix_expr_head, repeat($._infix_expr_tail)),
    _deinit_decl: ($) => seq("deinit", $._brace_stmt),
    _operator_notation: ($) => choice("infix", "prefix", "postfix"),
    _type_casting_operator: ($) => choice("as", "as!"),
    _argument_label_list: ($) =>
      repeat1(seq($._argument_label, ",", $._argument_label)),
    _type_argument_list: ($) => seq("<", $._type_argument_list_items, ">"),
    _type_argument_list_items: ($) =>
      repeat1(seq($._type_argument, ",", $._type_argument)),
    _type_argument: ($) => $._type_expr,
    _precedence_group: ($) =>
      choice(
        "assignment",
        "disjunction",
        "conjunction",
        "comparison",
        "fallback",
        "range",
        "addition",
        "multiplication",
        "shift",
      ),
  },
});
