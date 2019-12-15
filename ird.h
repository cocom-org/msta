#ifndef __IR_ird__
#define __IR_ird__

#define _IR_offsetof(type, field) ((char *)&((type *) 64)->field - (char *) 64)


#line 25 "./ird.sprut"


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* #ifdef HAVE_CONFIG_H */


#include <ctype.h>
#include "vlobject.h"
#include "objstack.h"
#include "position.h"

#include <assert.h>

/* Definitions of predefined types: */

typedef int integer_t;

typedef int bool_t;

typedef char *string_t;

/* All bit operations are executed by the following elements. */

typedef unsigned int bit_string_element_t;

/* Token string is given by its number (0, 1, ...). */

typedef long int token_string_t;

/* Variable length bit string. */

struct context_t
  {
    vlo_t bit_string;
  };

typedef struct context_t *context_t;



#line 50 "ird.h"

typedef enum IR_node_mode_enum
{
  IR_NM_node,
  IR_NM_identifier_or_literal,
  IR_NM_identifier,
  IR_NM_literal,
  IR_NM_string,
  IR_NM_number,
  IR_NM_code_insertion,
  IR_NM_additional_code,
  IR_NM_definition,
  IR_NM_start_definition,
  IR_NM_code,
  IR_NM_yacc_code,
  IR_NM_local_code,
  IR_NM_import_code,
  IR_NM_export_code,
  IR_NM_union_code,
  IR_NM_scanner_definition,
  IR_NM_expect_definition,
  IR_NM_symbol_definition,
  IR_NM_token_definition,
  IR_NM_left_definition,
  IR_NM_right_definition,
  IR_NM_nonassoc_definition,
  IR_NM_type_definition,
  IR_NM_symbol,
  IR_NM_rule,
  IR_NM_pattern,
  IR_NM_alternative,
  IR_NM_sequence,
  IR_NM_separator_iteration,
  IR_NM_sequence_element,
  IR_NM_control_point,
  IR_NM_default,
  IR_NM_star_iteration,
  IR_NM_plus_iteration,
  IR_NM_code_insertion_atom,
  IR_NM_unit,
  IR_NM_group,
  IR_NM_range_atom,
  IR_NM_range_no_left_bound_atom,
  IR_NM_range_no_right_bound_atom,
  IR_NM_range_no_left_right_bounds_atom,
  IR_NM_identifier_or_literal_atom,
  IR_NM_string_atom,
  IR_NM_description,
  IR_NM_denotation,
  IR_NM_single_definition,
  IR_NM_single_term_definition,
  IR_NM_literal_range_definition,
  IR_NM_single_nonterm_definition,
  IR_NM_canonical_rule,
  IR_NM_right_hand_side_element,
  IR_NM_canonical_rule_element,
  IR_NM_canonical_rule_end,
  IR_NM_LR_situation,
  IR_NM_LR_set,
  IR_NM_LR_set_look_ahead_trie_node,
  IR_NM_back_track_alternative,
  IR_NM_conflict,
  IR_NM_regular_arc,
  IR_NM_rule_list_element,
  IR_NM_LR_core,
  IR_NM_DeRemer_dependence,
  IR_NM_LR_set_dependence,
  IR_NM_shift_dependence,
  IR_NM_shift_LR_situation_dependence,
  IR_NM_dependence_list_element,
  IR_NM__root,
  IR_NM__error
} IR_node_mode_t;

extern short _IR_node_level [];

extern unsigned char _IR_SF_node [];

extern unsigned char _IR_SF_identifier_or_literal [];

extern unsigned char _IR_SF_identifier [];

extern unsigned char _IR_SF_literal [];

extern unsigned char _IR_SF_string [];

extern unsigned char _IR_SF_number [];

extern unsigned char _IR_SF_code_insertion [];

extern unsigned char _IR_SF_additional_code [];

extern unsigned char _IR_SF_definition [];

extern unsigned char _IR_SF_start_definition [];

extern unsigned char _IR_SF_code [];

extern unsigned char _IR_SF_yacc_code [];

extern unsigned char _IR_SF_local_code [];

extern unsigned char _IR_SF_import_code [];

extern unsigned char _IR_SF_export_code [];

extern unsigned char _IR_SF_union_code [];

extern unsigned char _IR_SF_scanner_definition [];

extern unsigned char _IR_SF_expect_definition [];

extern unsigned char _IR_SF_symbol_definition [];

extern unsigned char _IR_SF_token_definition [];

extern unsigned char _IR_SF_left_definition [];

extern unsigned char _IR_SF_right_definition [];

extern unsigned char _IR_SF_nonassoc_definition [];

extern unsigned char _IR_SF_type_definition [];

extern unsigned char _IR_SF_symbol [];

extern unsigned char _IR_SF_rule [];

extern unsigned char _IR_SF_pattern [];

extern unsigned char _IR_SF_alternative [];

extern unsigned char _IR_SF_sequence [];

extern unsigned char _IR_SF_separator_iteration [];

extern unsigned char _IR_SF_sequence_element [];

extern unsigned char _IR_SF_control_point [];

extern unsigned char _IR_SF_default [];

extern unsigned char _IR_SF_star_iteration [];

extern unsigned char _IR_SF_plus_iteration [];

extern unsigned char _IR_SF_code_insertion_atom [];

extern unsigned char _IR_SF_unit [];

extern unsigned char _IR_SF_group [];

extern unsigned char _IR_SF_range_atom [];

extern unsigned char _IR_SF_range_no_left_bound_atom [];

extern unsigned char _IR_SF_range_no_right_bound_atom [];

extern unsigned char _IR_SF_range_no_left_right_bounds_atom [];

extern unsigned char _IR_SF_identifier_or_literal_atom [];

extern unsigned char _IR_SF_string_atom [];

extern unsigned char _IR_SF_description [];

extern unsigned char _IR_SF_denotation [];

extern unsigned char _IR_SF_single_definition [];

extern unsigned char _IR_SF_single_term_definition [];

extern unsigned char _IR_SF_literal_range_definition [];

extern unsigned char _IR_SF_single_nonterm_definition [];

extern unsigned char _IR_SF_canonical_rule [];

extern unsigned char _IR_SF_right_hand_side_element [];

extern unsigned char _IR_SF_canonical_rule_element [];

extern unsigned char _IR_SF_canonical_rule_end [];

extern unsigned char _IR_SF_LR_situation [];

extern unsigned char _IR_SF_LR_set [];

extern unsigned char _IR_SF_LR_set_look_ahead_trie_node [];

extern unsigned char _IR_SF_back_track_alternative [];

extern unsigned char _IR_SF_conflict [];

extern unsigned char _IR_SF_regular_arc [];

extern unsigned char _IR_SF_rule_list_element [];

extern unsigned char _IR_SF_LR_core [];

extern unsigned char _IR_SF_DeRemer_dependence [];

extern unsigned char _IR_SF_LR_set_dependence [];

extern unsigned char _IR_SF_shift_dependence [];

extern unsigned char _IR_SF_shift_LR_situation_dependence [];

extern unsigned char _IR_SF_dependence_list_element [];

extern unsigned char _IR_SF__root [];

extern unsigned char _IR_SF__error [];

extern unsigned char *_IR_is_type[];

extern unsigned char _IR_D_identifier_or_literal [];

extern unsigned char _IR_D_pattern [];

extern unsigned char _IR_D_iteration_unit [];

extern unsigned char _IR_D_corresponding_single_nonterm_definition [];

extern unsigned char _IR_D_pass_number [];

extern unsigned char _IR_D_next_cp_flag [];

extern unsigned char _IR_D_canonical_rule [];

extern unsigned char _IR_D_context [];

extern unsigned char _IR_D_LR_set [];

extern unsigned char _IR_D_result_LR_set_will_be_on_the_stack [];

extern void *_IR_class_structure_array [];

typedef struct IR_node *IR_node_t;

typedef struct _IR_double_link *IR_double_link_t;

struct _IR_double_link
{
  IR_node_t field_itself;
  IR_node_t link_owner;
  void (*set_function) (IR_node_t, IR_node_t);
  IR_double_link_t previous_link;
  IR_double_link_t next_link;
};

struct _IR_S_node
{
  position_t  position;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_node _IR_S_node;
} _IR_node;

struct _IR_S_identifier_or_literal
{
  struct _IR_S_node _IR_M_node;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_identifier_or_literal _IR_S_identifier_or_literal;
} _IR_identifier_or_literal;

struct _IR_S_identifier
{
  struct _IR_S_identifier_or_literal _IR_M_identifier_or_literal;
  string_t  identifier_itself;
  bool_t  dot_presence_flag;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_identifier _IR_S_identifier;
} _IR_identifier;

struct _IR_S_literal
{
  struct _IR_S_identifier_or_literal _IR_M_identifier_or_literal;
  string_t  character_representation;
  integer_t  literal_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_literal _IR_S_literal;
} _IR_literal;

struct _IR_S_string
{
  struct _IR_S_node _IR_M_node;
  string_t  string_representation;
  string_t  string_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_string _IR_S_string;
} _IR_string;

struct _IR_S_number
{
  struct _IR_S_node _IR_M_node;
  integer_t  number_value;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_number _IR_S_number;
} _IR_number;

struct _IR_S_code_insertion
{
  struct _IR_S_node _IR_M_node;
  string_t  code_insertion_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_code_insertion _IR_S_code_insertion;
} _IR_code_insertion;

struct _IR_S_additional_code
{
  struct _IR_S_node _IR_M_node;
  string_t  additional_code_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_additional_code _IR_S_additional_code;
} _IR_additional_code;

struct _IR_S_definition
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  next_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_definition _IR_S_definition;
} _IR_definition;

struct _IR_S_start_definition
{
  struct _IR_S_definition _IR_M_definition;
  IR_node_t  identifier;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_start_definition _IR_S_start_definition;
} _IR_start_definition;

struct _IR_S_code
{
  struct _IR_S_definition _IR_M_definition;
  IR_node_t  code_itself;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_code _IR_S_code;
} _IR_code;

