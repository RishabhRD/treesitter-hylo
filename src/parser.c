#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 34
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 84
#define ALIAS_COUNT 0
#define TOKEN_COUNT 67
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_0 = 1,
  anon_sym_1 = 2,
  anon_sym__ = 3,
  anon_sym_2 = 4,
  anon_sym_3 = 5,
  anon_sym_4 = 6,
  anon_sym_5 = 7,
  anon_sym_6 = 8,
  anon_sym_7 = 9,
  anon_sym_8 = 10,
  anon_sym_9 = 11,
  anon_sym_a = 12,
  anon_sym_b = 13,
  anon_sym_c = 14,
  anon_sym_d = 15,
  anon_sym_e = 16,
  anon_sym_f = 17,
  anon_sym_A = 18,
  anon_sym_B = 19,
  anon_sym_C = 20,
  anon_sym_D = 21,
  anon_sym_E = 22,
  anon_sym_F = 23,
  anon_sym_DOT = 24,
  anon_sym_PLUS = 25,
  anon_sym_DASH = 26,
  sym__floating_point_suffix_head = 27,
  anon_sym_SQUOTE = 28,
  sym__c_char = 29,
  anon_sym_DQUOTE = 30,
  sym__s_char = 31,
  aux_sym__m_char_token1 = 32,
  aux_sym__m_char_token2 = 33,
  anon_sym_BQUOTE = 34,
  sym__identifier_head = 35,
  sym__identifier_tail = 36,
  sym__bq_char = 37,
  anon_sym_mutating = 38,
  anon_sym_size = 39,
  anon_sym_any = 40,
  anon_sym_in = 41,
  sym__raw_operator = 42,
  anon_sym_SPACE = 43,
  sym__single_line_comment = 44,
  anon_sym_STAR_SLASH = 45,
  sym__block_comment_open = 46,
  sym__newline = 47,
  anon_sym_SEMI = 48,
  anon_sym_import = 49,
  anon_sym_AT = 50,
  anon_sym_LPAREN = 51,
  anon_sym_COMMA = 52,
  anon_sym_RPAREN = 53,
  anon_sym_COLON = 54,
  anon_sym_LT = 55,
  anon_sym_GT = 56,
  anon_sym_EQ = 57,
  anon_sym_AMP = 58,
  anon_sym_LBRACE = 59,
  anon_sym_RBRACE = 60,
  anon_sym_PIPE = 61,
  aux_sym__prefix_operator_head_token1 = 62,
  aux_sym__prefix_operator_head_token2 = 63,
  aux_sym__postfix_operator_head_token1 = 64,
  anon_sym_LBRACK = 65,
  anon_sym_RBRACK = 66,
  sym_source_file = 67,
  sym_identifier = 68,
  sym__identifier_token = 69,
  sym__contextual_keyword = 70,
  sym__whitespace = 71,
  sym__horizontal_space = 72,
  sym__hspace = 73,
  sym__block_comment = 74,
  sym__stmt_separator = 75,
  sym__module_scope_stmt_list = 76,
  sym__module_scope_stmt = 77,
  sym_import_decl = 78,
  aux_sym_source_file_repeat1 = 79,
  aux_sym__identifier_token_repeat1 = 80,
  aux_sym__identifier_token_repeat2 = 81,
  aux_sym__stmt_separator_repeat1 = 82,
  aux_sym__stmt_separator_repeat2 = 83,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_0] = "0",
  [anon_sym_1] = "1",
  [anon_sym__] = "_",
  [anon_sym_2] = "2",
  [anon_sym_3] = "3",
  [anon_sym_4] = "4",
  [anon_sym_5] = "5",
  [anon_sym_6] = "6",
  [anon_sym_7] = "7",
  [anon_sym_8] = "8",
  [anon_sym_9] = "9",
  [anon_sym_a] = "a",
  [anon_sym_b] = "b",
  [anon_sym_c] = "c",
  [anon_sym_d] = "d",
  [anon_sym_e] = "e",
  [anon_sym_f] = "f",
  [anon_sym_A] = "A",
  [anon_sym_B] = "B",
  [anon_sym_C] = "C",
  [anon_sym_D] = "D",
  [anon_sym_E] = "E",
  [anon_sym_F] = "F",
  [anon_sym_DOT] = ".",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [sym__floating_point_suffix_head] = "_floating_point_suffix_head",
  [anon_sym_SQUOTE] = "'",
  [sym__c_char] = "_c_char",
  [anon_sym_DQUOTE] = "\"",
  [sym__s_char] = "_s_char",
  [aux_sym__m_char_token1] = "_m_char_token1",
  [aux_sym__m_char_token2] = "_m_char_token2",
  [anon_sym_BQUOTE] = "`",
  [sym__identifier_head] = "_identifier_head",
  [sym__identifier_tail] = "_identifier_tail",
  [sym__bq_char] = "_bq_char",
  [anon_sym_mutating] = "mutating",
  [anon_sym_size] = "size",
  [anon_sym_any] = "any",
  [anon_sym_in] = "in",
  [sym__raw_operator] = "_raw_operator",
  [anon_sym_SPACE] = " ",
  [sym__single_line_comment] = "_single_line_comment",
  [anon_sym_STAR_SLASH] = "*/",
  [sym__block_comment_open] = "_block_comment_open",
  [sym__newline] = "_newline",
  [anon_sym_SEMI] = ";",
  [anon_sym_import] = "import",
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
  [anon_sym_PIPE] = "|",
  [aux_sym__prefix_operator_head_token1] = "_prefix_operator_head_token1",
  [aux_sym__prefix_operator_head_token2] = "_prefix_operator_head_token2",
  [aux_sym__postfix_operator_head_token1] = "_postfix_operator_head_token1",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_source_file] = "source_file",
  [sym_identifier] = "identifier",
  [sym__identifier_token] = "_identifier_token",
  [sym__contextual_keyword] = "_contextual_keyword",
  [sym__whitespace] = "_whitespace",
  [sym__horizontal_space] = "_horizontal_space",
  [sym__hspace] = "_hspace",
  [sym__block_comment] = "_block_comment",
  [sym__stmt_separator] = "_stmt_separator",
  [sym__module_scope_stmt_list] = "_module_scope_stmt_list",
  [sym__module_scope_stmt] = "_module_scope_stmt",
  [sym_import_decl] = "import_decl",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__identifier_token_repeat1] = "_identifier_token_repeat1",
  [aux_sym__identifier_token_repeat2] = "_identifier_token_repeat2",
  [aux_sym__stmt_separator_repeat1] = "_stmt_separator_repeat1",
  [aux_sym__stmt_separator_repeat2] = "_stmt_separator_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_0] = anon_sym_0,
  [anon_sym_1] = anon_sym_1,
  [anon_sym__] = anon_sym__,
  [anon_sym_2] = anon_sym_2,
  [anon_sym_3] = anon_sym_3,
  [anon_sym_4] = anon_sym_4,
  [anon_sym_5] = anon_sym_5,
  [anon_sym_6] = anon_sym_6,
  [anon_sym_7] = anon_sym_7,
  [anon_sym_8] = anon_sym_8,
  [anon_sym_9] = anon_sym_9,
  [anon_sym_a] = anon_sym_a,
  [anon_sym_b] = anon_sym_b,
  [anon_sym_c] = anon_sym_c,
  [anon_sym_d] = anon_sym_d,
  [anon_sym_e] = anon_sym_e,
  [anon_sym_f] = anon_sym_f,
  [anon_sym_A] = anon_sym_A,
  [anon_sym_B] = anon_sym_B,
  [anon_sym_C] = anon_sym_C,
  [anon_sym_D] = anon_sym_D,
  [anon_sym_E] = anon_sym_E,
  [anon_sym_F] = anon_sym_F,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym__floating_point_suffix_head] = sym__floating_point_suffix_head,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [sym__c_char] = sym__c_char,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [sym__s_char] = sym__s_char,
  [aux_sym__m_char_token1] = aux_sym__m_char_token1,
  [aux_sym__m_char_token2] = aux_sym__m_char_token2,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [sym__identifier_head] = sym__identifier_head,
  [sym__identifier_tail] = sym__identifier_tail,
  [sym__bq_char] = sym__bq_char,
  [anon_sym_mutating] = anon_sym_mutating,
  [anon_sym_size] = anon_sym_size,
  [anon_sym_any] = anon_sym_any,
  [anon_sym_in] = anon_sym_in,
  [sym__raw_operator] = sym__raw_operator,
  [anon_sym_SPACE] = anon_sym_SPACE,
  [sym__single_line_comment] = sym__single_line_comment,
  [anon_sym_STAR_SLASH] = anon_sym_STAR_SLASH,
  [sym__block_comment_open] = sym__block_comment_open,
  [sym__newline] = sym__newline,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_import] = anon_sym_import,
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
  [anon_sym_PIPE] = anon_sym_PIPE,
  [aux_sym__prefix_operator_head_token1] = aux_sym__prefix_operator_head_token1,
  [aux_sym__prefix_operator_head_token2] = aux_sym__prefix_operator_head_token2,
  [aux_sym__postfix_operator_head_token1] = aux_sym__postfix_operator_head_token1,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_source_file] = sym_source_file,
  [sym_identifier] = sym_identifier,
  [sym__identifier_token] = sym__identifier_token,
  [sym__contextual_keyword] = sym__contextual_keyword,
  [sym__whitespace] = sym__whitespace,
  [sym__horizontal_space] = sym__horizontal_space,
  [sym__hspace] = sym__hspace,
  [sym__block_comment] = sym__block_comment,
  [sym__stmt_separator] = sym__stmt_separator,
  [sym__module_scope_stmt_list] = sym__module_scope_stmt_list,
  [sym__module_scope_stmt] = sym__module_scope_stmt,
  [sym_import_decl] = sym_import_decl,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym__identifier_token_repeat1] = aux_sym__identifier_token_repeat1,
  [aux_sym__identifier_token_repeat2] = aux_sym__identifier_token_repeat2,
  [aux_sym__stmt_separator_repeat1] = aux_sym__stmt_separator_repeat1,
  [aux_sym__stmt_separator_repeat2] = aux_sym__stmt_separator_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_0] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym__] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_3] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_5] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_6] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_7] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_8] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_9] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_a] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_b] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_c] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_d] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_e] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_f] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_A] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_B] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_C] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_D] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_E] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_F] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
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
  [sym__floating_point_suffix_head] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__c_char] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__s_char] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__m_char_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__m_char_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym__identifier_head] = {
    .visible = false,
    .named = true,
  },
  [sym__identifier_tail] = {
    .visible = false,
    .named = true,
  },
  [sym__bq_char] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_mutating] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_size] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_any] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [sym__raw_operator] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SPACE] = {
    .visible = true,
    .named = false,
  },
  [sym__single_line_comment] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_STAR_SLASH] = {
    .visible = true,
    .named = false,
  },
  [sym__block_comment_open] = {
    .visible = false,
    .named = true,
  },
  [sym__newline] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_import] = {
    .visible = true,
    .named = false,
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
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__prefix_operator_head_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__prefix_operator_head_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__postfix_operator_head_token1] = {
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
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__identifier_token] = {
    .visible = false,
    .named = true,
  },
  [sym__contextual_keyword] = {
    .visible = false,
    .named = true,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [sym__horizontal_space] = {
    .visible = false,
    .named = true,
  },
  [sym__hspace] = {
    .visible = false,
    .named = true,
  },
  [sym__block_comment] = {
    .visible = false,
    .named = true,
  },
  [sym__stmt_separator] = {
    .visible = false,
    .named = true,
  },
  [sym__module_scope_stmt_list] = {
    .visible = false,
    .named = true,
  },
  [sym__module_scope_stmt] = {
    .visible = false,
    .named = true,
  },
  [sym_import_decl] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__identifier_token_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__identifier_token_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__stmt_separator_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__stmt_separator_repeat2] = {
    .visible = false,
    .named = false,
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
  [4] = 4,
  [5] = 3,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 11,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 31,
};

