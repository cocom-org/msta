#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ird.h"


#line 152 "./ird.sprut"


#include "common.h"

/* All internal representation storage is implemented by object stack.  See
   package `object-stack'. */

os_t irp;


#line 19 "ird.c"
#ifndef IR_START_ALLOC
#define IR_START_ALLOC()
#endif

#ifndef IR_STOP_ALLOC
#define IR_STOP_ALLOC()
#endif

#ifndef IR_ALLOC
#define IR_ALLOC(ptr, size, ptr_type) ((ptr) = (ptr_type) malloc (size))
#endif

#ifndef IR_FREE
#define IR_FREE(ptr, size) free (ptr)
#endif

#ifndef IR_BEGIN_IR_node_t
#define IR_BEGIN_IR_node_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_IR_node_t
#define IR_END_IR_node_t(a)
#endif

#ifndef IR_COPY_IR_node_t
#define IR_COPY_IR_node_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_IR_node_t
#define IR_EQUAL_IR_node_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_IR_node_t
#define IR_PRINT_IR_node_t(a) printf ("%lx", (unsigned long) (a))
#endif

#ifndef IR_INPUT_IR_node_t
#define IR_INPUT_IR_node_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_IR_node_t
#define IR_OUTPUT_IR_node_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_integer_t
#define IR_BEGIN_integer_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_integer_t
#define IR_END_integer_t(a)
#endif

#ifndef IR_COPY_integer_t
#define IR_COPY_integer_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_integer_t
#define IR_EQUAL_integer_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_integer_t
#define IR_PRINT_integer_t(a)
#endif

#ifndef IR_INPUT_integer_t
#define IR_INPUT_integer_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_integer_t
#define IR_OUTPUT_integer_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_bool_t
#define IR_BEGIN_bool_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_bool_t
#define IR_END_bool_t(a)
#endif

#ifndef IR_COPY_bool_t
#define IR_COPY_bool_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_bool_t
#define IR_EQUAL_bool_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_bool_t
#define IR_PRINT_bool_t(a)
#endif

#ifndef IR_INPUT_bool_t
#define IR_INPUT_bool_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_bool_t
#define IR_OUTPUT_bool_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_string_t
#define IR_BEGIN_string_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_string_t
#define IR_END_string_t(a)
#endif

#ifndef IR_COPY_string_t
#define IR_COPY_string_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_string_t
#define IR_EQUAL_string_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_string_t
#define IR_PRINT_string_t(a)
#endif

#ifndef IR_INPUT_string_t
#define IR_INPUT_string_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_string_t
#define IR_OUTPUT_string_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_token_string_t
#define IR_BEGIN_token_string_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_token_string_t
#define IR_END_token_string_t(a)
#endif

#ifndef IR_COPY_token_string_t
#define IR_COPY_token_string_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_token_string_t
#define IR_EQUAL_token_string_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_token_string_t
#define IR_PRINT_token_string_t(a)
#endif

#ifndef IR_INPUT_token_string_t
#define IR_INPUT_token_string_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_token_string_t
#define IR_OUTPUT_token_string_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_context_t
#define IR_BEGIN_context_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_context_t
#define IR_END_context_t(a)
#endif

#ifndef IR_COPY_context_t
#define IR_COPY_context_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_context_t
#define IR_EQUAL_context_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_context_t
#define IR_PRINT_context_t(a)
#endif

#ifndef IR_INPUT_context_t
#define IR_INPUT_context_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_context_t
#define IR_OUTPUT_context_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_BEGIN_position_t
#define IR_BEGIN_position_t(a) memset (&(a), 0, sizeof (a))
#endif

#ifndef IR_END_position_t
#define IR_END_position_t(a)
#endif

#ifndef IR_COPY_position_t
#define IR_COPY_position_t(a, b) ((a) = (b))
#endif

#ifndef IR_EQUAL_position_t
#define IR_EQUAL_position_t(a, b) ((a) == (b))
#endif

#ifndef IR_PRINT_position_t
#define IR_PRINT_position_t(a)
#endif

#ifndef IR_INPUT_position_t
#define IR_INPUT_position_t(file, field) (fread (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

#ifndef IR_OUTPUT_position_t
#define IR_OUTPUT_position_t(file, field) (fwrite (&(field), sizeof (field), 1, (file)) != sizeof (field))
#endif

short _IR_node_level [] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

unsigned char _IR_SF_node [] =
{255, 255, 255, 255, 255, 223, 63, 0, 0
};