struct _IR_S_yacc_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_yacc_code _IR_S_yacc_code;
} _IR_yacc_code;

struct _IR_S_local_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_local_code _IR_S_local_code;
} _IR_local_code;

struct _IR_S_import_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_import_code _IR_S_import_code;
} _IR_import_code;

struct _IR_S_export_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_export_code _IR_S_export_code;
} _IR_export_code;

struct _IR_S_union_code
{
  struct _IR_S_code _IR_M_code;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_union_code _IR_S_union_code;
} _IR_union_code;

struct _IR_S_scanner_definition
{
  struct _IR_S_definition _IR_M_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_scanner_definition _IR_S_scanner_definition;
} _IR_scanner_definition;

struct _IR_S_expect_definition
{
  struct _IR_S_definition _IR_M_definition;
  IR_node_t  expected_number;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_expect_definition _IR_S_expect_definition;
} _IR_expect_definition;

struct _IR_S_symbol_definition
{
  struct _IR_S_definition _IR_M_definition;
  IR_node_t  symbol_list;
  IR_node_t  tag;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_symbol_definition _IR_S_symbol_definition;
} _IR_symbol_definition;

struct _IR_S_token_definition
{
  struct _IR_S_symbol_definition _IR_M_symbol_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_token_definition _IR_S_token_definition;
} _IR_token_definition;

struct _IR_S_left_definition
{
  struct _IR_S_symbol_definition _IR_M_symbol_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_left_definition _IR_S_left_definition;
} _IR_left_definition;

struct _IR_S_right_definition
{
  struct _IR_S_symbol_definition _IR_M_symbol_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_right_definition _IR_S_right_definition;
} _IR_right_definition;

struct _IR_S_nonassoc_definition
{
  struct _IR_S_symbol_definition _IR_M_symbol_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_nonassoc_definition _IR_S_nonassoc_definition;
} _IR_nonassoc_definition;

struct _IR_S_type_definition
{
  struct _IR_S_symbol_definition _IR_M_symbol_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_type_definition _IR_S_type_definition;
} _IR_type_definition;

struct _IR_S_symbol
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  identifier_or_literal;
  IR_node_t  number;
  IR_node_t  next_symbol;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_symbol _IR_S_symbol;
} _IR_symbol;

struct _IR_S_rule
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  nonterm_identifier;
  IR_node_t  pattern;
  IR_node_t  next_rule;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_rule _IR_S_rule;
} _IR_rule;

struct _IR_S_pattern
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  alternatives_list;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_pattern _IR_S_pattern;
} _IR_pattern;

struct _IR_S_denotation
{
  IR_node_t  corresponding_single_nonterm_definition;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_denotation _IR_S_denotation;
} _IR_denotation;

struct _IR_S_alternative
{
  struct _IR_S_node _IR_M_node;
  struct _IR_S_denotation _IR_M_denotation;
  IR_node_t  next_alternative;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_alternative _IR_S_alternative;
} _IR_alternative;

struct _IR_S_sequence
{
  struct _IR_S_alternative _IR_M_alternative;
  IR_node_t  sequence;
  IR_node_t  precedence_identifier_or_literal;
  IR_node_t  max_look_ahead_number;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_sequence _IR_S_sequence;
} _IR_sequence;

struct _IR_S_separator_iteration
{
  struct _IR_S_alternative _IR_M_alternative;
  IR_node_t  iteration_sequence;
  IR_node_t  iteration_precedence_identifier_or_literal;
  IR_node_t  iteration_max_look_ahead_number;
  IR_node_t  separator_sequence;
  IR_node_t  separator_precedence_identifier_or_literal;
  IR_node_t  separator_max_look_ahead_number;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_separator_iteration _IR_S_separator_iteration;
} _IR_separator_iteration;

struct _IR_S_sequence_element
{
  struct _IR_S_node _IR_M_node;
  struct _IR_S_denotation _IR_M_denotation;
  IR_node_t  next_sequence_element;
  IR_node_t  sequence_element_identifier;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_sequence_element _IR_S_sequence_element;
} _IR_sequence_element;

struct _IR_S_control_point
{
  struct _IR_S_sequence_element _IR_M_sequence_element;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_control_point _IR_S_control_point;
} _IR_control_point;

struct _IR_S_default
{
  struct _IR_S_sequence_element _IR_M_sequence_element;
  IR_node_t  default_pattern;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_default _IR_S_default;
} _IR_default;

struct _IR_S_star_iteration
{
  struct _IR_S_sequence_element _IR_M_sequence_element;
  IR_node_t  iteration_unit;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_star_iteration _IR_S_star_iteration;
} _IR_star_iteration;

struct _IR_S_plus_iteration
{
  struct _IR_S_sequence_element _IR_M_sequence_element;
  IR_node_t  iteration_unit;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_plus_iteration _IR_S_plus_iteration;
} _IR_plus_iteration;

struct _IR_S_code_insertion_atom
{
  struct _IR_S_sequence_element _IR_M_sequence_element;
  IR_node_t  code_insertion;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_code_insertion_atom _IR_S_code_insertion_atom;
} _IR_code_insertion_atom;

struct _IR_S_unit
{
  struct _IR_S_sequence_element _IR_M_sequence_element;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_unit _IR_S_unit;
} _IR_unit;

struct _IR_S_group
{
  struct _IR_S_unit _IR_M_unit;
  IR_node_t  pattern;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_group _IR_S_group;
} _IR_group;

struct _IR_S_range_atom
{
  struct _IR_S_unit _IR_M_unit;
  IR_node_t  left_bound;
  IR_node_t  right_bound;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_range_atom _IR_S_range_atom;
} _IR_range_atom;

struct _IR_S_range_no_left_bound_atom
{
  struct _IR_S_range_atom _IR_M_range_atom;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_range_no_left_bound_atom _IR_S_range_no_left_bound_atom;
} _IR_range_no_left_bound_atom;

struct _IR_S_range_no_right_bound_atom
{
  struct _IR_S_range_atom _IR_M_range_atom;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_range_no_right_bound_atom _IR_S_range_no_right_bound_atom;
} _IR_range_no_right_bound_atom;

struct _IR_S_range_no_left_right_bounds_atom
{
  struct _IR_S_range_atom _IR_M_range_atom;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_range_no_left_right_bounds_atom _IR_S_range_no_left_right_bounds_atom;
} _IR_range_no_left_right_bounds_atom;

struct _IR_S_identifier_or_literal_atom
{
  struct _IR_S_unit _IR_M_unit;
  IR_node_t  identifier_or_literal;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_identifier_or_literal_atom _IR_S_identifier_or_literal_atom;
} _IR_identifier_or_literal_atom;

struct _IR_S_string_atom
{
  struct _IR_S_unit _IR_M_unit;
  IR_node_t  string;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_string_atom _IR_S_string_atom;
} _IR_string_atom;

struct _IR_S_description
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  definition_list;
  IR_node_t  rule_list;
  IR_node_t  additional_code;
  IR_node_t  union_code;
  IR_node_t  single_definition_list;
  integer_t  tokens_number;
  integer_t  nonterminals_number;
  integer_t  canonical_rules_number;
  integer_t  duplicated_patterns_number;
  IR_node_t  canonical_rule_list;
  IR_node_t  axiom_identifier;
  IR_node_t  axiom_definition;
  bool_t  scanner_flag;
  integer_t  expected_shift_reduce_conflicts_number;
  IR_node_t  LR_core_list;
  integer_t  splitted_LR_sets_number;
  integer_t  LR_sets_number;
  integer_t  pushed_LR_sets_number;
  integer_t  reduces_number;
  integer_t  all_number_of_regular_arcs;
  integer_t  number_of_regular_arcs;
  integer_t  token_equivalence_classes_number;
  integer_t  duplicated_actions;
  bool_t  back_tracking_exists;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_description _IR_S_description;
} _IR_description;

struct _IR_S_single_definition
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  type;
  bool_t  accessibility_flag;
  IR_node_t  single_definition_usage_list;
  IR_node_t  identifier_or_literal;
  IR_node_t  next_single_definition;
  IR_node_t  last_symbol_LR_situation_processed;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_single_definition _IR_S_single_definition;
} _IR_single_definition;

struct _IR_S_single_term_definition
{
  struct _IR_S_single_definition _IR_M_single_definition;
  integer_t  token_order_number;
  integer_t  value;
  integer_t  priority;
  bool_t  left_assoc_flag;
  bool_t  right_assoc_flag;
  bool_t  nonassoc_flag;
  bool_t  deletion_flag;
  IR_node_t  next_equivalence_class_token;
  integer_t  equivalence_class_number;
  bool_t  token_was_processed_on_equivalence;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_single_term_definition _IR_S_single_term_definition;
} _IR_single_term_definition;

struct _IR_S_literal_range_definition
{
  struct _IR_S_single_term_definition _IR_M_single_term_definition;
  integer_t  right_range_bound_value;
  bool_t  bounds_have_explicit_values;
  IR_node_t  right_range_bound_literal;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_literal_range_definition _IR_S_literal_range_definition;
} _IR_literal_range_definition;

struct _IR_S_single_nonterm_definition
{
  struct _IR_S_single_definition _IR_M_single_definition;
  integer_t  nonterm_order_number;
  IR_node_t  nonterm_canonical_rule_list;
  bool_t  derivation_ability_flag;
  integer_t  pass_number;
  IR_node_t  corresponding_pattern;
  integer_t  minimal_derived_string_length;
  context_t  relation_FIRST;
  context_t  next_iter_relation_FIRST;
  bool_t  process_nonterminal_on_its_process_pass;
  bool_t  pattern_has_been_output;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_single_nonterm_definition _IR_S_single_nonterm_definition;
} _IR_single_nonterm_definition;

