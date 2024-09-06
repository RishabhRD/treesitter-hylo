module.exports = grammar({
  name: 'hylo',

  rules: {
    // Literals
    boolean_literal: $ => choice('true', 'false'),

    // Integer literals
    integer_literal: $ => choice(
      $.binary_literal,
      $.octal_literal,
      $.decimal_literal,
      $.hexadecimal_literal
    ),

    binary_literal: $ => seq('0b', repeat($.binary_digit)),
    binary_digit: $ => /[01]/,

    octal_literal: $ => seq('0o', repeat($.octal_digit)),
    octal_digit: $ => /[0-7]/,

    decimal_literal: $ => seq($.decimal_digit_head, optional(repeat($.decimal_digit))),
    decimal_digit: $ => /[0-9]/,
    decimal_digit_head: $ => /[0-9]/,

    hexadecimal_literal: $ => seq('0x', repeat($.hexadecimal_digit)),
    hexadecimal_digit: $ => /[0-9A-Fa-f]/,

    // Floating-point literals
    floating_point_literal: $ => choice(
      seq($.decimal_fractional_constant, optional($.exponent)),
      seq($.decimal_literal, $.exponent)
    ),

    decimal_fractional_constant: $ => seq($.decimal_literal, '.', $.floating_point_suffix),
    exponent: $ => choice(
      seq('e', optional($.exponent_sign), $.floating_point_suffix),
      seq('E', optional($.exponent_sign), $.floating_point_suffix)
    ),
    exponent_sign: $ => choice('+', '-'),
    floating_point_suffix: $ => seq($.floating_point_suffix_head, optional($.decimal_literal)),
    floating_point_suffix_head: $ => /[0-9]/,

    // Unicode scalar literals
    unicode_scalar_literal: $ => choice(
      seq("'", $.escape_char, "'"),
      seq("'", $.c_char, "'")
    ),
    escape_char: $ => choice($.simple_escape, $.unicode_escape),
    simple_escape: $ => choice('\\0', '\\t', '\\n', '\\r', "'", '"'),
    unicode_escape: $ => seq('\\u', repeat($.hexadecimal_digit)),
    c_char: $ => /[^\']/,
    string_literal: $ => choice($.simple_string, $.multiline_string),
    simple_string: $ => seq('"', repeat($.simple_quoted_text_item), '"'),
    simple_quoted_text_item: $ => choice($.escape_char, $.s_char),
    s_char: $ => /[^\"\x0a\x0d]/,
    multiline_string: $ => seq('"""', repeat($.multiline_quoted_text_item), '"""'),
    multiline_quoted_text_item: $ => choice($.escape_char, $.m_char),
m_char: $ => choice(
  /[^\"]/,
  seq('"', /[^"]/),
  seq('"', '"""')
),

    // Identifiers
    identifier: $ => choice($.identifier_token, $.contextual_keyword),
    identifier_token: $ => choice(
      seq($.identifier_head, repeat($.identifier_tail)),
      seq('`', repeat($.bq_char), '`')
    ),
    identifier_head: $ => /[_\p{Lu}\p{Ll}\p{Lt}\p{Lm}\p{Lo}\p{Nl}]/,
    identifier_tail: $ => /[_\p{Lu}\p{Ll}\p{Lt}\p{Lm}\p{Lo}\p{Mn}\p{Mc}\p{Nl}\p{Nd}\p{Pc}]/,
    bq_char: $ => /[^\`\x0a\x0d]/,
    contextual_keyword: $ => choice('mutating', 'size', 'any', 'in'),

    // Raw operators
    raw_operator: $ => /[-*/^%&!?\p{Sm}]/,
    document: $ => seq(
      repeat($.whitespace),
      optional(seq($.module_scope_stmt_list, repeat($.whitespace)))
    ),
    module_scope_stmt_list: $ => repeat1(
      seq($.module_scope_stmt, repeat($.stmt_separator), $.module_scope_stmt)
    ),
    module_scope_stmt: $ => choice(
      $.module_scope_decl,
      $.import_decl
    ),
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
    $ => seq('import', $.identifier),

    // Declarations
    decl_attribute: $ => seq(
      $.attribute_name,
      optional($.attribute_argument_list)
    ),
    attribute_name: $ => seq('@', $.identifier),
    attribute_argument_list: $ => seq(
      '(',
      $.attribute_argument,
      repeat(seq(',', $.attribute_argument)),
      ')'
    ),
    attribute_argument: $ => choice($.simple_string, $.integer_literal),

    // Modifiers
    access_modifier: $ => 'public',
    member_modifier: $ => choice($.receiver_modifier, $.static_modifier),
    receiver_modifier: $ => choice('sink', 'inout', 'yielded'),
    static_modifier: $ => 'static',
    conformance_list: $ => seq(
      ':',
      $.name_type_expr,
      repeat(seq(',', $.name_type_expr))
    ),

    // Generic clauses
    generic_clause: $ => seq(
      '<',
      $.generic_parameter_list,
      optional($.where_clause),
      '>'
    ),
    generic_parameter_list: $ => repeat1(
      seq($.generic_parameter, ',', $.generic_parameter)
    ),
    generic_parameter: $ => choice(
      $.generic_type_parameter,
      $.generic_value_parameter
    ),
    generic_type_parameter: $ => seq(
      optional('@type'),
      $.identifier,
      optional('...'),
      optional($.trait_annotation),
      optional(seq('=', $.type_expr))
    ),
    trait_annotation: $ => seq(':', $.trait_composition),
    generic_value_parameter: $ => seq(
      '@value',
      $.identifier,
      ':',
      $.type_expr,
      optional(seq('=', $.expr))
    ),

    // Where clauses
    where_clause: $ => seq('where', $.where_clause_constraint_list),
    where_clause_constraint_list: $ => repeat1(
      seq($.where_clause_constraint, ',', $.where_clause_constraint)
    ),
    where_clause_constraint: $ => choice(
      $.equality_constraint,
      $.conformance_constraint,
      $.value_constraint_expr
    ),
    equality_constraint: $ => seq($.name_type_expr, '==', $.type_expr),
    conformance_constraint: $ => seq($.name_type_expr, ':', $.trait_composition),
    value_constraint_expr: $ => seq('@value', $.expr),
    trait_composition: $ => seq(
      $.name_type_expr,
      repeat(seq('&', $.name_type_expr))
    ),
    namespace_decl: $ => seq($.namespace_head, $.namespace_body),
    namespace_head: $ => seq(
      optional($.access_modifier),
      'namespace',
      $.identifier
    ),
    namespace_body: $ => seq('{', optional($.namespace_member_list), '}'),
    namespace_member_list: $ => repeat1(
      seq($.namespace_member, repeat($.stmt_separator), $.namespace_member)
    ),
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

    // Trait declarations   

    trait_decl: $ => seq($.trait_head, $.trait_body),
    trait_head: $ => seq(
      optional($.access_modifier),
      'trait',
      $.identifier,
      optional($.trait_refinement_list)
    ),
    trait_refinement_list: $ => seq(
      ':',
      $.name_type_expr,
      repeat(seq(',', $.name_type_expr))
    ),
    trait_body: $ => seq('{', repeat(choice($.trait_requirement_decl, ';')), '}'),
    trait_requirement_decl: $ => choice(
      $.associated_decl,
      $.function_decl,
      $.subscript_decl,
      $.property_decl
    ),
    associated_decl: $ => choice(
      $.associated_type_decl,
      $.associated_value_decl
    ),
    associated_type_decl: $ => seq(
      $.associated_type_head,
      optional($.associated_type_constraints),
      optional(seq('=', $.type_expr))
    ),
    associated_type_head: $ => seq('type', $.identifier),
    associated_type_constraints: $ => choice(
      $.conformance_list,
      seq($.conformance_list, $.where_clause)
    ),
    associated_value_decl: $ => seq(
      $.associated_value_head,
      optional($.where_clause),
      optional(seq('=', $.expr))
    ),
    associated_value_head: $ => seq('value', $.identifier),
    product_type_decl: $ => seq($.product_type_head, $.product_type_body),
    product_type_head: $ => seq(
      optional($.access_modifier),
      'type',
      $.identifier,
      optional($.generic_clause),
      optional($.conformance_list)
    ),
    product_type_body: $ => seq('{', repeat(choice($.product_type_member_decl, ';')), '}'),
    product_type_member_decl: $ => choice(
      $.function_decl,
      $.deinit_decl,
      $.subscript_decl,
      $.property_decl,
      $.binding_decl,
      $.product_type_decl,
      $.type_alias_decl
    ),

    // Type alias declarations   

    type_alias_decl: $ => seq($.type_alias_head, '=', $.type_expr),
    type_alias_head: $ => seq(
      optional($.access_modifier),
      'typealias',
      $.identifier,
      optional($.generic_clause)
    ),
    union_decl: $ => seq($.product_type_decl, repeat(seq('|', $.product_type_decl))),

    // Extension declarations
    extension_decl: $ => seq($.extension_head, $.extension_body),
    extension_head: $ => seq(
      optional($.access_modifier),
      'extension',
      $.type_expr,
      optional($.where_clause)
    ),
    extension_body: $ => seq('{', repeat(choice($.extension_member_decl, ';')), '}'),
    extension_member_decl: $ => choice(
      $.function_decl,
      $.subscript_decl,
      $.product_type_decl,
      $.type_alias_decl
    ),

    // Conformance declarations
    conformance_decl: $ => seq($.conformance_head, $.conformance_body),
    conformance_head: $ => seq(
      optional($.access_modifier),
      'conformance',
      $.type_expr,
      $.conformance_list,
      optional($.where_clause)
    ),
    conformance_body: $ => seq('{', repeat(choice($.conformance_member_decl, ';')), '}'),
    conformance_member_decl: $ => choice(
      $.function_decl,
      $.subscript_decl,
      $.product_type_decl,
      $.type_alias_decl
    ),

    // Binding declarations
    binding_decl: $ => seq($.binding_head, optional($.binding_initializer)),
    binding_head: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.binding_pattern
    ),
    binding_initializer: $ => seq('=', $.expr),

    // Function declarations
    function_decl: $ => choice(
      $.memberwise_init_decl,
      seq($.function_head, $.function_signature, optional($.function_body))
    ),
    memberwise_init_decl: $ => seq(
      optional($.access_modifier),
      'memberwise',
      'init'
    ),
    function_head: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.function_decl_identifier,
      optional($.generic_clause),
      optional($.capture_list)
    ),
    function_decl_identifier: $ => choice(
      'init',
      seq('fun', $.identifier),
      seq('fun', $.operator_notation, $.operator)
    ),
    function_body: $ => choice($.method_bundle_body, $.brace_stmt),
    method_bundle_body: $ => seq('{', repeat($.method_impl), '}'),
    operator: $ => seq($.raw_operator, repeat($.raw_operator)),

    // Function signatures
    function_signature: $ => seq(
      '(',
      optional($.parameter_list),
      ')',
      optional($.receiver_effect),
      optional(seq('->', $.type_expr)),
      optional($.type_aliases_clause)
    ),
    type_aliases_clause: $ => seq(
      'where',
      $.type_aliases_clause_item,
      repeat(seq(',', $.type_aliases_clause_item))
    ),
    type_aliases_clause_item: $ => seq('typealias', $.identifier, '=', $.type_expr),
    method_impl: $ => seq($.method_introducer, optional($.brace_stmt)),
    method_introducer: $ => choice('let', 'sink', 'inout', 'set'),

    // Subscript declarations
    subscript_decl: $ => seq($.subscript_head, $.subscript_signature, $.subscript_body),
    subscript_head: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      'subscript',
      optional($.identifier),
      optional($.generic_clause),
      optional($.capture_list)
    ),
    subscript_identifier: $ => seq('subscript', $.identifier),
    subscript_body: $ => seq('{', repeat($.subscript_impl), '}'),
    subscript_signature: $ => seq(
      '(',
      optional($.parameter_list),
      ')',
      optional($.receiver_effect),
      ':',
      optional('var'),
      $.type_expr
    ),
    subscript_impl: $ => seq($.subscript_introducer, optional($.brace_stmt)),
    subscript_introducer: $ => choice('let', 'sink', 'inout', 'set'),

    // Property declarations
    property_decl: $ => seq($.property_head, $.property_annotation, $.subscript_body),
    property_head: $ => seq(repeat($.member_modifier), 'property', $.identifier),
    property_annotation: $ => seq(':', $.type_expr),

    // Parameter lists
    parameter_list: $ => repeat1(seq($.parameter_decl, ',', $.parameter_decl)),
    parameter_decl: $ => seq(
      choice($.identifier, '_'),
      optional($.identifier),
      optional(seq(':', $.parameter_type_expr)),
      optional(seq('=', $.expr))
    ),
    default_value: $ => seq('=', $.expr),
    stmt: $ => choice(
      $.brace_stmt,
      $.discard_stmt,
      $.loop_stmt,
      $.jump_stmt,
      $.decl_stmt,
      $.expr
    ),
    brace_stmt: $ => seq('{', optional($.stmt_list), '}'),
    stmt_list: $ => repeat1(
      seq($.stmt, repeat($.stmt_separator), $.stmt)
    ),
    stmt_separator: $ => seq(repeat($.horizontal_space), repeat1(seq(choice($.newline, ';'),optional($.horizontal_space)))),
    discard_stmt: $ => seq('_', '=', $.expr),
    loop_stmt: $ => choice($.do_while_stmt, $.while_stmt, $.for_stmt),
    do_while_stmt: $ => seq('do', $.brace_stmt, 'while', $.expr),
    while_stmt: $ => seq('while', $.while_condition_list, $.brace_stmt),
    while_condition_list: $ => repeat1(
      seq($.while_condition_item, ',', $.while_condition_item)
    ),
    while_condition_item: $ => choice(
      seq($.binding_pattern, '=', $.expr),
      $.expr
    ),
    for_stmt: $ => seq($.for_head, $.for_range, optional($.for_filter), $.brace_stmt),
    for_head: $ => seq('for', $.binding_decl),
    for_range: $ => seq('in', $.expr),
    for_filter: $ => seq('where', $.expr),
    jump_stmt: $ => choice(
      $.conditional_binding_stmt,
      seq('return', optional(seq($.horizontal_space, $.expr))),
      seq('yield', $.horizontal_space, $.expr),
      'break',
      'continue'
    ),
    conditional_binding_stmt: $ => seq(
      $.binding_pattern,
      'else',
      $.cond_binding_fallback
    ),
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

    // Expressions
    expr: $ => seq($.infix_expr_head, repeat($.infix_expr_tail)),
    infix_expr_head: $ => choice(
      $.async_expr,
      $.await_expr,
      $.unsafe_expr,
      $.prefix_expr
    ),
    infix_expr_tail: $ => choice(
      $.type_casting_tail,
      $.infix_operator_tail
    ),
    type_casting_tail: $ => seq($.type_casting_operator, $.type_expr),
    infix_operator_tail: $ => seq($.infix_operator, $.prefix_expr),
    infix_operator: $ => choice(
      $.operator,
      '=',
      '==',
      '<',
      '>',
      '..<',
      '...'
    ),
    prefix_expr: $ => seq(
      optional($.prefix_operator),
      $.postfix_expr
    ),
    prefix_operator: $ => seq($.prefix_operator_head, repeat($.raw_operator)),
prefix_operator_head: $ => choice(
  /[^<-]/,
  seq('-', /[^*/^%&!?\p{Sm}]/)
),
    postfix_expr: $ => seq($.compound_expr, optional(seq($.postfix_expr, $.postfix_operator))),
    postfix_operator: $ => seq($.postfix_operator_head, repeat($.raw_operator)),
postfix_operator_head: $ => choice(
  /[^>-]/,
  seq('-', /[^*/^%&!?\p{Sm}]/)
),

    // Primary expressions
    primary_expr: $ => choice(
      $.scalar_literal,
      $.compound_literal,
      $.primary_decl_ref,
      $.implicit_member_ref,
      $.lambda_expr,
      $.selection_expr,
      $.inout_expr,
      $.tuple_expr,
      'nil'   

    ),

    // Asynchronous expressions
    async_expr: $ => choice(
      seq($.async_expr_head, $.expr),
      seq($.async_expr_head, '->', $.type_expr, $.brace_stmt)
    ),
    async_expr_head: $ => seq('async', optional($.capture_list)),
    await_expr: $ => seq('await', $.expr),
    unsafe_expr: $ => seq('unsafe', $.expr),
    scalar_literal: $ => choice(
      $.boolean_literal,
      $.integer_literal,
      $.floating_point_literal,
      $.string_literal,
      $.unicode_scalar_literal
    ),

    // Compound literals
    compound_literal: $ => choice($.buffer_literal, $.map_literal),

    // Buffer literals
    buffer_literal: $ => seq('[', optional($.buffer_component_list), ']'),
    buffer_component_list: $ => repeat1(seq($.expr, ',', $.expr)),
    buffer_component: $ => $.expr,

    // Map literals
    map_literal: $ => choice(seq('[', $.map_component_list, ']'), seq('[', ':', ']')),
    map_component_list: $ => repeat1(seq($.map_component, ',', $.map_component)),
    map_component: $ => seq($.expr, ':', $.expr),

    // Primary declaration references
    primary_decl_ref: $ => seq($.identifier_expr, optional($.static_argument_list)),
    static_argument_list: $ => seq(
      '<',
      $.static_argument,
      repeat(seq(',', $.static_argument)),
      '>'
    ),
    static_argument: $ => seq(optional(seq($.identifier, ':')), choice($.expr, $.type_expr)),

    // Implicit member references
    implicit_member_ref: $ => seq('.', $.primary_decl_ref),

    // Identifier expressions
    identifier_expr: $ => seq($.entity_identifier, optional($.impl_identifier)),
    entity_identifier: $ => choice(
      $.identifier,
      $.function_entity_identifier,
      $.operator_entity_identifier
    ),
    function_entity_identifier: $ => seq($.identifier, '(', $.argument_label_list, ')'),
    operator_entity_identifier: $ => seq($.operator_notation, $.operator),
    argument_label: $ => seq($.identifier, ':'),
    impl_identifier: $ => seq('.', $.method_introducer),

    // Inout expressions
    inout_expr: $ => seq('&', $.expr),

    // Tuple expressions
    tuple_expr: $ => seq('(', optional($.tuple_expr_element_list), ')'),
    tuple_expr_element_list: $ => repeat1(
      seq($.tuple_expr_element, ',', $.tuple_expr_element)
    ),
    tuple_expr_element: $ => seq(optional(seq($.identifier, ':')), $.expr),

    // Compound expressions
    compound_expr: $ => choice(
      $.value_member_expr,
      $.static_value_member_expr,
      $.function_call_expr,
      $.subscript_call_expr,
      $.primary_expr
    ),

    // Value member expressions
    value_member_expr: $ => choice(
      $.labeled_member_expr,
      $.indexed_member_expr
    ),
    labeled_member_expr: $ => seq($.primary_expr, '.', $.primary_decl_ref),
    indexed_member_expr: $ => seq($.primary_expr, '.', $.member_index),
    member_index: $ => repeat1($.decimal_digit_head),

    // Static value member expressions
    static_value_member_expr: $ => seq($.type_expr, '.', $.primary_decl_ref),

    // Function call expressions
    function_call_expr: $ => seq(
      $.function_call_head,
      optional($.call_argument_list),
      ')'
    ),
    function_call_head: $ => seq($.primary_expr, '('),
    call_argument_list: $ => repeat1(seq($.call_argument, ',', $.call_argument)),
    call_argument: $ => seq(optional(seq($.identifier, ':')), $.expr),

    // Subscript call expressions
    subscript_call_expr: $ => seq(
      $.subscript_call_head,
      optional($.call_argument_list),
      ']'
    ),
    subscript_call_head: $ => seq($.primary_expr, '['),
    selection_expr: $ => choice($.conditional_expr, $.match_expr),
    conditional_expr: $ => seq(
      'if',
      $.conditional_clause,
      $.brace_stmt,
      optional($.conditional_tail)
    ),
    conditional_clause: $ => repeat1(
      seq($.conditional_clause_item, ',', $.conditional_clause_item)
    ),
    conditional_clause_item: $ => choice(
      seq($.binding_pattern, '=', $.expr),
      $.expr
    ),
    conditional_tail: $ => choice(
      seq('else', $.conditional_expr),
      'else',
      $.brace_stmt
    ),
    match_expr: $ => seq('match', $.expr, '{', repeat($.match_case), '}'),
    match_case: $ => seq(
      $.match_case_head,
      optional(seq('where', $.expr)),
      $.brace_stmt
    ),
    match_case_head: $ => $.binding_decl,

    // Type expressions
    type_expr: $ => choice(
      $.async_type_expr,
      $.conformance_lens_type_expr,
      $.existential_type_expr,
      $.opaque_type_expr,
      $.indirect_type_expr,
      $.lambda_type_expr,
      $.name_type_expr,
      $.stored_projection_type_expr,
      $.tuple_type_expr,
      $.union_type_expr,
      $.wildcard_type_expr,   

      seq('(', $.type_expr, ')')
    ),
    async_type_expr: $ => seq('async', $.type_expr),
    conformance_lens_type_expr: $ => seq($.type_expr, '::', $.type_identifier),
    existential_type_expr: $ => seq('any', $.trait_composition, optional($.where_clause)),
    opaque_type_expr: $ => choice(
      seq('some', $.trait_composition, optional($.where_clause)),
      'some',
      '_'
    ),
    indirect_type_expr: $ => seq('indirect', $.type_expr),
    lambda_type_expr: $ => seq(
      optional($.lambda_environment),
      '(',
      optional($.lamda_parameter_list),
      ')',
      optional($.receiver_effect),
      '->',
      $.type_expr
    ),
    lambda_environment: $ => choice('thin', seq('[', $.type_expr, ']')),
    lamda_parameter_list: $ => repeat1(
      seq($.lambda_parameter, ',', $.lambda_parameter)
    ),
    lambda_parameter: $ => seq(optional(seq($.identifier, ':')), $.type_expr),
    receiver_effect: $ => choice('inout', 'sink'),
    name_type_expr: $ => seq(optional(seq($.type_expr, '.')), $.primary_type_decl_ref),
    primary_type_decl_ref: $ => seq($.type_identifier, optional($.type_argument_list)),
    type_identifier: $ => $.identifier,
    parameter_type_expr: $ => seq(
      optional($.parameter_passing_convention),
      $.type_expr
    ),
    parameter_passing_convention: $ => choice('let', 'inout', 'sink', 'yielded'),
    stored_projection_type_expr: $ => seq(
      '[',
      $.stored_projection_capability,
      $.type_expr,
      ']'
    ),
    stored_projection_capability: $ => choice('let', 'inout', 'yielded'),
    tuple_type_expr: $ => seq('{', optional($.tuple_type_element_list), '}'),
    tuple_type_element_list: $ => repeat1(
      seq($.tuple_type_element, ',', $.tuple_type_element)
    ),
    tuple_type_element: $ => seq(optional(seq($.identifier, ':')), $.type_expr),
    union_type_expr: $ => seq($.type_expr, repeat(seq('|', $.type_expr))),
    wildcard_type_expr: $ => '_',
    lambda_expr: $ => seq(
      'fun',
      optional($.capture_list),
      $.function_signature,
      $.lambda_body
    ),

    capture_list: $ => seq('[', $.binding_decl_list, ']'),
    binding_decl_list: $ => repeat1(seq($.binding_decl, ',', $.binding_decl)),
    binding_decl: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.binding_pattern,
      optional(seq('=', $.expr))
    ),

    function_signature: $ => seq(
      '(',
      optional($.parameter_list),
      ')',
      optional($.receiver_effect),
      optional(seq('->', $.type_expr)),
      optional($.type_aliases_clause)
    ),

    lambda_body: $ => $.brace_stmt,
    lambda_expr: $ => seq(
      'fun',
      optional($.capture_list),
      $.function_signature,
      $.lambda_body
    ),

    capture_list: $ => seq('[', $.binding_decl_list, ']'),
    binding_decl_list: $ => repeat1(seq($.binding_decl, ',', $.binding_decl)),
    binding_decl: $ => seq(
      optional($.access_modifier),
      repeat($.member_modifier),
      $.binding_pattern,
      optional(seq('=', $.expr))
    ),

    function_signature: $ => seq(
      '(',
      optional($.parameter_list),
      ')',
      optional($.receiver_effect),
      optional(seq('->', $.type_expr)),
      optional($.type_aliases_clause)
    ),

    lambda_body: $ => $.brace_stmt,

    // Pattern rules
    pattern: $ => choice($.binding_pattern, $.expr_pattern, $.tuple_pattern, $.wildcard_pattern),

    binding_pattern: $ => seq(
      $.binding_introducer,
      choice($.tuple_pattern, $.wildcard_pattern, $.identifier),
      optional($.binding_annotation)
    ),

    binding_introducer: $ => choice('let', 'var', 'sink', 'inout'),

    binding_annotation: $ => seq(':', $.type_expr),

    expr_pattern: $ => $.expr,

    tuple_pattern: $ => seq('(', $.tuple_pattern_element_list, ')'),

    tuple_pattern_element_list: $ => repeat1(
      seq($.tuple_pattern_element, ',', $.tuple_pattern_element)
    ),

    tuple_pattern_element: $ => seq(optional(seq($.identifier, ':')), $.pattern),

    wildcard_pattern: $ => '_',
    whitespace: $ => choice($.horizontal_space, $.newline),

    horizontal_space: $ => choice($.hspace, $.single_line_comment, $.block_comment),

    hspace: $ => /\p{Zs}/,

    single_line_comment: $ => /\/\/.*/,

    block_comment: $ => seq($.block_comment_open, '*/'),

    block_comment_open: $ => /[*](?:[^*/]+|(?:[/]+|[*]+)[^*/])*/,

newline: $ => choice('\n', '\r', '\u2028', '\u2029'),
    operator_decl: $ => seq(
      'operator',
      $.operator_notation,
      $.operator,
      optional(seq(':', $.precedence_group))
    ),
    expr: $ => seq($.infix_expr_head, repeat($.infix_expr_tail)),
    deinit_decl: $ => seq('deinit', $.brace_stmt),
    operator_notation: $ => choice('infix', 'prefix', 'postfix'),
    type_casting_operator: $ => choice('as', 'as!'),
    argument_label_list: $ => repeat1(seq($.argument_label, ',', $.argument_label)),
    type_argument_list: $ => seq('<', $.type_argument_list_items, '>'),
    type_argument_list_items: $ => repeat1(seq($.type_argument, ',', $.type_argument)),
    type_argument: $ => $.type_expr,
    precedence_group: $ => choice(
      'assignment',
      'disjunction',
      'conjunction',
      'comparison',
      'fallback',
      'range',
      'addition',
      'multiplication',
      'shift'
    ),
  }
});