unsigned char _IR_SF_identifier_or_literal [] =
{14, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_identifier [] =
{4, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_literal [] =
{8, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_string [] =
{16, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_number [] =
{32, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_code_insertion [] =
{64, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_additional_code [] =
{128, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_definition [] =
{0, 255, 255, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_start_definition [] =
{0, 2, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_code [] =
{0, 252, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_yacc_code [] =
{0, 8, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_local_code [] =
{0, 16, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_import_code [] =
{0, 32, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_export_code [] =
{0, 64, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_union_code [] =
{0, 128, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_scanner_definition [] =
{0, 0, 1, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_expect_definition [] =
{0, 0, 2, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_symbol_definition [] =
{0, 0, 252, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_token_definition [] =
{0, 0, 8, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_left_definition [] =
{0, 0, 16, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_right_definition [] =
{0, 0, 32, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_nonassoc_definition [] =
{0, 0, 64, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_type_definition [] =
{0, 0, 128, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_symbol [] =
{0, 0, 0, 1, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_rule [] =
{0, 0, 0, 2, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_pattern [] =
{0, 0, 0, 4, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_alternative [] =
{0, 0, 0, 56, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_sequence [] =
{0, 0, 0, 16, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_separator_iteration [] =
{0, 0, 0, 32, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_sequence_element [] =
{0, 0, 0, 192, 255, 15, 0, 0, 0
};

unsigned char _IR_SF_control_point [] =
{0, 0, 0, 128, 0, 0, 0, 0, 0
};

unsigned char _IR_SF_default [] =
{0, 0, 0, 0, 1, 0, 0, 0, 0
};

unsigned char _IR_SF_star_iteration [] =
{0, 0, 0, 0, 2, 0, 0, 0, 0
};

unsigned char _IR_SF_plus_iteration [] =
{0, 0, 0, 0, 4, 0, 0, 0, 0
};

unsigned char _IR_SF_code_insertion_atom [] =
{0, 0, 0, 0, 8, 0, 0, 0, 0
};

unsigned char _IR_SF_unit [] =
{0, 0, 0, 0, 240, 15, 0, 0, 0
};

unsigned char _IR_SF_group [] =
{0, 0, 0, 0, 32, 0, 0, 0, 0
};

unsigned char _IR_SF_range_atom [] =
{0, 0, 0, 0, 192, 3, 0, 0, 0
};

unsigned char _IR_SF_range_no_left_bound_atom [] =
{0, 0, 0, 0, 128, 0, 0, 0, 0
};

unsigned char _IR_SF_range_no_right_bound_atom [] =
{0, 0, 0, 0, 0, 1, 0, 0, 0
};

unsigned char _IR_SF_range_no_left_right_bounds_atom [] =
{0, 0, 0, 0, 0, 2, 0, 0, 0
};

unsigned char _IR_SF_identifier_or_literal_atom [] =
{0, 0, 0, 0, 0, 4, 0, 0, 0
};

unsigned char _IR_SF_string_atom [] =
{0, 0, 0, 0, 0, 8, 0, 0, 0
};

unsigned char _IR_SF_description [] =
{0, 0, 0, 0, 0, 16, 0, 0, 0
};

unsigned char _IR_SF_denotation [] =
{0, 0, 0, 248, 255, 47, 0, 0, 0
};

unsigned char _IR_SF_single_definition [] =
{0, 0, 0, 0, 0, 192, 3, 0, 0
};

unsigned char _IR_SF_single_term_definition [] =
{0, 0, 0, 0, 0, 128, 1, 0, 0
};

unsigned char _IR_SF_literal_range_definition [] =
{0, 0, 0, 0, 0, 0, 1, 0, 0
};

unsigned char _IR_SF_single_nonterm_definition [] =
{0, 0, 0, 0, 0, 0, 2, 0, 0
};

unsigned char _IR_SF_canonical_rule [] =
{0, 0, 0, 0, 0, 0, 4, 0, 0
};

unsigned char _IR_SF_right_hand_side_element [] =
{0, 0, 0, 0, 0, 0, 56, 0, 0
};

unsigned char _IR_SF_canonical_rule_element [] =
{0, 0, 0, 0, 0, 0, 16, 0, 0
};

unsigned char _IR_SF_canonical_rule_end [] =
{0, 0, 0, 0, 0, 0, 32, 0, 0
};

unsigned char _IR_SF_LR_situation [] =
{0, 0, 0, 0, 0, 0, 64, 0, 0
};

unsigned char _IR_SF_LR_set [] =
{0, 0, 0, 0, 0, 0, 128, 0, 0
};

unsigned char _IR_SF_LR_set_look_ahead_trie_node [] =
{0, 0, 0, 0, 0, 0, 0, 1, 0
};

unsigned char _IR_SF_back_track_alternative [] =
{0, 0, 0, 0, 0, 0, 0, 2, 0
};

unsigned char _IR_SF_conflict [] =
{0, 0, 0, 0, 0, 0, 0, 4, 0
};

unsigned char _IR_SF_regular_arc [] =
{0, 0, 0, 0, 0, 0, 0, 8, 0
};

unsigned char _IR_SF_rule_list_element [] =
{0, 0, 0, 0, 0, 0, 0, 16, 0
};

unsigned char _IR_SF_LR_core [] =
{0, 0, 0, 0, 0, 0, 0, 32, 0
};

unsigned char _IR_SF_DeRemer_dependence [] =
{0, 0, 0, 0, 0, 0, 0, 192, 3
};

unsigned char _IR_SF_LR_set_dependence [] =
{0, 0, 0, 0, 0, 0, 0, 128, 0
};

unsigned char _IR_SF_shift_dependence [] =
{0, 0, 0, 0, 0, 0, 0, 0, 3
};

unsigned char _IR_SF_shift_LR_situation_dependence [] =
{0, 0, 0, 0, 0, 0, 0, 0, 2
};

unsigned char _IR_SF_dependence_list_element [] =
{0, 0, 0, 0, 0, 0, 0, 0, 4
};

unsigned char _IR_SF__root [] =
{255, 255, 255, 255, 255, 255, 255, 255, 31
};

unsigned char _IR_SF__error [] =
{0, 0, 0, 0, 0, 0, 0, 0, 16
};

unsigned char *_IR_is_type[] =
{
_IR_SF_node,
_IR_SF_identifier_or_literal,
_IR_SF_identifier,
_IR_SF_literal,
_IR_SF_string,
_IR_SF_number,
_IR_SF_code_insertion,
_IR_SF_additional_code,
_IR_SF_definition,
_IR_SF_start_definition,
_IR_SF_code,
_IR_SF_yacc_code,
_IR_SF_local_code,
_IR_SF_import_code,
_IR_SF_export_code,
_IR_SF_union_code,
_IR_SF_scanner_definition,
_IR_SF_expect_definition,
_IR_SF_symbol_definition,
_IR_SF_token_definition,
_IR_SF_left_definition,
_IR_SF_right_definition,
_IR_SF_nonassoc_definition,
_IR_SF_type_definition,
_IR_SF_symbol,
_IR_SF_rule,
_IR_SF_pattern,
_IR_SF_alternative,
_IR_SF_sequence,
_IR_SF_separator_iteration,
_IR_SF_sequence_element,
_IR_SF_control_point,
_IR_SF_default,
_IR_SF_star_iteration,
_IR_SF_plus_iteration,
_IR_SF_code_insertion_atom,
_IR_SF_unit,
_IR_SF_group,
_IR_SF_range_atom,
_IR_SF_range_no_left_bound_atom,
_IR_SF_range_no_right_bound_atom,
_IR_SF_range_no_left_right_bounds_atom,
_IR_SF_identifier_or_literal_atom,
_IR_SF_string_atom,
_IR_SF_description,
_IR_SF_denotation,
_IR_SF_single_definition,
_IR_SF_single_term_definition,
_IR_SF_literal_range_definition,
_IR_SF_single_nonterm_definition,
_IR_SF_canonical_rule,
_IR_SF_right_hand_side_element,
_IR_SF_canonical_rule_element,
_IR_SF_canonical_rule_end,
_IR_SF_LR_situation,
_IR_SF_LR_set,
_IR_SF_LR_set_look_ahead_trie_node,
_IR_SF_back_track_alternative,
_IR_SF_conflict,
_IR_SF_regular_arc,
_IR_SF_rule_list_element,
_IR_SF_LR_core,
_IR_SF_DeRemer_dependence,
_IR_SF_LR_set_dependence,
_IR_SF_shift_dependence,
_IR_SF_shift_LR_situation_dependence,
_IR_SF_dependence_list_element,
_IR_SF__root,
_IR_SF__error
};

unsigned char _IR_D_identifier_or_literal [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 
  _IR_offsetof (_IR_symbol, _IR_S_symbol)
    + _IR_offsetof (struct _IR_S_symbol, identifier_or_literal), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_identifier_or_literal_atom, _IR_S_identifier_or_literal_atom)
    + _IR_offsetof (struct _IR_S_identifier_or_literal_atom, identifier_or_literal), 
  0, 0, 0, 
  _IR_offsetof (_IR_single_definition, _IR_S_single_definition)
    + _IR_offsetof (struct _IR_S_single_definition, identifier_or_literal), 
  _IR_offsetof (_IR_single_term_definition, _IR_S_single_term_definition)
    + _IR_offsetof (struct _IR_S_single_term_definition, _IR_M_single_definition)
    + _IR_offsetof (struct _IR_S_single_definition, identifier_or_literal), 
  _IR_offsetof (_IR_literal_range_definition, _IR_S_literal_range_definition)
    + _IR_offsetof (struct _IR_S_literal_range_definition, _IR_M_single_term_definition)
    + _IR_offsetof (struct _IR_S_single_term_definition, _IR_M_single_definition)
    + _IR_offsetof (struct _IR_S_single_definition, identifier_or_literal), 
  _IR_offsetof (_IR_single_nonterm_definition, _IR_S_single_nonterm_definition)
    + _IR_offsetof (struct _IR_S_single_nonterm_definition, _IR_M_single_definition)
    + _IR_offsetof (struct _IR_S_single_definition, identifier_or_literal), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_D_pattern [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_rule, _IR_S_rule)
    + _IR_offsetof (struct _IR_S_rule, pattern), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_group, _IR_S_group)
    + _IR_offsetof (struct _IR_S_group, pattern), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_D_iteration_unit [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_star_iteration, _IR_S_star_iteration)
    + _IR_offsetof (struct _IR_S_star_iteration, iteration_unit), 
  _IR_offsetof (_IR_plus_iteration, _IR_S_plus_iteration)
    + _IR_offsetof (struct _IR_S_plus_iteration, iteration_unit), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_D_corresponding_single_nonterm_definition [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_alternative, _IR_S_alternative)
    + _IR_offsetof (struct _IR_S_alternative, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_sequence, _IR_S_sequence)
    + _IR_offsetof (struct _IR_S_sequence, _IR_M_alternative)
    + _IR_offsetof (struct _IR_S_alternative, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_separator_iteration, _IR_S_separator_iteration)
    + _IR_offsetof (struct _IR_S_separator_iteration, _IR_M_alternative)
    + _IR_offsetof (struct _IR_S_alternative, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_control_point, _IR_S_control_point)
    + _IR_offsetof (struct _IR_S_control_point, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_default, _IR_S_default)
    + _IR_offsetof (struct _IR_S_default, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_star_iteration, _IR_S_star_iteration)
    + _IR_offsetof (struct _IR_S_star_iteration, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_plus_iteration, _IR_S_plus_iteration)
    + _IR_offsetof (struct _IR_S_plus_iteration, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_code_insertion_atom, _IR_S_code_insertion_atom)
    + _IR_offsetof (struct _IR_S_code_insertion_atom, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_unit, _IR_S_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_group, _IR_S_group)
    + _IR_offsetof (struct _IR_S_group, _IR_M_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_range_atom, _IR_S_range_atom)
    + _IR_offsetof (struct _IR_S_range_atom, _IR_M_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_range_no_left_bound_atom, _IR_S_range_no_left_bound_atom)
    + _IR_offsetof (struct _IR_S_range_no_left_bound_atom, _IR_M_range_atom)
    + _IR_offsetof (struct _IR_S_range_atom, _IR_M_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_range_no_right_bound_atom, _IR_S_range_no_right_bound_atom)
    + _IR_offsetof (struct _IR_S_range_no_right_bound_atom, _IR_M_range_atom)
    + _IR_offsetof (struct _IR_S_range_atom, _IR_M_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_range_no_left_right_bounds_atom, _IR_S_range_no_left_right_bounds_atom)
    + _IR_offsetof (struct _IR_S_range_no_left_right_bounds_atom, _IR_M_range_atom)
    + _IR_offsetof (struct _IR_S_range_atom, _IR_M_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_identifier_or_literal_atom, _IR_S_identifier_or_literal_atom)
    + _IR_offsetof (struct _IR_S_identifier_or_literal_atom, _IR_M_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  _IR_offsetof (_IR_string_atom, _IR_S_string_atom)
    + _IR_offsetof (struct _IR_S_string_atom, _IR_M_unit)
    + _IR_offsetof (struct _IR_S_unit, _IR_M_sequence_element)
    + _IR_offsetof (struct _IR_S_sequence_element, _IR_M_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  0, 
  _IR_offsetof (_IR_denotation, _IR_S_denotation)
    + _IR_offsetof (struct _IR_S_denotation, corresponding_single_nonterm_definition), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0
};

unsigned char _IR_D_pass_number [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_single_nonterm_definition, _IR_S_single_nonterm_definition)
    + _IR_offsetof (struct _IR_S_single_nonterm_definition, pass_number), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, pass_number), 
  _IR_offsetof (_IR_LR_set_dependence, _IR_S_LR_set_dependence)
    + _IR_offsetof (struct _IR_S_LR_set_dependence, _IR_M_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, pass_number), 
  _IR_offsetof (_IR_shift_dependence, _IR_S_shift_dependence)
    + _IR_offsetof (struct _IR_S_shift_dependence, _IR_M_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, pass_number), 
  _IR_offsetof (_IR_shift_LR_situation_dependence, _IR_S_shift_LR_situation_dependence)
    + _IR_offsetof (struct _IR_S_shift_LR_situation_dependence, _IR_M_shift_dependence)
    + _IR_offsetof (struct _IR_S_shift_dependence, _IR_M_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, pass_number), 
  0, 0, 0
};

unsigned char _IR_D_next_cp_flag [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_canonical_rule, _IR_S_canonical_rule)
    + _IR_offsetof (struct _IR_S_canonical_rule, next_cp_flag), 
  0, 
  _IR_offsetof (_IR_canonical_rule_element, _IR_S_canonical_rule_element)
    + _IR_offsetof (struct _IR_S_canonical_rule_element, next_cp_flag), 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_D_canonical_rule [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_right_hand_side_element, _IR_S_right_hand_side_element)
    + _IR_offsetof (struct _IR_S_right_hand_side_element, canonical_rule), 
  _IR_offsetof (_IR_canonical_rule_element, _IR_S_canonical_rule_element)
    + _IR_offsetof (struct _IR_S_canonical_rule_element, _IR_M_right_hand_side_element)
    + _IR_offsetof (struct _IR_S_right_hand_side_element, canonical_rule), 
  _IR_offsetof (_IR_canonical_rule_end, _IR_S_canonical_rule_end)
    + _IR_offsetof (struct _IR_S_canonical_rule_end, _IR_M_right_hand_side_element)
    + _IR_offsetof (struct _IR_S_right_hand_side_element, canonical_rule), 
  0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_rule_list_element, _IR_S_rule_list_element)
    + _IR_offsetof (struct _IR_S_rule_list_element, canonical_rule), 
  0, 0, 0, 0, 0, 0, 0, 0
};

unsigned char _IR_D_context [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_LR_situation, _IR_S_LR_situation)
    + _IR_offsetof (struct _IR_S_LR_situation, context), 
  0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, context), 
  _IR_offsetof (_IR_LR_set_dependence, _IR_S_LR_set_dependence)
    + _IR_offsetof (struct _IR_S_LR_set_dependence, _IR_M_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, context), 
  _IR_offsetof (_IR_shift_dependence, _IR_S_shift_dependence)
    + _IR_offsetof (struct _IR_S_shift_dependence, _IR_M_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, context), 
  _IR_offsetof (_IR_shift_LR_situation_dependence, _IR_S_shift_LR_situation_dependence)
    + _IR_offsetof (struct _IR_S_shift_LR_situation_dependence, _IR_M_shift_dependence)
    + _IR_offsetof (struct _IR_S_shift_dependence, _IR_M_DeRemer_dependence)
    + _IR_offsetof (struct _IR_S_DeRemer_dependence, context), 
  0, 0, 0
};

unsigned char _IR_D_LR_set [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_LR_situation, _IR_S_LR_situation)
    + _IR_offsetof (struct _IR_S_LR_situation, LR_set), 
  0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_LR_set_dependence, _IR_S_LR_set_dependence)
    + _IR_offsetof (struct _IR_S_LR_set_dependence, LR_set), 
  0, 0, 0, 0, 0
};

unsigned char _IR_D_result_LR_set_will_be_on_the_stack [] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
  _IR_offsetof (_IR_regular_arc, _IR_S_regular_arc)
    + _IR_offsetof (struct _IR_S_regular_arc, result_LR_set_will_be_on_the_stack), 
  _IR_offsetof (_IR_rule_list_element, _IR_S_rule_list_element)
    + _IR_offsetof (struct _IR_S_rule_list_element, result_LR_set_will_be_on_the_stack), 
  0, 0, 0, 0, 0, 0, 0, 0
};

void *_IR_class_structure_array [] =
{
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
};

const char *IR_node_name[] =
{
  "node",
  "identifier_or_literal",
  "identifier",
  "literal",
  "string",
  "number",
  "code_insertion",
  "additional_code",
  "definition",
  "start_definition",
  "code",
  "yacc_code",
  "local_code",
  "import_code",
  "export_code",
  "union_code",
  "scanner_definition",
  "expect_definition",
  "symbol_definition",
  "token_definition",
  "left_definition",
  "right_definition",
  "nonassoc_definition",
  "type_definition",
  "symbol",
  "rule",
  "pattern",
  "alternative",
  "sequence",
  "separator_iteration",
  "sequence_element",
  "control_point",
  "default",
  "star_iteration",
  "plus_iteration",
  "code_insertion_atom",
  "unit",
  "group",
  "range_atom",
  "range_no_left_bound_atom",
  "range_no_right_bound_atom",
  "range_no_left_right_bounds_atom",
  "identifier_or_literal_atom",
  "string_atom",
  "description",
  "denotation",
  "single_definition",
  "single_term_definition",
  "literal_range_definition",
  "single_nonterm_definition",
  "canonical_rule",
  "right_hand_side_element",
  "canonical_rule_element",
  "canonical_rule_end",
  "LR_situation",
  "LR_set",
  "LR_set_look_ahead_trie_node",
  "back_track_alternative",
  "conflict",
  "regular_arc",
  "rule_list_element",
  "LR_core",
  "DeRemer_dependence",
  "LR_set_dependence",
  "shift_dependence",
  "shift_LR_situation_dependence",
  "dependence_list_element",
  "%root",
  "%error"
};

unsigned char IR_node_size[] =
{
  sizeof (_IR_node),
  sizeof (_IR_identifier_or_literal),
  sizeof (_IR_identifier),
  sizeof (_IR_literal),
  sizeof (_IR_string),
  sizeof (_IR_number),
  sizeof (_IR_code_insertion),
  sizeof (_IR_additional_code),
  sizeof (_IR_definition),
  sizeof (_IR_start_definition),
  sizeof (_IR_code),
  sizeof (_IR_yacc_code),
  sizeof (_IR_local_code),
  sizeof (_IR_import_code),
  sizeof (_IR_export_code),
  sizeof (_IR_union_code),
  sizeof (_IR_scanner_definition),
  sizeof (_IR_expect_definition),
  sizeof (_IR_symbol_definition),
  sizeof (_IR_token_definition),
  sizeof (_IR_left_definition),
  sizeof (_IR_right_definition),
  sizeof (_IR_nonassoc_definition),
  sizeof (_IR_type_definition),
  sizeof (_IR_symbol),
  sizeof (_IR_rule),
  sizeof (_IR_pattern),
  sizeof (_IR_alternative),
  sizeof (_IR_sequence),
  sizeof (_IR_separator_iteration),
  sizeof (_IR_sequence_element),
  sizeof (_IR_control_point),
  sizeof (_IR_default),
  sizeof (_IR_star_iteration),
  sizeof (_IR_plus_iteration),
  sizeof (_IR_code_insertion_atom),
  sizeof (_IR_unit),
  sizeof (_IR_group),
  sizeof (_IR_range_atom),
  sizeof (_IR_range_no_left_bound_atom),
  sizeof (_IR_range_no_right_bound_atom),
  sizeof (_IR_range_no_left_right_bounds_atom),
  sizeof (_IR_identifier_or_literal_atom),
  sizeof (_IR_string_atom),
  sizeof (_IR_description),
  sizeof (_IR_denotation),
  sizeof (_IR_single_definition),
  sizeof (_IR_single_term_definition),
  sizeof (_IR_literal_range_definition),
  sizeof (_IR_single_nonterm_definition),
  sizeof (_IR_canonical_rule),
  sizeof (_IR_right_hand_side_element),
  sizeof (_IR_canonical_rule_element),
  sizeof (_IR_canonical_rule_end),
  sizeof (_IR_LR_situation),
  sizeof (_IR_LR_set),
  sizeof (_IR_LR_set_look_ahead_trie_node),
  sizeof (_IR_back_track_alternative),
  sizeof (_IR_conflict),
  sizeof (_IR_regular_arc),
  sizeof (_IR_rule_list_element),
  sizeof (_IR_LR_core),
  sizeof (_IR_DeRemer_dependence),
  sizeof (_IR_LR_set_dependence),
  sizeof (_IR_shift_dependence),
  sizeof (_IR_shift_LR_situation_dependence),
  sizeof (_IR_dependence_list_element),
  sizeof (_IR__root),
  sizeof (_IR__error)
};

static int (* _IR_traverse_guard_function_variable) (IR_node_t node);

static int _IR_current_graph_pass_number;

void _IR_set_double_field_value
  (IR_double_link_t link, IR_node_t value, int disp, int flag)
{
  if (!flag)
    {
      /* Deletion from double linked field list */
      if (link->field_itself != NULL)
        {
          if (link->previous_link != NULL)
            link->previous_link->next_link = link->next_link;
          else
            *(IR_double_link_t *) ((char *) link->field_itself + disp) = link->next_link;
          if (link->next_link != NULL)
            link->next_link->previous_link = link->previous_link;
        }
      link->field_itself = value;
    }
  /* Inclusion into double linked field list */
  if (link->field_itself != NULL)
    {
      link->next_link = *(IR_double_link_t *) ((char *) link->field_itself + disp);
      if (*(IR_double_link_t *) ((char *) link->field_itself + disp) != NULL)
        (*(IR_double_link_t *) ((char *) link->field_itself + disp))->previous_link = link;
      link->previous_link = NULL;
      *(IR_double_link_t *) ((char *) link->field_itself + disp) = link;
    }
}

IR_double_link_t IR__first_double_link (IR_node_t node)
{
  switch (IR_NODE_MODE (node))
    {
    case IR_NM_identifier:
      return NULL;
    case IR_NM_literal:
      return NULL;
    case IR_NM_string:
      return NULL;
    case IR_NM_number:
      return NULL;
    case IR_NM_code_insertion:
      return NULL;
    case IR_NM_additional_code:
      return NULL;
    case IR_NM_start_definition:
      return NULL;
    case IR_NM_yacc_code:
      return NULL;
    case IR_NM_local_code:
      return NULL;
    case IR_NM_import_code:
      return NULL;
    case IR_NM_export_code:
      return NULL;
    case IR_NM_union_code:
      return NULL;
    case IR_NM_scanner_definition:
      return NULL;
    case IR_NM_expect_definition:
      return NULL;
    case IR_NM_token_definition:
      return NULL;
    case IR_NM_left_definition:
      return NULL;
    case IR_NM_right_definition:
      return NULL;
    case IR_NM_nonassoc_definition:
      return NULL;
    case IR_NM_type_definition:
      return NULL;
    case IR_NM_symbol:
      return NULL;
    case IR_NM_rule:
      return NULL;
    case IR_NM_pattern:
      return NULL;
    case IR_NM_sequence:
      return NULL;
    case IR_NM_separator_iteration:
      return NULL;
    case IR_NM_control_point:
      return NULL;
    case IR_NM_default:
      return NULL;
    case IR_NM_star_iteration:
      return NULL;
    case IR_NM_plus_iteration:
      return NULL;
    case IR_NM_code_insertion_atom:
      return NULL;
    case IR_NM_group:
      return NULL;
    case IR_NM_range_atom:
      return NULL;
    case IR_NM_range_no_left_bound_atom:
      return NULL;
    case IR_NM_range_no_right_bound_atom:
      return NULL;
    case IR_NM_range_no_left_right_bounds_atom:
      return NULL;
    case IR_NM_identifier_or_literal_atom:
      return NULL;
    case IR_NM_string_atom:
      return NULL;
    case IR_NM_description:
      return NULL;
    case IR_NM_single_term_definition:
      return NULL;
    case IR_NM_literal_range_definition:
      return NULL;
    case IR_NM_single_nonterm_definition:
      return NULL;
    case IR_NM_canonical_rule:
      return NULL;
    case IR_NM_canonical_rule_element:
      return NULL;
    case IR_NM_canonical_rule_end:
      return NULL;
    case IR_NM_LR_situation:
      return NULL;
    case IR_NM_LR_set:
      return ((_IR__root *) node)->_IR_first_link;
    case IR_NM_LR_set_look_ahead_trie_node:
      return NULL;
    case IR_NM_back_track_alternative:
      return NULL;
    case IR_NM_conflict:
      return NULL;
    case IR_NM_regular_arc:
      return NULL;
    case IR_NM_rule_list_element:
      return NULL;
    case IR_NM_LR_core:
      return NULL;
    case IR_NM_LR_set_dependence:
      return NULL;
    case IR_NM_shift_dependence:
      return NULL;
    case IR_NM_shift_LR_situation_dependence:
      return NULL;
    case IR_NM_dependence_list_element:
      return NULL;
    default:
      abort ();
      break;
    }
}

void IR__set_double_link (IR_double_link_t link, IR_node_t value)
{
#ifdef __IR_DEBUG__
  if (link == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  (*link->set_function) (link->link_owner, value);
}

void IR_F_set_goto_LR_set (IR_node_t _node, IR_node_t _value)
{
#ifdef __IR_DEBUG__
  if (_node == NULL
      || (_value != NULL && !((_IR_SF_LR_set [IR_NODE_MODE (_value) / 8] >> (IR_NODE_MODE (_value) % 8)) & 1)
         && IR_NODE_MODE (_value) != IR_NM__error)
      || !((_IR_SF_LR_situation [IR_NODE_MODE (_node) / 8] >> (IR_NODE_MODE (_node) % 8)) & 1))
    abort ();
#endif /* __IR_DEBUG__ */
  _IR_set_double_field_value
    (&((((_IR_LR_situation *) _node)->_IR_S_LR_situation.goto_LR_set)), _value,
     _IR_offsetof (struct IR_node, _IR_first_link), 0);
}

void IR_F_set_to_LR_set (IR_node_t _node, IR_node_t _value)
{
#ifdef __IR_DEBUG__
  if (_node == NULL
      || (_value != NULL && !((_IR_SF_LR_set [IR_NODE_MODE (_value) / 8] >> (IR_NODE_MODE (_value) % 8)) & 1)
         && IR_NODE_MODE (_value) != IR_NM__error)
      || !((_IR_SF_regular_arc [IR_NODE_MODE (_node) / 8] >> (IR_NODE_MODE (_node) % 8)) & 1))
    abort ();
#endif /* __IR_DEBUG__ */
  _IR_set_double_field_value
    (&((((_IR_regular_arc *) _node)->_IR_S_regular_arc.to_LR_set)), _value,
     _IR_offsetof (struct IR_node, _IR_first_link), 0);
}

static void _IR_node_field_initiation (IR_node_mode_t node_mode, IR_node_t node)
{
  switch (node_mode)
    {
    case IR_NM_node:
      IR_BEGIN_position_t ((((_IR_node *) node)->_IR_S_node.position));
      break;
    case IR_NM_identifier_or_literal:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_identifier_or_literal *) node)->_IR_S_identifier_or_literal._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      break;
    case IR_NM_identifier:
      _IR_node_field_initiation (IR_NM_identifier_or_literal, (IR_node_t) ((char *) &((_IR_identifier *) node)->_IR_S_identifier._IR_M_identifier_or_literal - _IR_offsetof (_IR_identifier_or_literal, _IR_S_identifier_or_literal)));
      IR_BEGIN_string_t ((((_IR_identifier *) node)->_IR_S_identifier.identifier_itself));
      IR_BEGIN_bool_t ((((_IR_identifier *) node)->_IR_S_identifier.dot_presence_flag));
      break;
    case IR_NM_literal:
      _IR_node_field_initiation (IR_NM_identifier_or_literal, (IR_node_t) ((char *) &((_IR_literal *) node)->_IR_S_literal._IR_M_identifier_or_literal - _IR_offsetof (_IR_identifier_or_literal, _IR_S_identifier_or_literal)));
      IR_BEGIN_string_t ((((_IR_literal *) node)->_IR_S_literal.character_representation));
      IR_BEGIN_integer_t ((((_IR_literal *) node)->_IR_S_literal.literal_code));
      break;
    case IR_NM_string:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_string *) node)->_IR_S_string._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_string *) node)->_IR_S_string.string_representation));
      IR_BEGIN_string_t ((((_IR_string *) node)->_IR_S_string.string_itself));
      break;
    case IR_NM_number:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_number *) node)->_IR_S_number._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_integer_t ((((_IR_number *) node)->_IR_S_number.number_value));
      break;
    case IR_NM_code_insertion:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_code_insertion *) node)->_IR_S_code_insertion._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_code_insertion *) node)->_IR_S_code_insertion.code_insertion_itself));
      break;
    case IR_NM_additional_code:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_additional_code *) node)->_IR_S_additional_code._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_string_t ((((_IR_additional_code *) node)->_IR_S_additional_code.additional_code_itself));
      break;
    case IR_NM_definition:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_definition *) node)->_IR_S_definition._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_definition *) node)->_IR_S_definition.next_definition));
      break;
    case IR_NM_start_definition:
      _IR_node_field_initiation (IR_NM_definition, (IR_node_t) ((char *) &((_IR_start_definition *) node)->_IR_S_start_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_BEGIN_IR_node_t ((((_IR_start_definition *) node)->_IR_S_start_definition.identifier));
      break;
    case IR_NM_code:
      _IR_node_field_initiation (IR_NM_definition, (IR_node_t) ((char *) &((_IR_code *) node)->_IR_S_code._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_BEGIN_IR_node_t ((((_IR_code *) node)->_IR_S_code.code_itself));
      break;
    case IR_NM_yacc_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_yacc_code *) node)->_IR_S_yacc_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_local_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_local_code *) node)->_IR_S_local_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_import_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_import_code *) node)->_IR_S_import_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_export_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_export_code *) node)->_IR_S_export_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_union_code:
      _IR_node_field_initiation (IR_NM_code, (IR_node_t) ((char *) &((_IR_union_code *) node)->_IR_S_union_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_scanner_definition:
      _IR_node_field_initiation (IR_NM_definition, (IR_node_t) ((char *) &((_IR_scanner_definition *) node)->_IR_S_scanner_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      break;
    case IR_NM_expect_definition:
      _IR_node_field_initiation (IR_NM_definition, (IR_node_t) ((char *) &((_IR_expect_definition *) node)->_IR_S_expect_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_BEGIN_IR_node_t ((((_IR_expect_definition *) node)->_IR_S_expect_definition.expected_number));
      break;
    case IR_NM_symbol_definition:
      _IR_node_field_initiation (IR_NM_definition, (IR_node_t) ((char *) &((_IR_symbol_definition *) node)->_IR_S_symbol_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_BEGIN_IR_node_t ((((_IR_symbol_definition *) node)->_IR_S_symbol_definition.symbol_list));
      IR_BEGIN_IR_node_t ((((_IR_symbol_definition *) node)->_IR_S_symbol_definition.tag));
      break;
    case IR_NM_token_definition:
      _IR_node_field_initiation (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_token_definition *) node)->_IR_S_token_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_left_definition:
      _IR_node_field_initiation (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_left_definition *) node)->_IR_S_left_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_right_definition:
      _IR_node_field_initiation (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_right_definition *) node)->_IR_S_right_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_nonassoc_definition:
      _IR_node_field_initiation (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_nonassoc_definition *) node)->_IR_S_nonassoc_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_type_definition:
      _IR_node_field_initiation (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_type_definition *) node)->_IR_S_type_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_symbol:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_symbol *) node)->_IR_S_symbol._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_symbol *) node)->_IR_S_symbol.identifier_or_literal));
      IR_BEGIN_IR_node_t ((((_IR_symbol *) node)->_IR_S_symbol.number));
      IR_BEGIN_IR_node_t ((((_IR_symbol *) node)->_IR_S_symbol.next_symbol));
      break;
    case IR_NM_rule:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_rule *) node)->_IR_S_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.nonterm_identifier));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.pattern));
      IR_BEGIN_IR_node_t ((((_IR_rule *) node)->_IR_S_rule.next_rule));
      break;
    case IR_NM_pattern:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_pattern *) node)->_IR_S_pattern._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_pattern *) node)->_IR_S_pattern.alternatives_list));
      break;
    case IR_NM_alternative:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_alternative *) node)->_IR_S_alternative._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      _IR_node_field_initiation (IR_NM_denotation, (IR_node_t) ((char *) &((_IR_alternative *) node)->_IR_S_alternative._IR_M_denotation - _IR_offsetof (_IR_denotation, _IR_S_denotation)));
      IR_BEGIN_IR_node_t ((((_IR_alternative *) node)->_IR_S_alternative.next_alternative));
      break;
    case IR_NM_sequence:
      _IR_node_field_initiation (IR_NM_alternative, (IR_node_t) ((char *) &((_IR_sequence *) node)->_IR_S_sequence._IR_M_alternative - _IR_offsetof (_IR_alternative, _IR_S_alternative)));
      IR_BEGIN_IR_node_t ((((_IR_sequence *) node)->_IR_S_sequence.sequence));
      IR_BEGIN_IR_node_t ((((_IR_sequence *) node)->_IR_S_sequence.precedence_identifier_or_literal));
      IR_BEGIN_IR_node_t ((((_IR_sequence *) node)->_IR_S_sequence.max_look_ahead_number));
      break;
    case IR_NM_separator_iteration:
      _IR_node_field_initiation (IR_NM_alternative, (IR_node_t) ((char *) &((_IR_separator_iteration *) node)->_IR_S_separator_iteration._IR_M_alternative - _IR_offsetof (_IR_alternative, _IR_S_alternative)));
      IR_BEGIN_IR_node_t ((((_IR_separator_iteration *) node)->_IR_S_separator_iteration.iteration_sequence));
      IR_BEGIN_IR_node_t ((((_IR_separator_iteration *) node)->_IR_S_separator_iteration.iteration_precedence_identifier_or_literal));
      IR_BEGIN_IR_node_t ((((_IR_separator_iteration *) node)->_IR_S_separator_iteration.iteration_max_look_ahead_number));
      IR_BEGIN_IR_node_t ((((_IR_separator_iteration *) node)->_IR_S_separator_iteration.separator_sequence));
      IR_BEGIN_IR_node_t ((((_IR_separator_iteration *) node)->_IR_S_separator_iteration.separator_precedence_identifier_or_literal));
      IR_BEGIN_IR_node_t ((((_IR_separator_iteration *) node)->_IR_S_separator_iteration.separator_max_look_ahead_number));
      break;
    case IR_NM_sequence_element:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_sequence_element *) node)->_IR_S_sequence_element._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      _IR_node_field_initiation (IR_NM_denotation, (IR_node_t) ((char *) &((_IR_sequence_element *) node)->_IR_S_sequence_element._IR_M_denotation - _IR_offsetof (_IR_denotation, _IR_S_denotation)));
      IR_BEGIN_IR_node_t ((((_IR_sequence_element *) node)->_IR_S_sequence_element.next_sequence_element));
      IR_BEGIN_IR_node_t ((((_IR_sequence_element *) node)->_IR_S_sequence_element.sequence_element_identifier));
      break;
    case IR_NM_control_point:
      _IR_node_field_initiation (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_control_point *) node)->_IR_S_control_point._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      break;
    case IR_NM_default:
      _IR_node_field_initiation (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_default *) node)->_IR_S_default._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_BEGIN_IR_node_t ((((_IR_default *) node)->_IR_S_default.default_pattern));
      break;
    case IR_NM_star_iteration:
      _IR_node_field_initiation (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_star_iteration *) node)->_IR_S_star_iteration._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_BEGIN_IR_node_t ((((_IR_star_iteration *) node)->_IR_S_star_iteration.iteration_unit));
      break;
    case IR_NM_plus_iteration:
      _IR_node_field_initiation (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_plus_iteration *) node)->_IR_S_plus_iteration._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_BEGIN_IR_node_t ((((_IR_plus_iteration *) node)->_IR_S_plus_iteration.iteration_unit));
      break;
    case IR_NM_code_insertion_atom:
      _IR_node_field_initiation (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_code_insertion_atom *) node)->_IR_S_code_insertion_atom._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_BEGIN_IR_node_t ((((_IR_code_insertion_atom *) node)->_IR_S_code_insertion_atom.code_insertion));
      break;
    case IR_NM_unit:
      _IR_node_field_initiation (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_unit *) node)->_IR_S_unit._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      break;
    case IR_NM_group:
      _IR_node_field_initiation (IR_NM_unit, (IR_node_t) ((char *) &((_IR_group *) node)->_IR_S_group._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_BEGIN_IR_node_t ((((_IR_group *) node)->_IR_S_group.pattern));
      break;
    case IR_NM_range_atom:
      _IR_node_field_initiation (IR_NM_unit, (IR_node_t) ((char *) &((_IR_range_atom *) node)->_IR_S_range_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_BEGIN_IR_node_t ((((_IR_range_atom *) node)->_IR_S_range_atom.left_bound));
      IR_BEGIN_IR_node_t ((((_IR_range_atom *) node)->_IR_S_range_atom.right_bound));
      break;
    case IR_NM_range_no_left_bound_atom:
      _IR_node_field_initiation (IR_NM_range_atom, (IR_node_t) ((char *) &((_IR_range_no_left_bound_atom *) node)->_IR_S_range_no_left_bound_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)));
      break;
    case IR_NM_range_no_right_bound_atom:
      _IR_node_field_initiation (IR_NM_range_atom, (IR_node_t) ((char *) &((_IR_range_no_right_bound_atom *) node)->_IR_S_range_no_right_bound_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)));
      break;
    case IR_NM_range_no_left_right_bounds_atom:
      _IR_node_field_initiation (IR_NM_range_atom, (IR_node_t) ((char *) &((_IR_range_no_left_right_bounds_atom *) node)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)));
      break;
    case IR_NM_identifier_or_literal_atom:
      _IR_node_field_initiation (IR_NM_unit, (IR_node_t) ((char *) &((_IR_identifier_or_literal_atom *) node)->_IR_S_identifier_or_literal_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_BEGIN_IR_node_t ((((_IR_identifier_or_literal_atom *) node)->_IR_S_identifier_or_literal_atom.identifier_or_literal));
      break;
    case IR_NM_string_atom:
      _IR_node_field_initiation (IR_NM_unit, (IR_node_t) ((char *) &((_IR_string_atom *) node)->_IR_S_string_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_BEGIN_IR_node_t ((((_IR_string_atom *) node)->_IR_S_string_atom.string));
      break;
    case IR_NM_description:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_description *) node)->_IR_S_description._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.definition_list));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.rule_list));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.additional_code));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.union_code));
{

#line 723 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.union_code) = NULL;

#line 1492 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.single_definition_list));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.tokens_number));
{

#line 732 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.tokens_number) = 0;

#line 1501 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.nonterminals_number));
{

#line 737 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.nonterminals_number) = 0;

#line 1509 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.canonical_rules_number));
{

#line 742 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.canonical_rules_number) = 0;

#line 1517 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.duplicated_patterns_number));
{

#line 745 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.duplicated_patterns_number) = 0;

#line 1525 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.canonical_rule_list));
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.axiom_identifier));
{

#line 753 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.axiom_identifier) = NULL;

#line 1534 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.axiom_definition));
{

#line 758 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.axiom_definition) = NULL;

#line 1542 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_description *) node)->_IR_S_description.scanner_flag));
{

#line 761 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.scanner_flag) = FALSE;

#line 1550 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.expected_shift_reduce_conflicts_number));
{

#line 766 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.expected_shift_reduce_conflicts_number) = -1;

#line 1558 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_description *) node)->_IR_S_description.LR_core_list));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.splitted_LR_sets_number));
{

#line 1319 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.splitted_LR_sets_number) = 0;

#line 1567 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.LR_sets_number));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.pushed_LR_sets_number));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.reduces_number));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.all_number_of_regular_arcs));
{

#line 1332 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.all_number_of_regular_arcs) = 0;

#line 1578 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.number_of_regular_arcs));
{

#line 1335 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.number_of_regular_arcs) = 0;

#line 1586 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.token_equivalence_classes_number));
      IR_BEGIN_integer_t ((((_IR_description *) node)->_IR_S_description.duplicated_actions));
{

#line 1344 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.duplicated_actions) = 0;

#line 1595 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_description *) node)->_IR_S_description.back_tracking_exists));
{

#line 1346 "./ird.sprut"
(((_IR_description *) node)->_IR_S_description.back_tracking_exists) = FALSE;

#line 1603 "ird.c"
}
      break;
    case IR_NM_denotation:
      IR_BEGIN_IR_node_t ((((_IR_denotation *) node)->_IR_S_denotation.corresponding_single_nonterm_definition));
      break;
    case IR_NM_single_definition:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_single_definition *) node)->_IR_S_single_definition._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_single_definition *) node)->_IR_S_single_definition.type));
{

#line 544 "./ird.sprut"
(((_IR_single_definition *) node)->_IR_S_single_definition.type) = NULL;

#line 1617 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_single_definition *) node)->_IR_S_single_definition.accessibility_flag));
{

#line 547 "./ird.sprut"
(((_IR_single_definition *) node)->_IR_S_single_definition.accessibility_flag) = FALSE;

#line 1625 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_single_definition *) node)->_IR_S_single_definition.single_definition_usage_list));
{

#line 551 "./ird.sprut"
(((_IR_single_definition *) node)->_IR_S_single_definition.single_definition_usage_list) = NULL;

#line 1633 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_single_definition *) node)->_IR_S_single_definition.identifier_or_literal));
      IR_BEGIN_IR_node_t ((((_IR_single_definition *) node)->_IR_S_single_definition.next_single_definition));
      IR_BEGIN_IR_node_t ((((_IR_single_definition *) node)->_IR_S_single_definition.last_symbol_LR_situation_processed));
{

#line 850 "./ird.sprut"
(((_IR_single_definition *) node)->_IR_S_single_definition.last_symbol_LR_situation_processed) = NULL;

#line 1643 "ird.c"
}
      break;
    case IR_NM_single_term_definition:
      _IR_node_field_initiation (IR_NM_single_definition, (IR_node_t) ((char *) &((_IR_single_term_definition *) node)->_IR_S_single_term_definition._IR_M_single_definition - _IR_offsetof (_IR_single_definition, _IR_S_single_definition)));
      IR_BEGIN_integer_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.token_order_number));
      IR_BEGIN_integer_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.value));
{

#line 570 "./ird.sprut"
(((_IR_single_term_definition *) node)->_IR_S_single_term_definition.value) = (-1);

#line 1655 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.priority));
{

#line 574 "./ird.sprut"
(((_IR_single_term_definition *) node)->_IR_S_single_term_definition.priority) = (-1);

#line 1663 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.left_assoc_flag));
      IR_BEGIN_bool_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.right_assoc_flag));
      IR_BEGIN_bool_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.nonassoc_flag));
{

#line 576 "./ird.sprut"
(((_IR_single_term_definition *) node)->_IR_S_single_term_definition.nonassoc_flag) = FALSE;

#line 1673 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.deletion_flag));
{

#line 579 "./ird.sprut"
(((_IR_single_term_definition *) node)->_IR_S_single_term_definition.deletion_flag) = FALSE;

#line 1681 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.next_equivalence_class_token));
      IR_BEGIN_integer_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.equivalence_class_number));
      IR_BEGIN_bool_t ((((_IR_single_term_definition *) node)->_IR_S_single_term_definition.token_was_processed_on_equivalence));
      break;
    case IR_NM_literal_range_definition:
      _IR_node_field_initiation (IR_NM_single_term_definition, (IR_node_t) ((char *) &((_IR_literal_range_definition *) node)->_IR_S_literal_range_definition._IR_M_single_term_definition - _IR_offsetof (_IR_single_term_definition, _IR_S_single_term_definition)));
      IR_BEGIN_integer_t ((((_IR_literal_range_definition *) node)->_IR_S_literal_range_definition.right_range_bound_value));
      IR_BEGIN_bool_t ((((_IR_literal_range_definition *) node)->_IR_S_literal_range_definition.bounds_have_explicit_values));
{

#line 598 "./ird.sprut"
(((_IR_literal_range_definition *) node)->_IR_S_literal_range_definition.bounds_have_explicit_values) = FALSE;

#line 1696 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_literal_range_definition *) node)->_IR_S_literal_range_definition.right_range_bound_literal));
      break;
    case IR_NM_single_nonterm_definition:
      _IR_node_field_initiation (IR_NM_single_definition, (IR_node_t) ((char *) &((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition._IR_M_single_definition - _IR_offsetof (_IR_single_definition, _IR_S_single_definition)));
      IR_BEGIN_integer_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.nonterm_order_number));
      IR_BEGIN_IR_node_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.nonterm_canonical_rule_list));
{

#line 623 "./ird.sprut"
(((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.nonterm_canonical_rule_list) = NULL;

#line 1709 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.derivation_ability_flag));
{

#line 626 "./ird.sprut"
(((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.derivation_ability_flag) = FALSE;

#line 1717 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.pass_number));
      IR_BEGIN_IR_node_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.corresponding_pattern));
{

#line 614 "./ird.sprut"
(((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.corresponding_pattern) = NULL;

#line 1726 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.minimal_derived_string_length));
{

#line 820 "./ird.sprut"
(((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.minimal_derived_string_length) = -1; /* Undefined */

#line 1734 "ird.c"
}
      IR_BEGIN_context_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.relation_FIRST));
{

#line 826 "./ird.sprut"
(((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.relation_FIRST) = NULL;

#line 1742 "ird.c"
}
      IR_BEGIN_context_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.next_iter_relation_FIRST));
{

#line 829 "./ird.sprut"
(((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.next_iter_relation_FIRST) = NULL;

#line 1750 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.process_nonterminal_on_its_process_pass));
      IR_BEGIN_bool_t ((((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.pattern_has_been_output));
{

#line 836 "./ird.sprut"
(((_IR_single_nonterm_definition *) node)->_IR_S_single_nonterm_definition.pattern_has_been_output) = FALSE;

#line 1759 "ird.c"
}
      break;
    case IR_NM_canonical_rule:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_canonical_rule *) node)->_IR_S_canonical_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_bool_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.next_cp_flag));
{

#line 659 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.next_cp_flag) = FALSE;

#line 1770 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.canonical_rule_order_number));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.next_nonterm_canonical_rule));
{

#line 664 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.next_nonterm_canonical_rule) = NULL;

#line 1779 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.precedence_single_term_definition));
{

#line 667 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.precedence_single_term_definition) = NULL;

#line 1787 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.rule_priority));
{

#line 672 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.rule_priority) = (-1);

#line 1795 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.max_look_ahead_value));
{

#line 675 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.max_look_ahead_value) = 0;

#line 1803 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.output_action_number));
{

#line 679 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.output_action_number) = 0;

#line 1811 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.left_hand_side));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.right_hand_side));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.action));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.original_code_insertion_place));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.next_canonical_rule));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.canonical_rule_LR_situation));
{

#line 842 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.canonical_rule_LR_situation) = NULL;

#line 1824 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.canonical_rule_action_has_been_output));
{

#line 1300 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.canonical_rule_action_has_been_output) = FALSE;

#line 1832 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_canonical_rule *) node)->_IR_S_canonical_rule.action_code_copies_number));
{

#line 1308 "./ird.sprut"
(((_IR_canonical_rule *) node)->_IR_S_canonical_rule.action_code_copies_number) = 0;

#line 1840 "ird.c"
}
      break;
    case IR_NM_right_hand_side_element:
      _IR_node_field_initiation (IR_NM_node, (IR_node_t) ((char *) &((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_BEGIN_IR_node_t ((((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.canonical_rule));
      IR_BEGIN_IR_node_t ((((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.next_right_hand_side_element));
      IR_BEGIN_bool_t ((((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.cp_start_flag));
{

#line 776 "./ird.sprut"
(((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.cp_start_flag) = FALSE;

#line 1853 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.cp_flag));
{

#line 781 "./ird.sprut"
(((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.cp_flag) = FALSE;

#line 1861 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.minimal_FIRST_of_rule_tail_length));
      IR_BEGIN_context_t ((((_IR_right_hand_side_element *) node)->_IR_S_right_hand_side_element.FIRST_of_rule_tail));
      break;
    case IR_NM_canonical_rule_element:
      _IR_node_field_initiation (IR_NM_right_hand_side_element, (IR_node_t) ((char *) &((_IR_canonical_rule_element *) node)->_IR_S_canonical_rule_element._IR_M_right_hand_side_element - _IR_offsetof (_IR_right_hand_side_element, _IR_S_right_hand_side_element)));
      IR_BEGIN_bool_t ((((_IR_canonical_rule_element *) node)->_IR_S_canonical_rule_element.next_cp_flag));
{

#line 716 "./ird.sprut"
(((_IR_canonical_rule_element *) node)->_IR_S_canonical_rule_element.next_cp_flag) = FALSE;

#line 1874 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule_element *) node)->_IR_S_canonical_rule_element.element_itself));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule_element *) node)->_IR_S_canonical_rule_element.element_identifier));
      IR_BEGIN_IR_node_t ((((_IR_canonical_rule_element *) node)->_IR_S_canonical_rule_element.next_single_definition_usage));
      break;
    case IR_NM_canonical_rule_end:
      _IR_node_field_initiation (IR_NM_right_hand_side_element, (IR_node_t) ((char *) &((_IR_canonical_rule_end *) node)->_IR_S_canonical_rule_end._IR_M_right_hand_side_element - _IR_offsetof (_IR_right_hand_side_element, _IR_S_right_hand_side_element)));
      break;
    case IR_NM_LR_situation:
      IR_BEGIN_IR_node_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.goto_LR_set).field_itself);
      (((_IR_LR_situation *) node)->_IR_S_LR_situation.goto_LR_set).link_owner = node;
      (((_IR_LR_situation *) node)->_IR_S_LR_situation.goto_LR_set).set_function = IR_F_set_goto_LR_set;
{

#line 878 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.goto_LR_set).field_itself = NULL;

#line 1892 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.goto_arc_has_been_removed));
{

#line 883 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.goto_arc_has_been_removed) = FALSE;

#line 1900 "ird.c"
}
      IR_BEGIN_context_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.look_ahead_context));
{

#line 888 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.look_ahead_context) = NULL;

#line 1908 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.first_symbol_LR_situation));
      IR_BEGIN_IR_node_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.next_symbol_LR_situation));
{

#line 894 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.next_symbol_LR_situation) = NULL;

#line 1917 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.important_LR_situation_flag));
      IR_BEGIN_bool_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.situation_in_stack_flag));
{

#line 899 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.situation_in_stack_flag) = FALSE;

#line 1926 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.under_control_point_flag));
{

#line 905 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.under_control_point_flag) = FALSE;

#line 1934 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.back_tracking_conflict_flag));
{

#line 911 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.back_tracking_conflict_flag) = FALSE;

#line 1942 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.corresponding_regular_arc));
{

#line 927 "./ird.sprut"
(((_IR_LR_situation *) node)->_IR_S_LR_situation.corresponding_regular_arc) = NULL;

#line 1950 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.reduce_number));
      IR_BEGIN_integer_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.popped_LR_sets_number));
      IR_BEGIN_integer_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.popped_attributes_number));
      IR_BEGIN_IR_node_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.element_after_dot));
      IR_BEGIN_context_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.context));
      IR_BEGIN_IR_node_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.LR_set));
      IR_BEGIN_IR_node_t ((((_IR_LR_situation *) node)->_IR_S_LR_situation.next_LR_situation));
      break;
    case IR_NM_LR_set:
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.conflicts_list));
{

#line 984 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.conflicts_list) = NULL;

#line 1967 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.it_is_in_LALR_sets_stack));
{

#line 989 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.it_is_in_LALR_sets_stack) = FALSE;

#line 1975 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.reachable_flag));
{

#line 992 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.reachable_flag) = TRUE;

#line 1983 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.it_is_pushed_LR_set));
{

#line 993 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.it_is_pushed_LR_set) = FALSE;

#line 1991 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.it_is_errored_LR_set));
{

#line 995 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.it_is_errored_LR_set) = FALSE;

#line 1999 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.attribute_is_used));
{

#line 1000 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.attribute_is_used) = FALSE;

#line 2007 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.visit_flag));
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.first_splitted_LR_set));
{

#line 1006 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.first_splitted_LR_set) = NULL;

#line 2016 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.next_splitted_LR_set));
{

#line 1007 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.next_splitted_LR_set) = NULL;

#line 2024 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.back_tracking_flag));
{

#line 1010 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.back_tracking_flag) = FALSE;

#line 2032 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.it_is_in_reduce_action_LR_sets_stack));
{

#line 1018 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.it_is_in_reduce_action_LR_sets_stack) = FALSE;

#line 2040 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.LR_set_look_ahead_trie));
      IR_BEGIN_integer_t ((((_IR_LR_set *) node)->_IR_S_LR_set.LR_set_order_number));
      IR_BEGIN_integer_t ((((_IR_LR_set *) node)->_IR_S_LR_set.term_arcs_number));
      IR_BEGIN_integer_t ((((_IR_LR_set *) node)->_IR_S_LR_set.nonterm_arcs_number));
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.start_LR_set_pass));
{

#line 1037 "./ird.sprut"
(((_IR_LR_set *) node)->_IR_S_LR_set.start_LR_set_pass) = NULL;

#line 2052 "ird.c"
}
      IR_BEGIN_bool_t ((((_IR_LR_set *) node)->_IR_S_LR_set.LR_set_has_been_output_in_comment));
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.LR_situation_list));
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.LR_core));
      IR_BEGIN_IR_node_t ((((_IR_LR_set *) node)->_IR_S_LR_set.next_LR_set));
      break;
    case IR_NM_LR_set_look_ahead_trie_node:
      IR_BEGIN_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.first_back_track_alternative));
{

#line 1080 "./ird.sprut"
(((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.first_back_track_alternative) = NULL;

#line 2066 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.last_back_track_alternative));
{

#line 1084 "./ird.sprut"
(((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.last_back_track_alternative) = NULL;

#line 2074 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.additional_action_table_number));
      IR_BEGIN_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.corresponding_single_term_definition));
      IR_BEGIN_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.corresponding_LR_situation));
      IR_BEGIN_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.first_son));
      IR_BEGIN_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) node)->_IR_S_LR_set_look_ahead_trie_node.next_brother));
      break;
    case IR_NM_back_track_alternative:
      IR_BEGIN_IR_node_t ((((_IR_back_track_alternative *) node)->_IR_S_back_track_alternative.corresponding_LR_set_look_ahead_trie_node));
      IR_BEGIN_IR_node_t ((((_IR_back_track_alternative *) node)->_IR_S_back_track_alternative.next_back_track_alternative));
      break;
    case IR_NM_conflict:
      IR_BEGIN_IR_node_t ((((_IR_conflict *) node)->_IR_S_conflict.used_LR_situation));
      IR_BEGIN_IR_node_t ((((_IR_conflict *) node)->_IR_S_conflict.unused_LR_situation));
      IR_BEGIN_token_string_t ((((_IR_conflict *) node)->_IR_S_conflict.token_string));
      IR_BEGIN_IR_node_t ((((_IR_conflict *) node)->_IR_S_conflict.next_conflict));
      break;
    case IR_NM_regular_arc:
      IR_BEGIN_IR_node_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.first_rule_list_element));
{

#line 1142 "./ird.sprut"
(((_IR_regular_arc *) node)->_IR_S_regular_arc.first_rule_list_element) = NULL;

#line 2099 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.last_rule_list_element));
{

#line 1143 "./ird.sprut"
(((_IR_regular_arc *) node)->_IR_S_regular_arc.last_rule_list_element) = NULL;

#line 2107 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.regular_arc_popped_LR_sets_number));
      IR_BEGIN_integer_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.regular_arc_popped_attributes_number));
      IR_BEGIN_integer_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.max_states_stack_increment));
      IR_BEGIN_integer_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.max_attributes_stack_increment));
      IR_BEGIN_bool_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.first_equivalent_regular_arc_flag));
{

#line 1188 "./ird.sprut"
(((_IR_regular_arc *) node)->_IR_S_regular_arc.first_equivalent_regular_arc_flag) = FALSE;

#line 2119 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.next_equivalent_regular_arc));
{

#line 1190 "./ird.sprut"
(((_IR_regular_arc *) node)->_IR_S_regular_arc.next_equivalent_regular_arc) = NULL;

#line 2127 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.number_of_regular_arc));
      IR_BEGIN_bool_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.result_LR_set_will_be_on_the_stack));
{

#line 1198 "./ird.sprut"
(((_IR_regular_arc *) node)->_IR_S_regular_arc.result_LR_set_will_be_on_the_stack) = 0 /* FALSE */;

#line 2136 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.from_LR_situation));
      IR_BEGIN_IR_node_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.to_LR_set).field_itself);
      (((_IR_regular_arc *) node)->_IR_S_regular_arc.to_LR_set).link_owner = node;
      (((_IR_regular_arc *) node)->_IR_S_regular_arc.to_LR_set).set_function = IR_F_set_to_LR_set;
      IR_BEGIN_IR_node_t ((((_IR_regular_arc *) node)->_IR_S_regular_arc.terminal_marking_arc));
      break;
    case IR_NM_rule_list_element:
      IR_BEGIN_integer_t ((((_IR_rule_list_element *) node)->_IR_S_rule_list_element.right_hand_side_used_attributes_number));
      IR_BEGIN_bool_t ((((_IR_rule_list_element *) node)->_IR_S_rule_list_element.lhs_nonterm_attribute_is_used));
      IR_BEGIN_bool_t ((((_IR_rule_list_element *) node)->_IR_S_rule_list_element.result_LR_set_will_be_on_the_stack));
{

#line 1222 "./ird.sprut"
(((_IR_rule_list_element *) node)->_IR_S_rule_list_element.result_LR_set_will_be_on_the_stack) = 0 /* FALSE */;

#line 2153 "ird.c"
}
      IR_BEGIN_IR_node_t ((((_IR_rule_list_element *) node)->_IR_S_rule_list_element.canonical_rule));
      IR_BEGIN_IR_node_t ((((_IR_rule_list_element *) node)->_IR_S_rule_list_element.next_rule_list_element));
      break;
    case IR_NM_LR_core:
      IR_BEGIN_bool_t ((((_IR_LR_core *) node)->_IR_S_LR_core.first_pass_flag));
      IR_BEGIN_bool_t ((((_IR_LR_core *) node)->_IR_S_LR_core.second_pass_flag));
      IR_BEGIN_IR_node_t ((((_IR_LR_core *) node)->_IR_S_LR_core.LR_set_list));
      IR_BEGIN_IR_node_t ((((_IR_LR_core *) node)->_IR_S_LR_core.next_LR_core));
      break;
    case IR_NM_DeRemer_dependence:
      IR_BEGIN_context_t ((((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.context));
      IR_BEGIN_IR_node_t ((((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.dependencies));
      IR_BEGIN_bool_t ((((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.context_has_been_evaluated));
{

#line 1254 "./ird.sprut"
(((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.context_has_been_evaluated) = FALSE;

#line 2173 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.pass_number));
{

#line 1257 "./ird.sprut"
(((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.pass_number) = -1;

#line 2181 "ird.c"
}
      IR_BEGIN_integer_t ((((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.unique_number));
      IR_BEGIN_integer_t ((((_IR_DeRemer_dependence *) node)->_IR_S_DeRemer_dependence.look_ahead));
      break;
    case IR_NM_LR_set_dependence:
      _IR_node_field_initiation (IR_NM_DeRemer_dependence, (IR_node_t) ((char *) &((_IR_LR_set_dependence *) node)->_IR_S_LR_set_dependence._IR_M_DeRemer_dependence - _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)));
      IR_BEGIN_IR_node_t ((((_IR_LR_set_dependence *) node)->_IR_S_LR_set_dependence.LR_set));
      IR_BEGIN_integer_t ((((_IR_LR_set_dependence *) node)->_IR_S_LR_set_dependence.back_distance));
      IR_BEGIN_IR_node_t ((((_IR_LR_set_dependence *) node)->_IR_S_LR_set_dependence.nonterm));
      break;
    case IR_NM_shift_dependence:
      _IR_node_field_initiation (IR_NM_DeRemer_dependence, (IR_node_t) ((char *) &((_IR_shift_dependence *) node)->_IR_S_shift_dependence._IR_M_DeRemer_dependence - _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)));
      IR_BEGIN_IR_node_t ((((_IR_shift_dependence *) node)->_IR_S_shift_dependence.token));
      break;
    case IR_NM_shift_LR_situation_dependence:
      _IR_node_field_initiation (IR_NM_shift_dependence, (IR_node_t) ((char *) &((_IR_shift_LR_situation_dependence *) node)->_IR_S_shift_LR_situation_dependence._IR_M_shift_dependence - _IR_offsetof (_IR_shift_dependence, _IR_S_shift_dependence)));
      IR_BEGIN_IR_node_t ((((_IR_shift_LR_situation_dependence *) node)->_IR_S_shift_LR_situation_dependence.shift_LR_situation));
      break;
    case IR_NM_dependence_list_element:
      IR_BEGIN_IR_node_t ((((_IR_dependence_list_element *) node)->_IR_S_dependence_list_element.dependence));
      IR_BEGIN_IR_node_t ((((_IR_dependence_list_element *) node)->_IR_S_dependence_list_element.next_dependence_list_element));
      break;
    case IR_NM__error:
      break;
    default:
      abort ();
      break;
    }
}

IR_node_t IR_create_node (IR_node_mode_t node_mode)
{
 IR_node_t _result;

  IR_ALLOC (_result, IR_node_size [node_mode], IR_node_t);
#ifdef __IR_DEBUG__
  if (_result == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  IR_NODE_MODE (_result) = node_mode;
  ((_IR__root *) _result)->_IR_first_link = NULL;
  _IR_node_field_initiation (node_mode, _result);
  return _result;
}

IR_node_t IR_new_identifier
(position_t position,
 string_t identifier_itself,
 bool_t dot_presence_flag)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_identifier);
  (((_IR_identifier *) _result)->_IR_S_identifier._IR_M_identifier_or_literal._IR_M_node.position) = position;
  (((_IR_identifier *) _result)->_IR_S_identifier.identifier_itself) = identifier_itself;
  (((_IR_identifier *) _result)->_IR_S_identifier.dot_presence_flag) = dot_presence_flag;
  return _result;
}

IR_node_t IR_new_literal
(position_t position,
 string_t character_representation,
 integer_t literal_code)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_literal);
  (((_IR_literal *) _result)->_IR_S_literal._IR_M_identifier_or_literal._IR_M_node.position) = position;
  (((_IR_literal *) _result)->_IR_S_literal.character_representation) = character_representation;
  (((_IR_literal *) _result)->_IR_S_literal.literal_code) = literal_code;
  return _result;
}

IR_node_t IR_new_string
(position_t position,
 string_t string_representation,
 string_t string_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_string);
  (((_IR_string *) _result)->_IR_S_string._IR_M_node.position) = position;
  (((_IR_string *) _result)->_IR_S_string.string_representation) = string_representation;
  (((_IR_string *) _result)->_IR_S_string.string_itself) = string_itself;
  return _result;
}

IR_node_t IR_new_number
(position_t position,
 integer_t number_value)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_number);
  (((_IR_number *) _result)->_IR_S_number._IR_M_node.position) = position;
  (((_IR_number *) _result)->_IR_S_number.number_value) = number_value;
  return _result;
}

IR_node_t IR_new_code_insertion
(position_t position,
 string_t code_insertion_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_code_insertion);
  (((_IR_code_insertion *) _result)->_IR_S_code_insertion._IR_M_node.position) = position;
  (((_IR_code_insertion *) _result)->_IR_S_code_insertion.code_insertion_itself) = code_insertion_itself;
  return _result;
}

IR_node_t IR_new_additional_code
(position_t position,
 string_t additional_code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_additional_code);
  (((_IR_additional_code *) _result)->_IR_S_additional_code._IR_M_node.position) = position;
  (((_IR_additional_code *) _result)->_IR_S_additional_code.additional_code_itself) = additional_code_itself;
  return _result;
}

IR_node_t IR_new_start_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t identifier)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_start_definition);
  (((_IR_start_definition *) _result)->_IR_S_start_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_start_definition *) _result)->_IR_S_start_definition._IR_M_definition.next_definition) = next_definition;
  (((_IR_start_definition *) _result)->_IR_S_start_definition.identifier) = identifier;
  return _result;
}

IR_node_t IR_new_yacc_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_yacc_code);
  (((_IR_yacc_code *) _result)->_IR_S_yacc_code._IR_M_code._IR_M_definition._IR_M_node.position) = position;
  (((_IR_yacc_code *) _result)->_IR_S_yacc_code._IR_M_code._IR_M_definition.next_definition) = next_definition;
  (((_IR_yacc_code *) _result)->_IR_S_yacc_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_local_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_local_code);
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code._IR_M_definition._IR_M_node.position) = position;
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code._IR_M_definition.next_definition) = next_definition;
  (((_IR_local_code *) _result)->_IR_S_local_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_import_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_import_code);
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code._IR_M_definition._IR_M_node.position) = position;
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code._IR_M_definition.next_definition) = next_definition;
  (((_IR_import_code *) _result)->_IR_S_import_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_export_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_export_code);
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code._IR_M_definition._IR_M_node.position) = position;
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code._IR_M_definition.next_definition) = next_definition;
  (((_IR_export_code *) _result)->_IR_S_export_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_union_code
(position_t position,
 IR_node_t next_definition,
 IR_node_t code_itself)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_union_code);
  (((_IR_union_code *) _result)->_IR_S_union_code._IR_M_code._IR_M_definition._IR_M_node.position) = position;
  (((_IR_union_code *) _result)->_IR_S_union_code._IR_M_code._IR_M_definition.next_definition) = next_definition;
  (((_IR_union_code *) _result)->_IR_S_union_code._IR_M_code.code_itself) = code_itself;
  return _result;
}