struct _IR_S_canonical_rule
{
  struct _IR_S_node _IR_M_node;
  bool_t  next_cp_flag;
  integer_t  canonical_rule_order_number;
  IR_node_t  next_nonterm_canonical_rule;
  IR_node_t  precedence_single_term_definition;
  integer_t  rule_priority;
  integer_t  max_look_ahead_value;
  integer_t  output_action_number;
  IR_node_t  left_hand_side;
  IR_node_t  right_hand_side;
  IR_node_t  action;
  IR_node_t  original_code_insertion_place;
  IR_node_t  next_canonical_rule;
  IR_node_t  canonical_rule_LR_situation;
  bool_t  canonical_rule_action_has_been_output;
  integer_t  action_code_copies_number;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_canonical_rule _IR_S_canonical_rule;
} _IR_canonical_rule;

struct _IR_S_right_hand_side_element
{
  struct _IR_S_node _IR_M_node;
  IR_node_t  canonical_rule;
  IR_node_t  next_right_hand_side_element;
  bool_t  cp_start_flag;
  bool_t  cp_flag;
  integer_t  minimal_FIRST_of_rule_tail_length;
  context_t  FIRST_of_rule_tail;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_right_hand_side_element _IR_S_right_hand_side_element;
} _IR_right_hand_side_element;

struct _IR_S_canonical_rule_element
{
  struct _IR_S_right_hand_side_element _IR_M_right_hand_side_element;
  bool_t  next_cp_flag;
  IR_node_t  element_itself;
  IR_node_t  element_identifier;
  IR_node_t  next_single_definition_usage;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_canonical_rule_element _IR_S_canonical_rule_element;
} _IR_canonical_rule_element;

struct _IR_S_canonical_rule_end
{
  struct _IR_S_right_hand_side_element _IR_M_right_hand_side_element;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_canonical_rule_end _IR_S_canonical_rule_end;
} _IR_canonical_rule_end;

struct _IR_S_LR_situation
{
  struct _IR_double_link  goto_LR_set;
  bool_t  goto_arc_has_been_removed;
  context_t  look_ahead_context;
  bool_t  first_symbol_LR_situation;
  IR_node_t  next_symbol_LR_situation;
  bool_t  important_LR_situation_flag;
  bool_t  situation_in_stack_flag;
  bool_t  under_control_point_flag;
  bool_t  back_tracking_conflict_flag;
  IR_node_t  corresponding_regular_arc;
  integer_t  reduce_number;
  integer_t  popped_LR_sets_number;
  integer_t  popped_attributes_number;
  IR_node_t  element_after_dot;
  context_t  context;
  IR_node_t  LR_set;
  IR_node_t  next_LR_situation;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_LR_situation _IR_S_LR_situation;
} _IR_LR_situation;

struct _IR_S_LR_set
{
  IR_node_t  conflicts_list;
  bool_t  it_is_in_LALR_sets_stack;
  bool_t  reachable_flag;
  bool_t  it_is_pushed_LR_set;
  bool_t  it_is_errored_LR_set;
  bool_t  attribute_is_used;
  bool_t  visit_flag;
  IR_node_t  first_splitted_LR_set;
  IR_node_t  next_splitted_LR_set;
  bool_t  back_tracking_flag;
  bool_t  it_is_in_reduce_action_LR_sets_stack;
  IR_node_t  LR_set_look_ahead_trie;
  integer_t  LR_set_order_number;
  integer_t  term_arcs_number;
  integer_t  nonterm_arcs_number;
  IR_node_t  start_LR_set_pass;
  bool_t  LR_set_has_been_output_in_comment;
  IR_node_t  LR_situation_list;
  IR_node_t  LR_core;
  IR_node_t  next_LR_set;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_LR_set _IR_S_LR_set;
} _IR_LR_set;

struct _IR_S_LR_set_look_ahead_trie_node
{
  IR_node_t  first_back_track_alternative;
  IR_node_t  last_back_track_alternative;
  integer_t  additional_action_table_number;
  IR_node_t  corresponding_single_term_definition;
  IR_node_t  corresponding_LR_situation;
  IR_node_t  first_son;
  IR_node_t  next_brother;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_LR_set_look_ahead_trie_node _IR_S_LR_set_look_ahead_trie_node;
} _IR_LR_set_look_ahead_trie_node;

struct _IR_S_back_track_alternative
{
  IR_node_t  corresponding_LR_set_look_ahead_trie_node;
  IR_node_t  next_back_track_alternative;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_back_track_alternative _IR_S_back_track_alternative;
} _IR_back_track_alternative;

struct _IR_S_conflict
{
  IR_node_t  used_LR_situation;
  IR_node_t  unused_LR_situation;
  token_string_t  token_string;
  IR_node_t  next_conflict;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_conflict _IR_S_conflict;
} _IR_conflict;

struct _IR_S_regular_arc
{
  IR_node_t  first_rule_list_element;
  IR_node_t  last_rule_list_element;
  integer_t  regular_arc_popped_LR_sets_number;
  integer_t  regular_arc_popped_attributes_number;
  integer_t  max_states_stack_increment;
  integer_t  max_attributes_stack_increment;
  bool_t  first_equivalent_regular_arc_flag;
  IR_node_t  next_equivalent_regular_arc;
  integer_t  number_of_regular_arc;
  bool_t  result_LR_set_will_be_on_the_stack;
  IR_node_t  from_LR_situation;
  struct _IR_double_link  to_LR_set;
  IR_node_t  terminal_marking_arc;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_regular_arc _IR_S_regular_arc;
} _IR_regular_arc;

struct _IR_S_rule_list_element
{
  integer_t  right_hand_side_used_attributes_number;
  bool_t  lhs_nonterm_attribute_is_used;
  bool_t  result_LR_set_will_be_on_the_stack;
  IR_node_t  canonical_rule;
  IR_node_t  next_rule_list_element;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_rule_list_element _IR_S_rule_list_element;
} _IR_rule_list_element;

struct _IR_S_LR_core
{
  bool_t  first_pass_flag;
  bool_t  second_pass_flag;
  IR_node_t  LR_set_list;
  IR_node_t  next_LR_core;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_LR_core _IR_S_LR_core;
} _IR_LR_core;

struct _IR_S_DeRemer_dependence
{
  context_t  context;
  IR_node_t  dependencies;
  bool_t  context_has_been_evaluated;
  integer_t  pass_number;
  integer_t  unique_number;
  integer_t  look_ahead;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_DeRemer_dependence _IR_S_DeRemer_dependence;
} _IR_DeRemer_dependence;

struct _IR_S_LR_set_dependence
{
  struct _IR_S_DeRemer_dependence _IR_M_DeRemer_dependence;
  IR_node_t  LR_set;
  integer_t  back_distance;
  IR_node_t  nonterm;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_LR_set_dependence _IR_S_LR_set_dependence;
} _IR_LR_set_dependence;

struct _IR_S_shift_dependence
{
  struct _IR_S_DeRemer_dependence _IR_M_DeRemer_dependence;
  IR_node_t  token;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_shift_dependence _IR_S_shift_dependence;
} _IR_shift_dependence;

struct _IR_S_shift_LR_situation_dependence
{
  struct _IR_S_shift_dependence _IR_M_shift_dependence;
  IR_node_t  shift_LR_situation;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_shift_LR_situation_dependence _IR_S_shift_LR_situation_dependence;
} _IR_shift_LR_situation_dependence;

struct _IR_S_dependence_list_element
{
  IR_node_t  dependence;
  IR_node_t  next_dependence_list_element;
};

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
  struct _IR_S_dependence_list_element _IR_S_dependence_list_element;
} _IR_dependence_list_element;

typedef struct IR_node
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
} _IR__root;

typedef struct
{
  IR_node_mode_t _IR_node_mode;
  IR_double_link_t _IR_first_link;
} _IR__error;

#define IR_NODE_MODE(t) ((t)->_IR_node_mode)

extern const char *IR_node_name[];

extern unsigned char IR_node_size[];

#define IR_NODE_LEVEL(node) _IR_node_level [IR_NODE_MODE (node)]

#define IR_IS_TYPE(type, super) ((_IR_is_type [super] [type /8] >> (type % 8)) & 1)

#define IR_IS_OF_TYPE(node, super)IR_IS_TYPE (IR_NODE_MODE (node), super)

extern void _IR_set_double_field_value
  (IR_double_link_t link, IR_node_t value, int disp, int flag);

extern IR_double_link_t IR__first_double_link (IR_node_t node);

#define IR__next_double_link(prev_double_link) ((prev_double_link)->next_link)

#define IR__previous_double_link(next_double_link) ((next_double_link)->previous_link)

#define IR__owner(link) ((link)->link_owner)

#define IR_position(_node) (((_IR_node *) (_node))->_IR_S_node.position)

#define IR_identifier_itself(_node) (((_IR_identifier *) (_node))->_IR_S_identifier.identifier_itself)

#define IR_dot_presence_flag(_node) (((_IR_identifier *) (_node))->_IR_S_identifier.dot_presence_flag)

#define IR_character_representation(_node) (((_IR_literal *) (_node))->_IR_S_literal.character_representation)

#define IR_literal_code(_node) (((_IR_literal *) (_node))->_IR_S_literal.literal_code)

#define IR_string_representation(_node) (((_IR_string *) (_node))->_IR_S_string.string_representation)

#define IR_string_itself(_node) (((_IR_string *) (_node))->_IR_S_string.string_itself)

#define IR_number_value(_node) (((_IR_number *) (_node))->_IR_S_number.number_value)

#define IR_code_insertion_itself(_node) (((_IR_code_insertion *) (_node))->_IR_S_code_insertion.code_insertion_itself)

#define IR_additional_code_itself(_node) (((_IR_additional_code *) (_node))->_IR_S_additional_code.additional_code_itself)

#define IR_next_definition(_node) (((_IR_definition *) (_node))->_IR_S_definition.next_definition)

#define IR_identifier(_node) (((_IR_start_definition *) (_node))->_IR_S_start_definition.identifier)

#define IR_code_itself(_node) (((_IR_code *) (_node))->_IR_S_code.code_itself)

#define IR_expected_number(_node) (((_IR_expect_definition *) (_node))->_IR_S_expect_definition.expected_number)

#define IR_symbol_list(_node) (((_IR_symbol_definition *) (_node))->_IR_S_symbol_definition.symbol_list)

