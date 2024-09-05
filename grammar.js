module.exports = {
  name: "hylo",

  rules: {
    source_file: $ => repeat(choice($.module_scope_stmt, $.whitespace)),

    module_scope_stmt: $ => choice($.module_scope_decl, $.import_decl),
    module_scope_decl: $ => choice(
      $.namespace_decl,
      $.trait_decl,
      $.type_alias_decl,
      $.product_type_decl,
      $.extension_decl,
      $.conformance_decl,
      $.binding_decl,
      $.function_decl,
      $.subscript_decl,
      $.operator_decl
    ),
    import_decl:  
    $ => seq("import", $.identifier),

    namespace_decl: $ => seq(
      optional($.access_modifier),
      "namespace",
      $.identifier,
      $.namespace_body
    ),
    namespace_body: $ => seq("{", repeat(choice($.namespace_member, $.whitespace)), "}"),
    namespace_member: $ => choice(
      $.namespace_decl,
      $.trait_decl,
      $.type_alias_decl,
      $.product_type_decl,
      $.extension_decl,
      $.conformance_decl,
      $.binding_decl,
      $.function_decl,
      $.subscript_decl
    ),
    trait_decl:  
    $ => seq(
      optional($.access_modifier),
      "trait",
      $.identifier,
      optional($.trait_refinement_list),
      $.trait_body
    ),
    trait_refinement_list: $ => seq(":", $.name_type_expr, repeat(",", $.name_type_expr)),
    trait_body: $ => seq("{", repeat(choice($.trait_requirement_decl, ";"), $.whitespace), "}"),
    trait_requirement_decl: $ => choice(
      $.associated_decl,
      $.function_decl,
      $.subscript_decl,
      $.property_decl
    ),
    associated_decl: $ => choice($.associated_type_decl, $.associated_value_decl),
    associated_type_decl: $ => seq(
      "type",
      $.identifier,
      optional($.associated_type_constraints),
      optional($.type_expr)
    ),
    associated_type_constraints: $ => choice($.conformance_list, seq($.conformance_list, $.where_clause)),
    associated_value_decl: $ => seq(
      "value",
      $.identifier,
      optional($.where_clause),
      optional($.expr)
    ),
    product_type_decl: $ => seq(
      optional($.access_modifier),
      "type",
      $.identifier,
      optional($.generic_clause),
      optional($.conformance_list),
      $.product_type_body
    ),
    product_type_body: $ => seq("{", repeat(choice($.product_type_member_decl, ";"), $.whitespace), "}"),
    product_type_member_decl: $ => choice(
      $.function_decl,
      $.deinit_decl,
      $.subscript_decl,
      $.property_decl,
      $.binding_decl,
      $.product_type_decl,
      $.type_alias_decl
    ),
    type_alias_decl: $ => seq($.type_alias_head, "=", $.type_expr),
    type_alias_head: $ => seq(optional($.access_modifier), "typealias", $.identifier, optional($.generic_clause)),
    union_decl: $ => seq($.product_type_decl, repeat("|", $.product_type_decl)),
    extension_decl: $ => seq(
      optional($.access_modifier),
      "extension",
      $.type_expr,
      optional($.where_clause),
      $.extension_body
    ),
    extension_body: $ => seq("{", repeat(choice($.extension_member_decl, ";"), $.whitespace), "}"),
    extension_member_decl: $ => choice(
      $.function_decl,
      $.subscript_decl,
      $.product_type_decl,
      $.type_alias_decl
    ),
    conformance_decl: $ => seq(
      optional($.access_modifier),
      "conformance",
      $.type_expr,
      $.conformance_list,
      optional($.where_clause),
      $.conformance_body
    ),
    conformance_body: $ => seq("{", repeat(choice($.conformance_member_decl, ";"), $.whitespace), "}"),
    conformance_member_decl: $ => choice(
      $.function_decl,
      $.subscript_decl,
      $.product_type_decl,
      $.type_alias_decl
    ),
    binding_decl: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.binding_pattern,
      optional($.binding_initializer)
    ),
    binding_head: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.binding_pattern
    ),
    binding_initializer: $ => seq("=", $.expr),
    function_decl: $ => choice($.memberwise_init_decl, seq($.function_head, $.function_signature, optional($.function_body))),
    memberwise_init_decl: $ => seq(optional($.access_modifier), "memberwise", "init"),
    deinit_decl: $ => "deinit",
    function_head: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.function_decl_identifier,
      optional($.generic_clause),
      optional($.capture_list)
    ),
    function_decl_identifier: $ => choice("init", "fun", seq("fun", $.identifier), seq("fun", $.operator_notation, $.operator)),
    function_body: $ => choice($.method_bundle_body, $.brace_stmt),
    method_bundle_body: $ => seq("{", repeat($.method_impl, $.whitespace), "}"),
    operator: $ => repeat($.raw_operator),
    function_signature: $ => seq(
      "(",
      optional($.parameter_list),
      ")",
      optional($.receiver_effect),
      optional(seq("->", $.type_expr)),
      optional($.type_aliases_clause)
    ),
    type_aliases_clause: $ => seq(
      "where",
      $.type_aliases_clause_item,
      repeat(",", $.type_aliases_clause_item)
    ),
    type_aliases_clause_item: $ => seq("typealias", $.identifier, "=", $.type_expr),
    method_impl: $ => seq($.method_introducer, optional($.brace_stmt)),
    method_introducer: $ => choice("let", "sink", "inout", "set"),
    subscript_decl: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.subscript_identifier,
      optional($.generic_clause),
      optional($.capture_list),
      $.subscript_body
    ),
    subscript_identifier: $ => "subscript",
    generic_clause: $ => seq("<", $.generic_parameter, repeat(",", $.generic_parameter), optional($.where_clause), ">"),
    generic_parameter: $ => choice($.generic_type_parameter, $.generic_value_parameter),
    generic_type_parameter: $ => seq(
      optional("@type"),
      $.identifier,
      optional("..."),
      optional($.trait_annotation),
      optional(seq("=", $.type_expr))
    ),
    trait_annotation: $ => ":", $.trait_composition,
    generic_value_parameter: $ => seq(
      "@value",
      $.identifier,
      ":",
      $.type_expr,
      optional(seq("=", $.expr))
    ),
    where_clause: $ => seq("where", $.where_clause_constraint_list),
    where_clause_constraint_list: $ => seq(
      $.where_clause_constraint,
      repeat(",", $.where_clause_constraint)
    ),
    where_clause_constraint: $ => choice($.equality_constraint, $.conformance_constraint, $.value_constraint_expr),
    equality_constraint: $ => seq($.name_type_expr, "==", $.type_expr),
    conformance_constraint: $ => seq($.name_type_expr, ":", $.trait_composition),
    value_constraint_expr: $ => seq("@value", $.expr),
    trait_composition: $ => seq($.name_type_expr, repeat("&", $.name_type_expr)),
    capture_list: $ => seq("[", $.binding_decl, repeat(",", $.binding_decl), "]"),
    stmt: $ => choice($.brace_stmt, $.discard_stmt, $.loop_stmt, $.jump_stmt, $.decl_stmt, $.expr),
    brace_stmt: $ => seq("{", $.stmt_list?, "}"),
    stmt_list: $ => repeat(choice($.stmt, $.stmt_separator)),
    stmt_separator: $ => choice($.horizontal_space, seq($.newline, optional($.horizontal_space))),
    discard_stmt: $ => seq("_", "=", $.expr),
    loop_stmt: $ => choice($.do_while_stmt, $.while_stmt, $.for_stmt),
    do_while_stmt: $ => seq("do", $.brace_stmt, "while", $.expr),
    while_stmt: $ => seq("while", $.while_condition_list, $.brace_stmt),
    while_condition_list: $ => seq($.while_condition_item, repeat(",", $.while_condition_item)),
    while_condition_item: $ => choice($.binding_pattern, "=", $.expr, $.expr),
    for_stmt: $ => seq($.for_head, $.for_range, optional($.for_filter), $.brace_stmt),
    for_head: $ => seq("for", $.binding_decl),
    for_range: $ => seq("in", $.expr),
    for_filter: $ => seq("where", $.expr),
    jump_stmt: $ => choice(
      $.conditional_binding_stmt,
      seq("return", optional($.horizontal_space), $.expr),
      seq("yield", $.horizontal_space, $.expr),
      "break",
      "continue"
    ),
    conditional_binding_stmt: $ => seq($.binding_pattern, "else", $.cond_binding_fallback),
    cond_binding_fallback: $ => choice($.jump_stmt, $.brace_stmt, $.expr),
    decl_stmt: $ => choice(
      $.type_alias_decl,
      $.product_type_decl,
      $.extension_decl,
      $.conformance_decl,
      $.function_decl,
      $.subscript_decl,
      $.binding_decl
    ),
    expr: $ => seq($.infix_expr_head, $.infix_expr_tail+),
    infix_expr_head: $ => choice($.async_expr, $.await_expr, $.unsafe_expr, $.prefix_expr),
    infix_expr_tail: $ => choice($.type_casting_tail, $.infix_operator_tail),
    type_casting_tail: $ => seq($.type_casting_operator, $.type_expr),
    infix_operator_tail: $ => seq($.infix_operator, $.prefix_expr),
    infix_operator: $ => choice($.operator, "=", "==", "<", ">", "..", "..."),
    async_expr: $ => seq($.async_expr_head, $.expr, optional(seq("->", $.type_expr), $.brace_stmt)),
    async_expr_head: $ => seq("async", optional($.capture_list)),
    await_expr: $ => seq("await", $.expr),
    unsafe_expr: $ => seq("unsafe", $.expr),
    prefix_expr: $ => seq(optional($.prefix_operator), $.postfix_expr),
    prefix_operator: $ => seq($.prefix_operator_head, $.raw_operator+),
    prefix_operator_head: $ => /(?:(?![<])[-*/^%&!?\p{Sm}])/,
    postfix_expr: $ => seq($.compound_expr, optional($.postfix_operator)),
    postfix_operator: $ => seq($.postfix_operator_head, $.raw_operator+),
    postfix_operator_head: $ => /(?:(?![>])[-*/^%&!?\p{Sm}])/,
    primary_expr: $ => choice(
      $.scalar_literal,
      $.compound_literal,
      $.primary_decl_ref,
      $.implicit_member_ref,
      $.lambda_expr,
      $.selection_expr,
      $.inout_expr,
      $.tuple_expr,
      "nil"
    ),
    scalar_literal:  
    $ => choice($.boolean_literal, $.integer_literal, $.floating_point_literal, $.string_literal, $.unicode_scalar_literal),
    compound_literal: $ => choice($.buffer_literal, $.map_literal),
    buffer_literal: $ => seq("[", optional($.buffer_component_list), "]"),
    buffer_component_list: $ => seq($.expr, repeat(",", $.expr), optional(",")),
    map_literal: $ => seq("[", $.map_component_list, "]"),
    map_component_list: $ => seq($.map_component, repeat(",", $.map_component)),
    map_component: $ => seq($.expr, ":", $.expr),
    primary_decl_ref: $ => seq($.identifier_expr, optional($.static_argument_list)),
    static_argument_list: $ => seq("<", $.static_argument, repeat(",", $.static_argument), ">"),
    static_argument: $ => seq(optional(seq($.identifier, ":")), choice($.expr, $.type_expr)),
    implicit_member_ref: $ => seq(".", $.primary_decl_ref),
    identifier_expr: $ => seq($.entity_identifier, optional($.impl_identifier)),
    entity_identifier: $ => choice($.identifier, $.function_entity_identifier, $.operator_entity_identifier),
    function_entity_identifier: $ => seq($.identifier, "(", $.argument_label+, ")"),
    operator_entity_identifier: $ => seq($.operator_notation, $.operator),
    argument_label: $ => seq($.identifier, ":"),
    impl_identifier: $ => seq(".", $.method_introducer),
    inout_expr: $ => seq("&", $.expr),
    tuple_expr: $ => seq("(", optional($.tuple_expr_element_list), ")"),
    tuple_expr_element_list: $ => seq($.tuple_expr_element, optional(seq(",", $.tuple_expr_element))),
    tuple_expr_element: $ => seq(optional(seq($.identifier, ":")), $.expr),
    compound_expr: $ => choice(
      $.value_member_expr,
      $.static_value_member_expr,
      $.function_call_expr,
      $.subscript_call_expr,
      $.primary_expr
    ),
    value_member_expr: $ => choice($.labeled_member_expr, $.indexed_member_expr),
    labeled_member_expr: $ => seq($.primary_expr, ".", $.primary_decl_ref),
    indexed_member_expr: $ => seq($.primary_expr, ".", $.member_index),
    member_index: $ => repeat($.decimal_digit_head),
    static_value_member_expr: $ => seq($.type_expr, ".", $.primary_decl_ref),
    function_call_expr: $ => seq($.function_call_head, optional($.call_argument_list), ")"),
    function_call_head: $ => seq($.primary_expr, "("),
    call_argument_list: $ => seq($.call_argument, repeat(",", $.call_argument)),
    call_argument: $ => seq(optional(seq($.identifier, ":")), $.expr),
    subscript_call_expr: $ => seq($.subscript_call_head, $.call_argument_list?, "]"),
    subscript_call_head: $ => seq($.primary_expr, "["),
    lambda_expr: $ => seq("fun", optional($.capture_list), $.function_signature, $.lambda_body),
    lambda_body: $ => $.brace_stmt,
    selection_expr: $ => choice($.conditional_expr, $.match_expr),
    conditional_expr: $ => seq("if", $.conditional_clause, $.brace_stmt, optional($.conditional_tail)),
    conditional_clause: $ => seq($.conditional_clause_item, repeat(",", $.conditional_clause_item)),
    conditional_clause_item: $ => choice($.binding_pattern, "=", $.expr, $.expr),
    conditional_tail: $ => choice("else", $.conditional_expr, "else", $.brace_stmt),
    match_expr: $ => seq("match", $.expr, "{", $.match_case+, "}"),
    match_case: $ => seq($.match_case_head, optional(seq("where", $.expr)), $.brace_stmt),
    match_case_head: $ => $.binding_decl,
  },
  tokens: {
    keyword: $ => choice("true", "false", "mutating", "size", "any", "in", "import", "namespace", "trait", "typealias", "extension", "conformance", "binding", "function", "subscript", "operator", "deinit", "memberwise", "let", "sink", "inout", "set", "return", "yield", "break", "continue", "if", "else", "match", "where", "async", "await", "unsafe", "some", "indirect", "thin", "as", "as!", "public", "static", "nil"),
    operator: $ => /[[-*/^%&!?\p{Sm}]/],
    boolean_literal: $ => choice("true", "false"),
    integer_literal: $ => choice(
      $.binary_literal,
      $.octal_literal,
      $.decimal_literal,
      $.hexadecimal_literal
    ),
    floating_point_literal: $ => /\d+(\.\d+)?(e|E)([+-]?\d+)?/,
    string_literal: $ => choice(
      /"(?:[^"\\]|\\.)*"/,
      /"""(?:[^"]|"(?!"))*"""/
    ),
    unicode_scalar_literal: $ => /'(?:[^']|\\.)'/,
    identifier: $ => /[a-zA-Z_]\w*/,
    punctuation: $ => /[()\[\]{}:;,.<>=+-*/%&|^~]/,
    whitespace: $ => /\s+/
  }
};