IR_node_t IR_new_scanner_definition
(position_t position,
 IR_node_t next_definition)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_scanner_definition);
  (((_IR_scanner_definition *) _result)->_IR_S_scanner_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_scanner_definition *) _result)->_IR_S_scanner_definition._IR_M_definition.next_definition) = next_definition;
  return _result;
}

IR_node_t IR_new_expect_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t expected_number)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_expect_definition);
  (((_IR_expect_definition *) _result)->_IR_S_expect_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_expect_definition *) _result)->_IR_S_expect_definition._IR_M_definition.next_definition) = next_definition;
  (((_IR_expect_definition *) _result)->_IR_S_expect_definition.expected_number) = expected_number;
  return _result;
}

IR_node_t IR_new_token_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_token_definition);
  (((_IR_token_definition *) _result)->_IR_S_token_definition._IR_M_symbol_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_token_definition *) _result)->_IR_S_token_definition._IR_M_symbol_definition._IR_M_definition.next_definition) = next_definition;
  (((_IR_token_definition *) _result)->_IR_S_token_definition._IR_M_symbol_definition.symbol_list) = symbol_list;
  (((_IR_token_definition *) _result)->_IR_S_token_definition._IR_M_symbol_definition.tag) = tag;
  return _result;
}

IR_node_t IR_new_left_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_left_definition);
  (((_IR_left_definition *) _result)->_IR_S_left_definition._IR_M_symbol_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_left_definition *) _result)->_IR_S_left_definition._IR_M_symbol_definition._IR_M_definition.next_definition) = next_definition;
  (((_IR_left_definition *) _result)->_IR_S_left_definition._IR_M_symbol_definition.symbol_list) = symbol_list;
  (((_IR_left_definition *) _result)->_IR_S_left_definition._IR_M_symbol_definition.tag) = tag;
  return _result;
}