#define IR_tag(_node) (((_IR_symbol_definition *) (_node))->_IR_S_symbol_definition.tag)

#define IR_identifier_or_literal(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_identifier_or_literal [IR_NODE_MODE ((_node))]))

#define IR_number(_node) (((_IR_symbol *) (_node))->_IR_S_symbol.number)

#define IR_next_symbol(_node) (((_IR_symbol *) (_node))->_IR_S_symbol.next_symbol)

#define IR_nonterm_identifier(_node) (((_IR_rule *) (_node))->_IR_S_rule.nonterm_identifier)

#define IR_pattern(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_pattern [IR_NODE_MODE ((_node))]))

#define IR_next_rule(_node) (((_IR_rule *) (_node))->_IR_S_rule.next_rule)

#define IR_alternatives_list(_node) (((_IR_pattern *) (_node))->_IR_S_pattern.alternatives_list)

#define IR_next_alternative(_node) (((_IR_alternative *) (_node))->_IR_S_alternative.next_alternative)

#define IR_sequence(_node) (((_IR_sequence *) (_node))->_IR_S_sequence.sequence)

#define IR_precedence_identifier_or_literal(_node) (((_IR_sequence *) (_node))->_IR_S_sequence.precedence_identifier_or_literal)

#define IR_max_look_ahead_number(_node) (((_IR_sequence *) (_node))->_IR_S_sequence.max_look_ahead_number)

#define IR_iteration_sequence(_node) (((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.iteration_sequence)

#define IR_iteration_precedence_identifier_or_literal(_node) (((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.iteration_precedence_identifier_or_literal)

#define IR_iteration_max_look_ahead_number(_node) (((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.iteration_max_look_ahead_number)

#define IR_separator_sequence(_node) (((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.separator_sequence)

#define IR_separator_precedence_identifier_or_literal(_node) (((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.separator_precedence_identifier_or_literal)

#define IR_separator_max_look_ahead_number(_node) (((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.separator_max_look_ahead_number)

#define IR_next_sequence_element(_node) (((_IR_sequence_element *) (_node))->_IR_S_sequence_element.next_sequence_element)

#define IR_sequence_element_identifier(_node) (((_IR_sequence_element *) (_node))->_IR_S_sequence_element.sequence_element_identifier)

#define IR_default_pattern(_node) (((_IR_default *) (_node))->_IR_S_default.default_pattern)

#define IR_iteration_unit(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_iteration_unit [IR_NODE_MODE ((_node))]))

#define IR_code_insertion(_node) (((_IR_code_insertion_atom *) (_node))->_IR_S_code_insertion_atom.code_insertion)

#define IR_left_bound(_node) (((_IR_range_atom *) (_node))->_IR_S_range_atom.left_bound)

#define IR_right_bound(_node) (((_IR_range_atom *) (_node))->_IR_S_range_atom.right_bound)

#define IR_string(_node) (((_IR_string_atom *) (_node))->_IR_S_string_atom.string)

#define IR_definition_list(_node) (((_IR_description *) (_node))->_IR_S_description.definition_list)

#define IR_rule_list(_node) (((_IR_description *) (_node))->_IR_S_description.rule_list)

#define IR_additional_code(_node) (((_IR_description *) (_node))->_IR_S_description.additional_code)

#define IR_union_code(_node) (((_IR_description *) (_node))->_IR_S_description.union_code)

#define IR_single_definition_list(_node) (((_IR_description *) (_node))->_IR_S_description.single_definition_list)

#define IR_tokens_number(_node) (((_IR_description *) (_node))->_IR_S_description.tokens_number)

#define IR_nonterminals_number(_node) (((_IR_description *) (_node))->_IR_S_description.nonterminals_number)

#define IR_canonical_rules_number(_node) (((_IR_description *) (_node))->_IR_S_description.canonical_rules_number)

#define IR_duplicated_patterns_number(_node) (((_IR_description *) (_node))->_IR_S_description.duplicated_patterns_number)

#define IR_canonical_rule_list(_node) (((_IR_description *) (_node))->_IR_S_description.canonical_rule_list)

#define IR_axiom_identifier(_node) (((_IR_description *) (_node))->_IR_S_description.axiom_identifier)

#define IR_axiom_definition(_node) (((_IR_description *) (_node))->_IR_S_description.axiom_definition)

#define IR_scanner_flag(_node) (((_IR_description *) (_node))->_IR_S_description.scanner_flag)

#define IR_expected_shift_reduce_conflicts_number(_node) (((_IR_description *) (_node))->_IR_S_description.expected_shift_reduce_conflicts_number)

#define IR_LR_core_list(_node) (((_IR_description *) (_node))->_IR_S_description.LR_core_list)

#define IR_splitted_LR_sets_number(_node) (((_IR_description *) (_node))->_IR_S_description.splitted_LR_sets_number)

#define IR_LR_sets_number(_node) (((_IR_description *) (_node))->_IR_S_description.LR_sets_number)

#define IR_pushed_LR_sets_number(_node) (((_IR_description *) (_node))->_IR_S_description.pushed_LR_sets_number)

#define IR_reduces_number(_node) (((_IR_description *) (_node))->_IR_S_description.reduces_number)

#define IR_all_number_of_regular_arcs(_node) (((_IR_description *) (_node))->_IR_S_description.all_number_of_regular_arcs)

#define IR_number_of_regular_arcs(_node) (((_IR_description *) (_node))->_IR_S_description.number_of_regular_arcs)

#define IR_token_equivalence_classes_number(_node) (((_IR_description *) (_node))->_IR_S_description.token_equivalence_classes_number)

#define IR_duplicated_actions(_node) (((_IR_description *) (_node))->_IR_S_description.duplicated_actions)

#define IR_back_tracking_exists(_node) (((_IR_description *) (_node))->_IR_S_description.back_tracking_exists)

#define IR_corresponding_single_nonterm_definition(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_corresponding_single_nonterm_definition [IR_NODE_MODE ((_node))]))

#define IR_type(_node) (((_IR_single_definition *) (_node))->_IR_S_single_definition.type)

#define IR_accessibility_flag(_node) (((_IR_single_definition *) (_node))->_IR_S_single_definition.accessibility_flag)

#define IR_single_definition_usage_list(_node) (((_IR_single_definition *) (_node))->_IR_S_single_definition.single_definition_usage_list)

#define IR_next_single_definition(_node) (((_IR_single_definition *) (_node))->_IR_S_single_definition.next_single_definition)

#define IR_last_symbol_LR_situation_processed(_node) (((_IR_single_definition *) (_node))->_IR_S_single_definition.last_symbol_LR_situation_processed)

#define IR_token_order_number(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.token_order_number)

#define IR_value(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.value)

#define IR_priority(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.priority)

#define IR_left_assoc_flag(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.left_assoc_flag)

#define IR_right_assoc_flag(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.right_assoc_flag)

#define IR_nonassoc_flag(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.nonassoc_flag)

#define IR_deletion_flag(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.deletion_flag)

#define IR_next_equivalence_class_token(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.next_equivalence_class_token)

#define IR_equivalence_class_number(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.equivalence_class_number)

#define IR_token_was_processed_on_equivalence(_node) (((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.token_was_processed_on_equivalence)

#define IR_right_range_bound_value(_node) (((_IR_literal_range_definition *) (_node))->_IR_S_literal_range_definition.right_range_bound_value)

#define IR_bounds_have_explicit_values(_node) (((_IR_literal_range_definition *) (_node))->_IR_S_literal_range_definition.bounds_have_explicit_values)

#define IR_right_range_bound_literal(_node) (((_IR_literal_range_definition *) (_node))->_IR_S_literal_range_definition.right_range_bound_literal)

#define IR_nonterm_order_number(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.nonterm_order_number)

#define IR_nonterm_canonical_rule_list(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.nonterm_canonical_rule_list)

#define IR_derivation_ability_flag(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.derivation_ability_flag)

#define IR_pass_number(_node) (*(integer_t *) ((char *) (_node) + _IR_D_pass_number [IR_NODE_MODE ((_node))]))

#define IR_corresponding_pattern(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.corresponding_pattern)

#define IR_minimal_derived_string_length(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.minimal_derived_string_length)

#define IR_relation_FIRST(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.relation_FIRST)

#define IR_next_iter_relation_FIRST(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.next_iter_relation_FIRST)

#define IR_process_nonterminal_on_its_process_pass(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.process_nonterminal_on_its_process_pass)

#define IR_pattern_has_been_output(_node) (((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.pattern_has_been_output)

#define IR_next_cp_flag(_node) (*(bool_t *) ((char *) (_node) + _IR_D_next_cp_flag [IR_NODE_MODE ((_node))]))

#define IR_canonical_rule_order_number(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.canonical_rule_order_number)

#define IR_next_nonterm_canonical_rule(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.next_nonterm_canonical_rule)

#define IR_precedence_single_term_definition(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.precedence_single_term_definition)

#define IR_rule_priority(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.rule_priority)

#define IR_max_look_ahead_value(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.max_look_ahead_value)

#define IR_output_action_number(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.output_action_number)

#define IR_left_hand_side(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.left_hand_side)

#define IR_right_hand_side(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.right_hand_side)

#define IR_action(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.action)

#define IR_original_code_insertion_place(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.original_code_insertion_place)

#define IR_next_canonical_rule(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.next_canonical_rule)

#define IR_canonical_rule_LR_situation(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.canonical_rule_LR_situation)

#define IR_canonical_rule_action_has_been_output(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.canonical_rule_action_has_been_output)

#define IR_action_code_copies_number(_node) (((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.action_code_copies_number)

#define IR_canonical_rule(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_canonical_rule [IR_NODE_MODE ((_node))]))

#define IR_next_right_hand_side_element(_node) (((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.next_right_hand_side_element)

#define IR_cp_start_flag(_node) (((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.cp_start_flag)

#define IR_cp_flag(_node) (((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.cp_flag)

#define IR_minimal_FIRST_of_rule_tail_length(_node) (((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.minimal_FIRST_of_rule_tail_length)

#define IR_FIRST_of_rule_tail(_node) (((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.FIRST_of_rule_tail)