static TSCharacterRange sym__identifier_head_character_set_1[] = {
  {'A', 'Z'}, {'_', '_'}, {'a', 'z'}, {0xaa, 0xaa}, {0xb5, 0xb5}, {0xba, 0xba}, {0xc0, 0xd6}, {0xd8, 0xf6},
  {0xf8, 0x2c1}, {0x2c6, 0x2d1}, {0x2e0, 0x2e4}, {0x2ec, 0x2ec}, {0x2ee, 0x2ee}, {0x370, 0x374}, {0x376, 0x377}, {0x37a, 0x37d},
  {0x37f, 0x37f}, {0x386, 0x386}, {0x388, 0x38a}, {0x38c, 0x38c}, {0x38e, 0x3a1}, {0x3a3, 0x3f5}, {0x3f7, 0x481}, {0x48a, 0x52f},
  {0x531, 0x556}, {0x559, 0x559}, {0x560, 0x588}, {0x5d0, 0x5ea}, {0x5ef, 0x5f2}, {0x620, 0x64a}, {0x66e, 0x66f}, {0x671, 0x6d3},
  {0x6d5, 0x6d5}, {0x6e5, 0x6e6}, {0x6ee, 0x6ef}, {0x6fa, 0x6fc}, {0x6ff, 0x6ff}, {0x710, 0x710}, {0x712, 0x72f}, {0x74d, 0x7a5},
  {0x7b1, 0x7b1}, {0x7ca, 0x7ea}, {0x7f4, 0x7f5}, {0x7fa, 0x7fa}, {0x800, 0x815}, {0x81a, 0x81a}, {0x824, 0x824}, {0x828, 0x828},
  {0x840, 0x858}, {0x860, 0x86a}, {0x870, 0x887}, {0x889, 0x88e}, {0x8a0, 0x8c9}, {0x904, 0x939}, {0x93d, 0x93d}, {0x950, 0x950},
  {0x958, 0x961}, {0x971, 0x980}, {0x985, 0x98c}, {0x98f, 0x990}, {0x993, 0x9a8}, {0x9aa, 0x9b0}, {0x9b2, 0x9b2}, {0x9b6, 0x9b9},
  {0x9bd, 0x9bd}, {0x9ce, 0x9ce}, {0x9dc, 0x9dd}, {0x9df, 0x9e1}, {0x9f0, 0x9f1}, {0x9fc, 0x9fc}, {0xa05, 0xa0a}, {0xa0f, 0xa10},
  {0xa13, 0xa28}, {0xa2a, 0xa30}, {0xa32, 0xa33}, {0xa35, 0xa36}, {0xa38, 0xa39}, {0xa59, 0xa5c}, {0xa5e, 0xa5e}, {0xa72, 0xa74},
  {0xa85, 0xa8d}, {0xa8f, 0xa91}, {0xa93, 0xaa8}, {0xaaa, 0xab0}, {0xab2, 0xab3}, {0xab5, 0xab9}, {0xabd, 0xabd}, {0xad0, 0xad0},
  {0xae0, 0xae1}, {0xaf9, 0xaf9}, {0xb05, 0xb0c}, {0xb0f, 0xb10}, {0xb13, 0xb28}, {0xb2a, 0xb30}, {0xb32, 0xb33}, {0xb35, 0xb39},
  {0xb3d, 0xb3d}, {0xb5c, 0xb5d}, {0xb5f, 0xb61}, {0xb71, 0xb71}, {0xb83, 0xb83}, {0xb85, 0xb8a}, {0xb8e, 0xb90}, {0xb92, 0xb95},
  {0xb99, 0xb9a}, {0xb9c, 0xb9c}, {0xb9e, 0xb9f}, {0xba3, 0xba4}, {0xba8, 0xbaa}, {0xbae, 0xbb9}, {0xbd0, 0xbd0}, {0xc05, 0xc0c},
  {0xc0e, 0xc10}, {0xc12, 0xc28}, {0xc2a, 0xc39}, {0xc3d, 0xc3d}, {0xc58, 0xc5a}, {0xc5d, 0xc5d}, {0xc60, 0xc61}, {0xc80, 0xc80},
  {0xc85, 0xc8c}, {0xc8e, 0xc90}, {0xc92, 0xca8}, {0xcaa, 0xcb3}, {0xcb5, 0xcb9}, {0xcbd, 0xcbd}, {0xcdd, 0xcde}, {0xce0, 0xce1},
  {0xcf1, 0xcf2}, {0xd04, 0xd0c}, {0xd0e, 0xd10}, {0xd12, 0xd3a}, {0xd3d, 0xd3d}, {0xd4e, 0xd4e}, {0xd54, 0xd56}, {0xd5f, 0xd61},
  {0xd7a, 0xd7f}, {0xd85, 0xd96}, {0xd9a, 0xdb1}, {0xdb3, 0xdbb}, {0xdbd, 0xdbd}, {0xdc0, 0xdc6}, {0xe01, 0xe30}, {0xe32, 0xe33},
  {0xe40, 0xe46}, {0xe81, 0xe82}, {0xe84, 0xe84}, {0xe86, 0xe8a}, {0xe8c, 0xea3}, {0xea5, 0xea5}, {0xea7, 0xeb0}, {0xeb2, 0xeb3},
  {0xebd, 0xebd}, {0xec0, 0xec4}, {0xec6, 0xec6}, {0xedc, 0xedf}, {0xf00, 0xf00}, {0xf40, 0xf47}, {0xf49, 0xf6c}, {0xf88, 0xf8c},
  {0x1000, 0x102a}, {0x103f, 0x103f}, {0x1050, 0x1055}, {0x105a, 0x105d}, {0x1061, 0x1061}, {0x1065, 0x1066}, {0x106e, 0x1070}, {0x1075, 0x1081},
  {0x108e, 0x108e}, {0x10a0, 0x10c5}, {0x10c7, 0x10c7}, {0x10cd, 0x10cd}, {0x10d0, 0x10fa}, {0x10fc, 0x1248}, {0x124a, 0x124d}, {0x1250, 0x1256},
  {0x1258, 0x1258}, {0x125a, 0x125d}, {0x1260, 0x1288}, {0x128a, 0x128d}, {0x1290, 0x12b0}, {0x12b2, 0x12b5}, {0x12b8, 0x12be}, {0x12c0, 0x12c0},
  {0x12c2, 0x12c5}, {0x12c8, 0x12d6}, {0x12d8, 0x1310}, {0x1312, 0x1315}, {0x1318, 0x135a}, {0x1380, 0x138f}, {0x13a0, 0x13f5}, {0x13f8, 0x13fd},
  {0x1401, 0x166c}, {0x166f, 0x167f}, {0x1681, 0x169a}, {0x16a0, 0x16ea}, {0x16ee, 0x16f8}, {0x1700, 0x1711}, {0x171f, 0x1731}, {0x1740, 0x1751},
  {0x1760, 0x176c}, {0x176e, 0x1770}, {0x1780, 0x17b3}, {0x17d7, 0x17d7}, {0x17dc, 0x17dc}, {0x1820, 0x1878}, {0x1880, 0x1884}, {0x1887, 0x18a8},
  {0x18aa, 0x18aa}, {0x18b0, 0x18f5}, {0x1900, 0x191e}, {0x1950, 0x196d}, {0x1970, 0x1974}, {0x1980, 0x19ab}, {0x19b0, 0x19c9}, {0x1a00, 0x1a16},
  {0x1a20, 0x1a54}, {0x1aa7, 0x1aa7}, {0x1b05, 0x1b33}, {0x1b45, 0x1b4c}, {0x1b83, 0x1ba0}, {0x1bae, 0x1baf}, {0x1bba, 0x1be5}, {0x1c00, 0x1c23},
  {0x1c4d, 0x1c4f}, {0x1c5a, 0x1c7d}, {0x1c80, 0x1c88}, {0x1c90, 0x1cba}, {0x1cbd, 0x1cbf}, {0x1ce9, 0x1cec}, {0x1cee, 0x1cf3}, {0x1cf5, 0x1cf6},
  {0x1cfa, 0x1cfa}, {0x1d00, 0x1dbf}, {0x1e00, 0x1f15}, {0x1f18, 0x1f1d}, {0x1f20, 0x1f45}, {0x1f48, 0x1f4d}, {0x1f50, 0x1f57}, {0x1f59, 0x1f59},
  {0x1f5b, 0x1f5b}, {0x1f5d, 0x1f5d}, {0x1f5f, 0x1f7d}, {0x1f80, 0x1fb4}, {0x1fb6, 0x1fbc}, {0x1fbe, 0x1fbe}, {0x1fc2, 0x1fc4}, {0x1fc6, 0x1fcc},
  {0x1fd0, 0x1fd3}, {0x1fd6, 0x1fdb}, {0x1fe0, 0x1fec}, {0x1ff2, 0x1ff4}, {0x1ff6, 0x1ffc}, {0x2071, 0x2071}, {0x207f, 0x207f}, {0x2090, 0x209c},
  {0x2102, 0x2102}, {0x2107, 0x2107}, {0x210a, 0x2113}, {0x2115, 0x2115}, {0x2119, 0x211d}, {0x2124, 0x2124}, {0x2126, 0x2126}, {0x2128, 0x2128},
  {0x212a, 0x212d}, {0x212f, 0x2139}, {0x213c, 0x213f}, {0x2145, 0x2149}, {0x214e, 0x214e}, {0x2160, 0x2188}, {0x2c00, 0x2ce4}, {0x2ceb, 0x2cee},
  {0x2cf2, 0x2cf3}, {0x2d00, 0x2d25}, {0x2d27, 0x2d27}, {0x2d2d, 0x2d2d}, {0x2d30, 0x2d67}, {0x2d6f, 0x2d6f}, {0x2d80, 0x2d96}, {0x2da0, 0x2da6},
  {0x2da8, 0x2dae}, {0x2db0, 0x2db6}, {0x2db8, 0x2dbe}, {0x2dc0, 0x2dc6}, {0x2dc8, 0x2dce}, {0x2dd0, 0x2dd6}, {0x2dd8, 0x2dde}, {0x2e2f, 0x2e2f},
  {0x3005, 0x3007}, {0x3021, 0x3029}, {0x3031, 0x3035}, {0x3038, 0x303c}, {0x3041, 0x3096}, {0x309d, 0x309f}, {0x30a1, 0x30fa}, {0x30fc, 0x30ff},
  {0x3105, 0x312f}, {0x3131, 0x318e}, {0x31a0, 0x31bf}, {0x31f0, 0x31ff}, {0x3400, 0x3400}, {0x4dbf, 0x4dbf}, {0x4e00, 0x4e00}, {0x9fff, 0xa48c},
  {0xa4d0, 0xa4fd}, {0xa500, 0xa60c}, {0xa610, 0xa61f}, {0xa62a, 0xa62b}, {0xa640, 0xa66e}, {0xa67f, 0xa69d}, {0xa6a0, 0xa6ef}, {0xa717, 0xa71f},
  {0xa722, 0xa788}, {0xa78b, 0xa7ca}, {0xa7d0, 0xa7d1}, {0xa7d3, 0xa7d3}, {0xa7d5, 0xa7d9}, {0xa7f2, 0xa801}, {0xa803, 0xa805}, {0xa807, 0xa80a},
  {0xa80c, 0xa822}, {0xa840, 0xa873}, {0xa882, 0xa8b3}, {0xa8f2, 0xa8f7}, {0xa8fb, 0xa8fb}, {0xa8fd, 0xa8fe}, {0xa90a, 0xa925}, {0xa930, 0xa946},
  {0xa960, 0xa97c}, {0xa984, 0xa9b2}, {0xa9cf, 0xa9cf}, {0xa9e0, 0xa9e4}, {0xa9e6, 0xa9ef}, {0xa9fa, 0xa9fe}, {0xaa00, 0xaa28}, {0xaa40, 0xaa42},
  {0xaa44, 0xaa4b}, {0xaa60, 0xaa76}, {0xaa7a, 0xaa7a}, {0xaa7e, 0xaaaf}, {0xaab1, 0xaab1}, {0xaab5, 0xaab6}, {0xaab9, 0xaabd}, {0xaac0, 0xaac0},
  {0xaac2, 0xaac2}, {0xaadb, 0xaadd}, {0xaae0, 0xaaea}, {0xaaf2, 0xaaf4}, {0xab01, 0xab06}, {0xab09, 0xab0e}, {0xab11, 0xab16}, {0xab20, 0xab26},
  {0xab28, 0xab2e}, {0xab30, 0xab5a}, {0xab5c, 0xab69}, {0xab70, 0xabe2}, {0xac00, 0xac00}, {0xd7a3, 0xd7a3}, {0xd7b0, 0xd7c6}, {0xd7cb, 0xd7fb},
  {0xf900, 0xfa6d}, {0xfa70, 0xfad9}, {0xfb00, 0xfb06}, {0xfb13, 0xfb17}, {0xfb1d, 0xfb1d}, {0xfb1f, 0xfb28}, {0xfb2a, 0xfb36}, {0xfb38, 0xfb3c},
  {0xfb3e, 0xfb3e}, {0xfb40, 0xfb41}, {0xfb43, 0xfb44}, {0xfb46, 0xfbb1}, {0xfbd3, 0xfd3d}, {0xfd50, 0xfd8f}, {0xfd92, 0xfdc7}, {0xfdf0, 0xfdfb},
  {0xfe70, 0xfe74}, {0xfe76, 0xfefc}, {0xff21, 0xff3a}, {0xff41, 0xff5a}, {0xff66, 0xffbe}, {0xffc2, 0xffc7}, {0xffca, 0xffcf}, {0xffd2, 0xffd7},
  {0xffda, 0xffdc}, {0x10000, 0x1000b}, {0x1000d, 0x10026}, {0x10028, 0x1003a}, {0x1003c, 0x1003d}, {0x1003f, 0x1004d}, {0x10050, 0x1005d}, {0x10080, 0x100fa},
  {0x10140, 0x10174}, {0x10280, 0x1029c}, {0x102a0, 0x102d0}, {0x10300, 0x1031f}, {0x1032d, 0x1034a}, {0x10350, 0x10375}, {0x10380, 0x1039d}, {0x103a0, 0x103c3},
  {0x103c8, 0x103cf}, {0x103d1, 0x103d5}, {0x10400, 0x1049d}, {0x104b0, 0x104d3}, {0x104d8, 0x104fb}, {0x10500, 0x10527}, {0x10530, 0x10563}, {0x10570, 0x1057a},
  {0x1057c, 0x1058a}, {0x1058c, 0x10592}, {0x10594, 0x10595}, {0x10597, 0x105a1}, {0x105a3, 0x105b1}, {0x105b3, 0x105b9}, {0x105bb, 0x105bc}, {0x10600, 0x10736},
  {0x10740, 0x10755}, {0x10760, 0x10767}, {0x10780, 0x10785}, {0x10787, 0x107b0}, {0x107b2, 0x107ba}, {0x10800, 0x10805}, {0x10808, 0x10808}, {0x1080a, 0x10835},
  {0x10837, 0x10838}, {0x1083c, 0x1083c}, {0x1083f, 0x10855}, {0x10860, 0x10876}, {0x10880, 0x1089e}, {0x108e0, 0x108f2}, {0x108f4, 0x108f5}, {0x10900, 0x10915},
};