IR_node_t IR_new_right_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_right_definition);
  (((_IR_right_definition *) _result)->_IR_S_right_definition._IR_M_symbol_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_right_definition *) _result)->_IR_S_right_definition._IR_M_symbol_definition._IR_M_definition.next_definition) = next_definition;
  (((_IR_right_definition *) _result)->_IR_S_right_definition._IR_M_symbol_definition.symbol_list) = symbol_list;
  (((_IR_right_definition *) _result)->_IR_S_right_definition._IR_M_symbol_definition.tag) = tag;
  return _result;
}

IR_node_t IR_new_nonassoc_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_nonassoc_definition);
  (((_IR_nonassoc_definition *) _result)->_IR_S_nonassoc_definition._IR_M_symbol_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_nonassoc_definition *) _result)->_IR_S_nonassoc_definition._IR_M_symbol_definition._IR_M_definition.next_definition) = next_definition;
  (((_IR_nonassoc_definition *) _result)->_IR_S_nonassoc_definition._IR_M_symbol_definition.symbol_list) = symbol_list;
  (((_IR_nonassoc_definition *) _result)->_IR_S_nonassoc_definition._IR_M_symbol_definition.tag) = tag;
  return _result;
}

IR_node_t IR_new_type_definition
(position_t position,
 IR_node_t next_definition,
 IR_node_t symbol_list,
 IR_node_t tag)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_type_definition);
  (((_IR_type_definition *) _result)->_IR_S_type_definition._IR_M_symbol_definition._IR_M_definition._IR_M_node.position) = position;
  (((_IR_type_definition *) _result)->_IR_S_type_definition._IR_M_symbol_definition._IR_M_definition.next_definition) = next_definition;
  (((_IR_type_definition *) _result)->_IR_S_type_definition._IR_M_symbol_definition.symbol_list) = symbol_list;
  (((_IR_type_definition *) _result)->_IR_S_type_definition._IR_M_symbol_definition.tag) = tag;
  return _result;
}

IR_node_t IR_new_symbol
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t number,
 IR_node_t next_symbol)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_symbol);
  (((_IR_symbol *) _result)->_IR_S_symbol._IR_M_node.position) = position;
  (((_IR_symbol *) _result)->_IR_S_symbol.identifier_or_literal) = identifier_or_literal;
  (((_IR_symbol *) _result)->_IR_S_symbol.number) = number;
  (((_IR_symbol *) _result)->_IR_S_symbol.next_symbol) = next_symbol;
  return _result;
}

IR_node_t IR_new_rule
(position_t position,
 IR_node_t nonterm_identifier,
 IR_node_t pattern,
 IR_node_t next_rule)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_rule);
  (((_IR_rule *) _result)->_IR_S_rule._IR_M_node.position) = position;
  (((_IR_rule *) _result)->_IR_S_rule.nonterm_identifier) = nonterm_identifier;
  (((_IR_rule *) _result)->_IR_S_rule.pattern) = pattern;
  (((_IR_rule *) _result)->_IR_S_rule.next_rule) = next_rule;
  return _result;
}

IR_node_t IR_new_pattern
(position_t position,
 IR_node_t alternatives_list)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_pattern);
  (((_IR_pattern *) _result)->_IR_S_pattern._IR_M_node.position) = position;
  (((_IR_pattern *) _result)->_IR_S_pattern.alternatives_list) = alternatives_list;
  return _result;
}

IR_node_t IR_new_sequence
(position_t position,
 IR_node_t next_alternative,
 IR_node_t sequence,
 IR_node_t precedence_identifier_or_literal,
 IR_node_t max_look_ahead_number)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_sequence);
  (((_IR_sequence *) _result)->_IR_S_sequence._IR_M_alternative._IR_M_node.position) = position;
  (((_IR_sequence *) _result)->_IR_S_sequence._IR_M_alternative.next_alternative) = next_alternative;
  (((_IR_sequence *) _result)->_IR_S_sequence.sequence) = sequence;
  (((_IR_sequence *) _result)->_IR_S_sequence.precedence_identifier_or_literal) = precedence_identifier_or_literal;
  (((_IR_sequence *) _result)->_IR_S_sequence.max_look_ahead_number) = max_look_ahead_number;
  return _result;
}

IR_node_t IR_new_separator_iteration
(position_t position,
 IR_node_t next_alternative,
 IR_node_t iteration_sequence,
 IR_node_t iteration_precedence_identifier_or_literal,
 IR_node_t iteration_max_look_ahead_number,
 IR_node_t separator_sequence,
 IR_node_t separator_precedence_identifier_or_literal,
 IR_node_t separator_max_look_ahead_number)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_separator_iteration);
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration._IR_M_alternative._IR_M_node.position) = position;
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration._IR_M_alternative.next_alternative) = next_alternative;
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration.iteration_sequence) = iteration_sequence;
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration.iteration_precedence_identifier_or_literal) = iteration_precedence_identifier_or_literal;
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration.iteration_max_look_ahead_number) = iteration_max_look_ahead_number;
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration.separator_sequence) = separator_sequence;
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration.separator_precedence_identifier_or_literal) = separator_precedence_identifier_or_literal;
  (((_IR_separator_iteration *) _result)->_IR_S_separator_iteration.separator_max_look_ahead_number) = separator_max_look_ahead_number;
  return _result;
}

IR_node_t IR_new_control_point
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_control_point);
  (((_IR_control_point *) _result)->_IR_S_control_point._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_control_point *) _result)->_IR_S_control_point._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_control_point *) _result)->_IR_S_control_point._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  return _result;
}

IR_node_t IR_new_default
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t default_pattern)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_default);
  (((_IR_default *) _result)->_IR_S_default._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_default *) _result)->_IR_S_default._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_default *) _result)->_IR_S_default._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_default *) _result)->_IR_S_default.default_pattern) = default_pattern;
  return _result;
}

IR_node_t IR_new_star_iteration
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t iteration_unit)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_star_iteration);
  (((_IR_star_iteration *) _result)->_IR_S_star_iteration._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_star_iteration *) _result)->_IR_S_star_iteration._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_star_iteration *) _result)->_IR_S_star_iteration._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_star_iteration *) _result)->_IR_S_star_iteration.iteration_unit) = iteration_unit;
  return _result;
}

IR_node_t IR_new_plus_iteration
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t iteration_unit)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_plus_iteration);
  (((_IR_plus_iteration *) _result)->_IR_S_plus_iteration._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_plus_iteration *) _result)->_IR_S_plus_iteration._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_plus_iteration *) _result)->_IR_S_plus_iteration._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_plus_iteration *) _result)->_IR_S_plus_iteration.iteration_unit) = iteration_unit;
  return _result;
}

IR_node_t IR_new_code_insertion_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t code_insertion)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_code_insertion_atom);
  (((_IR_code_insertion_atom *) _result)->_IR_S_code_insertion_atom._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_code_insertion_atom *) _result)->_IR_S_code_insertion_atom._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_code_insertion_atom *) _result)->_IR_S_code_insertion_atom._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_code_insertion_atom *) _result)->_IR_S_code_insertion_atom.code_insertion) = code_insertion;
  return _result;
}

IR_node_t IR_new_group
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t pattern)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_group);
  (((_IR_group *) _result)->_IR_S_group._IR_M_unit._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_group *) _result)->_IR_S_group._IR_M_unit._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_group *) _result)->_IR_S_group._IR_M_unit._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_group *) _result)->_IR_S_group.pattern) = pattern;
  return _result;
}

IR_node_t IR_new_range_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_range_atom);
  (((_IR_range_atom *) _result)->_IR_S_range_atom._IR_M_unit._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_range_atom *) _result)->_IR_S_range_atom._IR_M_unit._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_range_atom *) _result)->_IR_S_range_atom._IR_M_unit._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_range_atom *) _result)->_IR_S_range_atom.left_bound) = left_bound;
  (((_IR_range_atom *) _result)->_IR_S_range_atom.right_bound) = right_bound;
  return _result;
}

IR_node_t IR_new_range_no_left_bound_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_range_no_left_bound_atom);
  (((_IR_range_no_left_bound_atom *) _result)->_IR_S_range_no_left_bound_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_range_no_left_bound_atom *) _result)->_IR_S_range_no_left_bound_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_range_no_left_bound_atom *) _result)->_IR_S_range_no_left_bound_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_range_no_left_bound_atom *) _result)->_IR_S_range_no_left_bound_atom._IR_M_range_atom.left_bound) = left_bound;
  (((_IR_range_no_left_bound_atom *) _result)->_IR_S_range_no_left_bound_atom._IR_M_range_atom.right_bound) = right_bound;
  return _result;
}

IR_node_t IR_new_range_no_right_bound_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_range_no_right_bound_atom);
  (((_IR_range_no_right_bound_atom *) _result)->_IR_S_range_no_right_bound_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_range_no_right_bound_atom *) _result)->_IR_S_range_no_right_bound_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_range_no_right_bound_atom *) _result)->_IR_S_range_no_right_bound_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_range_no_right_bound_atom *) _result)->_IR_S_range_no_right_bound_atom._IR_M_range_atom.left_bound) = left_bound;
  (((_IR_range_no_right_bound_atom *) _result)->_IR_S_range_no_right_bound_atom._IR_M_range_atom.right_bound) = right_bound;
  return _result;
}