#define IR_element_itself(_node) (((_IR_canonical_rule_element *) (_node))->_IR_S_canonical_rule_element.element_itself)

#define IR_element_identifier(_node) (((_IR_canonical_rule_element *) (_node))->_IR_S_canonical_rule_element.element_identifier)

#define IR_next_single_definition_usage(_node) (((_IR_canonical_rule_element *) (_node))->_IR_S_canonical_rule_element.next_single_definition_usage)

#define IR_goto_LR_set(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.goto_LR_set).field_itself

#define IR_goto_arc_has_been_removed(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.goto_arc_has_been_removed)

#define IR_look_ahead_context(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.look_ahead_context)

#define IR_first_symbol_LR_situation(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.first_symbol_LR_situation)

#define IR_next_symbol_LR_situation(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.next_symbol_LR_situation)

#define IR_important_LR_situation_flag(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.important_LR_situation_flag)

#define IR_situation_in_stack_flag(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.situation_in_stack_flag)

#define IR_under_control_point_flag(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.under_control_point_flag)

#define IR_back_tracking_conflict_flag(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.back_tracking_conflict_flag)

#define IR_corresponding_regular_arc(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.corresponding_regular_arc)

#define IR_reduce_number(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.reduce_number)

#define IR_popped_LR_sets_number(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.popped_LR_sets_number)

#define IR_popped_attributes_number(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.popped_attributes_number)

#define IR_element_after_dot(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.element_after_dot)

#define IR_context(_node) (*(context_t *) ((char *) (_node) + _IR_D_context [IR_NODE_MODE ((_node))]))

#define IR_LR_set(_node) (*(IR_node_t *) ((char *) (_node) + _IR_D_LR_set [IR_NODE_MODE ((_node))]))

#define IR_next_LR_situation(_node) (((_IR_LR_situation *) (_node))->_IR_S_LR_situation.next_LR_situation)

#define IR_conflicts_list(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.conflicts_list)

#define IR_it_is_in_LALR_sets_stack(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_in_LALR_sets_stack)

#define IR_reachable_flag(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.reachable_flag)

#define IR_it_is_pushed_LR_set(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_pushed_LR_set)

#define IR_it_is_errored_LR_set(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_errored_LR_set)

#define IR_attribute_is_used(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.attribute_is_used)

#define IR_visit_flag(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.visit_flag)

#define IR_first_splitted_LR_set(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.first_splitted_LR_set)

#define IR_next_splitted_LR_set(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.next_splitted_LR_set)

#define IR_back_tracking_flag(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.back_tracking_flag)

#define IR_it_is_in_reduce_action_LR_sets_stack(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_in_reduce_action_LR_sets_stack)

#define IR_LR_set_look_ahead_trie(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_set_look_ahead_trie)

#define IR_LR_set_order_number(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_set_order_number)

#define IR_term_arcs_number(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.term_arcs_number)

#define IR_nonterm_arcs_number(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.nonterm_arcs_number)

#define IR_start_LR_set_pass(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.start_LR_set_pass)

#define IR_LR_set_has_been_output_in_comment(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_set_has_been_output_in_comment)

#define IR_LR_situation_list(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_situation_list)

#define IR_LR_core(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_core)

#define IR_next_LR_set(_node) (((_IR_LR_set *) (_node))->_IR_S_LR_set.next_LR_set)

#define IR_first_back_track_alternative(_node) (((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.first_back_track_alternative)

#define IR_last_back_track_alternative(_node) (((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.last_back_track_alternative)

#define IR_additional_action_table_number(_node) (((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.additional_action_table_number)

#define IR_corresponding_single_term_definition(_node) (((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.corresponding_single_term_definition)

#define IR_corresponding_LR_situation(_node) (((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.corresponding_LR_situation)

#define IR_first_son(_node) (((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.first_son)

#define IR_next_brother(_node) (((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.next_brother)

#define IR_corresponding_LR_set_look_ahead_trie_node(_node) (((_IR_back_track_alternative *) (_node))->_IR_S_back_track_alternative.corresponding_LR_set_look_ahead_trie_node)

#define IR_next_back_track_alternative(_node) (((_IR_back_track_alternative *) (_node))->_IR_S_back_track_alternative.next_back_track_alternative)

#define IR_used_LR_situation(_node) (((_IR_conflict *) (_node))->_IR_S_conflict.used_LR_situation)

#define IR_unused_LR_situation(_node) (((_IR_conflict *) (_node))->_IR_S_conflict.unused_LR_situation)

#define IR_token_string(_node) (((_IR_conflict *) (_node))->_IR_S_conflict.token_string)

#define IR_next_conflict(_node) (((_IR_conflict *) (_node))->_IR_S_conflict.next_conflict)

#define IR_first_rule_list_element(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.first_rule_list_element)

#define IR_last_rule_list_element(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.last_rule_list_element)

#define IR_regular_arc_popped_LR_sets_number(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.regular_arc_popped_LR_sets_number)

#define IR_regular_arc_popped_attributes_number(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.regular_arc_popped_attributes_number)

#define IR_max_states_stack_increment(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.max_states_stack_increment)

#define IR_max_attributes_stack_increment(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.max_attributes_stack_increment)

#define IR_first_equivalent_regular_arc_flag(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.first_equivalent_regular_arc_flag)

#define IR_next_equivalent_regular_arc(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.next_equivalent_regular_arc)

#define IR_number_of_regular_arc(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.number_of_regular_arc)

#define IR_result_LR_set_will_be_on_the_stack(_node) (*(bool_t *) ((char *) (_node) + _IR_D_result_LR_set_will_be_on_the_stack [IR_NODE_MODE ((_node))]))

#define IR_from_LR_situation(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.from_LR_situation)

#define IR_to_LR_set(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.to_LR_set).field_itself

#define IR_terminal_marking_arc(_node) (((_IR_regular_arc *) (_node))->_IR_S_regular_arc.terminal_marking_arc)

#define IR_right_hand_side_used_attributes_number(_node) (((_IR_rule_list_element *) (_node))->_IR_S_rule_list_element.right_hand_side_used_attributes_number)

#define IR_lhs_nonterm_attribute_is_used(_node) (((_IR_rule_list_element *) (_node))->_IR_S_rule_list_element.lhs_nonterm_attribute_is_used)

#define IR_next_rule_list_element(_node) (((_IR_rule_list_element *) (_node))->_IR_S_rule_list_element.next_rule_list_element)

#define IR_first_pass_flag(_node) (((_IR_LR_core *) (_node))->_IR_S_LR_core.first_pass_flag)

#define IR_second_pass_flag(_node) (((_IR_LR_core *) (_node))->_IR_S_LR_core.second_pass_flag)

#define IR_LR_set_list(_node) (((_IR_LR_core *) (_node))->_IR_S_LR_core.LR_set_list)

#define IR_next_LR_core(_node) (((_IR_LR_core *) (_node))->_IR_S_LR_core.next_LR_core)

#define IR_dependencies(_node) (((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.dependencies)

#define IR_context_has_been_evaluated(_node) (((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.context_has_been_evaluated)

#define IR_unique_number(_node) (((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.unique_number)

#define IR_look_ahead(_node) (((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.look_ahead)

#define IR_back_distance(_node) (((_IR_LR_set_dependence *) (_node))->_IR_S_LR_set_dependence.back_distance)

#define IR_nonterm(_node) (((_IR_LR_set_dependence *) (_node))->_IR_S_LR_set_dependence.nonterm)

#define IR_token(_node) (((_IR_shift_dependence *) (_node))->_IR_S_shift_dependence.token)

#define IR_shift_LR_situation(_node) (((_IR_shift_LR_situation_dependence *) (_node))->_IR_S_shift_LR_situation_dependence.shift_LR_situation)

#define IR_dependence(_node) (((_IR_dependence_list_element *) (_node))->_IR_S_dependence_list_element.dependence)

#define IR_next_dependence_list_element(_node) (((_IR_dependence_list_element *) (_node))->_IR_S_dependence_list_element.next_dependence_list_element)

extern void IR__set_double_link (IR_double_link_t link, IR_node_t value);

extern void IR_F_set_goto_LR_set (IR_node_t _node, IR_node_t _value);

extern void IR_F_set_to_LR_set (IR_node_t _node, IR_node_t _value);

#define IR_set_position(_node, _value) ((((_IR_node *) (_node))->_IR_S_node.position) = (_value))

#define IR_set_identifier_itself(_node, _value) ((((_IR_identifier *) (_node))->_IR_S_identifier.identifier_itself) = (_value))

#define IR_set_dot_presence_flag(_node, _value) ((((_IR_identifier *) (_node))->_IR_S_identifier.dot_presence_flag) = (_value))

#define IR_set_character_representation(_node, _value) ((((_IR_literal *) (_node))->_IR_S_literal.character_representation) = (_value))

#define IR_set_literal_code(_node, _value) ((((_IR_literal *) (_node))->_IR_S_literal.literal_code) = (_value))

#define IR_set_string_representation(_node, _value) ((((_IR_string *) (_node))->_IR_S_string.string_representation) = (_value))

#define IR_set_string_itself(_node, _value) ((((_IR_string *) (_node))->_IR_S_string.string_itself) = (_value))

#define IR_set_number_value(_node, _value) ((((_IR_number *) (_node))->_IR_S_number.number_value) = (_value))

#define IR_set_code_insertion_itself(_node, _value) ((((_IR_code_insertion *) (_node))->_IR_S_code_insertion.code_insertion_itself) = (_value))

#define IR_set_additional_code_itself(_node, _value) ((((_IR_additional_code *) (_node))->_IR_S_additional_code.additional_code_itself) = (_value))

#define IR_set_next_definition(_node, _value) ((((_IR_definition *) (_node))->_IR_S_definition.next_definition) = (_value))

#define IR_set_identifier(_node, _value) ((((_IR_start_definition *) (_node))->_IR_S_start_definition.identifier) = (_value))

#define IR_set_code_itself(_node, _value) ((((_IR_code *) (_node))->_IR_S_code.code_itself) = (_value))