static TSCharacterRange sym__identifier_tail_character_set_1[] = {
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

static TSCharacterRange sym__raw_operator_character_set_1[] = {
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
      if (eof) ADVANCE(25);
      ADVANCE_MAP(
        ' ', 67,
        '"', 54,
        '&', 82,
        '\'', 52,
        '(', 75,
        ')', 77,
        '+', 50,
        ',', 76,
        '-', 51,
        '.', 49,
        '0', 26,
        '1', 27,
        '2', 29,
        '3', 30,
        '4', 31,
        '5', 32,
        '6', 33,
        '7', 34,
        '8', 35,
        '9', 36,
        ':', 78,
        ';', 72,
        '<', 79,
        '=', 81,
        '>', 80,
        '@', 74,
        'A', 43,
        'B', 44,
        'C', 45,
        'D', 46,
        'E', 47,
        'F', 48,
        '[', 86,
        ']', 87,
        '_', 28,
        '`', 55,
        'a', 37,
        'b', 38,
        'c', 39,
        'd', 40,
        'e', 41,
        'f', 42,
        '{', 83,
        '|', 85,
        '}', 84,
        '\n', 53,
        '\r', 53,
      );
      if (set_contains(sym__raw_operator_character_set_1, 58, lookahead)) ADVANCE(53);
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
          (0x104a0 <= lookahead && lookahead <= 0x104a9)) ADVANCE(53);
      if (set_contains(sym__identifier_tail_character_set_1, 483, lookahead)) ADVANCE(53);
      if (lookahead != 0) ADVANCE(53);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(71);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(71);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ' ') ADVANCE(67);
      if (lookahead == '*') ADVANCE(70);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == ';') ADVANCE(72);
      if (set_contains(sym__identifier_tail_character_set_1, 483, lookahead)) ADVANCE(61);
      END_STATE();
    case 3:
      ADVANCE_MAP(
        '\n', 71,
        '\r', 1,
        ' ', 67,
        '*', 70,
        '/', 7,
        '`', 55,
        'a', 58,
        'i', 59,
        'm', 60,
        's', 57,
      );
      if (set_contains(sym__identifier_head_character_set_1, 432, lookahead)) ADVANCE(56);
      END_STATE();
    case 4:
      if (lookahead == '*') ADVANCE(4);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(70);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(8);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(6);
      if (lookahead != 0 &&
          lookahead != '*') ADVANCE(70);
      END_STATE();
    case 7:
      if (lookahead == '/') ADVANCE(68);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(69);
      END_STATE();
    case 9:
      if (lookahead == '`') ADVANCE(55);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(62);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(21);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 12:
      if (lookahead == 'g') ADVANCE(63);
      END_STATE();
    case 13:
      if (lookahead == 'i') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'm') ADVANCE(17);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 17:
      if (lookahead == 'p') ADVANCE(16);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(73);
      END_STATE();
    case 20:
      if (lookahead == 't') ADVANCE(10);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 22:
      if (lookahead == 'y') ADVANCE(65);
      END_STATE();
    case 23:
      if (lookahead == 'z') ADVANCE(11);
      END_STATE();
    case 24:
      if (eof) ADVANCE(25);
      if (lookahead == '\n') ADVANCE(71);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == ' ') ADVANCE(67);
      if (lookahead == '*') ADVANCE(70);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == ';') ADVANCE(72);
      if (lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_0);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_1);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym__);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_2);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_3);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_4);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_5);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_6);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_7);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_8);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_9);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_a);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_b);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_c);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_d);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_e);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_f);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_A);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_B);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_C);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_D);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_E);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_F);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym__c_char);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym__identifier_head);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym__identifier_head);
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym__identifier_head);
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym__identifier_head);
      if (lookahead == 'n') ADVANCE(66);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym__identifier_head);
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym__identifier_tail);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym__bq_char);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_mutating);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_size);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_any);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_in);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_SPACE);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym__single_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(68);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym__block_comment_open);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '/') ADVANCE(6);
      if (lookahead != 0) ADVANCE(70);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym__newline);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_import);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_LT);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 24},
  [2] = {.lex_state = 3},
  [3] = {.lex_state = 3},
  [4] = {.lex_state = 24},
  [5] = {.lex_state = 24},
  [6] = {.lex_state = 24},
  [7] = {.lex_state = 24},
  [8] = {.lex_state = 24},
  [9] = {.lex_state = 24},
  [10] = {.lex_state = 24},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 24},
  [13] = {.lex_state = 24},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 24},
  [18] = {.lex_state = 24},
  [19] = {.lex_state = 24},
  [20] = {.lex_state = 24},
  [21] = {.lex_state = 24},
  [22] = {.lex_state = 24},
  [23] = {.lex_state = 24},
  [24] = {.lex_state = 24},
  [25] = {.lex_state = 24},
  [26] = {.lex_state = 24},
  [27] = {.lex_state = 24},
  [28] = {.lex_state = 9},
  [29] = {.lex_state = 9},
  [30] = {.lex_state = 9},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 5},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_0] = ACTIONS(1),
    [anon_sym_1] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_2] = ACTIONS(1),
    [anon_sym_3] = ACTIONS(1),
    [anon_sym_4] = ACTIONS(1),
    [anon_sym_5] = ACTIONS(1),
    [anon_sym_6] = ACTIONS(1),
    [anon_sym_7] = ACTIONS(1),
    [anon_sym_8] = ACTIONS(1),
    [anon_sym_9] = ACTIONS(1),
    [anon_sym_a] = ACTIONS(1),
    [anon_sym_b] = ACTIONS(1),
    [anon_sym_c] = ACTIONS(1),
    [anon_sym_d] = ACTIONS(1),
    [anon_sym_e] = ACTIONS(1),
    [anon_sym_f] = ACTIONS(1),
    [anon_sym_A] = ACTIONS(1),
    [anon_sym_B] = ACTIONS(1),
    [anon_sym_C] = ACTIONS(1),
    [anon_sym_D] = ACTIONS(1),
    [anon_sym_E] = ACTIONS(1),
    [anon_sym_F] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym__floating_point_suffix_head] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym__c_char] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [sym__s_char] = ACTIONS(1),
    [aux_sym__m_char_token1] = ACTIONS(1),
    [aux_sym__m_char_token2] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym__identifier_head] = ACTIONS(1),
    [sym__identifier_tail] = ACTIONS(1),
    [sym__bq_char] = ACTIONS(1),
    [sym__raw_operator] = ACTIONS(1),
    [anon_sym_SPACE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
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
    [anon_sym_PIPE] = ACTIONS(1),
    [aux_sym__prefix_operator_head_token1] = ACTIONS(1),
    [aux_sym__prefix_operator_head_token2] = ACTIONS(1),
    [aux_sym__postfix_operator_head_token1] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(32),
    [sym__whitespace] = STATE(4),
    [sym__horizontal_space] = STATE(4),
    [sym__hspace] = STATE(4),
    [sym__block_comment] = STATE(4),
    [sym__module_scope_stmt_list] = STATE(6),
    [sym__module_scope_stmt] = STATE(6),
    [sym_import_decl] = STATE(6),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_SPACE] = ACTIONS(5),
    [sym__single_line_comment] = ACTIONS(5),
    [sym__block_comment_open] = ACTIONS(7),
    [sym__newline] = ACTIONS(5),
    [anon_sym_import] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(11), 1,
      anon_sym_BQUOTE,
    ACTIONS(13), 1,
      sym__identifier_head,
    ACTIONS(19), 1,
      sym__block_comment_open,
    STATE(19), 1,
      sym_identifier,
    STATE(20), 2,
      sym__identifier_token,
      sym__contextual_keyword,
    ACTIONS(17), 3,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__newline,
    ACTIONS(15), 4,
      anon_sym_mutating,
      anon_sym_size,
      anon_sym_any,
      anon_sym_in,
    STATE(3), 5,
      sym__whitespace,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym_source_file_repeat1,
  [35] = 5,
    ACTIONS(23), 1,
      sym__identifier_head,
    ACTIONS(28), 1,
      sym__block_comment_open,
    ACTIONS(25), 3,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__newline,
    ACTIONS(21), 5,
      anon_sym_BQUOTE,
      anon_sym_mutating,
      anon_sym_size,
      anon_sym_any,
      anon_sym_in,
    STATE(3), 5,
      sym__whitespace,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym_source_file_repeat1,
  [61] = 6,
    ACTIONS(7), 1,
      sym__block_comment_open,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 3,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__newline,
    STATE(10), 3,
      sym__module_scope_stmt_list,
      sym__module_scope_stmt,
      sym_import_decl,
    STATE(5), 5,
      sym__whitespace,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym_source_file_repeat1,
  [88] = 4,
    ACTIONS(38), 1,
      sym__block_comment_open,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_import,
    ACTIONS(35), 3,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__newline,
    STATE(5), 5,
      sym__whitespace,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym_source_file_repeat1,
  [108] = 6,
    ACTIONS(7), 1,
      sym__block_comment_open,
    STATE(18), 1,
      aux_sym__stmt_separator_repeat2,
    STATE(26), 1,
      sym__stmt_separator,
    ACTIONS(41), 2,
      anon_sym_SPACE,
      sym__single_line_comment,
    ACTIONS(43), 2,
      sym__newline,
      anon_sym_SEMI,
    STATE(12), 4,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym__stmt_separator_repeat1,
  [132] = 4,
    ACTIONS(50), 1,
      sym__block_comment_open,
    ACTIONS(47), 2,
      anon_sym_SPACE,
      sym__single_line_comment,
    ACTIONS(45), 4,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_SEMI,
      anon_sym_import,
    STATE(7), 4,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym__stmt_separator_repeat1,
  [152] = 4,
    ACTIONS(7), 1,
      sym__block_comment_open,
    ACTIONS(55), 2,
      anon_sym_SPACE,
      sym__single_line_comment,
    ACTIONS(53), 4,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_SEMI,
      anon_sym_import,
    STATE(9), 4,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym__stmt_separator_repeat1,
  [172] = 4,
    ACTIONS(7), 1,
      sym__block_comment_open,
    ACTIONS(59), 2,
      anon_sym_SPACE,
      sym__single_line_comment,
    ACTIONS(57), 4,
      ts_builtin_sym_end,
      sym__newline,
      anon_sym_SEMI,
      anon_sym_import,
    STATE(7), 4,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym__stmt_separator_repeat1,
  [192] = 6,
    ACTIONS(7), 1,
      sym__block_comment_open,
    STATE(18), 1,
      aux_sym__stmt_separator_repeat2,
    STATE(27), 1,
      sym__stmt_separator,
    ACTIONS(41), 2,
      anon_sym_SPACE,
      sym__single_line_comment,
    ACTIONS(43), 2,
      sym__newline,
      anon_sym_SEMI,
    STATE(12), 4,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym__stmt_separator_repeat1,
  [216] = 2,
    ACTIONS(63), 1,
      sym__identifier_head,
    ACTIONS(61), 9,
      anon_sym_BQUOTE,
      anon_sym_mutating,
      anon_sym_size,
      anon_sym_any,
      anon_sym_in,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
  [231] = 5,
    ACTIONS(7), 1,
      sym__block_comment_open,
    STATE(22), 1,
      aux_sym__stmt_separator_repeat2,
    ACTIONS(43), 2,
      sym__newline,
      anon_sym_SEMI,
    ACTIONS(59), 2,
      anon_sym_SPACE,
      sym__single_line_comment,
    STATE(7), 4,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym__stmt_separator_repeat1,
  [252] = 3,
    ACTIONS(19), 1,
      sym__block_comment_open,
    ACTIONS(65), 3,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__newline,
    STATE(2), 5,
      sym__whitespace,
      sym__horizontal_space,
      sym__hspace,
      sym__block_comment,
      aux_sym_source_file_repeat1,
  [268] = 3,
    ACTIONS(67), 1,
      sym__identifier_tail,
    STATE(15), 1,
      aux_sym__identifier_token_repeat1,
    ACTIONS(69), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [282] = 3,
    ACTIONS(71), 1,
      sym__identifier_tail,
    STATE(16), 1,
      aux_sym__identifier_token_repeat1,
    ACTIONS(73), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [296] = 3,
    ACTIONS(75), 1,
      sym__identifier_tail,
    STATE(16), 1,
      aux_sym__identifier_token_repeat1,
    ACTIONS(78), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [310] = 1,
    ACTIONS(61), 7,
      ts_builtin_sym_end,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
      anon_sym_import,
  [320] = 3,
    STATE(23), 1,
      aux_sym__stmt_separator_repeat2,
    ACTIONS(43), 2,
      sym__newline,
      anon_sym_SEMI,
    ACTIONS(80), 2,
      ts_builtin_sym_end,
      anon_sym_import,
  [332] = 1,
    ACTIONS(82), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [340] = 1,
    ACTIONS(84), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [348] = 1,
    ACTIONS(86), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [356] = 3,
    STATE(23), 1,
      aux_sym__stmt_separator_repeat2,
    ACTIONS(43), 2,
      sym__newline,
      anon_sym_SEMI,
    ACTIONS(88), 2,
      ts_builtin_sym_end,
      anon_sym_import,
  [368] = 3,
    STATE(23), 1,
      aux_sym__stmt_separator_repeat2,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      anon_sym_import,
    ACTIONS(90), 2,
      sym__newline,
      anon_sym_SEMI,
  [380] = 1,
    ACTIONS(73), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [388] = 1,
    ACTIONS(93), 5,
      anon_sym_SPACE,
      sym__single_line_comment,
      sym__block_comment_open,
      sym__newline,
      anon_sym_SEMI,
  [396] = 3,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(95), 1,
      ts_builtin_sym_end,
    STATE(21), 2,
      sym__module_scope_stmt,
      sym_import_decl,
  [407] = 3,
    ACTIONS(9), 1,
      anon_sym_import,
    ACTIONS(97), 1,
      ts_builtin_sym_end,
    STATE(21), 2,
      sym__module_scope_stmt,
      sym_import_decl,
  [418] = 3,
    ACTIONS(99), 1,
      anon_sym_BQUOTE,
    ACTIONS(101), 1,
      sym__bq_char,
    STATE(29), 1,
      aux_sym__identifier_token_repeat2,
  [428] = 3,
    ACTIONS(103), 1,
      anon_sym_BQUOTE,
    ACTIONS(105), 1,
      sym__bq_char,
    STATE(30), 1,
      aux_sym__identifier_token_repeat2,
  [438] = 3,
    ACTIONS(107), 1,
      anon_sym_BQUOTE,
    ACTIONS(109), 1,
      sym__bq_char,
    STATE(30), 1,
      aux_sym__identifier_token_repeat2,
  [448] = 1,
    ACTIONS(112), 1,
      anon_sym_STAR_SLASH,
  [452] = 1,
    ACTIONS(114), 1,
      ts_builtin_sym_end,
  [456] = 1,
    ACTIONS(116), 1,
      anon_sym_STAR_SLASH,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 35,
  [SMALL_STATE(4)] = 61,
  [SMALL_STATE(5)] = 88,
  [SMALL_STATE(6)] = 108,
  [SMALL_STATE(7)] = 132,
  [SMALL_STATE(8)] = 152,
  [SMALL_STATE(9)] = 172,
  [SMALL_STATE(10)] = 192,
  [SMALL_STATE(11)] = 216,
  [SMALL_STATE(12)] = 231,
  [SMALL_STATE(13)] = 252,
  [SMALL_STATE(14)] = 268,
  [SMALL_STATE(15)] = 282,
  [SMALL_STATE(16)] = 296,
  [SMALL_STATE(17)] = 310,
  [SMALL_STATE(18)] = 320,
  [SMALL_STATE(19)] = 332,
  [SMALL_STATE(20)] = 340,
  [SMALL_STATE(21)] = 348,
  [SMALL_STATE(22)] = 356,
  [SMALL_STATE(23)] = 368,
  [SMALL_STATE(24)] = 380,
  [SMALL_STATE(25)] = 388,
  [SMALL_STATE(26)] = 396,
  [SMALL_STATE(27)] = 407,
  [SMALL_STATE(28)] = 418,
  [SMALL_STATE(29)] = 428,
  [SMALL_STATE(30)] = 438,
  [SMALL_STATE(31)] = 448,
  [SMALL_STATE(32)] = 452,
  [SMALL_STATE(33)] = 456,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(33),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stmt_separator_repeat1, 2, 0, 0),
  [47] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__stmt_separator_repeat1, 2, 0, 0), SHIFT_REPEAT(7),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__stmt_separator_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stmt_separator_repeat2, 1, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__stmt_separator_repeat2, 2, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__block_comment, 2, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__block_comment, 2, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__identifier_token, 1, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__identifier_token, 2, 0, 0),
  [75] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__identifier_token_repeat1, 2, 0, 0), SHIFT_REPEAT(16),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__identifier_token_repeat1, 2, 0, 0),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stmt_separator, 1, 0, 0),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_import_decl, 3, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier, 1, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__module_scope_stmt_list, 3, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__stmt_separator, 2, 0, 0),
  [90] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__stmt_separator_repeat2, 2, 0, 0), SHIFT_REPEAT(8),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__identifier_token, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 3, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__identifier_token_repeat2, 2, 0, 0),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__identifier_token_repeat2, 2, 0, 0), SHIFT_REPEAT(30),
  [112] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [114] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
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