IR_node_t IR_new_range_no_left_right_bounds_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t left_bound,
 IR_node_t right_bound)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_range_no_left_right_bounds_atom);
  (((_IR_range_no_left_right_bounds_atom *) _result)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_range_no_left_right_bounds_atom *) _result)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_range_no_left_right_bounds_atom *) _result)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom._IR_M_unit._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_range_no_left_right_bounds_atom *) _result)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom.left_bound) = left_bound;
  (((_IR_range_no_left_right_bounds_atom *) _result)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom.right_bound) = right_bound;
  return _result;
}

IR_node_t IR_new_identifier_or_literal_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t identifier_or_literal)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_identifier_or_literal_atom);
  (((_IR_identifier_or_literal_atom *) _result)->_IR_S_identifier_or_literal_atom._IR_M_unit._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_identifier_or_literal_atom *) _result)->_IR_S_identifier_or_literal_atom._IR_M_unit._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_identifier_or_literal_atom *) _result)->_IR_S_identifier_or_literal_atom._IR_M_unit._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_identifier_or_literal_atom *) _result)->_IR_S_identifier_or_literal_atom.identifier_or_literal) = identifier_or_literal;
  return _result;
}

IR_node_t IR_new_string_atom
(position_t position,
 IR_node_t next_sequence_element,
 IR_node_t sequence_element_identifier,
 IR_node_t string)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_string_atom);
  (((_IR_string_atom *) _result)->_IR_S_string_atom._IR_M_unit._IR_M_sequence_element._IR_M_node.position) = position;
  (((_IR_string_atom *) _result)->_IR_S_string_atom._IR_M_unit._IR_M_sequence_element.next_sequence_element) = next_sequence_element;
  (((_IR_string_atom *) _result)->_IR_S_string_atom._IR_M_unit._IR_M_sequence_element.sequence_element_identifier) = sequence_element_identifier;
  (((_IR_string_atom *) _result)->_IR_S_string_atom.string) = string;
  return _result;
}

IR_node_t IR_new_description
(position_t position,
 IR_node_t definition_list,
 IR_node_t rule_list,
 IR_node_t additional_code)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_description);
  (((_IR_description *) _result)->_IR_S_description._IR_M_node.position) = position;
  (((_IR_description *) _result)->_IR_S_description.definition_list) = definition_list;
  (((_IR_description *) _result)->_IR_S_description.rule_list) = rule_list;
  (((_IR_description *) _result)->_IR_S_description.additional_code) = additional_code;
  return _result;
}

IR_node_t IR_new_single_term_definition
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t next_single_definition)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_single_term_definition);
  (((_IR_single_term_definition *) _result)->_IR_S_single_term_definition._IR_M_single_definition._IR_M_node.position) = position;
  (((_IR_single_term_definition *) _result)->_IR_S_single_term_definition._IR_M_single_definition.identifier_or_literal) = identifier_or_literal;
  (((_IR_single_term_definition *) _result)->_IR_S_single_term_definition._IR_M_single_definition.next_single_definition) = next_single_definition;
  return _result;
}

IR_node_t IR_new_literal_range_definition
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t next_single_definition,
 IR_node_t right_range_bound_literal)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_literal_range_definition);
  (((_IR_literal_range_definition *) _result)->_IR_S_literal_range_definition._IR_M_single_term_definition._IR_M_single_definition._IR_M_node.position) = position;
  (((_IR_literal_range_definition *) _result)->_IR_S_literal_range_definition._IR_M_single_term_definition._IR_M_single_definition.identifier_or_literal) = identifier_or_literal;
  (((_IR_literal_range_definition *) _result)->_IR_S_literal_range_definition._IR_M_single_term_definition._IR_M_single_definition.next_single_definition) = next_single_definition;
  (((_IR_literal_range_definition *) _result)->_IR_S_literal_range_definition.right_range_bound_literal) = right_range_bound_literal;
  return _result;
}

IR_node_t IR_new_single_nonterm_definition
(position_t position,
 IR_node_t identifier_or_literal,
 IR_node_t next_single_definition,
 IR_node_t corresponding_pattern)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_single_nonterm_definition);
  (((_IR_single_nonterm_definition *) _result)->_IR_S_single_nonterm_definition._IR_M_single_definition._IR_M_node.position) = position;
  (((_IR_single_nonterm_definition *) _result)->_IR_S_single_nonterm_definition._IR_M_single_definition.identifier_or_literal) = identifier_or_literal;
  (((_IR_single_nonterm_definition *) _result)->_IR_S_single_nonterm_definition._IR_M_single_definition.next_single_definition) = next_single_definition;
  (((_IR_single_nonterm_definition *) _result)->_IR_S_single_nonterm_definition.corresponding_pattern) = corresponding_pattern;
  return _result;
}

IR_node_t IR_new_canonical_rule
(position_t position,
 IR_node_t left_hand_side,
 IR_node_t right_hand_side,
 IR_node_t action,
 IR_node_t original_code_insertion_place,
 IR_node_t next_canonical_rule)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_canonical_rule);
  (((_IR_canonical_rule *) _result)->_IR_S_canonical_rule._IR_M_node.position) = position;
  (((_IR_canonical_rule *) _result)->_IR_S_canonical_rule.left_hand_side) = left_hand_side;
  (((_IR_canonical_rule *) _result)->_IR_S_canonical_rule.right_hand_side) = right_hand_side;
  (((_IR_canonical_rule *) _result)->_IR_S_canonical_rule.action) = action;
  (((_IR_canonical_rule *) _result)->_IR_S_canonical_rule.original_code_insertion_place) = original_code_insertion_place;
  (((_IR_canonical_rule *) _result)->_IR_S_canonical_rule.next_canonical_rule) = next_canonical_rule;
  return _result;
}

IR_node_t IR_new_canonical_rule_element
(position_t position,
 IR_node_t canonical_rule,
 IR_node_t next_right_hand_side_element,
 IR_node_t element_itself,
 IR_node_t element_identifier,
 IR_node_t next_single_definition_usage)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_canonical_rule_element);
  (((_IR_canonical_rule_element *) _result)->_IR_S_canonical_rule_element._IR_M_right_hand_side_element._IR_M_node.position) = position;
  (((_IR_canonical_rule_element *) _result)->_IR_S_canonical_rule_element._IR_M_right_hand_side_element.canonical_rule) = canonical_rule;
  (((_IR_canonical_rule_element *) _result)->_IR_S_canonical_rule_element._IR_M_right_hand_side_element.next_right_hand_side_element) = next_right_hand_side_element;
  (((_IR_canonical_rule_element *) _result)->_IR_S_canonical_rule_element.element_itself) = element_itself;
  (((_IR_canonical_rule_element *) _result)->_IR_S_canonical_rule_element.element_identifier) = element_identifier;
  (((_IR_canonical_rule_element *) _result)->_IR_S_canonical_rule_element.next_single_definition_usage) = next_single_definition_usage;
  return _result;
}

IR_node_t IR_new_canonical_rule_end
(position_t position,
 IR_node_t canonical_rule,
 IR_node_t next_right_hand_side_element)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_canonical_rule_end);
  (((_IR_canonical_rule_end *) _result)->_IR_S_canonical_rule_end._IR_M_right_hand_side_element._IR_M_node.position) = position;
  (((_IR_canonical_rule_end *) _result)->_IR_S_canonical_rule_end._IR_M_right_hand_side_element.canonical_rule) = canonical_rule;
  (((_IR_canonical_rule_end *) _result)->_IR_S_canonical_rule_end._IR_M_right_hand_side_element.next_right_hand_side_element) = next_right_hand_side_element;
  return _result;
}

IR_node_t IR_new_LR_situation
(IR_node_t element_after_dot,
 context_t context,
 IR_node_t LR_set,
 IR_node_t next_LR_situation)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_LR_situation);
  (((_IR_LR_situation *) _result)->_IR_S_LR_situation.element_after_dot) = element_after_dot;
  (((_IR_LR_situation *) _result)->_IR_S_LR_situation.context) = context;
  (((_IR_LR_situation *) _result)->_IR_S_LR_situation.LR_set) = LR_set;
  (((_IR_LR_situation *) _result)->_IR_S_LR_situation.next_LR_situation) = next_LR_situation;
  return _result;
}

IR_node_t IR_new_LR_set
(IR_node_t LR_situation_list,
 IR_node_t LR_core,
 IR_node_t next_LR_set)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_LR_set);
  (((_IR_LR_set *) _result)->_IR_S_LR_set.LR_situation_list) = LR_situation_list;
  (((_IR_LR_set *) _result)->_IR_S_LR_set.LR_core) = LR_core;
  (((_IR_LR_set *) _result)->_IR_S_LR_set.next_LR_set) = next_LR_set;
  return _result;
}

IR_node_t IR_new_LR_set_look_ahead_trie_node
(IR_node_t corresponding_single_term_definition,
 IR_node_t corresponding_LR_situation,
 IR_node_t first_son,
 IR_node_t next_brother)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_LR_set_look_ahead_trie_node);
  (((_IR_LR_set_look_ahead_trie_node *) _result)->_IR_S_LR_set_look_ahead_trie_node.corresponding_single_term_definition) = corresponding_single_term_definition;
  (((_IR_LR_set_look_ahead_trie_node *) _result)->_IR_S_LR_set_look_ahead_trie_node.corresponding_LR_situation) = corresponding_LR_situation;
  (((_IR_LR_set_look_ahead_trie_node *) _result)->_IR_S_LR_set_look_ahead_trie_node.first_son) = first_son;
  (((_IR_LR_set_look_ahead_trie_node *) _result)->_IR_S_LR_set_look_ahead_trie_node.next_brother) = next_brother;
  return _result;
}

IR_node_t IR_new_back_track_alternative
(IR_node_t corresponding_LR_set_look_ahead_trie_node,
 IR_node_t next_back_track_alternative)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_back_track_alternative);
  (((_IR_back_track_alternative *) _result)->_IR_S_back_track_alternative.corresponding_LR_set_look_ahead_trie_node) = corresponding_LR_set_look_ahead_trie_node;
  (((_IR_back_track_alternative *) _result)->_IR_S_back_track_alternative.next_back_track_alternative) = next_back_track_alternative;
  return _result;
}

IR_node_t IR_new_conflict
(IR_node_t used_LR_situation,
 IR_node_t unused_LR_situation,
 token_string_t token_string,
 IR_node_t next_conflict)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_conflict);
  (((_IR_conflict *) _result)->_IR_S_conflict.used_LR_situation) = used_LR_situation;
  (((_IR_conflict *) _result)->_IR_S_conflict.unused_LR_situation) = unused_LR_situation;
  (((_IR_conflict *) _result)->_IR_S_conflict.token_string) = token_string;
  (((_IR_conflict *) _result)->_IR_S_conflict.next_conflict) = next_conflict;
  return _result;
}

IR_node_t IR_new_regular_arc
(IR_node_t from_LR_situation,
 IR_node_t to_LR_set,
 IR_node_t terminal_marking_arc)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_regular_arc);
  (((_IR_regular_arc *) _result)->_IR_S_regular_arc.from_LR_situation) = from_LR_situation;
  (((_IR_regular_arc *) _result)->_IR_S_regular_arc.to_LR_set).field_itself = to_LR_set;
  _IR_set_double_field_value
    (&((((_IR_regular_arc *) _result)->_IR_S_regular_arc.to_LR_set)), NULL,
     _IR_offsetof (struct IR_node, _IR_first_link), 1);
  (((_IR_regular_arc *) _result)->_IR_S_regular_arc.terminal_marking_arc) = terminal_marking_arc;
  return _result;
}

IR_node_t IR_new_rule_list_element
(IR_node_t canonical_rule,
 IR_node_t next_rule_list_element)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_rule_list_element);
  (((_IR_rule_list_element *) _result)->_IR_S_rule_list_element.canonical_rule) = canonical_rule;
  (((_IR_rule_list_element *) _result)->_IR_S_rule_list_element.next_rule_list_element) = next_rule_list_element;
  return _result;
}

IR_node_t IR_new_LR_core
(IR_node_t LR_set_list,
 IR_node_t next_LR_core)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_LR_core);
  (((_IR_LR_core *) _result)->_IR_S_LR_core.LR_set_list) = LR_set_list;
  (((_IR_LR_core *) _result)->_IR_S_LR_core.next_LR_core) = next_LR_core;
  return _result;
}

IR_node_t IR_new_LR_set_dependence
(integer_t look_ahead,
 IR_node_t LR_set,
 integer_t back_distance,
 IR_node_t nonterm)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_LR_set_dependence);
  (((_IR_LR_set_dependence *) _result)->_IR_S_LR_set_dependence._IR_M_DeRemer_dependence.look_ahead) = look_ahead;
  (((_IR_LR_set_dependence *) _result)->_IR_S_LR_set_dependence.LR_set) = LR_set;
  (((_IR_LR_set_dependence *) _result)->_IR_S_LR_set_dependence.back_distance) = back_distance;
  (((_IR_LR_set_dependence *) _result)->_IR_S_LR_set_dependence.nonterm) = nonterm;
  return _result;
}

IR_node_t IR_new_shift_dependence
(integer_t look_ahead,
 IR_node_t token)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_shift_dependence);
  (((_IR_shift_dependence *) _result)->_IR_S_shift_dependence._IR_M_DeRemer_dependence.look_ahead) = look_ahead;
  (((_IR_shift_dependence *) _result)->_IR_S_shift_dependence.token) = token;
  return _result;
}

IR_node_t IR_new_shift_LR_situation_dependence
(integer_t look_ahead,
 IR_node_t token,
 IR_node_t shift_LR_situation)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_shift_LR_situation_dependence);
  (((_IR_shift_LR_situation_dependence *) _result)->_IR_S_shift_LR_situation_dependence._IR_M_shift_dependence._IR_M_DeRemer_dependence.look_ahead) = look_ahead;
  (((_IR_shift_LR_situation_dependence *) _result)->_IR_S_shift_LR_situation_dependence._IR_M_shift_dependence.token) = token;
  (((_IR_shift_LR_situation_dependence *) _result)->_IR_S_shift_LR_situation_dependence.shift_LR_situation) = shift_LR_situation;
  return _result;
}

IR_node_t IR_new_dependence_list_element
(IR_node_t dependence,
 IR_node_t next_dependence_list_element)
{
  IR_node_t _result;

  _result = IR_create_node (IR_NM_dependence_list_element);
  (((_IR_dependence_list_element *) _result)->_IR_S_dependence_list_element.dependence) = dependence;
  (((_IR_dependence_list_element *) _result)->_IR_S_dependence_list_element.next_dependence_list_element) = next_dependence_list_element;
  return _result;
}