#define IR_set_expected_number(_node, _value) ((((_IR_expect_definition *) (_node))->_IR_S_expect_definition.expected_number) = (_value))

#define IR_set_symbol_list(_node, _value) ((((_IR_symbol_definition *) (_node))->_IR_S_symbol_definition.symbol_list) = (_value))

#define IR_set_tag(_node, _value) ((((_IR_symbol_definition *) (_node))->_IR_S_symbol_definition.tag) = (_value))

#define IR_set_identifier_or_literal(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_identifier_or_literal [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_number(_node, _value) ((((_IR_symbol *) (_node))->_IR_S_symbol.number) = (_value))

#define IR_set_next_symbol(_node, _value) ((((_IR_symbol *) (_node))->_IR_S_symbol.next_symbol) = (_value))

#define IR_set_nonterm_identifier(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.nonterm_identifier) = (_value))

#define IR_set_pattern(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_pattern [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_next_rule(_node, _value) ((((_IR_rule *) (_node))->_IR_S_rule.next_rule) = (_value))

#define IR_set_alternatives_list(_node, _value) ((((_IR_pattern *) (_node))->_IR_S_pattern.alternatives_list) = (_value))

#define IR_set_next_alternative(_node, _value) ((((_IR_alternative *) (_node))->_IR_S_alternative.next_alternative) = (_value))

#define IR_set_sequence(_node, _value) ((((_IR_sequence *) (_node))->_IR_S_sequence.sequence) = (_value))

#define IR_set_precedence_identifier_or_literal(_node, _value) ((((_IR_sequence *) (_node))->_IR_S_sequence.precedence_identifier_or_literal) = (_value))

#define IR_set_max_look_ahead_number(_node, _value) ((((_IR_sequence *) (_node))->_IR_S_sequence.max_look_ahead_number) = (_value))

#define IR_set_iteration_sequence(_node, _value) ((((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.iteration_sequence) = (_value))

#define IR_set_iteration_precedence_identifier_or_literal(_node, _value) ((((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.iteration_precedence_identifier_or_literal) = (_value))

#define IR_set_iteration_max_look_ahead_number(_node, _value) ((((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.iteration_max_look_ahead_number) = (_value))

#define IR_set_separator_sequence(_node, _value) ((((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.separator_sequence) = (_value))

#define IR_set_separator_precedence_identifier_or_literal(_node, _value) ((((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.separator_precedence_identifier_or_literal) = (_value))

#define IR_set_separator_max_look_ahead_number(_node, _value) ((((_IR_separator_iteration *) (_node))->_IR_S_separator_iteration.separator_max_look_ahead_number) = (_value))

#define IR_set_next_sequence_element(_node, _value) ((((_IR_sequence_element *) (_node))->_IR_S_sequence_element.next_sequence_element) = (_value))

#define IR_set_sequence_element_identifier(_node, _value) ((((_IR_sequence_element *) (_node))->_IR_S_sequence_element.sequence_element_identifier) = (_value))

#define IR_set_default_pattern(_node, _value) ((((_IR_default *) (_node))->_IR_S_default.default_pattern) = (_value))

#define IR_set_iteration_unit(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_iteration_unit [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_code_insertion(_node, _value) ((((_IR_code_insertion_atom *) (_node))->_IR_S_code_insertion_atom.code_insertion) = (_value))

#define IR_set_left_bound(_node, _value) ((((_IR_range_atom *) (_node))->_IR_S_range_atom.left_bound) = (_value))

#define IR_set_right_bound(_node, _value) ((((_IR_range_atom *) (_node))->_IR_S_range_atom.right_bound) = (_value))

#define IR_set_string(_node, _value) ((((_IR_string_atom *) (_node))->_IR_S_string_atom.string) = (_value))

#define IR_set_definition_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.definition_list) = (_value))

#define IR_set_rule_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.rule_list) = (_value))

#define IR_set_additional_code(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.additional_code) = (_value))

#define IR_set_union_code(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.union_code) = (_value))

#define IR_set_single_definition_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.single_definition_list) = (_value))

#define IR_set_tokens_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.tokens_number) = (_value))

#define IR_set_nonterminals_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.nonterminals_number) = (_value))

#define IR_set_canonical_rules_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.canonical_rules_number) = (_value))

#define IR_set_duplicated_patterns_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.duplicated_patterns_number) = (_value))

#define IR_set_canonical_rule_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.canonical_rule_list) = (_value))

#define IR_set_axiom_identifier(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.axiom_identifier) = (_value))

#define IR_set_axiom_definition(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.axiom_definition) = (_value))

#define IR_set_scanner_flag(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.scanner_flag) = (_value))

#define IR_set_expected_shift_reduce_conflicts_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.expected_shift_reduce_conflicts_number) = (_value))

#define IR_set_LR_core_list(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.LR_core_list) = (_value))

#define IR_set_splitted_LR_sets_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.splitted_LR_sets_number) = (_value))

#define IR_set_LR_sets_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.LR_sets_number) = (_value))

#define IR_set_pushed_LR_sets_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.pushed_LR_sets_number) = (_value))

#define IR_set_reduces_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.reduces_number) = (_value))

#define IR_set_all_number_of_regular_arcs(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.all_number_of_regular_arcs) = (_value))

#define IR_set_number_of_regular_arcs(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.number_of_regular_arcs) = (_value))

#define IR_set_token_equivalence_classes_number(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.token_equivalence_classes_number) = (_value))

#define IR_set_duplicated_actions(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.duplicated_actions) = (_value))

#define IR_set_back_tracking_exists(_node, _value) ((((_IR_description *) (_node))->_IR_S_description.back_tracking_exists) = (_value))

#define IR_set_corresponding_single_nonterm_definition(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_corresponding_single_nonterm_definition [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_type(_node, _value) ((((_IR_single_definition *) (_node))->_IR_S_single_definition.type) = (_value))

#define IR_set_accessibility_flag(_node, _value) ((((_IR_single_definition *) (_node))->_IR_S_single_definition.accessibility_flag) = (_value))

#define IR_set_single_definition_usage_list(_node, _value) ((((_IR_single_definition *) (_node))->_IR_S_single_definition.single_definition_usage_list) = (_value))

#define IR_set_next_single_definition(_node, _value) ((((_IR_single_definition *) (_node))->_IR_S_single_definition.next_single_definition) = (_value))

#define IR_set_last_symbol_LR_situation_processed(_node, _value) ((((_IR_single_definition *) (_node))->_IR_S_single_definition.last_symbol_LR_situation_processed) = (_value))

#define IR_set_token_order_number(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.token_order_number) = (_value))

#define IR_set_value(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.value) = (_value))

#define IR_set_priority(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.priority) = (_value))

#define IR_set_left_assoc_flag(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.left_assoc_flag) = (_value))

#define IR_set_right_assoc_flag(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.right_assoc_flag) = (_value))

#define IR_set_nonassoc_flag(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.nonassoc_flag) = (_value))

#define IR_set_deletion_flag(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.deletion_flag) = (_value))

#define IR_set_next_equivalence_class_token(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.next_equivalence_class_token) = (_value))

#define IR_set_equivalence_class_number(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.equivalence_class_number) = (_value))

#define IR_set_token_was_processed_on_equivalence(_node, _value) ((((_IR_single_term_definition *) (_node))->_IR_S_single_term_definition.token_was_processed_on_equivalence) = (_value))

#define IR_set_right_range_bound_value(_node, _value) ((((_IR_literal_range_definition *) (_node))->_IR_S_literal_range_definition.right_range_bound_value) = (_value))

#define IR_set_bounds_have_explicit_values(_node, _value) ((((_IR_literal_range_definition *) (_node))->_IR_S_literal_range_definition.bounds_have_explicit_values) = (_value))

#define IR_set_right_range_bound_literal(_node, _value) ((((_IR_literal_range_definition *) (_node))->_IR_S_literal_range_definition.right_range_bound_literal) = (_value))

#define IR_set_nonterm_order_number(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.nonterm_order_number) = (_value))

#define IR_set_nonterm_canonical_rule_list(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.nonterm_canonical_rule_list) = (_value))

#define IR_set_derivation_ability_flag(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.derivation_ability_flag) = (_value))

#define IR_set_pass_number(_node, _value) ((*(integer_t *) ((char *) (_node) + _IR_D_pass_number [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_corresponding_pattern(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.corresponding_pattern) = (_value))

#define IR_set_minimal_derived_string_length(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.minimal_derived_string_length) = (_value))

#define IR_set_relation_FIRST(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.relation_FIRST) = (_value))

#define IR_set_next_iter_relation_FIRST(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.next_iter_relation_FIRST) = (_value))

#define IR_set_process_nonterminal_on_its_process_pass(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.process_nonterminal_on_its_process_pass) = (_value))

#define IR_set_pattern_has_been_output(_node, _value) ((((_IR_single_nonterm_definition *) (_node))->_IR_S_single_nonterm_definition.pattern_has_been_output) = (_value))

#define IR_set_next_cp_flag(_node, _value) ((*(bool_t *) ((char *) (_node) + _IR_D_next_cp_flag [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_canonical_rule_order_number(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.canonical_rule_order_number) = (_value))

#define IR_set_next_nonterm_canonical_rule(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.next_nonterm_canonical_rule) = (_value))

#define IR_set_precedence_single_term_definition(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.precedence_single_term_definition) = (_value))

#define IR_set_rule_priority(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.rule_priority) = (_value))

#define IR_set_max_look_ahead_value(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.max_look_ahead_value) = (_value))

#define IR_set_output_action_number(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.output_action_number) = (_value))

#define IR_set_left_hand_side(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.left_hand_side) = (_value))

#define IR_set_right_hand_side(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.right_hand_side) = (_value))

#define IR_set_action(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.action) = (_value))

#define IR_set_original_code_insertion_place(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.original_code_insertion_place) = (_value))

#define IR_set_next_canonical_rule(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.next_canonical_rule) = (_value))

#define IR_set_canonical_rule_LR_situation(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.canonical_rule_LR_situation) = (_value))

