#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 4
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 48
#define ALIAS_COUNT 0
#define TOKEN_COUNT 47
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 1
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_true = 1,
  anon_sym_false = 2,
  sym_binary_digit = 3,
  sym_octal_digit = 4,
  aux_sym_decimal_digit_token1 = 5,
  sym_hexadecimal_digit = 6,
  anon_sym_DOT = 7,
  anon_sym_e = 8,
  anon_sym_E = 9,
  anon_sym_PLUS = 10,
  anon_sym_DASH = 11,
  anon_sym_SQUOTE = 12,
  anon_sym_DQUOTE = 13,
  sym_c_char = 14,
  sym_s_char = 15,
  aux_sym_m_char_token1 = 16,
  aux_sym_m_char_token2 = 17,
  anon_sym_BQUOTE = 18,
  sym_identifier_head = 19,
  sym_identifier_tail = 20,
  sym_bq_char = 21,
  sym_raw_operator = 22,
  anon_sym_AT = 23,
  anon_sym_LPAREN = 24,
  anon_sym_COMMA = 25,
  anon_sym_RPAREN = 26,
  anon_sym_COLON = 27,
  anon_sym_LT = 28,
  anon_sym_GT = 29,
  anon_sym_EQ = 30,
  anon_sym_AMP = 31,
  anon_sym_LBRACE = 32,
  anon_sym_RBRACE = 33,
  anon_sym_SEMI = 34,
  anon_sym_PIPE = 35,
  anon_sym__ = 36,
  aux_sym_prefix_operator_head_token1 = 37,
  aux_sym_prefix_operator_head_token2 = 38,
  aux_sym_postfix_operator_head_token1 = 39,
  anon_sym_LBRACK = 40,
  anon_sym_RBRACK = 41,
  sym_hspace = 42,
  anon_sym_LF = 43,
  anon_sym_CR = 44,
  anon_sym_u2028 = 45,
  anon_sym_u2029 = 46,
  sym_boolean_literal = 47,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_binary_digit] = "binary_digit",
  [sym_octal_digit] = "octal_digit",
  [aux_sym_decimal_digit_token1] = "decimal_digit_token1",
  [sym_hexadecimal_digit] = "hexadecimal_digit",
  [anon_sym_DOT] = ".",
  [anon_sym_e] = "e",
  [anon_sym_E] = "E",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_DQUOTE] = "\"",
  [sym_c_char] = "c_char",
  [sym_s_char] = "s_char",
  [aux_sym_m_char_token1] = "m_char_token1",
  [aux_sym_m_char_token2] = "m_char_token2",
  [anon_sym_BQUOTE] = "`",
  [sym_identifier_head] = "identifier_head",
  [sym_identifier_tail] = "identifier_tail",
  [sym_bq_char] = "bq_char",
  [sym_raw_operator] = "raw_operator",
  [anon_sym_AT] = "@",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_EQ] = "=",
  [anon_sym_AMP] = "&",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_SEMI] = ";",
  [anon_sym_PIPE] = "|",
  [anon_sym__] = "_",
  [aux_sym_prefix_operator_head_token1] = "prefix_operator_head_token1",
  [aux_sym_prefix_operator_head_token2] = "prefix_operator_head_token2",
  [aux_sym_postfix_operator_head_token1] = "postfix_operator_head_token1",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_hspace] = "hspace",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_u2028] = "\u2028",
  [anon_sym_u2029] = "\u2029",
  [sym_boolean_literal] = "boolean_literal",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_binary_digit] = sym_binary_digit,
  [sym_octal_digit] = sym_octal_digit,
  [aux_sym_decimal_digit_token1] = aux_sym_decimal_digit_token1,
  [sym_hexadecimal_digit] = sym_hexadecimal_digit,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_e] = anon_sym_e,
  [anon_sym_E] = anon_sym_E,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [sym_c_char] = sym_c_char,
  [sym_s_char] = sym_s_char,
  [aux_sym_m_char_token1] = aux_sym_m_char_token1,
  [aux_sym_m_char_token2] = aux_sym_m_char_token2,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [sym_identifier_head] = sym_identifier_head,
  [sym_identifier_tail] = sym_identifier_tail,
  [sym_bq_char] = sym_bq_char,
  [sym_raw_operator] = sym_raw_operator,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym__] = anon_sym__,
  [aux_sym_prefix_operator_head_token1] = aux_sym_prefix_operator_head_token1,
  [aux_sym_prefix_operator_head_token2] = aux_sym_prefix_operator_head_token2,
  [aux_sym_postfix_operator_head_token1] = aux_sym_postfix_operator_head_token1,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_hspace] = sym_hspace,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_u2028] = anon_sym_u2028,
  [anon_sym_u2029] = anon_sym_u2029,
  [sym_boolean_literal] = sym_boolean_literal,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_binary_digit] = {
    .visible = true,
    .named = true,
  },
  [sym_octal_digit] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_decimal_digit_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_hexadecimal_digit] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_e] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_E] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_c_char] = {
    .visible = true,
    .named = true,
  },
  [sym_s_char] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_m_char_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_m_char_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier_head] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier_tail] = {
    .visible = true,
    .named = true,
  },
  [sym_bq_char] = {
    .visible = true,
    .named = true,
  },
  [sym_raw_operator] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_prefix_operator_head_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_prefix_operator_head_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_postfix_operator_head_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_hspace] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u2028] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_u2029] = {
    .visible = true,
    .named = false,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
};