static void _IR_copy_node_fields (IR_node_mode_t node_mode, IR_node_t to, IR_node_t from)
{
  switch (node_mode)
    {
    case IR_NM_node:
      IR_COPY_position_t ((((_IR_node *) to)->_IR_S_node.position), (((_IR_node *) from)->_IR_S_node.position));
      break;
    case IR_NM_identifier_or_literal:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_identifier_or_literal *) to)->_IR_S_identifier_or_literal._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_identifier_or_literal *) from)->_IR_S_identifier_or_literal._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      break;
    case IR_NM_identifier:
      _IR_copy_node_fields (IR_NM_identifier_or_literal, (IR_node_t) ((char *) &((_IR_identifier *) to)->_IR_S_identifier._IR_M_identifier_or_literal - _IR_offsetof (_IR_identifier_or_literal, _IR_S_identifier_or_literal)), (IR_node_t) ((char *) &((_IR_identifier *) from)->_IR_S_identifier._IR_M_identifier_or_literal - _IR_offsetof (_IR_identifier_or_literal, _IR_S_identifier_or_literal)));
      IR_COPY_string_t ((((_IR_identifier *) to)->_IR_S_identifier.identifier_itself), (((_IR_identifier *) from)->_IR_S_identifier.identifier_itself));
      IR_COPY_bool_t ((((_IR_identifier *) to)->_IR_S_identifier.dot_presence_flag), (((_IR_identifier *) from)->_IR_S_identifier.dot_presence_flag));
      break;
    case IR_NM_literal:
      _IR_copy_node_fields (IR_NM_identifier_or_literal, (IR_node_t) ((char *) &((_IR_literal *) to)->_IR_S_literal._IR_M_identifier_or_literal - _IR_offsetof (_IR_identifier_or_literal, _IR_S_identifier_or_literal)), (IR_node_t) ((char *) &((_IR_literal *) from)->_IR_S_literal._IR_M_identifier_or_literal - _IR_offsetof (_IR_identifier_or_literal, _IR_S_identifier_or_literal)));
      IR_COPY_string_t ((((_IR_literal *) to)->_IR_S_literal.character_representation), (((_IR_literal *) from)->_IR_S_literal.character_representation));
      IR_COPY_integer_t ((((_IR_literal *) to)->_IR_S_literal.literal_code), (((_IR_literal *) from)->_IR_S_literal.literal_code));
      break;
    case IR_NM_string:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_string *) to)->_IR_S_string._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_string *) from)->_IR_S_string._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_string_t ((((_IR_string *) to)->_IR_S_string.string_representation), (((_IR_string *) from)->_IR_S_string.string_representation));
      IR_COPY_string_t ((((_IR_string *) to)->_IR_S_string.string_itself), (((_IR_string *) from)->_IR_S_string.string_itself));
      break;
    case IR_NM_number:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_number *) to)->_IR_S_number._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_number *) from)->_IR_S_number._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_integer_t ((((_IR_number *) to)->_IR_S_number.number_value), (((_IR_number *) from)->_IR_S_number.number_value));
      break;
    case IR_NM_code_insertion:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_code_insertion *) to)->_IR_S_code_insertion._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_code_insertion *) from)->_IR_S_code_insertion._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_string_t ((((_IR_code_insertion *) to)->_IR_S_code_insertion.code_insertion_itself), (((_IR_code_insertion *) from)->_IR_S_code_insertion.code_insertion_itself));
      break;
    case IR_NM_additional_code:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_additional_code *) to)->_IR_S_additional_code._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_additional_code *) from)->_IR_S_additional_code._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_string_t ((((_IR_additional_code *) to)->_IR_S_additional_code.additional_code_itself), (((_IR_additional_code *) from)->_IR_S_additional_code.additional_code_itself));
      break;
    case IR_NM_definition:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_definition *) to)->_IR_S_definition._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_definition *) from)->_IR_S_definition._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_definition *) to)->_IR_S_definition.next_definition), (((_IR_definition *) from)->_IR_S_definition.next_definition));
      break;
    case IR_NM_start_definition:
      _IR_copy_node_fields (IR_NM_definition, (IR_node_t) ((char *) &((_IR_start_definition *) to)->_IR_S_start_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)), (IR_node_t) ((char *) &((_IR_start_definition *) from)->_IR_S_start_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_COPY_IR_node_t ((((_IR_start_definition *) to)->_IR_S_start_definition.identifier), (((_IR_start_definition *) from)->_IR_S_start_definition.identifier));
      break;
    case IR_NM_code:
      _IR_copy_node_fields (IR_NM_definition, (IR_node_t) ((char *) &((_IR_code *) to)->_IR_S_code._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)), (IR_node_t) ((char *) &((_IR_code *) from)->_IR_S_code._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_COPY_IR_node_t ((((_IR_code *) to)->_IR_S_code.code_itself), (((_IR_code *) from)->_IR_S_code.code_itself));
      break;
    case IR_NM_yacc_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_yacc_code *) to)->_IR_S_yacc_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_yacc_code *) from)->_IR_S_yacc_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_local_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_local_code *) to)->_IR_S_local_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_local_code *) from)->_IR_S_local_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_import_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_import_code *) to)->_IR_S_import_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_import_code *) from)->_IR_S_import_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_export_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_export_code *) to)->_IR_S_export_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_export_code *) from)->_IR_S_export_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_union_code:
      _IR_copy_node_fields (IR_NM_code, (IR_node_t) ((char *) &((_IR_union_code *) to)->_IR_S_union_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)), (IR_node_t) ((char *) &((_IR_union_code *) from)->_IR_S_union_code._IR_M_code - _IR_offsetof (_IR_code, _IR_S_code)));
      break;
    case IR_NM_scanner_definition:
      _IR_copy_node_fields (IR_NM_definition, (IR_node_t) ((char *) &((_IR_scanner_definition *) to)->_IR_S_scanner_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)), (IR_node_t) ((char *) &((_IR_scanner_definition *) from)->_IR_S_scanner_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      break;
    case IR_NM_expect_definition:
      _IR_copy_node_fields (IR_NM_definition, (IR_node_t) ((char *) &((_IR_expect_definition *) to)->_IR_S_expect_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)), (IR_node_t) ((char *) &((_IR_expect_definition *) from)->_IR_S_expect_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_COPY_IR_node_t ((((_IR_expect_definition *) to)->_IR_S_expect_definition.expected_number), (((_IR_expect_definition *) from)->_IR_S_expect_definition.expected_number));
      break;
    case IR_NM_symbol_definition:
      _IR_copy_node_fields (IR_NM_definition, (IR_node_t) ((char *) &((_IR_symbol_definition *) to)->_IR_S_symbol_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)), (IR_node_t) ((char *) &((_IR_symbol_definition *) from)->_IR_S_symbol_definition._IR_M_definition - _IR_offsetof (_IR_definition, _IR_S_definition)));
      IR_COPY_IR_node_t ((((_IR_symbol_definition *) to)->_IR_S_symbol_definition.symbol_list), (((_IR_symbol_definition *) from)->_IR_S_symbol_definition.symbol_list));
      IR_COPY_IR_node_t ((((_IR_symbol_definition *) to)->_IR_S_symbol_definition.tag), (((_IR_symbol_definition *) from)->_IR_S_symbol_definition.tag));
      break;
    case IR_NM_token_definition:
      _IR_copy_node_fields (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_token_definition *) to)->_IR_S_token_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)), (IR_node_t) ((char *) &((_IR_token_definition *) from)->_IR_S_token_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_left_definition:
      _IR_copy_node_fields (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_left_definition *) to)->_IR_S_left_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)), (IR_node_t) ((char *) &((_IR_left_definition *) from)->_IR_S_left_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_right_definition:
      _IR_copy_node_fields (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_right_definition *) to)->_IR_S_right_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)), (IR_node_t) ((char *) &((_IR_right_definition *) from)->_IR_S_right_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_nonassoc_definition:
      _IR_copy_node_fields (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_nonassoc_definition *) to)->_IR_S_nonassoc_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)), (IR_node_t) ((char *) &((_IR_nonassoc_definition *) from)->_IR_S_nonassoc_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_type_definition:
      _IR_copy_node_fields (IR_NM_symbol_definition, (IR_node_t) ((char *) &((_IR_type_definition *) to)->_IR_S_type_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)), (IR_node_t) ((char *) &((_IR_type_definition *) from)->_IR_S_type_definition._IR_M_symbol_definition - _IR_offsetof (_IR_symbol_definition, _IR_S_symbol_definition)));
      break;
    case IR_NM_symbol:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_symbol *) to)->_IR_S_symbol._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_symbol *) from)->_IR_S_symbol._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_symbol *) to)->_IR_S_symbol.identifier_or_literal), (((_IR_symbol *) from)->_IR_S_symbol.identifier_or_literal));
      IR_COPY_IR_node_t ((((_IR_symbol *) to)->_IR_S_symbol.number), (((_IR_symbol *) from)->_IR_S_symbol.number));
      IR_COPY_IR_node_t ((((_IR_symbol *) to)->_IR_S_symbol.next_symbol), (((_IR_symbol *) from)->_IR_S_symbol.next_symbol));
      break;
    case IR_NM_rule:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_rule *) to)->_IR_S_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_rule *) from)->_IR_S_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.nonterm_identifier), (((_IR_rule *) from)->_IR_S_rule.nonterm_identifier));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.pattern), (((_IR_rule *) from)->_IR_S_rule.pattern));
      IR_COPY_IR_node_t ((((_IR_rule *) to)->_IR_S_rule.next_rule), (((_IR_rule *) from)->_IR_S_rule.next_rule));
      break;
    case IR_NM_pattern:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_pattern *) to)->_IR_S_pattern._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_pattern *) from)->_IR_S_pattern._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_pattern *) to)->_IR_S_pattern.alternatives_list), (((_IR_pattern *) from)->_IR_S_pattern.alternatives_list));
      break;
    case IR_NM_alternative:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_alternative *) to)->_IR_S_alternative._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_alternative *) from)->_IR_S_alternative._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      _IR_copy_node_fields (IR_NM_denotation, (IR_node_t) ((char *) &((_IR_alternative *) to)->_IR_S_alternative._IR_M_denotation - _IR_offsetof (_IR_denotation, _IR_S_denotation)), (IR_node_t) ((char *) &((_IR_alternative *) from)->_IR_S_alternative._IR_M_denotation - _IR_offsetof (_IR_denotation, _IR_S_denotation)));
      IR_COPY_IR_node_t ((((_IR_alternative *) to)->_IR_S_alternative.next_alternative), (((_IR_alternative *) from)->_IR_S_alternative.next_alternative));
      break;
    case IR_NM_sequence:
      _IR_copy_node_fields (IR_NM_alternative, (IR_node_t) ((char *) &((_IR_sequence *) to)->_IR_S_sequence._IR_M_alternative - _IR_offsetof (_IR_alternative, _IR_S_alternative)), (IR_node_t) ((char *) &((_IR_sequence *) from)->_IR_S_sequence._IR_M_alternative - _IR_offsetof (_IR_alternative, _IR_S_alternative)));
      IR_COPY_IR_node_t ((((_IR_sequence *) to)->_IR_S_sequence.sequence), (((_IR_sequence *) from)->_IR_S_sequence.sequence));
      IR_COPY_IR_node_t ((((_IR_sequence *) to)->_IR_S_sequence.precedence_identifier_or_literal), (((_IR_sequence *) from)->_IR_S_sequence.precedence_identifier_or_literal));
      IR_COPY_IR_node_t ((((_IR_sequence *) to)->_IR_S_sequence.max_look_ahead_number), (((_IR_sequence *) from)->_IR_S_sequence.max_look_ahead_number));
      break;
    case IR_NM_separator_iteration:
      _IR_copy_node_fields (IR_NM_alternative, (IR_node_t) ((char *) &((_IR_separator_iteration *) to)->_IR_S_separator_iteration._IR_M_alternative - _IR_offsetof (_IR_alternative, _IR_S_alternative)), (IR_node_t) ((char *) &((_IR_separator_iteration *) from)->_IR_S_separator_iteration._IR_M_alternative - _IR_offsetof (_IR_alternative, _IR_S_alternative)));
      IR_COPY_IR_node_t ((((_IR_separator_iteration *) to)->_IR_S_separator_iteration.iteration_sequence), (((_IR_separator_iteration *) from)->_IR_S_separator_iteration.iteration_sequence));
      IR_COPY_IR_node_t ((((_IR_separator_iteration *) to)->_IR_S_separator_iteration.iteration_precedence_identifier_or_literal), (((_IR_separator_iteration *) from)->_IR_S_separator_iteration.iteration_precedence_identifier_or_literal));
      IR_COPY_IR_node_t ((((_IR_separator_iteration *) to)->_IR_S_separator_iteration.iteration_max_look_ahead_number), (((_IR_separator_iteration *) from)->_IR_S_separator_iteration.iteration_max_look_ahead_number));
      IR_COPY_IR_node_t ((((_IR_separator_iteration *) to)->_IR_S_separator_iteration.separator_sequence), (((_IR_separator_iteration *) from)->_IR_S_separator_iteration.separator_sequence));
      IR_COPY_IR_node_t ((((_IR_separator_iteration *) to)->_IR_S_separator_iteration.separator_precedence_identifier_or_literal), (((_IR_separator_iteration *) from)->_IR_S_separator_iteration.separator_precedence_identifier_or_literal));
      IR_COPY_IR_node_t ((((_IR_separator_iteration *) to)->_IR_S_separator_iteration.separator_max_look_ahead_number), (((_IR_separator_iteration *) from)->_IR_S_separator_iteration.separator_max_look_ahead_number));
      break;
    case IR_NM_sequence_element:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_sequence_element *) to)->_IR_S_sequence_element._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_sequence_element *) from)->_IR_S_sequence_element._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      _IR_copy_node_fields (IR_NM_denotation, (IR_node_t) ((char *) &((_IR_sequence_element *) to)->_IR_S_sequence_element._IR_M_denotation - _IR_offsetof (_IR_denotation, _IR_S_denotation)), (IR_node_t) ((char *) &((_IR_sequence_element *) from)->_IR_S_sequence_element._IR_M_denotation - _IR_offsetof (_IR_denotation, _IR_S_denotation)));
      IR_COPY_IR_node_t ((((_IR_sequence_element *) to)->_IR_S_sequence_element.next_sequence_element), (((_IR_sequence_element *) from)->_IR_S_sequence_element.next_sequence_element));
      IR_COPY_IR_node_t ((((_IR_sequence_element *) to)->_IR_S_sequence_element.sequence_element_identifier), (((_IR_sequence_element *) from)->_IR_S_sequence_element.sequence_element_identifier));
      break;
    case IR_NM_control_point:
      _IR_copy_node_fields (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_control_point *) to)->_IR_S_control_point._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)), (IR_node_t) ((char *) &((_IR_control_point *) from)->_IR_S_control_point._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      break;
    case IR_NM_default:
      _IR_copy_node_fields (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_default *) to)->_IR_S_default._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)), (IR_node_t) ((char *) &((_IR_default *) from)->_IR_S_default._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_COPY_IR_node_t ((((_IR_default *) to)->_IR_S_default.default_pattern), (((_IR_default *) from)->_IR_S_default.default_pattern));
      break;
    case IR_NM_star_iteration:
      _IR_copy_node_fields (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_star_iteration *) to)->_IR_S_star_iteration._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)), (IR_node_t) ((char *) &((_IR_star_iteration *) from)->_IR_S_star_iteration._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_COPY_IR_node_t ((((_IR_star_iteration *) to)->_IR_S_star_iteration.iteration_unit), (((_IR_star_iteration *) from)->_IR_S_star_iteration.iteration_unit));
      break;
    case IR_NM_plus_iteration:
      _IR_copy_node_fields (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_plus_iteration *) to)->_IR_S_plus_iteration._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)), (IR_node_t) ((char *) &((_IR_plus_iteration *) from)->_IR_S_plus_iteration._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_COPY_IR_node_t ((((_IR_plus_iteration *) to)->_IR_S_plus_iteration.iteration_unit), (((_IR_plus_iteration *) from)->_IR_S_plus_iteration.iteration_unit));
      break;
    case IR_NM_code_insertion_atom:
      _IR_copy_node_fields (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_code_insertion_atom *) to)->_IR_S_code_insertion_atom._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)), (IR_node_t) ((char *) &((_IR_code_insertion_atom *) from)->_IR_S_code_insertion_atom._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      IR_COPY_IR_node_t ((((_IR_code_insertion_atom *) to)->_IR_S_code_insertion_atom.code_insertion), (((_IR_code_insertion_atom *) from)->_IR_S_code_insertion_atom.code_insertion));
      break;
    case IR_NM_unit:
      _IR_copy_node_fields (IR_NM_sequence_element, (IR_node_t) ((char *) &((_IR_unit *) to)->_IR_S_unit._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)), (IR_node_t) ((char *) &((_IR_unit *) from)->_IR_S_unit._IR_M_sequence_element - _IR_offsetof (_IR_sequence_element, _IR_S_sequence_element)));
      break;
    case IR_NM_group:
      _IR_copy_node_fields (IR_NM_unit, (IR_node_t) ((char *) &((_IR_group *) to)->_IR_S_group._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)), (IR_node_t) ((char *) &((_IR_group *) from)->_IR_S_group._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_COPY_IR_node_t ((((_IR_group *) to)->_IR_S_group.pattern), (((_IR_group *) from)->_IR_S_group.pattern));
      break;
    case IR_NM_range_atom:
      _IR_copy_node_fields (IR_NM_unit, (IR_node_t) ((char *) &((_IR_range_atom *) to)->_IR_S_range_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)), (IR_node_t) ((char *) &((_IR_range_atom *) from)->_IR_S_range_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_COPY_IR_node_t ((((_IR_range_atom *) to)->_IR_S_range_atom.left_bound), (((_IR_range_atom *) from)->_IR_S_range_atom.left_bound));
      IR_COPY_IR_node_t ((((_IR_range_atom *) to)->_IR_S_range_atom.right_bound), (((_IR_range_atom *) from)->_IR_S_range_atom.right_bound));
      break;
    case IR_NM_range_no_left_bound_atom:
      _IR_copy_node_fields (IR_NM_range_atom, (IR_node_t) ((char *) &((_IR_range_no_left_bound_atom *) to)->_IR_S_range_no_left_bound_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)), (IR_node_t) ((char *) &((_IR_range_no_left_bound_atom *) from)->_IR_S_range_no_left_bound_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)));
      break;
    case IR_NM_range_no_right_bound_atom:
      _IR_copy_node_fields (IR_NM_range_atom, (IR_node_t) ((char *) &((_IR_range_no_right_bound_atom *) to)->_IR_S_range_no_right_bound_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)), (IR_node_t) ((char *) &((_IR_range_no_right_bound_atom *) from)->_IR_S_range_no_right_bound_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)));
      break;
    case IR_NM_range_no_left_right_bounds_atom:
      _IR_copy_node_fields (IR_NM_range_atom, (IR_node_t) ((char *) &((_IR_range_no_left_right_bounds_atom *) to)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)), (IR_node_t) ((char *) &((_IR_range_no_left_right_bounds_atom *) from)->_IR_S_range_no_left_right_bounds_atom._IR_M_range_atom - _IR_offsetof (_IR_range_atom, _IR_S_range_atom)));
      break;
    case IR_NM_identifier_or_literal_atom:
      _IR_copy_node_fields (IR_NM_unit, (IR_node_t) ((char *) &((_IR_identifier_or_literal_atom *) to)->_IR_S_identifier_or_literal_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)), (IR_node_t) ((char *) &((_IR_identifier_or_literal_atom *) from)->_IR_S_identifier_or_literal_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_COPY_IR_node_t ((((_IR_identifier_or_literal_atom *) to)->_IR_S_identifier_or_literal_atom.identifier_or_literal), (((_IR_identifier_or_literal_atom *) from)->_IR_S_identifier_or_literal_atom.identifier_or_literal));
      break;
    case IR_NM_string_atom:
      _IR_copy_node_fields (IR_NM_unit, (IR_node_t) ((char *) &((_IR_string_atom *) to)->_IR_S_string_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)), (IR_node_t) ((char *) &((_IR_string_atom *) from)->_IR_S_string_atom._IR_M_unit - _IR_offsetof (_IR_unit, _IR_S_unit)));
      IR_COPY_IR_node_t ((((_IR_string_atom *) to)->_IR_S_string_atom.string), (((_IR_string_atom *) from)->_IR_S_string_atom.string));
      break;
    case IR_NM_description:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_description *) to)->_IR_S_description._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_description *) from)->_IR_S_description._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.definition_list), (((_IR_description *) from)->_IR_S_description.definition_list));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.rule_list), (((_IR_description *) from)->_IR_S_description.rule_list));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.additional_code), (((_IR_description *) from)->_IR_S_description.additional_code));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.union_code), (((_IR_description *) from)->_IR_S_description.union_code));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.single_definition_list), (((_IR_description *) from)->_IR_S_description.single_definition_list));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.tokens_number), (((_IR_description *) from)->_IR_S_description.tokens_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.nonterminals_number), (((_IR_description *) from)->_IR_S_description.nonterminals_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.canonical_rules_number), (((_IR_description *) from)->_IR_S_description.canonical_rules_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.duplicated_patterns_number), (((_IR_description *) from)->_IR_S_description.duplicated_patterns_number));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.canonical_rule_list), (((_IR_description *) from)->_IR_S_description.canonical_rule_list));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.axiom_identifier), (((_IR_description *) from)->_IR_S_description.axiom_identifier));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.axiom_definition), (((_IR_description *) from)->_IR_S_description.axiom_definition));
      IR_COPY_bool_t ((((_IR_description *) to)->_IR_S_description.scanner_flag), (((_IR_description *) from)->_IR_S_description.scanner_flag));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.expected_shift_reduce_conflicts_number), (((_IR_description *) from)->_IR_S_description.expected_shift_reduce_conflicts_number));
      IR_COPY_IR_node_t ((((_IR_description *) to)->_IR_S_description.LR_core_list), (((_IR_description *) from)->_IR_S_description.LR_core_list));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.splitted_LR_sets_number), (((_IR_description *) from)->_IR_S_description.splitted_LR_sets_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.LR_sets_number), (((_IR_description *) from)->_IR_S_description.LR_sets_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.pushed_LR_sets_number), (((_IR_description *) from)->_IR_S_description.pushed_LR_sets_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.reduces_number), (((_IR_description *) from)->_IR_S_description.reduces_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.all_number_of_regular_arcs), (((_IR_description *) from)->_IR_S_description.all_number_of_regular_arcs));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.number_of_regular_arcs), (((_IR_description *) from)->_IR_S_description.number_of_regular_arcs));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.token_equivalence_classes_number), (((_IR_description *) from)->_IR_S_description.token_equivalence_classes_number));
      IR_COPY_integer_t ((((_IR_description *) to)->_IR_S_description.duplicated_actions), (((_IR_description *) from)->_IR_S_description.duplicated_actions));
      IR_COPY_bool_t ((((_IR_description *) to)->_IR_S_description.back_tracking_exists), (((_IR_description *) from)->_IR_S_description.back_tracking_exists));
      break;
    case IR_NM_denotation:
      IR_COPY_IR_node_t ((((_IR_denotation *) to)->_IR_S_denotation.corresponding_single_nonterm_definition), (((_IR_denotation *) from)->_IR_S_denotation.corresponding_single_nonterm_definition));
      break;
    case IR_NM_single_definition:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_single_definition *) to)->_IR_S_single_definition._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_single_definition *) from)->_IR_S_single_definition._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_single_definition *) to)->_IR_S_single_definition.type), (((_IR_single_definition *) from)->_IR_S_single_definition.type));
      IR_COPY_bool_t ((((_IR_single_definition *) to)->_IR_S_single_definition.accessibility_flag), (((_IR_single_definition *) from)->_IR_S_single_definition.accessibility_flag));
      IR_COPY_IR_node_t ((((_IR_single_definition *) to)->_IR_S_single_definition.single_definition_usage_list), (((_IR_single_definition *) from)->_IR_S_single_definition.single_definition_usage_list));
      IR_COPY_IR_node_t ((((_IR_single_definition *) to)->_IR_S_single_definition.identifier_or_literal), (((_IR_single_definition *) from)->_IR_S_single_definition.identifier_or_literal));
      IR_COPY_IR_node_t ((((_IR_single_definition *) to)->_IR_S_single_definition.next_single_definition), (((_IR_single_definition *) from)->_IR_S_single_definition.next_single_definition));
      IR_COPY_IR_node_t ((((_IR_single_definition *) to)->_IR_S_single_definition.last_symbol_LR_situation_processed), (((_IR_single_definition *) from)->_IR_S_single_definition.last_symbol_LR_situation_processed));
      break;
    case IR_NM_single_term_definition:
      _IR_copy_node_fields (IR_NM_single_definition, (IR_node_t) ((char *) &((_IR_single_term_definition *) to)->_IR_S_single_term_definition._IR_M_single_definition - _IR_offsetof (_IR_single_definition, _IR_S_single_definition)), (IR_node_t) ((char *) &((_IR_single_term_definition *) from)->_IR_S_single_term_definition._IR_M_single_definition - _IR_offsetof (_IR_single_definition, _IR_S_single_definition)));
      IR_COPY_integer_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.token_order_number), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.token_order_number));
      IR_COPY_integer_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.value), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.value));
      IR_COPY_integer_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.priority), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.priority));
      IR_COPY_bool_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.left_assoc_flag), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.left_assoc_flag));
      IR_COPY_bool_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.right_assoc_flag), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.right_assoc_flag));
      IR_COPY_bool_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.nonassoc_flag), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.nonassoc_flag));
      IR_COPY_bool_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.deletion_flag), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.deletion_flag));
      IR_COPY_IR_node_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.next_equivalence_class_token), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.next_equivalence_class_token));
      IR_COPY_integer_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.equivalence_class_number), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.equivalence_class_number));
      IR_COPY_bool_t ((((_IR_single_term_definition *) to)->_IR_S_single_term_definition.token_was_processed_on_equivalence), (((_IR_single_term_definition *) from)->_IR_S_single_term_definition.token_was_processed_on_equivalence));
      break;
    case IR_NM_literal_range_definition:
      _IR_copy_node_fields (IR_NM_single_term_definition, (IR_node_t) ((char *) &((_IR_literal_range_definition *) to)->_IR_S_literal_range_definition._IR_M_single_term_definition - _IR_offsetof (_IR_single_term_definition, _IR_S_single_term_definition)), (IR_node_t) ((char *) &((_IR_literal_range_definition *) from)->_IR_S_literal_range_definition._IR_M_single_term_definition - _IR_offsetof (_IR_single_term_definition, _IR_S_single_term_definition)));
      IR_COPY_integer_t ((((_IR_literal_range_definition *) to)->_IR_S_literal_range_definition.right_range_bound_value), (((_IR_literal_range_definition *) from)->_IR_S_literal_range_definition.right_range_bound_value));
      IR_COPY_bool_t ((((_IR_literal_range_definition *) to)->_IR_S_literal_range_definition.bounds_have_explicit_values), (((_IR_literal_range_definition *) from)->_IR_S_literal_range_definition.bounds_have_explicit_values));
      IR_COPY_IR_node_t ((((_IR_literal_range_definition *) to)->_IR_S_literal_range_definition.right_range_bound_literal), (((_IR_literal_range_definition *) from)->_IR_S_literal_range_definition.right_range_bound_literal));
      break;
    case IR_NM_single_nonterm_definition:
      _IR_copy_node_fields (IR_NM_single_definition, (IR_node_t) ((char *) &((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition._IR_M_single_definition - _IR_offsetof (_IR_single_definition, _IR_S_single_definition)), (IR_node_t) ((char *) &((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition._IR_M_single_definition - _IR_offsetof (_IR_single_definition, _IR_S_single_definition)));
      IR_COPY_integer_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.nonterm_order_number), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.nonterm_order_number));
      IR_COPY_IR_node_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.nonterm_canonical_rule_list), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.nonterm_canonical_rule_list));
      IR_COPY_bool_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.derivation_ability_flag), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.derivation_ability_flag));
      IR_COPY_integer_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.pass_number), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.pass_number));
      IR_COPY_IR_node_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.corresponding_pattern), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.corresponding_pattern));
      IR_COPY_integer_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.minimal_derived_string_length), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.minimal_derived_string_length));
      IR_COPY_context_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.relation_FIRST), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.relation_FIRST));
      IR_COPY_context_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.next_iter_relation_FIRST), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.next_iter_relation_FIRST));
      IR_COPY_bool_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.process_nonterminal_on_its_process_pass), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.process_nonterminal_on_its_process_pass));
      IR_COPY_bool_t ((((_IR_single_nonterm_definition *) to)->_IR_S_single_nonterm_definition.pattern_has_been_output), (((_IR_single_nonterm_definition *) from)->_IR_S_single_nonterm_definition.pattern_has_been_output));
      break;
    case IR_NM_canonical_rule:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_canonical_rule *) to)->_IR_S_canonical_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_canonical_rule *) from)->_IR_S_canonical_rule._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_bool_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.next_cp_flag), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.next_cp_flag));
      IR_COPY_integer_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.canonical_rule_order_number), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.canonical_rule_order_number));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.next_nonterm_canonical_rule), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.next_nonterm_canonical_rule));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.precedence_single_term_definition), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.precedence_single_term_definition));
      IR_COPY_integer_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.rule_priority), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.rule_priority));
      IR_COPY_integer_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.max_look_ahead_value), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.max_look_ahead_value));
      IR_COPY_integer_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.output_action_number), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.output_action_number));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.left_hand_side), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.left_hand_side));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.right_hand_side), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.right_hand_side));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.action), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.action));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.original_code_insertion_place), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.original_code_insertion_place));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.next_canonical_rule), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.next_canonical_rule));
      IR_COPY_IR_node_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.canonical_rule_LR_situation), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.canonical_rule_LR_situation));
      IR_COPY_bool_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.canonical_rule_action_has_been_output), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.canonical_rule_action_has_been_output));
      IR_COPY_integer_t ((((_IR_canonical_rule *) to)->_IR_S_canonical_rule.action_code_copies_number), (((_IR_canonical_rule *) from)->_IR_S_canonical_rule.action_code_copies_number));
      break;
    case IR_NM_right_hand_side_element:
      _IR_copy_node_fields (IR_NM_node, (IR_node_t) ((char *) &((_IR_right_hand_side_element *) to)->_IR_S_right_hand_side_element._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)), (IR_node_t) ((char *) &((_IR_right_hand_side_element *) from)->_IR_S_right_hand_side_element._IR_M_node - _IR_offsetof (_IR_node, _IR_S_node)));
      IR_COPY_IR_node_t ((((_IR_right_hand_side_element *) to)->_IR_S_right_hand_side_element.canonical_rule), (((_IR_right_hand_side_element *) from)->_IR_S_right_hand_side_element.canonical_rule));
      IR_COPY_IR_node_t ((((_IR_right_hand_side_element *) to)->_IR_S_right_hand_side_element.next_right_hand_side_element), (((_IR_right_hand_side_element *) from)->_IR_S_right_hand_side_element.next_right_hand_side_element));
      IR_COPY_bool_t ((((_IR_right_hand_side_element *) to)->_IR_S_right_hand_side_element.cp_start_flag), (((_IR_right_hand_side_element *) from)->_IR_S_right_hand_side_element.cp_start_flag));
      IR_COPY_bool_t ((((_IR_right_hand_side_element *) to)->_IR_S_right_hand_side_element.cp_flag), (((_IR_right_hand_side_element *) from)->_IR_S_right_hand_side_element.cp_flag));
      IR_COPY_integer_t ((((_IR_right_hand_side_element *) to)->_IR_S_right_hand_side_element.minimal_FIRST_of_rule_tail_length), (((_IR_right_hand_side_element *) from)->_IR_S_right_hand_side_element.minimal_FIRST_of_rule_tail_length));
      IR_COPY_context_t ((((_IR_right_hand_side_element *) to)->_IR_S_right_hand_side_element.FIRST_of_rule_tail), (((_IR_right_hand_side_element *) from)->_IR_S_right_hand_side_element.FIRST_of_rule_tail));
      break;
    case IR_NM_canonical_rule_element:
      _IR_copy_node_fields (IR_NM_right_hand_side_element, (IR_node_t) ((char *) &((_IR_canonical_rule_element *) to)->_IR_S_canonical_rule_element._IR_M_right_hand_side_element - _IR_offsetof (_IR_right_hand_side_element, _IR_S_right_hand_side_element)), (IR_node_t) ((char *) &((_IR_canonical_rule_element *) from)->_IR_S_canonical_rule_element._IR_M_right_hand_side_element - _IR_offsetof (_IR_right_hand_side_element, _IR_S_right_hand_side_element)));
      IR_COPY_bool_t ((((_IR_canonical_rule_element *) to)->_IR_S_canonical_rule_element.next_cp_flag), (((_IR_canonical_rule_element *) from)->_IR_S_canonical_rule_element.next_cp_flag));
      IR_COPY_IR_node_t ((((_IR_canonical_rule_element *) to)->_IR_S_canonical_rule_element.element_itself), (((_IR_canonical_rule_element *) from)->_IR_S_canonical_rule_element.element_itself));
      IR_COPY_IR_node_t ((((_IR_canonical_rule_element *) to)->_IR_S_canonical_rule_element.element_identifier), (((_IR_canonical_rule_element *) from)->_IR_S_canonical_rule_element.element_identifier));
      IR_COPY_IR_node_t ((((_IR_canonical_rule_element *) to)->_IR_S_canonical_rule_element.next_single_definition_usage), (((_IR_canonical_rule_element *) from)->_IR_S_canonical_rule_element.next_single_definition_usage));
      break;
    case IR_NM_canonical_rule_end:
      _IR_copy_node_fields (IR_NM_right_hand_side_element, (IR_node_t) ((char *) &((_IR_canonical_rule_end *) to)->_IR_S_canonical_rule_end._IR_M_right_hand_side_element - _IR_offsetof (_IR_right_hand_side_element, _IR_S_right_hand_side_element)), (IR_node_t) ((char *) &((_IR_canonical_rule_end *) from)->_IR_S_canonical_rule_end._IR_M_right_hand_side_element - _IR_offsetof (_IR_right_hand_side_element, _IR_S_right_hand_side_element)));
      break;
    case IR_NM_LR_situation:
      IR_COPY_IR_node_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.goto_LR_set).field_itself, (((_IR_LR_situation *) from)->_IR_S_LR_situation.goto_LR_set).field_itself);
      (((_IR_LR_situation *) to)->_IR_S_LR_situation.goto_LR_set).link_owner = to;
      (((_IR_LR_situation *) to)->_IR_S_LR_situation.goto_LR_set).set_function = IR_F_set_goto_LR_set;
      _IR_set_double_field_value
        (&((((_IR_LR_situation *) to)->_IR_S_LR_situation.goto_LR_set)), NULL,
         _IR_offsetof (struct IR_node, _IR_first_link), 1);
      IR_COPY_bool_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.goto_arc_has_been_removed), (((_IR_LR_situation *) from)->_IR_S_LR_situation.goto_arc_has_been_removed));
      IR_COPY_context_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.look_ahead_context), (((_IR_LR_situation *) from)->_IR_S_LR_situation.look_ahead_context));
      IR_COPY_bool_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.first_symbol_LR_situation), (((_IR_LR_situation *) from)->_IR_S_LR_situation.first_symbol_LR_situation));
      IR_COPY_IR_node_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.next_symbol_LR_situation), (((_IR_LR_situation *) from)->_IR_S_LR_situation.next_symbol_LR_situation));
      IR_COPY_bool_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.important_LR_situation_flag), (((_IR_LR_situation *) from)->_IR_S_LR_situation.important_LR_situation_flag));
      IR_COPY_bool_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.situation_in_stack_flag), (((_IR_LR_situation *) from)->_IR_S_LR_situation.situation_in_stack_flag));
      IR_COPY_bool_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.under_control_point_flag), (((_IR_LR_situation *) from)->_IR_S_LR_situation.under_control_point_flag));
      IR_COPY_bool_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.back_tracking_conflict_flag), (((_IR_LR_situation *) from)->_IR_S_LR_situation.back_tracking_conflict_flag));
      IR_COPY_IR_node_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.corresponding_regular_arc), (((_IR_LR_situation *) from)->_IR_S_LR_situation.corresponding_regular_arc));
      IR_COPY_integer_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.reduce_number), (((_IR_LR_situation *) from)->_IR_S_LR_situation.reduce_number));
      IR_COPY_integer_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.popped_LR_sets_number), (((_IR_LR_situation *) from)->_IR_S_LR_situation.popped_LR_sets_number));
      IR_COPY_integer_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.popped_attributes_number), (((_IR_LR_situation *) from)->_IR_S_LR_situation.popped_attributes_number));
      IR_COPY_IR_node_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.element_after_dot), (((_IR_LR_situation *) from)->_IR_S_LR_situation.element_after_dot));
      IR_COPY_context_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.context), (((_IR_LR_situation *) from)->_IR_S_LR_situation.context));
      IR_COPY_IR_node_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.LR_set), (((_IR_LR_situation *) from)->_IR_S_LR_situation.LR_set));
      IR_COPY_IR_node_t ((((_IR_LR_situation *) to)->_IR_S_LR_situation.next_LR_situation), (((_IR_LR_situation *) from)->_IR_S_LR_situation.next_LR_situation));
      break;
    case IR_NM_LR_set:
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.conflicts_list), (((_IR_LR_set *) from)->_IR_S_LR_set.conflicts_list));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.it_is_in_LALR_sets_stack), (((_IR_LR_set *) from)->_IR_S_LR_set.it_is_in_LALR_sets_stack));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.reachable_flag), (((_IR_LR_set *) from)->_IR_S_LR_set.reachable_flag));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.it_is_pushed_LR_set), (((_IR_LR_set *) from)->_IR_S_LR_set.it_is_pushed_LR_set));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.it_is_errored_LR_set), (((_IR_LR_set *) from)->_IR_S_LR_set.it_is_errored_LR_set));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.attribute_is_used), (((_IR_LR_set *) from)->_IR_S_LR_set.attribute_is_used));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.visit_flag), (((_IR_LR_set *) from)->_IR_S_LR_set.visit_flag));
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.first_splitted_LR_set), (((_IR_LR_set *) from)->_IR_S_LR_set.first_splitted_LR_set));
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.next_splitted_LR_set), (((_IR_LR_set *) from)->_IR_S_LR_set.next_splitted_LR_set));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.back_tracking_flag), (((_IR_LR_set *) from)->_IR_S_LR_set.back_tracking_flag));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.it_is_in_reduce_action_LR_sets_stack), (((_IR_LR_set *) from)->_IR_S_LR_set.it_is_in_reduce_action_LR_sets_stack));
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.LR_set_look_ahead_trie), (((_IR_LR_set *) from)->_IR_S_LR_set.LR_set_look_ahead_trie));
      IR_COPY_integer_t ((((_IR_LR_set *) to)->_IR_S_LR_set.LR_set_order_number), (((_IR_LR_set *) from)->_IR_S_LR_set.LR_set_order_number));
      IR_COPY_integer_t ((((_IR_LR_set *) to)->_IR_S_LR_set.term_arcs_number), (((_IR_LR_set *) from)->_IR_S_LR_set.term_arcs_number));
      IR_COPY_integer_t ((((_IR_LR_set *) to)->_IR_S_LR_set.nonterm_arcs_number), (((_IR_LR_set *) from)->_IR_S_LR_set.nonterm_arcs_number));
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.start_LR_set_pass), (((_IR_LR_set *) from)->_IR_S_LR_set.start_LR_set_pass));
      IR_COPY_bool_t ((((_IR_LR_set *) to)->_IR_S_LR_set.LR_set_has_been_output_in_comment), (((_IR_LR_set *) from)->_IR_S_LR_set.LR_set_has_been_output_in_comment));
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.LR_situation_list), (((_IR_LR_set *) from)->_IR_S_LR_set.LR_situation_list));
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.LR_core), (((_IR_LR_set *) from)->_IR_S_LR_set.LR_core));
      IR_COPY_IR_node_t ((((_IR_LR_set *) to)->_IR_S_LR_set.next_LR_set), (((_IR_LR_set *) from)->_IR_S_LR_set.next_LR_set));
      break;
    case IR_NM_LR_set_look_ahead_trie_node:
      IR_COPY_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) to)->_IR_S_LR_set_look_ahead_trie_node.first_back_track_alternative), (((_IR_LR_set_look_ahead_trie_node *) from)->_IR_S_LR_set_look_ahead_trie_node.first_back_track_alternative));
      IR_COPY_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) to)->_IR_S_LR_set_look_ahead_trie_node.last_back_track_alternative), (((_IR_LR_set_look_ahead_trie_node *) from)->_IR_S_LR_set_look_ahead_trie_node.last_back_track_alternative));
      IR_COPY_integer_t ((((_IR_LR_set_look_ahead_trie_node *) to)->_IR_S_LR_set_look_ahead_trie_node.additional_action_table_number), (((_IR_LR_set_look_ahead_trie_node *) from)->_IR_S_LR_set_look_ahead_trie_node.additional_action_table_number));
      IR_COPY_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) to)->_IR_S_LR_set_look_ahead_trie_node.corresponding_single_term_definition), (((_IR_LR_set_look_ahead_trie_node *) from)->_IR_S_LR_set_look_ahead_trie_node.corresponding_single_term_definition));
      IR_COPY_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) to)->_IR_S_LR_set_look_ahead_trie_node.corresponding_LR_situation), (((_IR_LR_set_look_ahead_trie_node *) from)->_IR_S_LR_set_look_ahead_trie_node.corresponding_LR_situation));
      IR_COPY_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) to)->_IR_S_LR_set_look_ahead_trie_node.first_son), (((_IR_LR_set_look_ahead_trie_node *) from)->_IR_S_LR_set_look_ahead_trie_node.first_son));
      IR_COPY_IR_node_t ((((_IR_LR_set_look_ahead_trie_node *) to)->_IR_S_LR_set_look_ahead_trie_node.next_brother), (((_IR_LR_set_look_ahead_trie_node *) from)->_IR_S_LR_set_look_ahead_trie_node.next_brother));
      break;
    case IR_NM_back_track_alternative:
      IR_COPY_IR_node_t ((((_IR_back_track_alternative *) to)->_IR_S_back_track_alternative.corresponding_LR_set_look_ahead_trie_node), (((_IR_back_track_alternative *) from)->_IR_S_back_track_alternative.corresponding_LR_set_look_ahead_trie_node));
      IR_COPY_IR_node_t ((((_IR_back_track_alternative *) to)->_IR_S_back_track_alternative.next_back_track_alternative), (((_IR_back_track_alternative *) from)->_IR_S_back_track_alternative.next_back_track_alternative));
      break;
    case IR_NM_conflict:
      IR_COPY_IR_node_t ((((_IR_conflict *) to)->_IR_S_conflict.used_LR_situation), (((_IR_conflict *) from)->_IR_S_conflict.used_LR_situation));
      IR_COPY_IR_node_t ((((_IR_conflict *) to)->_IR_S_conflict.unused_LR_situation), (((_IR_conflict *) from)->_IR_S_conflict.unused_LR_situation));
      IR_COPY_token_string_t ((((_IR_conflict *) to)->_IR_S_conflict.token_string), (((_IR_conflict *) from)->_IR_S_conflict.token_string));
      IR_COPY_IR_node_t ((((_IR_conflict *) to)->_IR_S_conflict.next_conflict), (((_IR_conflict *) from)->_IR_S_conflict.next_conflict));
      break;
    case IR_NM_regular_arc:
      IR_COPY_IR_node_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.first_rule_list_element), (((_IR_regular_arc *) from)->_IR_S_regular_arc.first_rule_list_element));
      IR_COPY_IR_node_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.last_rule_list_element), (((_IR_regular_arc *) from)->_IR_S_regular_arc.last_rule_list_element));
      IR_COPY_integer_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.regular_arc_popped_LR_sets_number), (((_IR_regular_arc *) from)->_IR_S_regular_arc.regular_arc_popped_LR_sets_number));
      IR_COPY_integer_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.regular_arc_popped_attributes_number), (((_IR_regular_arc *) from)->_IR_S_regular_arc.regular_arc_popped_attributes_number));
      IR_COPY_integer_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.max_states_stack_increment), (((_IR_regular_arc *) from)->_IR_S_regular_arc.max_states_stack_increment));
      IR_COPY_integer_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.max_attributes_stack_increment), (((_IR_regular_arc *) from)->_IR_S_regular_arc.max_attributes_stack_increment));
      IR_COPY_bool_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.first_equivalent_regular_arc_flag), (((_IR_regular_arc *) from)->_IR_S_regular_arc.first_equivalent_regular_arc_flag));
      IR_COPY_IR_node_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.next_equivalent_regular_arc), (((_IR_regular_arc *) from)->_IR_S_regular_arc.next_equivalent_regular_arc));
      IR_COPY_integer_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.number_of_regular_arc), (((_IR_regular_arc *) from)->_IR_S_regular_arc.number_of_regular_arc));
      IR_COPY_bool_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.result_LR_set_will_be_on_the_stack), (((_IR_regular_arc *) from)->_IR_S_regular_arc.result_LR_set_will_be_on_the_stack));
      IR_COPY_IR_node_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.from_LR_situation), (((_IR_regular_arc *) from)->_IR_S_regular_arc.from_LR_situation));
      IR_COPY_IR_node_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.to_LR_set).field_itself, (((_IR_regular_arc *) from)->_IR_S_regular_arc.to_LR_set).field_itself);
      (((_IR_regular_arc *) to)->_IR_S_regular_arc.to_LR_set).link_owner = to;
      (((_IR_regular_arc *) to)->_IR_S_regular_arc.to_LR_set).set_function = IR_F_set_to_LR_set;
      _IR_set_double_field_value
        (&((((_IR_regular_arc *) to)->_IR_S_regular_arc.to_LR_set)), NULL,
         _IR_offsetof (struct IR_node, _IR_first_link), 1);
      IR_COPY_IR_node_t ((((_IR_regular_arc *) to)->_IR_S_regular_arc.terminal_marking_arc), (((_IR_regular_arc *) from)->_IR_S_regular_arc.terminal_marking_arc));
      break;
    case IR_NM_rule_list_element:
      IR_COPY_integer_t ((((_IR_rule_list_element *) to)->_IR_S_rule_list_element.right_hand_side_used_attributes_number), (((_IR_rule_list_element *) from)->_IR_S_rule_list_element.right_hand_side_used_attributes_number));
      IR_COPY_bool_t ((((_IR_rule_list_element *) to)->_IR_S_rule_list_element.lhs_nonterm_attribute_is_used), (((_IR_rule_list_element *) from)->_IR_S_rule_list_element.lhs_nonterm_attribute_is_used));
      IR_COPY_bool_t ((((_IR_rule_list_element *) to)->_IR_S_rule_list_element.result_LR_set_will_be_on_the_stack), (((_IR_rule_list_element *) from)->_IR_S_rule_list_element.result_LR_set_will_be_on_the_stack));
      IR_COPY_IR_node_t ((((_IR_rule_list_element *) to)->_IR_S_rule_list_element.canonical_rule), (((_IR_rule_list_element *) from)->_IR_S_rule_list_element.canonical_rule));
      IR_COPY_IR_node_t ((((_IR_rule_list_element *) to)->_IR_S_rule_list_element.next_rule_list_element), (((_IR_rule_list_element *) from)->_IR_S_rule_list_element.next_rule_list_element));
      break;
    case IR_NM_LR_core:
      IR_COPY_bool_t ((((_IR_LR_core *) to)->_IR_S_LR_core.first_pass_flag), (((_IR_LR_core *) from)->_IR_S_LR_core.first_pass_flag));
      IR_COPY_bool_t ((((_IR_LR_core *) to)->_IR_S_LR_core.second_pass_flag), (((_IR_LR_core *) from)->_IR_S_LR_core.second_pass_flag));
      IR_COPY_IR_node_t ((((_IR_LR_core *) to)->_IR_S_LR_core.LR_set_list), (((_IR_LR_core *) from)->_IR_S_LR_core.LR_set_list));
      IR_COPY_IR_node_t ((((_IR_LR_core *) to)->_IR_S_LR_core.next_LR_core), (((_IR_LR_core *) from)->_IR_S_LR_core.next_LR_core));
      break;
    case IR_NM_DeRemer_dependence:
      IR_COPY_context_t ((((_IR_DeRemer_dependence *) to)->_IR_S_DeRemer_dependence.context), (((_IR_DeRemer_dependence *) from)->_IR_S_DeRemer_dependence.context));
      IR_COPY_IR_node_t ((((_IR_DeRemer_dependence *) to)->_IR_S_DeRemer_dependence.dependencies), (((_IR_DeRemer_dependence *) from)->_IR_S_DeRemer_dependence.dependencies));
      IR_COPY_bool_t ((((_IR_DeRemer_dependence *) to)->_IR_S_DeRemer_dependence.context_has_been_evaluated), (((_IR_DeRemer_dependence *) from)->_IR_S_DeRemer_dependence.context_has_been_evaluated));
      IR_COPY_integer_t ((((_IR_DeRemer_dependence *) to)->_IR_S_DeRemer_dependence.pass_number), (((_IR_DeRemer_dependence *) from)->_IR_S_DeRemer_dependence.pass_number));
      IR_COPY_integer_t ((((_IR_DeRemer_dependence *) to)->_IR_S_DeRemer_dependence.unique_number), (((_IR_DeRemer_dependence *) from)->_IR_S_DeRemer_dependence.unique_number));
      IR_COPY_integer_t ((((_IR_DeRemer_dependence *) to)->_IR_S_DeRemer_dependence.look_ahead), (((_IR_DeRemer_dependence *) from)->_IR_S_DeRemer_dependence.look_ahead));
      break;
    case IR_NM_LR_set_dependence:
      _IR_copy_node_fields (IR_NM_DeRemer_dependence, (IR_node_t) ((char *) &((_IR_LR_set_dependence *) to)->_IR_S_LR_set_dependence._IR_M_DeRemer_dependence - _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)), (IR_node_t) ((char *) &((_IR_LR_set_dependence *) from)->_IR_S_LR_set_dependence._IR_M_DeRemer_dependence - _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)));
      IR_COPY_IR_node_t ((((_IR_LR_set_dependence *) to)->_IR_S_LR_set_dependence.LR_set), (((_IR_LR_set_dependence *) from)->_IR_S_LR_set_dependence.LR_set));
      IR_COPY_integer_t ((((_IR_LR_set_dependence *) to)->_IR_S_LR_set_dependence.back_distance), (((_IR_LR_set_dependence *) from)->_IR_S_LR_set_dependence.back_distance));
      IR_COPY_IR_node_t ((((_IR_LR_set_dependence *) to)->_IR_S_LR_set_dependence.nonterm), (((_IR_LR_set_dependence *) from)->_IR_S_LR_set_dependence.nonterm));
      break;
    case IR_NM_shift_dependence:
      _IR_copy_node_fields (IR_NM_DeRemer_dependence, (IR_node_t) ((char *) &((_IR_shift_dependence *) to)->_IR_S_shift_dependence._IR_M_DeRemer_dependence - _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)), (IR_node_t) ((char *) &((_IR_shift_dependence *) from)->_IR_S_shift_dependence._IR_M_DeRemer_dependence - _IR_offsetof (_IR_DeRemer_dependence, _IR_S_DeRemer_dependence)));
      IR_COPY_IR_node_t ((((_IR_shift_dependence *) to)->_IR_S_shift_dependence.token), (((_IR_shift_dependence *) from)->_IR_S_shift_dependence.token));
      break;
    case IR_NM_shift_LR_situation_dependence:
      _IR_copy_node_fields (IR_NM_shift_dependence, (IR_node_t) ((char *) &((_IR_shift_LR_situation_dependence *) to)->_IR_S_shift_LR_situation_dependence._IR_M_shift_dependence - _IR_offsetof (_IR_shift_dependence, _IR_S_shift_dependence)), (IR_node_t) ((char *) &((_IR_shift_LR_situation_dependence *) from)->_IR_S_shift_LR_situation_dependence._IR_M_shift_dependence - _IR_offsetof (_IR_shift_dependence, _IR_S_shift_dependence)));
      IR_COPY_IR_node_t ((((_IR_shift_LR_situation_dependence *) to)->_IR_S_shift_LR_situation_dependence.shift_LR_situation), (((_IR_shift_LR_situation_dependence *) from)->_IR_S_shift_LR_situation_dependence.shift_LR_situation));
      break;
    case IR_NM_dependence_list_element:
      IR_COPY_IR_node_t ((((_IR_dependence_list_element *) to)->_IR_S_dependence_list_element.dependence), (((_IR_dependence_list_element *) from)->_IR_S_dependence_list_element.dependence));
      IR_COPY_IR_node_t ((((_IR_dependence_list_element *) to)->_IR_S_dependence_list_element.next_dependence_list_element), (((_IR_dependence_list_element *) from)->_IR_S_dependence_list_element.next_dependence_list_element));
      break;
    default:
      abort ();
      break;
    }
}