#define IR_set_canonical_rule_action_has_been_output(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.canonical_rule_action_has_been_output) = (_value))

#define IR_set_action_code_copies_number(_node, _value) ((((_IR_canonical_rule *) (_node))->_IR_S_canonical_rule.action_code_copies_number) = (_value))

#define IR_set_canonical_rule(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_canonical_rule [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_next_right_hand_side_element(_node, _value) ((((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.next_right_hand_side_element) = (_value))

#define IR_set_cp_start_flag(_node, _value) ((((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.cp_start_flag) = (_value))

#define IR_set_cp_flag(_node, _value) ((((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.cp_flag) = (_value))

#define IR_set_minimal_FIRST_of_rule_tail_length(_node, _value) ((((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.minimal_FIRST_of_rule_tail_length) = (_value))

#define IR_set_FIRST_of_rule_tail(_node, _value) ((((_IR_right_hand_side_element *) (_node))->_IR_S_right_hand_side_element.FIRST_of_rule_tail) = (_value))

#define IR_set_element_itself(_node, _value) ((((_IR_canonical_rule_element *) (_node))->_IR_S_canonical_rule_element.element_itself) = (_value))

#define IR_set_element_identifier(_node, _value) ((((_IR_canonical_rule_element *) (_node))->_IR_S_canonical_rule_element.element_identifier) = (_value))

#define IR_set_next_single_definition_usage(_node, _value) ((((_IR_canonical_rule_element *) (_node))->_IR_S_canonical_rule_element.next_single_definition_usage) = (_value))

#define IR_set_goto_LR_set(_node, _value) (_IR_set_double_field_value  (&((((_IR_LR_situation *) _node)->_IR_S_LR_situation.goto_LR_set)), (_value), _IR_offsetof (struct IR_node, _IR_first_link), 0))

#define IR_set_goto_arc_has_been_removed(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.goto_arc_has_been_removed) = (_value))

#define IR_set_look_ahead_context(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.look_ahead_context) = (_value))

#define IR_set_first_symbol_LR_situation(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.first_symbol_LR_situation) = (_value))

#define IR_set_next_symbol_LR_situation(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.next_symbol_LR_situation) = (_value))

#define IR_set_important_LR_situation_flag(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.important_LR_situation_flag) = (_value))

#define IR_set_situation_in_stack_flag(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.situation_in_stack_flag) = (_value))

#define IR_set_under_control_point_flag(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.under_control_point_flag) = (_value))

#define IR_set_back_tracking_conflict_flag(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.back_tracking_conflict_flag) = (_value))

#define IR_set_corresponding_regular_arc(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.corresponding_regular_arc) = (_value))

#define IR_set_reduce_number(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.reduce_number) = (_value))

#define IR_set_popped_LR_sets_number(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.popped_LR_sets_number) = (_value))

#define IR_set_popped_attributes_number(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.popped_attributes_number) = (_value))

#define IR_set_element_after_dot(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.element_after_dot) = (_value))

#define IR_set_context(_node, _value) ((*(context_t *) ((char *) (_node) + _IR_D_context [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_LR_set(_node, _value) ((*(IR_node_t *) ((char *) (_node) + _IR_D_LR_set [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_next_LR_situation(_node, _value) ((((_IR_LR_situation *) (_node))->_IR_S_LR_situation.next_LR_situation) = (_value))

#define IR_set_conflicts_list(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.conflicts_list) = (_value))

#define IR_set_it_is_in_LALR_sets_stack(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_in_LALR_sets_stack) = (_value))

#define IR_set_reachable_flag(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.reachable_flag) = (_value))

#define IR_set_it_is_pushed_LR_set(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_pushed_LR_set) = (_value))

#define IR_set_it_is_errored_LR_set(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_errored_LR_set) = (_value))

#define IR_set_attribute_is_used(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.attribute_is_used) = (_value))

#define IR_set_visit_flag(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.visit_flag) = (_value))

#define IR_set_first_splitted_LR_set(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.first_splitted_LR_set) = (_value))

#define IR_set_next_splitted_LR_set(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.next_splitted_LR_set) = (_value))

#define IR_set_back_tracking_flag(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.back_tracking_flag) = (_value))

#define IR_set_it_is_in_reduce_action_LR_sets_stack(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.it_is_in_reduce_action_LR_sets_stack) = (_value))

#define IR_set_LR_set_look_ahead_trie(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_set_look_ahead_trie) = (_value))

#define IR_set_LR_set_order_number(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_set_order_number) = (_value))

#define IR_set_term_arcs_number(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.term_arcs_number) = (_value))

#define IR_set_nonterm_arcs_number(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.nonterm_arcs_number) = (_value))

#define IR_set_start_LR_set_pass(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.start_LR_set_pass) = (_value))

#define IR_set_LR_set_has_been_output_in_comment(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_set_has_been_output_in_comment) = (_value))

#define IR_set_LR_situation_list(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_situation_list) = (_value))

#define IR_set_LR_core(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.LR_core) = (_value))

#define IR_set_next_LR_set(_node, _value) ((((_IR_LR_set *) (_node))->_IR_S_LR_set.next_LR_set) = (_value))

#define IR_set_first_back_track_alternative(_node, _value) ((((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.first_back_track_alternative) = (_value))

#define IR_set_last_back_track_alternative(_node, _value) ((((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.last_back_track_alternative) = (_value))

#define IR_set_additional_action_table_number(_node, _value) ((((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.additional_action_table_number) = (_value))

#define IR_set_corresponding_single_term_definition(_node, _value) ((((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.corresponding_single_term_definition) = (_value))

#define IR_set_corresponding_LR_situation(_node, _value) ((((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.corresponding_LR_situation) = (_value))

#define IR_set_first_son(_node, _value) ((((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.first_son) = (_value))

#define IR_set_next_brother(_node, _value) ((((_IR_LR_set_look_ahead_trie_node *) (_node))->_IR_S_LR_set_look_ahead_trie_node.next_brother) = (_value))

#define IR_set_corresponding_LR_set_look_ahead_trie_node(_node, _value) ((((_IR_back_track_alternative *) (_node))->_IR_S_back_track_alternative.corresponding_LR_set_look_ahead_trie_node) = (_value))

#define IR_set_next_back_track_alternative(_node, _value) ((((_IR_back_track_alternative *) (_node))->_IR_S_back_track_alternative.next_back_track_alternative) = (_value))

#define IR_set_used_LR_situation(_node, _value) ((((_IR_conflict *) (_node))->_IR_S_conflict.used_LR_situation) = (_value))

#define IR_set_unused_LR_situation(_node, _value) ((((_IR_conflict *) (_node))->_IR_S_conflict.unused_LR_situation) = (_value))

#define IR_set_token_string(_node, _value) ((((_IR_conflict *) (_node))->_IR_S_conflict.token_string) = (_value))

#define IR_set_next_conflict(_node, _value) ((((_IR_conflict *) (_node))->_IR_S_conflict.next_conflict) = (_value))

#define IR_set_first_rule_list_element(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.first_rule_list_element) = (_value))

#define IR_set_last_rule_list_element(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.last_rule_list_element) = (_value))

#define IR_set_regular_arc_popped_LR_sets_number(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.regular_arc_popped_LR_sets_number) = (_value))

#define IR_set_regular_arc_popped_attributes_number(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.regular_arc_popped_attributes_number) = (_value))

#define IR_set_max_states_stack_increment(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.max_states_stack_increment) = (_value))

#define IR_set_max_attributes_stack_increment(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.max_attributes_stack_increment) = (_value))

#define IR_set_first_equivalent_regular_arc_flag(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.first_equivalent_regular_arc_flag) = (_value))

#define IR_set_next_equivalent_regular_arc(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.next_equivalent_regular_arc) = (_value))

#define IR_set_number_of_regular_arc(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.number_of_regular_arc) = (_value))

#define IR_set_result_LR_set_will_be_on_the_stack(_node, _value) ((*(bool_t *) ((char *) (_node) + _IR_D_result_LR_set_will_be_on_the_stack [IR_NODE_MODE ((_node))])) = (_value))

#define IR_set_from_LR_situation(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.from_LR_situation) = (_value))

#define IR_set_to_LR_set(_node, _value) (_IR_set_double_field_value  (&((((_IR_regular_arc *) _node)->_IR_S_regular_arc.to_LR_set)), (_value), _IR_offsetof (struct IR_node, _IR_first_link), 0))

#define IR_set_terminal_marking_arc(_node, _value) ((((_IR_regular_arc *) (_node))->_IR_S_regular_arc.terminal_marking_arc) = (_value))

#define IR_set_right_hand_side_used_attributes_number(_node, _value) ((((_IR_rule_list_element *) (_node))->_IR_S_rule_list_element.right_hand_side_used_attributes_number) = (_value))

#define IR_set_lhs_nonterm_attribute_is_used(_node, _value) ((((_IR_rule_list_element *) (_node))->_IR_S_rule_list_element.lhs_nonterm_attribute_is_used) = (_value))

#define IR_set_next_rule_list_element(_node, _value) ((((_IR_rule_list_element *) (_node))->_IR_S_rule_list_element.next_rule_list_element) = (_value))

#define IR_set_first_pass_flag(_node, _value) ((((_IR_LR_core *) (_node))->_IR_S_LR_core.first_pass_flag) = (_value))

#define IR_set_second_pass_flag(_node, _value) ((((_IR_LR_core *) (_node))->_IR_S_LR_core.second_pass_flag) = (_value))

#define IR_set_LR_set_list(_node, _value) ((((_IR_LR_core *) (_node))->_IR_S_LR_core.LR_set_list) = (_value))

#define IR_set_next_LR_core(_node, _value) ((((_IR_LR_core *) (_node))->_IR_S_LR_core.next_LR_core) = (_value))

#define IR_set_dependencies(_node, _value) ((((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.dependencies) = (_value))

#define IR_set_context_has_been_evaluated(_node, _value) ((((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.context_has_been_evaluated) = (_value))

#define IR_set_unique_number(_node, _value) ((((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.unique_number) = (_value))