static TSCharacterRange sym_identifier_tail_character_set_1[] = {
  {'0', '9'}, {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xba, 0xba}, {0xc0, 0xd6},
  {0xd8, 0xf6}, {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x300, 0x374}, {0x376, 0x377},
  {0x37a, 0x37d}, {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5}, {0x3f7, 0x481},
  {0x483, 0x487}, {0x48a, 0x52f}, {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x591, 0x5bd}, {0x5bf, 0x5bf}, {0x5c1, 0x5c2},
  {0x5c4, 0x5c5}, {0x5c7, 0x5c7}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x610, 0x61a}, {0x620, 0x669}, {0x66e, 0x6d3}, {0x6d5, 0x6dc},
  {0x6df, 0x6e8}, {0x6ea, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x74a}, {0x74d, 0x7b1}, {0x7c0, 0x7f5}, {0x7fa, 0x7fa}, {0x7fd, 0x7fd},
  {0x800, 0x82d}, {0x840, 0x85b}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x898, 0x8e1}, {0x8e3, 0x963}, {0x966, 0x96f},
  {0x971, 0x983}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9}, {0x9bc, 0x9c4},
  {0x9c7, 0x9c8}, {0x9cb, 0x9ce}, {0x9d7, 0x9d7}, {0x9dc, 0x9dd}, {0x9df, 0x9e3}, {0x9e6, 0x9f1}, {0x9fc, 0x9fc}, {0x9fe, 0x9fe},
  {0xa01, 0xa03}, {0xa05, 0xa0a}, {0xa0f, 0xa10}, {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39},
  {0xa3c, 0xa3c}, {0xa3e, 0xa42}, {0xa47, 0xa48}, {0xa4b, 0xa4d}, {0xa51, 0xa51}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa66, 0xa75},
  {0xa81, 0xa83}, {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabc, 0xac5},
  {0xac7, 0xac9}, {0xacb, 0xacd}, {0xad0, 0xad0}, {0xae0, 0xae3}, {0xae6, 0xaef}, {0xaf9, 0xaff}, {0xb01, 0xb03}, {0xb05, 0xb0c},
  {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39}, {0xb3c, 0xb44}, {0xb47, 0xb48}, {0xb4b, 0xb4d},
  {0xb55, 0xb57}, {0xb5c, 0xb5d}, {0xb5f, 0xb63}, {0xb66, 0xb6f}, {0xb71, 0xb71}, {0xb82, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90},
  {0xb92, 0xb95}, {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbbe, 0xbc2},
  {0xbc6, 0xbc8}, {0xbca, 0xbcd}, {0xbd0, 0xbd0}, {0xbd7, 0xbd7}, {0xbe6, 0xbef}, {0xc00, 0xc0c}, {0xc0e, 0xc10}, {0xc12, 0xc28},
  {0xc2a, 0xc39}, {0xc3c, 0xc44}, {0xc46, 0xc48}, {0xc4a, 0xc4d}, {0xc55, 0xc56}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc63},
  {0xc66, 0xc6f}, {0xc80, 0xc83}, {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbc, 0xcc4},
  {0xcc6, 0xcc8}, {0xcca, 0xccd}, {0xcd5, 0xcd6}, {0xcdd, 0xcde}, {0xce0, 0xce3}, {0xce6, 0xcef}, {0xcf1, 0xcf3}, {0xd00, 0xd0c},
  {0xd0e, 0xd10}, {0xd12, 0xd44}, {0xd46, 0xd48}, {0xd4a, 0xd4e}, {0xd54, 0xd57}, {0xd5f, 0xd63}, {0xd66, 0xd6f}, {0xd7a, 0xd7f},
  {0xd81, 0xd83}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xdca, 0xdca}, {0xdcf, 0xdd4},
  {0xdd6, 0xdd6}, {0xdd8, 0xddf}, {0xde6, 0xdef}, {0xdf2, 0xdf3}, {0xe01, 0xe3a}, {0xe40, 0xe4e}, {0xe50, 0xe59}, {0xe81, 0xe82},
  {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xec8, 0xece},
  {0xed0, 0xed9}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf18, 0xf19}, {0xf20, 0xf29}, {0xf35, 0xf35}, {0xf37, 0xf37}, {0xf39, 0xf39},
  {0xf3e, 0xf47}, {0xf49, 0xf6c}, {0xf71, 0xf84}, {0xf86, 0xf97}, {0xf99, 0xfbc}, {0xfc6, 0xfc6}, {0x1000, 0x1049}, {0x1050, 0x109d},
  {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256}, {0x1258, 0x1258},
  {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0}, {0x12c2, 0x12c5},
  {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x135d, 0x135f}, {0x1380, 0x138f}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd},
  {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16ee, 0x16f8}, {0x1700, 0x1715}, {0x171f, 0x1734}, {0x1740, 0x1753},
  {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1772, 0x1773}, {0x1780, 0x17d3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dd}, {0x17e0, 0x17e9}, {0x180b, 0x180d},
  {0x180f, 0x1819}, {0x1820, 0x1878}, {0x1880, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1920, 0x192b}, {0x1930, 0x193b}, {0x1946, 0x196d},
  {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x19d0, 0x19d9}, {0x1a00, 0x1a1b}, {0x1a20, 0x1a5e}, {0x1a60, 0x1a7c}, {0x1a7f, 0x1a89},
  {0x1a90, 0x1a99}, {0x1aa7, 0x1aa7}, {0x1ab0, 0x1abd}, {0x1abf, 0x1ace}, {0x1b00, 0x1b4c}, {0x1b50, 0x1b59}, {0x1b6b, 0x1b73}, {0x1b80, 0x1bf3},
  {0x1c00, 0x1c37}, {0x1c40, 0x1c49}, {0x1c4d, 0x1c7d}, {0x1c80, 0x1c88}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1cd0, 0x1cd2}, {0x1cd4, 0x1cfa},
  {0x1d00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59}, {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d},
  {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4}, {0x1fc6, 0x1fcc}, {0x1fd0, 0x1fd3}, {0x1fd6, 0x1fdb},
  {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x203f, 0x2040}, {0x2054, 0x2054}, {0x2071, 0x2071}, {0x207f, 0x207f}, {0x2090, 0x209c},
  {0x20d0, 0x20dc}, {0x20e1, 0x20e1}, {0x20e5, 0x20f0}, {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d},
  {0x2124, 0x2124}, {0x2126, 0x2126}, {0x2128, 0x2128}, {0x212a, 0x212d}, {0x212f, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e},
  {0x2160, 0x2188}, {0x2c00, 0x2ce4}, {0x2ceb, 0x2cf3}, {0x2d00, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f},
  {0x2d7f, 0x2d96}, {0x2da0, 0x2da6}, {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6},
  {0x2dd8, 0x2dde}, {0x2de0, 0x2dff}, {0x2e2f, 0x2e2f}, {0x3005, 0x3007}, {0x3021, 0x302f}, {0x3031, 0x3035}, {0x3038, 0x303c}, {0x3041, 0x3096},
  {0x3099, 0x309a}, {0x309d, 0x309f}, {0x30a1, 0x30fa}, {0x30fc, 0x30ff}, {0x3105, 0x312f}, {0x3131, 0x318e}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff},
  {0x3400, 0x3400}, {0x4dbf, 0x4dbf}, {0x4e00, 0x4e00}, {0x9fff, 0xa48c}, {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa62b}, {0xa640, 0xa66f},
  {0xa674, 0xa67d}, {0xa67f, 0xa6f1}, {0xa717, 0xa71f}, {0xa722, 0xa788}, {0xa78b, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7d9},
  {0xa7f2, 0xa827}, {0xa82c, 0xa82c}, {0xa840, 0xa873}, {0xa880, 0xa8c5}, {0xa8d0, 0xa8d9}, {0xa8e0, 0xa8f7}, {0xa8fb, 0xa8fb}, {0xa8fd, 0xa92d},
  {0xa930, 0xa953}, {0xa960, 0xa97c}, {0xa980, 0xa9c0}, {0xa9cf, 0xa9d9}, {0xa9e0, 0xa9fe}, {0xaa00, 0xaa36}, {0xaa40, 0xaa4d}, {0xaa50, 0xaa59},
  {0xaa60, 0xaa76}, {0xaa7a, 0xaac2}, {0xaadb, 0xaadd}, {0xaae0, 0xaaef}, {0xaaf2, 0xaaf6}, {0xab01, 0xab06}, {0xab09, 0xab0e}, {0xab11, 0xab16},
  {0xab20, 0xab26}, {0xab28, 0xab2e}, {0xab30, 0xab5a}, {0xab5c, 0xab69}, {0xab70, 0xabea}, {0xabec, 0xabed}, {0xabf0, 0xabf9}, {0xac00, 0xac00},
  {0xd7a3, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb}, {0xf900, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb28},
  {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c}, {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfd3d}, {0xfd50, 0xfd8f},
  {0xfd92, 0xfdc7}, {0xfdf0, 0xfdfb}, {0xfe00, 0xfe0f}, {0xfe20, 0xfe2f}, {0xfe33, 0xfe34}, {0xfe4d, 0xfe4f}, {0xfe70, 0xfe74}, {0xfe76, 0xfefc},
  {0xff10, 0xff19}, {0xff21, 0xff3a}, {0xff3f, 0xff3f}, {0xff41, 0xff5a}, {0xff66, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7},
  {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d}, {0x10080, 0x100fa},
  {0x10140, 0x10174}, {0x101fd, 0x101fd}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x102e0, 0x102e0}, {0x10300, 0x1031f}, {0x1032d, 0x1034a}, {0x10350, 0x1037a},
  {0x10380, 0x1039d}, {0x103a0, 0x103c3}, {0x103c8, 0x103cf}, {0x103d1, 0x103d5}, {0x10400, 0x1049d}, {0x104a0, 0x104a9}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb},
  {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a}, {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1},
  {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736}, {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba},
  {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835}, {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10860, 0x10876}, {0x10880, 0x1089e},
  {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x10900, 0x10915},
};