IR_node_t IR_copy_node (IR_node_t node)
{
  IR_node_t _result;

  if (node == NULL)
    return NULL;
  IR_ALLOC (_result, IR_node_size [IR_NODE_MODE (node)], IR_node_t);
#ifdef __IR_DEBUG__
  if (_result == NULL)
    abort ();
#endif /* __IR_DEBUG__ */
  IR_NODE_MODE (_result) = IR_NODE_MODE (node);
  ((_IR__root *) _result)->_IR_first_link = NULL;
  _IR_copy_node_fields (IR_NODE_MODE (node), _result, node);
  return _result;
}

void IR_start (void)
{
#ifdef __IR_DEBUG__
  if (sizeof (_IR_node) > 255)
    {
      fprintf (stderr, "Very long node `node' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_identifier_or_literal) > 255)
    {
      fprintf (stderr, "Very long node `identifier_or_literal' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_identifier) > 255)
    {
      fprintf (stderr, "Very long node `identifier' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_literal) > 255)
    {
      fprintf (stderr, "Very long node `literal' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_string) > 255)
    {
      fprintf (stderr, "Very long node `string' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_number) > 255)
    {
      fprintf (stderr, "Very long node `number' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_code_insertion) > 255)
    {
      fprintf (stderr, "Very long node `code_insertion' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_additional_code) > 255)
    {
      fprintf (stderr, "Very long node `additional_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_definition) > 255)
    {
      fprintf (stderr, "Very long node `definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_start_definition) > 255)
    {
      fprintf (stderr, "Very long node `start_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_code) > 255)
    {
      fprintf (stderr, "Very long node `code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_yacc_code) > 255)
    {
      fprintf (stderr, "Very long node `yacc_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_local_code) > 255)
    {
      fprintf (stderr, "Very long node `local_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_import_code) > 255)
    {
      fprintf (stderr, "Very long node `import_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_export_code) > 255)
    {
      fprintf (stderr, "Very long node `export_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_union_code) > 255)
    {
      fprintf (stderr, "Very long node `union_code' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_scanner_definition) > 255)
    {
      fprintf (stderr, "Very long node `scanner_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_expect_definition) > 255)
    {
      fprintf (stderr, "Very long node `expect_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_symbol_definition) > 255)
    {
      fprintf (stderr, "Very long node `symbol_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_token_definition) > 255)
    {
      fprintf (stderr, "Very long node `token_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_left_definition) > 255)
    {
      fprintf (stderr, "Very long node `left_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_right_definition) > 255)
    {
      fprintf (stderr, "Very long node `right_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_nonassoc_definition) > 255)
    {
      fprintf (stderr, "Very long node `nonassoc_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_type_definition) > 255)
    {
      fprintf (stderr, "Very long node `type_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_symbol) > 255)
    {
      fprintf (stderr, "Very long node `symbol' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_rule) > 255)
    {
      fprintf (stderr, "Very long node `rule' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_pattern) > 255)
    {
      fprintf (stderr, "Very long node `pattern' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_alternative) > 255)
    {
      fprintf (stderr, "Very long node `alternative' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_sequence) > 255)
    {
      fprintf (stderr, "Very long node `sequence' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_separator_iteration) > 255)
    {
      fprintf (stderr, "Very long node `separator_iteration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_sequence_element) > 255)
    {
      fprintf (stderr, "Very long node `sequence_element' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_control_point) > 255)
    {
      fprintf (stderr, "Very long node `control_point' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_default) > 255)
    {
      fprintf (stderr, "Very long node `default' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_star_iteration) > 255)
    {
      fprintf (stderr, "Very long node `star_iteration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_plus_iteration) > 255)
    {
      fprintf (stderr, "Very long node `plus_iteration' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_code_insertion_atom) > 255)
    {
      fprintf (stderr, "Very long node `code_insertion_atom' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_unit) > 255)
    {
      fprintf (stderr, "Very long node `unit' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_group) > 255)
    {
      fprintf (stderr, "Very long node `group' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_range_atom) > 255)
    {
      fprintf (stderr, "Very long node `range_atom' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_range_no_left_bound_atom) > 255)
    {
      fprintf (stderr, "Very long node `range_no_left_bound_atom' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_range_no_right_bound_atom) > 255)
    {
      fprintf (stderr, "Very long node `range_no_right_bound_atom' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_range_no_left_right_bounds_atom) > 255)
    {
      fprintf (stderr, "Very long node `range_no_left_right_bounds_atom' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_identifier_or_literal_atom) > 255)
    {
      fprintf (stderr, "Very long node `identifier_or_literal_atom' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_string_atom) > 255)
    {
      fprintf (stderr, "Very long node `string_atom' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_description) > 255)
    {
      fprintf (stderr, "Very long node `description' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_denotation) > 255)
    {
      fprintf (stderr, "Very long node `denotation' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_single_definition) > 255)
    {
      fprintf (stderr, "Very long node `single_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_single_term_definition) > 255)
    {
      fprintf (stderr, "Very long node `single_term_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_literal_range_definition) > 255)
    {
      fprintf (stderr, "Very long node `literal_range_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_single_nonterm_definition) > 255)
    {
      fprintf (stderr, "Very long node `single_nonterm_definition' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_canonical_rule) > 255)
    {
      fprintf (stderr, "Very long node `canonical_rule' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_right_hand_side_element) > 255)
    {
      fprintf (stderr, "Very long node `right_hand_side_element' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_canonical_rule_element) > 255)
    {
      fprintf (stderr, "Very long node `canonical_rule_element' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_canonical_rule_end) > 255)
    {
      fprintf (stderr, "Very long node `canonical_rule_end' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_LR_situation) > 255)
    {
      fprintf (stderr, "Very long node `LR_situation' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_LR_set) > 255)
    {
      fprintf (stderr, "Very long node `LR_set' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_LR_set_look_ahead_trie_node) > 255)
    {
      fprintf (stderr, "Very long node `LR_set_look_ahead_trie_node' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_back_track_alternative) > 255)
    {
      fprintf (stderr, "Very long node `back_track_alternative' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_conflict) > 255)
    {
      fprintf (stderr, "Very long node `conflict' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_regular_arc) > 255)
    {
      fprintf (stderr, "Very long node `regular_arc' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_rule_list_element) > 255)
    {
      fprintf (stderr, "Very long node `rule_list_element' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_LR_core) > 255)
    {
      fprintf (stderr, "Very long node `LR_core' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_DeRemer_dependence) > 255)
    {
      fprintf (stderr, "Very long node `DeRemer_dependence' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_LR_set_dependence) > 255)
    {
      fprintf (stderr, "Very long node `LR_set_dependence' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_shift_dependence) > 255)
    {
      fprintf (stderr, "Very long node `shift_dependence' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_shift_LR_situation_dependence) > 255)
    {
      fprintf (stderr, "Very long node `shift_LR_situation_dependence' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
#ifdef __IR_DEBUG__
  if (sizeof (_IR_dependence_list_element) > 255)
    {
      fprintf (stderr, "Very long node `dependence_list_element' use option `-long-node-size' or `-short-node-size'\n");
      exit (1);
    }
#endif /* __IR_DEBUG__ */
  _IR_current_graph_pass_number = 0;
  IR_START_ALLOC ();
}

void IR_stop (void)
{
  IR_STOP_ALLOC ();
}



#line 1349 "./ird.sprut"


/* ??? */
void
process_canonical_rule_action
  (IR_node_t canonical_rule, void (*process_char) (char ch),
   void (*process_attribute) (IR_node_t canonical_rule,
                              position_t attribute_position,
                              const char *tag_name,
                              const char *attribute_name))
{
  char *code;
  char *start_code;
  vlo_t attribute_name;
  vlo_t tag_name;
  position_t start_attribute_position;
  position_t current_position;

  if (IR_action (canonical_rule) == NULL)
    return;
  VLO_CREATE (attribute_name, 100);
  VLO_CREATE (tag_name, 100);
  current_position = IR_position (IR_action (canonical_rule));
  current_position.column_number++; /* skip '{' */
  code = IR_code_insertion_itself (IR_action (canonical_rule));
  assert (code != NULL);
  /* !! This code is bound to scanner */
  while (*code != '\0')
    {
      switch (*code)
        {
        case '$':
          start_attribute_position = current_position;
          if (code [1] == '<' && (isalpha (code [2]) || code [2] == '_'))
            {
              start_code = code;
              code += 2;
              current_position.column_number += 2;
              do
                {
                  VLO_ADD_BYTE (tag_name, *code);
                  code++;
                  current_position.column_number++;
                }
              while (isalpha (*code) || isdigit (*code) || *code == '_');
              VLO_ADD_BYTE (tag_name, '\0');
              if (*code != '>')
                {
                  current_position = start_attribute_position;
                  code = start_code;
                }
            }
          VLO_ADD_BYTE (tag_name, '\0');
          if (*code != '\0')
            {
              if (code [1] == '$')
                {
                  code++;
                  current_position.column_number++;
                  (*process_attribute) (canonical_rule,
                                        start_attribute_position,
                                        VLO_BEGIN (tag_name), "$");
                }
              else if (isdigit (code [1])
                       || (code [1] == '-' && isdigit (code [2])))
                {
                  code++;
                  current_position.column_number++;
                  do
                    {
                      VLO_ADD_BYTE (attribute_name, *code);
                      code++;
                      current_position.column_number++;
                    }
                  while (isdigit (*code));
                  VLO_ADD_BYTE (attribute_name, '\0');
                  (*process_attribute) (canonical_rule,
                                        start_attribute_position,
                                        VLO_BEGIN (tag_name),
                                        VLO_BEGIN (attribute_name));
                  if (*code != '\0')
                    (*process_char) (*code);
                  VLO_NULLIFY (attribute_name);
                }
              else if (isalpha (code [1]) || code [1] == '_')
                {
                  code++;
                  current_position.column_number++;
                  do
                    {
                      VLO_ADD_BYTE (attribute_name, *code);
                      code++;
                      current_position.column_number++;
                    }
                  while (isalpha (*code) || isdigit (*code) || *code == '_');
                  VLO_ADD_BYTE (attribute_name, '\0');
                  (*process_attribute) (canonical_rule,
                                        start_attribute_position,
                                        VLO_BEGIN (tag_name),
                                        VLO_BEGIN (attribute_name));
                  if (*code != '\0')
                    (*process_char) (*code);
                  VLO_NULLIFY (attribute_name);
                }
              else
                (*process_char) (*code);
            }
          VLO_NULLIFY (tag_name);
          break;
        case '/':
          (*process_char) (*code);
          if (code [1] == '*')
            {
              /* C comment. */
              code++;
              current_position.column_number++;
              (*process_char) (*code);
              for (;;)
                {
                  code++;
                  if (*code == '*')
                    {
                      current_position.column_number++;
                      (*process_char) (*code);
                      code++;
                      if (*code == '/')
                        {
                          current_position.column_number++;
                          (*process_char) (*code);
                          break;
                        }
                      else
                        {
                          code--;
                          continue;
                        }
                    }
                  else if (*code == '\0')
                    {
                      code--;
                      break;
                    }
                  else
                    {
                      if (*code == '\n')
                        {
                          current_position.column_number = 1;
                          current_position.line_number++;
                        }
                      else
                        current_position.column_number++;
                      (*process_char) (*code);
                    }
                }
            }
          break;
        case '\'':
          (*process_char) (*code);
          code++;
          if (*code == '\0' || *code == '\n')
            code--;
          else if (*code != '\'')
            {
              current_position.column_number++;
              if (*code == '\\')
                {
                  (*process_char) (*code);
                  code++;
                  if (*code == 'n' || *code == 't' || *code == 'v'
                      || *code == 'b' || *code == 'r' || *code == 'f'
                      || *code == '\\' || *code == '\'' || *code == '\"')
                    {
                      current_position.column_number++;
                      (*process_char) (*code);
                    }
                  else if (*code == '\n')
                    {
                      current_position.column_number = 1;
                      current_position.line_number++;
                      (*process_char) (*code);
                    }
                  else if (isdigit (*code) && *code != '8' && *code != '9')
                    {
                      current_position.column_number++;
                      (*process_char) (*code);
                      if (isdigit (code [1]) && code [1] != '8'
                          && code [1] != '9')
                        {
                          code++;
                          current_position.column_number++;
                          (*process_char) (*code);
                          if (isdigit (code [1]) && code [1] != '8'
                              && code [1] != '9')
                            {
                              code++;
                              current_position.column_number++;
                              (*process_char) (*code);
                            }
                        }
                    }
                  else
                    code--;
                }
              else
                (*process_char) (*code);
            }
          else
            {
              current_position.column_number++;
              (*process_char) (*code);
            }
          if (code [1] == '\'')
            {
              code++;
              current_position.column_number++;
              (*process_char) (*code);
            }
          break;
        case '\"':
          (*process_char) (*code);
          for (;;)
            {
              code++;
              if (*code == '\"')
                {
                  current_position.column_number++;
                  (*process_char) (*code);
                  break;
                }
              else if (*code == '\0' || *code == '\n')
                {
                  code--;
                  break;
                }
              else
                {
                  current_position.column_number++;
                  if (*code == '\\')
                    {
                      (*process_char) (*code);
                      code++;
                      if (*code == 'n' || *code == 't' || *code == 'v'
                          || *code == 'b' || *code == 'r' || *code == 'f'
                          || *code == '\\' || *code == '\'' || *code == '\"')
                        {
                          current_position.column_number++;
                          (*process_char) (*code);
                        }
                      else if (*code == '\n')
                        {
                          current_position.column_number = 1;
                          current_position.line_number++;
                          (*process_char) (*code);
                        }
                      else if (isdigit (*code) && *code != '8' && *code != '9')
                        {
                          current_position.column_number++;
                          (*process_char) (*code);
                          if (isdigit (code [1]) && code [1] != '8'
                              && code [1] != '9')
                            {
                              code++;
                              current_position.column_number++;
                              (*process_char) (*code);
                              if (isdigit (code [1]) && code [1] != '8'
                                  && code [1] != '9')
                                {
                                  code++;
                                  current_position.column_number++;
                                  (*process_char) (*code);
                                }
                            }
                        }
                      else
                        code--;
                    }
                  else
                    (*process_char) (*code);
                }
            }
          break;
        default:
          (*process_char) (*code);
          break;
        }
      if (*code != '\0')
        {
          if (*code != '\n')
            current_position.column_number++;
          else
            {
              current_position.column_number = 1;
              current_position.line_number++;
            }
          code++;
        }
    }
  VLO_DELETE (attribute_name);
  VLO_DELETE (tag_name);
}


/*
Local Variables:
mode:c
End:
*/