#define IR_set_look_ahead(_node, _value) ((((_IR_DeRemer_dependence *) (_node))->_IR_S_DeRemer_dependence.look_ahead) = (_value))

#define IR_set_back_distance(_node, _value) ((((_IR_LR_set_dependence *) (_node))->_IR_S_LR_set_dependence.back_distance) = (_value))

#define IR_set_nonterm(_node, _value) ((((_IR_LR_set_dependence *) (_node))->_IR_S_LR_set_dependence.nonterm) = (_value))

#define IR_set_token(_node, _value) ((((_IR_shift_dependence *) (_node))->_IR_S_shift_dependence.token) = (_value))

#define IR_set_shift_LR_situation(_node, _value) ((((_IR_shift_LR_situation_dependence *) (_node))->_IR_S_shift_LR_situation_dependence.shift_LR_situation) = (_value))

#define IR_set_dependence(_node, _value) ((((_IR_dependence_list_element *) (_node))->_IR_S_dependence_list_element.dependence) = (_value))

#define IR_set_next_dependence_list_element(_node, _value) ((((_IR_dependence_list_element *) (_node))->_IR_S_dependence_list_element.next_dependence_list_element) = (_value))

extern IR_node_t IR_create_node (IR_node_mode_t node_mode);

extern IR_node_t IR_new_identifier
(position_t position,
 string_t identifier_itself,
 bool_t dot_presence_flag);

extern IR_node_t IR_new_literal
(position_t position,
 string_t character_representation,
 integer_t literal_code);

extern IR_node_t IR_new_string
(position_t position,
 string_t string_representation,
 string_t string_itself);

extern IR_node_t IR_new_number
(position_t position,
 integer_t number_value);

extern IR_node_t IR_new_code_insertion
(position_t position,
 string_t code_insertion_itself);

extern IR_node_t IR_new_additional_code
(position_t position,
 string_t additional_code_itself);

extern IR_node_t IR_new_start_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t identifier);

extern IR_node_t IR_new_yacc_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself);

extern IR_node_t IR_new_local_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself);

extern IR_node_t IR_new_import_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself);

extern IR_node_t IR_new_export_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself);

extern IR_node_t IR_new_union_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself);

extern IR_node_t IR_new_scanner_definition
(position_t position,
 IR_node_t next_definition);

extern IR_node_t IR_new_expect_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t expected_number);

extern IR_node_t IR_new_token_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag);

extern IR_node_t IR_new_left_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag);

extern IR_node_t IR_new_right_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag);

extern IR_node_t IR_new_nonassoc_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag);

extern IR_node_t IR_new_type_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag);

extern IR_node_t IR_new_symbol
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t number,
 IR_node_t next_symbol);

extern IR_node_t IR_new_rule
(position_t position,
 IR_node_t nonterm_identifier,
 IR_node_t pattern,
 IR_node_t next_rule);

extern IR_node_t IR_new_pattern
(position_t position,
 IR_node_t alternatives_list);

extern IR_node_t IR_new_sequence
(position_t position,
 IR_node_t next_alternative,
 IR_node_t sequence,
 IR_node_t precedence_identifier_or_literal,
 IR_node_t max_look_ahead_number);

extern IR_node_t IR_new_separator_iteration
(position_t position,
 IR_node_t next_alternative,
 IR_node_t iteration_sequence,
 IR_node_t iteration_precedence_identifier_or_literal,
 IR_node_t iteration_max_look_ahead_number,
 IR_node_t separator_sequence,
 IR_node_t separator_precedence_identifier_or_literal,
 IR_node_t separator_max_look_ahead_number);

extern IR_node_t IR_new_control_point
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier);

extern IR_node_t IR_new_default
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t default_pattern);

extern IR_node_t IR_new_star_iteration
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t iteration_unit);

extern IR_node_t IR_new_plus_iteration
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t iteration_unit);

extern IR_node_t IR_new_code_insertion_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t code_insertion);

extern IR_node_t IR_new_group
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t pattern);

extern IR_node_t IR_new_range_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound);

extern IR_node_t IR_new_range_no_left_bound_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound);

extern IR_node_t IR_new_range_no_right_bound_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound);

extern IR_node_t IR_new_range_no_left_right_bounds_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound);

extern IR_node_t IR_new_identifier_or_literal_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t identifier_or_literal);

extern IR_node_t IR_new_string_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t string);

extern IR_node_t IR_new_description
(position_t position,
 IR_node_t definition_list,
 IR_node_t rule_list,
 IR_node_t additional_code);

extern IR_node_t IR_new_single_term_definition
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t next_single_definition);

extern IR_node_t IR_new_literal_range_definition
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t next_single_definition,
 IR_node_t right_range_bound_literal);

extern IR_node_t IR_new_single_nonterm_definition
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t next_single_definition,
 IR_node_t corresponding_pattern);

extern IR_node_t IR_new_canonical_rule
(position_t position,
 IR_node_t left_hand_side,
 IR_node_t right_hand_side,
 IR_node_t action,
 IR_node_t original_code_insertion_place,
 IR_node_t next_canonical_rule);

extern IR_node_t IR_new_canonical_rule_element
(position_t position,
 IR_node_t canonical_rule,
 IR_node_t next_right_hand_side_element,
 IR_node_t element_itself,
 IR_node_t element_identifier,
 IR_node_t next_single_definition_usage);

extern IR_node_t IR_new_canonical_rule_end
(position_t position,
 IR_node_t canonical_rule,
 IR_node_t next_right_hand_side_element);

extern IR_node_t IR_new_LR_situation
(IR_node_t element_after_dot,
 context_t context,
 IR_node_t LR_set,
 IR_node_t next_LR_situation);

extern IR_node_t IR_new_LR_set
(IR_node_t LR_situation_list,
 IR_node_t LR_core,
 IR_node_t next_LR_set);

extern IR_node_t IR_new_LR_set_look_ahead_trie_node
(IR_node_t corresponding_single_term_definition,
 IR_node_t corresponding_LR_situation,
 IR_node_t first_son,
 IR_node_t next_brother);

extern IR_node_t IR_new_back_track_alternative
(IR_node_t corresponding_LR_set_look_ahead_trie_node,
 IR_node_t next_back_track_alternative);

extern IR_node_t IR_new_conflict
(IR_node_t used_LR_situation,
 IR_node_t unused_LR_situation,
 token_string_t token_string,
 IR_node_t next_conflict);

extern IR_node_t IR_new_regular_arc
(IR_node_t from_LR_situation,
 IR_node_t to_LR_set,
 IR_node_t terminal_marking_arc);

extern IR_node_t IR_new_rule_list_element
(IR_node_t canonical_rule,
 IR_node_t next_rule_list_element);

extern IR_node_t IR_new_LR_core
(IR_node_t LR_set_list,
 IR_node_t next_LR_core);

extern IR_node_t IR_new_LR_set_dependence
(integer_t look_ahead,
 IR_node_t LR_set,
 integer_t back_distance,
 IR_node_t nonterm);

extern IR_node_t IR_new_shift_dependence
(integer_t look_ahead,
 IR_node_t token);

extern IR_node_t IR_new_shift_LR_situation_dependence
(integer_t look_ahead,
 IR_node_t token,
 IR_node_t shift_LR_situation);

extern IR_node_t IR_new_dependence_list_element
(IR_node_t dependence,
 IR_node_t next_dependence_list_element);

extern IR_node_t IR_copy_node (IR_node_t node);

extern void IR_start (void);

extern void IR_stop (void);


#line 67 "./ird.sprut"


/* These macros for storage management of MSTA internal representation: */

/* Start work with the storage manager -- see MSTA documentation. */

#define IR_START_ALLOC()    OS_CREATE (irp, 5000)

/* Finish work with the storage manager -- see MSTA documentation. */

#define IR_STOP_ALLOC()     OS_DELETE (irp)

/* Allocate storage for internal representation of given size
   -- see MSTA documentation. */

#define IR_ALLOC(ptr, size, ptr_type)\
  do {\
    OS_TOP_EXPAND (irp, size); ptr = (ptr_type) OS_TOP_BEGIN (irp);\
    OS_TOP_FINISH (irp);\
  } while (0);

/* Free storage of internal representation of given size -- see MSTA
   documentation. */

#define IR_FREE(ptr, size)


/* These macros are analogous to ones of package `object-stack'
   worked with storage of MSTA internal representation: */

/* Start new internal representation object -- see also package
   `object-stack'. */

#define IR_TOP_FINISH()  OS_TOP_FINISH (irp)

/* Nullify current internal representation object -- see also package
   `object-stack'. */

#define IR_TOP_NULLIFY()  OS_TOP_NULLIFY (irp)

/* Shorten current internal representation object on given number bytes -- see
   also package `object-stack'. */

#define IR_TOP_SHORTEN(length) OS_TOP_SHORTEN (irp, length)

/* Return start address of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_BEGIN()  OS_TOP_BEGIN (irp)

/* The following macro increases length of current internal
   representation object -- see also package `object-stack'. */

#define IR_TOP_EXPAND(length)  OS_TOP_EXPAND (irp, length)

/* Return length of current internal representation object in bytes -- see
   also package `object-stack'. */

#define IR_TOP_LENGTH()  OS_TOP_LENGTH (irp)

/* Add byte to the end of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_ADD_BYTE(b)  OS_TOP_ADD_BYTE (irp, b)

/* Add string to the end of current internal representation object -- see also
   package `object-stack'. */

#define IR_TOP_ADD_STRING(str)  OS_TOP_ADD_STRING (irp, str)

/* Add memory of given length to the end of current internal representation
   object -- see also package `object-stack'. */

#define IR_TOP_ADD_MEMORY(mem, length)  OS_TOP_ADD_MEMORY (irp, mem, length)

extern os_t irp;

void process_canonical_rule_action
      (IR_node_t canonical_rule, void (*process_char) (char ch),
       void (*process_attribute) (IR_node_t canonical_rule,
                                  position_t attribute_position,
                                  const char *tag_name,
                                  const char *attribute_name));


#line 2539 "ird.h"
#endif /* __IR_ird__ */