static TSCharacterRange sym_raw_operator_character_set_1[] = {
  {'!', '!'}, {'%', '&'}, {'*', '+'}, {'-', '-'}, {'/', '/'}, {'<', '?'}, {'^', '^'}, {'|', '|'},
  {'~', '~'}, {0xac, 0xac}, {0xb1, 0xb1}, {0xd7, 0xd7}, {0xf7, 0xf7}, {0x3f6, 0x3f6}, {0x606, 0x608}, {0x2044, 0x2044},
  {0x2052, 0x2052}, {0x207a, 0x207c}, {0x208a, 0x208c}, {0x2118, 0x2118}, {0x2140, 0x2144}, {0x214b, 0x214b}, {0x2190, 0x2194}, {0x219a, 0x219b},
  {0x21a0, 0x21a0}, {0x21a3, 0x21a3}, {0x21a6, 0x21a6}, {0x21ae, 0x21ae}, {0x21ce, 0x21cf}, {0x21d2, 0x21d2}, {0x21d4, 0x21d4}, {0x21f4, 0x22ff},
  {0x2320, 0x2321}, {0x237c, 0x237c}, {0x239b, 0x23b3}, {0x23dc, 0x23e1}, {0x25b7, 0x25b7}, {0x25c1, 0x25c1}, {0x25f8, 0x25ff}, {0x266f, 0x266f},
  {0x27c0, 0x27c4}, {0x27c7, 0x27e5}, {0x27f0, 0x27ff}, {0x2900, 0x2982}, {0x2999, 0x29d7}, {0x29dc, 0x29fb}, {0x29fe, 0x2aff}, {0x2b30, 0x2b44},
  {0x2b47, 0x2b4c}, {0xfb29, 0xfb29}, {0xfe62, 0xfe62}, {0xfe64, 0xfe66}, {0xff0b, 0xff0b}, {0xff1c, 0xff1e}, {0xff5c, 0xff5c}, {0xff5e, 0xff5e},
  {0xffe2, 0xffe2}, {0xffe9, 0xffec},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(9);
      ADVANCE_MAP(
        '\n', 41,
        '\r', 42,
        '"', 22,
        '&', 33,
        '\'', 21,
        '(', 26,
        ')', 28,
        '+', 19,
        ',', 27,
        '-', 20,
        '.', 16,
        ':', 29,
        ';', 36,
        '<', 30,
        '=', 32,
        '>', 31,
        '@', 25,
        'E', 18,
        '[', 39,
        ']', 40,
        '_', 38,
        '`', 24,
        'e', 17,
        '{', 34,
        '|', 37,
        '}', 35,
        0x2028, 43,
        0x2029, 44,
        '0', 12,
        '1', 12,
        '8', 14,
        '9', 14,
      );
      if (('2' <= lookahead && lookahead <= '7')) ADVANCE(13);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      if (lookahead == ' ' ||
          lookahead == 0xa0 ||
          lookahead == 0x1680 ||
          (0x2000 <= lookahead && lookahead <= 0x200a) ||
          lookahead == 0x202f ||
          lookahead == 0x205f ||
          lookahead == 0x3000) ADVANCE(23);
      if (set_contains(sym_raw_operator_character_set_1, 58, lookahead)) ADVANCE(23);
      if ((0x300 <= lookahead && lookahead <= 0x36f) ||
          (0x483 <= lookahead && lookahead <= 0x487) ||
          (0x591 <= lookahead && lookahead <= 0x5bd) ||
          lookahead == 0x5bf ||
          lookahead == 0x5c1 ||
          lookahead == 0x5c2 ||
          lookahead == 0x5c4 ||
          lookahead == 0x5c5 ||
          lookahead == 0x5c7 ||
          (0x610 <= lookahead && lookahead <= 0x61a) ||
          (0x64b <= lookahead && lookahead <= 0x669) ||
          lookahead == 0x670 ||
          (0x6d6 <= lookahead && lookahead <= 0x6dc) ||
          (0x6df <= lookahead && lookahead <= 0x6e4) ||
          lookahead == 0x6e7 ||
          lookahead == 0x6e8 ||
          (0x6ea <= lookahead && lookahead <= 0x6ed) ||
          (0x6f0 <= lookahead && lookahead <= 0x6f9) ||
          lookahead == 0x711 ||
          (0x730 <= lookahead && lookahead <= 0x74a) ||
          (0x7a6 <= lookahead && lookahead <= 0x7b0) ||
          (0x7c0 <= lookahead && lookahead <= 0x7c9) ||
          (0x7eb <= lookahead && lookahead <= 0x7f3) ||
          lookahead == 0x7fd ||
          (0x816 <= lookahead && lookahead <= 0x819) ||
          (0x81b <= lookahead && lookahead <= 0x823) ||
          (0x825 <= lookahead && lookahead <= 0x827) ||
          (0x829 <= lookahead && lookahead <= 0x82d) ||
          (0x859 <= lookahead && lookahead <= 0x85b) ||
          (0x898 <= lookahead && lookahead <= 0x89f) ||
          (0x8ca <= lookahead && lookahead <= 0x8e1) ||
          (0x8e3 <= lookahead && lookahead <= 0x903) ||
          (0x93a <= lookahead && lookahead <= 0x93c) ||
          (0x93e <= lookahead && lookahead <= 0x94f) ||
          (0x951 <= lookahead && lookahead <= 0x957) ||
          lookahead == 0x962 ||
          lookahead == 0x963 ||
          (0x966 <= lookahead && lookahead <= 0x96f) ||
          (0x981 <= lookahead && lookahead <= 0x983) ||
          lookahead == 0x9bc ||
          (0x9be <= lookahead && lookahead <= 0x9c4) ||
          lookahead == 0x9c7 ||
          lookahead == 0x9c8 ||
          (0x9cb <= lookahead && lookahead <= 0x9cd) ||
          lookahead == 0x9d7 ||
          lookahead == 0x9e2 ||
          lookahead == 0x9e3 ||
          (0x9e6 <= lookahead && lookahead <= 0x9ef) ||
          lookahead == 0x9fe ||
          (0xa01 <= lookahead && lookahead <= 0xa03) ||
          lookahead == 0xa3c ||
          (0xa3e <= lookahead && lookahead <= 0xa42) ||
          lookahead == 0xa47 ||
          lookahead == 0xa48 ||
          (0xa4b <= lookahead && lookahead <= 0xa4d) ||
          lookahead == 0xa51 ||
          (0xa66 <= lookahead && lookahead <= 0xa71) ||
          lookahead == 0xa75 ||
          (0xa81 <= lookahead && lookahead <= 0xa83) ||
          lookahead == 0xabc ||
          (0xabe <= lookahead && lookahead <= 0xac5) ||
          (0xac7 <= lookahead && lookahead <= 0xac9) ||
          (0xacb <= lookahead && lookahead <= 0xacd) ||
          lookahead == 0xae2 ||
          lookahead == 0xae3 ||
          (0xae6 <= lookahead && lookahead <= 0xaef) ||
          (0xafa <= lookahead && lookahead <= 0xaff) ||
          (0xb01 <= lookahead && lookahead <= 0xb03) ||
          lookahead == 0xb3c ||
          (0xb3e <= lookahead && lookahead <= 0xb44) ||
          lookahead == 0xb47 ||
          lookahead == 0xb48 ||
          (0xb4b <= lookahead && lookahead <= 0xb4d) ||
          (0xb55 <= lookahead && lookahead <= 0xb57) ||
          lookahead == 0xb62 ||
          lookahead == 0xb63 ||
          (0xb66 <= lookahead && lookahead <= 0xb6f) ||
          lookahead == 0xb82 ||
          (0xbbe <= lookahead && lookahead <= 0xbc2) ||
          (0xbc6 <= lookahead && lookahead <= 0xbc8) ||
          (0xbca <= lookahead && lookahead <= 0xbcd) ||
          lookahead == 0xbd7 ||
          (0xbe6 <= lookahead && lookahead <= 0xbef) ||
          (0xc00 <= lookahead && lookahead <= 0xc04) ||
          lookahead == 0xc3c ||
          (0xc3e <= lookahead && lookahead <= 0xc44) ||
          (0xc46 <= lookahead && lookahead <= 0xc48) ||
          (0xc4a <= lookahead && lookahead <= 0xc4d) ||
          lookahead == 0xc55 ||
          lookahead == 0xc56 ||
          lookahead == 0xc62 ||
          lookahead == 0xc63 ||
          (0xc66 <= lookahead && lookahead <= 0xc6f) ||
          (0xc81 <= lookahead && lookahead <= 0xc83) ||
          lookahead == 0xcbc ||
          (0xcbe <= lookahead && lookahead <= 0xcc4) ||
          (0xcc6 <= lookahead && lookahead <= 0xcc8) ||
          (0xcca <= lookahead && lookahead <= 0xccd) ||
          lookahead == 0xcd5 ||
          lookahead == 0xcd6 ||
          lookahead == 0xce2 ||
          lookahead == 0xce3 ||
          (0xce6 <= lookahead && lookahead <= 0xcef) ||
          lookahead == 0xcf3 ||
          (0xd00 <= lookahead && lookahead <= 0xd03) ||
          lookahead == 0xd3b ||
          lookahead == 0xd3c ||
          (0xd3e <= lookahead && lookahead <= 0xd44) ||
          (0xd46 <= lookahead && lookahead <= 0xd48) ||
          (0xd4a <= lookahead && lookahead <= 0xd4d) ||
          lookahead == 0xd57 ||
          lookahead == 0xd62 ||
          lookahead == 0xd63 ||
          (0xd66 <= lookahead && lookahead <= 0xd6f) ||
          (0xd81 <= lookahead && lookahead <= 0xd83) ||
          lookahead == 0xdca ||
          (0xdcf <= lookahead && lookahead <= 0xdd4) ||
          lookahead == 0xdd6 ||
          (0xdd8 <= lookahead && lookahead <= 0xddf) ||
          (0xde6 <= lookahead && lookahead <= 0xdef) ||
          lookahead == 0xdf2 ||
          lookahead == 0xdf3 ||
          lookahead == 0xe31 ||
          (0xe34 <= lookahead && lookahead <= 0xe3a) ||
          (0xe47 <= lookahead && lookahead <= 0xe4e) ||
          (0xe50 <= lookahead && lookahead <= 0xe59) ||
          lookahead == 0xeb1 ||
          (0xeb4 <= lookahead && lookahead <= 0xebc) ||
          (0xec8 <= lookahead && lookahead <= 0xece) ||
          (0xed0 <= lookahead && lookahead <= 0xed9) ||
          lookahead == 0xf18 ||
          lookahead == 0xf19 ||
          (0xf20 <= lookahead && lookahead <= 0xf29) ||
          lookahead == 0xf35 ||
          lookahead == 0xf37 ||
          lookahead == 0xf39 ||
          lookahead == 0xf3e ||
          lookahead == 0xf3f ||
          (0xf71 <= lookahead && lookahead <= 0xf84) ||
          lookahead == 0xf86 ||
          lookahead == 0xf87 ||
          (0xf8d <= lookahead && lookahead <= 0xf97) ||
          (0xf99 <= lookahead && lookahead <= 0xfbc) ||
          lookahead == 0xfc6 ||
          (0x102b <= lookahead && lookahead <= 0x103e) ||
          (0x1040 <= lookahead && lookahead <= 0x1049) ||
          (0x1056 <= lookahead && lookahead <= 0x1059) ||
          (0x105e <= lookahead && lookahead <= 0x1060) ||
          (0x1062 <= lookahead && lookahead <= 0x1064) ||
          (0x1067 <= lookahead && lookahead <= 0x106d) ||
          (0x1071 <= lookahead && lookahead <= 0x1074) ||
          (0x1082 <= lookahead && lookahead <= 0x108d) ||
          (0x108f <= lookahead && lookahead <= 0x109d) ||
          (0x135d <= lookahead && lookahead <= 0x135f) ||
          (0x1712 <= lookahead && lookahead <= 0x1715) ||
          (0x1732 <= lookahead && lookahead <= 0x1734) ||
          lookahead == 0x1752 ||
          lookahead == 0x1753 ||
          lookahead == 0x1772 ||
          lookahead == 0x1773 ||
          (0x17b4 <= lookahead && lookahead <= 0x17d3) ||
          lookahead == 0x17dd ||
          (0x17e0 <= lookahead && lookahead <= 0x17e9) ||
          (0x180b <= lookahead && lookahead <= 0x180d) ||
          (0x180f <= lookahead && lookahead <= 0x1819) ||
          lookahead == 0x1885 ||
          lookahead == 0x1886 ||
          lookahead == 0x18a9 ||
          (0x1920 <= lookahead && lookahead <= 0x192b) ||
          (0x1930 <= lookahead && lookahead <= 0x193b) ||
          (0x1946 <= lookahead && lookahead <= 0x194f) ||
          (0x19d0 <= lookahead && lookahead <= 0x19d9) ||
          (0x1a17 <= lookahead && lookahead <= 0x1a1b) ||
          (0x1a55 <= lookahead && lookahead <= 0x1a5e) ||
          (0x1a60 <= lookahead && lookahead <= 0x1a7c) ||
          (0x1a7f <= lookahead && lookahead <= 0x1a89) ||
          (0x1a90 <= lookahead && lookahead <= 0x1a99) ||
          (0x1ab0 <= lookahead && lookahead <= 0x1abd) ||
          (0x1abf <= lookahead && lookahead <= 0x1ace) ||
          (0x1b00 <= lookahead && lookahead <= 0x1b04) ||
          (0x1b34 <= lookahead && lookahead <= 0x1b44) ||
          (0x1b50 <= lookahead && lookahead <= 0x1b59) ||
          (0x1b6b <= lookahead && lookahead <= 0x1b73) ||
          (0x1b80 <= lookahead && lookahead <= 0x1b82) ||
          (0x1ba1 <= lookahead && lookahead <= 0x1bad) ||
          (0x1bb0 <= lookahead && lookahead <= 0x1bb9) ||
          (0x1be6 <= lookahead && lookahead <= 0x1bf3) ||
          (0x1c24 <= lookahead && lookahead <= 0x1c37) ||
          (0x1c40 <= lookahead && lookahead <= 0x1c49) ||
          (0x1c50 <= lookahead && lookahead <= 0x1c59) ||
          (0x1cd0 <= lookahead && lookahead <= 0x1cd2) ||
          (0x1cd4 <= lookahead && lookahead <= 0x1ce8) ||
          lookahead == 0x1ced ||
          lookahead == 0x1cf4 ||
          (0x1cf7 <= lookahead && lookahead <= 0x1cf9) ||
          (0x1dc0 <= lookahead && lookahead <= 0x1dff) ||
          lookahead == 0x203f ||
          lookahead == 0x2040 ||
          lookahead == 0x2054 ||
          (0x20d0 <= lookahead && lookahead <= 0x20dc) ||
          lookahead == 0x20e1 ||
          (0x20e5 <= lookahead && lookahead <= 0x20f0) ||
          (0x2cef <= lookahead && lookahead <= 0x2cf1) ||
          lookahead == 0x2d7f ||
          (0x2de0 <= lookahead && lookahead <= 0x2dff) ||
          (0x302a <= lookahead && lookahead <= 0x302f) ||
          lookahead == 0x3099 ||
          lookahead == 0x309a ||
          (0xa620 <= lookahead && lookahead <= 0xa629) ||
          lookahead == 0xa66f ||
          (0xa674 <= lookahead && lookahead <= 0xa67d) ||
          lookahead == 0xa69e ||
          lookahead == 0xa69f ||
          lookahead == 0xa6f0 ||
          lookahead == 0xa6f1 ||
          lookahead == 0xa802 ||
          lookahead == 0xa806 ||
          lookahead == 0xa80b ||
          (0xa823 <= lookahead && lookahead <= 0xa827) ||
          lookahead == 0xa82c ||
          lookahead == 0xa880 ||
          lookahead == 0xa881 ||
          (0xa8b4 <= lookahead && lookahead <= 0xa8c5) ||
          (0xa8d0 <= lookahead && lookahead <= 0xa8d9) ||
          (0xa8e0 <= lookahead && lookahead <= 0xa8f1) ||
          (0xa8ff <= lookahead && lookahead <= 0xa909) ||
          (0xa926 <= lookahead && lookahead <= 0xa92d) ||
          (0xa947 <= lookahead && lookahead <= 0xa953) ||
          (0xa980 <= lookahead && lookahead <= 0xa983) ||
          (0xa9b3 <= lookahead && lookahead <= 0xa9c0) ||
          (0xa9d0 <= lookahead && lookahead <= 0xa9d9) ||
          lookahead == 0xa9e5 ||
          (0xa9f0 <= lookahead && lookahead <= 0xa9f9) ||
          (0xaa29 <= lookahead && lookahead <= 0xaa36) ||
          lookahead == 0xaa43 ||
          lookahead == 0xaa4c ||
          lookahead == 0xaa4d ||
          (0xaa50 <= lookahead && lookahead <= 0xaa59) ||
          (0xaa7b <= lookahead && lookahead <= 0xaa7d) ||
          lookahead == 0xaab0 ||
          (0xaab2 <= lookahead && lookahead <= 0xaab4) ||
          lookahead == 0xaab7 ||
          lookahead == 0xaab8 ||
          lookahead == 0xaabe ||
          lookahead == 0xaabf ||
          lookahead == 0xaac1 ||
          (0xaaeb <= lookahead && lookahead <= 0xaaef) ||
          lookahead == 0xaaf5 ||
          lookahead == 0xaaf6 ||
          (0xabe3 <= lookahead && lookahead <= 0xabea) ||
          lookahead == 0xabec ||
          lookahead == 0xabed ||
          (0xabf0 <= lookahead && lookahead <= 0xabf9) ||
          lookahead == 0xfb1e ||
          (0xfe00 <= lookahead && lookahead <= 0xfe0f) ||
          (0xfe20 <= lookahead && lookahead <= 0xfe2f) ||
          lookahead == 0xfe33 ||
          lookahead == 0xfe34 ||
          (0xfe4d <= lookahead && lookahead <= 0xfe4f) ||
          (0xff10 <= lookahead && lookahead <= 0xff19) ||
          lookahead == 0xff3f ||
          lookahead == 0x101fd ||
          lookahead == 0x102e0 ||
          (0x10376 <= lookahead && lookahead <= 0x1037a) ||
          (0x104a0 <= lookahead && lookahead <= 0x104a9)) ADVANCE(23);
      if (set_contains(sym_identifier_tail_character_set_1, 483, lookahead)) ADVANCE(23);
      if (lookahead != 0) ADVANCE(23);
      END_STATE();
    case 1:
      if (lookahead == 'a') ADVANCE(5);
      END_STATE();
    case 2:
      if (lookahead == 'e') ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 4:
      if (lookahead == 'f') ADVANCE(1);
      if (lookahead == 't') ADVANCE(6);
      END_STATE();
    case 5:
      if (lookahead == 'l') ADVANCE(7);
      END_STATE();
    case 6:
      if (lookahead == 'r') ADVANCE(8);
      END_STATE();
    case 7:
      if (lookahead == 's') ADVANCE(3);
      END_STATE();
    case 8:
      if (lookahead == 'u') ADVANCE(2);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_binary_digit);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_octal_digit);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_decimal_digit_token1);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_hexadecimal_digit);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_e);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_E);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_c_char);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_CR);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_u2028);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_u2029);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 4},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_binary_digit] = ACTIONS(1),
    [sym_octal_digit] = ACTIONS(1),
    [aux_sym_decimal_digit_token1] = ACTIONS(1),
    [sym_hexadecimal_digit] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_e] = ACTIONS(1),
    [anon_sym_E] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym_c_char] = ACTIONS(1),
    [sym_s_char] = ACTIONS(1),
    [aux_sym_m_char_token1] = ACTIONS(1),
    [aux_sym_m_char_token2] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_identifier_head] = ACTIONS(1),
    [sym_identifier_tail] = ACTIONS(1),
    [sym_bq_char] = ACTIONS(1),
    [sym_raw_operator] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [aux_sym_prefix_operator_head_token1] = ACTIONS(1),
    [aux_sym_prefix_operator_head_token2] = ACTIONS(1),
    [aux_sym_postfix_operator_head_token1] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_hspace] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [anon_sym_CR] = ACTIONS(1),
    [anon_sym_u2028] = ACTIONS(1),
    [anon_sym_u2029] = ACTIONS(1),
  },
  [1] = {
    [sym_boolean_literal] = STATE(3),
    [anon_sym_true] = ACTIONS(3),
    [anon_sym_false] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(5), 1,
      ts_builtin_sym_end,
  [4] = 1,
    ACTIONS(7), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 4,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_hylo(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
