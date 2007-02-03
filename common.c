/*
   Copyright (C) 1997-2007 Vladimir Makarov.

   Written by Vladimir Makarov <vmakarov@users.sourceforge.net>

   This file is part of the tool MSTA.

   This is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This software is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GNU CC; see the file COPYING.  If not, write to the Free
   Software Foundation, 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.

*/

#include "ird.h"
#include "common.h"

/* Flag of creation of the interface (header) file (`-d', `-define').
   By default only the implementation (code) file is created. */

int define_flag;

/* Flag of the implementation file gneration without any #line
   constructs (`-l', `-line').  If this option is not present, it is
   unspecified whether the code file or header file contains #line
   directives. */

int line_flag;

/* Flag of modification of conditional compilation directives to
   permit compilation of debugging code in the code file (`-t',
   `-trace').  Runtime debugging statements shall be always contained
   in the code file, but by default conditional compilation directives
   prevent their compilation. */

int trace_flag;

/* Flag of creation of a file containing a description of the parser
   and a report of conflicts generated by ambiguities in the grammar
   (`-v', `-verbose'). */

int verbose_flag;

/* Name without suffixes of generated files (header, code, and
   description files) when option `-yacc-file-names' is on.  See flag
   `-b ...'.  File_prefix is used as the prefix for all output
   filenames.  The default value is "y".  The code file y.tab.c, the
   header file y.tab.h (created when -d is specified), and the
   description file y.output (created when -v is specified), shall be
   changed to file_prefix.tab.c, file_prefix.tab.h, and
   file_prefix.output, respectively. */

const char *file_prefix;

/* Sym_prefix is used as the prefix for all external names produced by
   MSTA.  The default value is "yy".  The names affected shall include
   the functions yyparse(), yylex(), and yyerror(), and the variables
   yylval, yychar, and yydebug. (In the remainder of this clause, the
   six symbols cited are referenced using their default names only as
   a notational convenience.)  Local names may also be affected by the
   -p option; however, the -p option shall not affect MSTA-generated
   #define symbols.  See option `-p ...'. */

const char *sym_prefix;

/* Flag `-w' of inhibiting all warning messages. */

int w_flag;

/* Flag `-c++' for generation of C++ code. */

int cpp_flag;

/* Flag `-enum' for generation of token constants as enum instead of
   as macro. */

int enum_flag;

/* Flag `-pattern-equiv' means that equivalent patterns are denoted by
   the same nonterminal, otherwise equivalent patterns are denoted by
   different nonterminals and are expanded into the different set of
   rules. Exmaple, the rules
       a : ('b' / ',') c
         | ('b' / ',') d
   will be expanded into
       a : $1 c
         | $1 d
       $1 : $2
       $2 : $2 ',' 'b'
          | 'b'
   not into
       a : $1 c
         | $3 d
       $1 : $2
       $2 : $2 ',' 'b'
          | 'b'
       $3 : $4
       $4 : $4 ',' 'b'
          | 'b'
   as when -no-pattern-equiv is given.

   Equivalence is deteremined by equivalence of the corresponding
   abstract trees (without any symbolic manipulations).  The exceptions:
      all actions are different (i.e. Two "('b' {})" are not equivalent);
      names (after 'a') of patterns are not taken into account;
*/

int pattern_equiv_flag;

/* Flag `-full-lr-set' of writing full LR-sets into a file containing
   description of the parser (the option acts only with option
   `-v'). */

int full_lr_set_flag;

/* Flag `-lr-situation-context' of writing context of LR-situations
   into a file containing description of the parser (the option acts
   only with option `-v'). */

int lr_situation_context_flag;

/* Flag `-removed-lr-sets' of writing LR-sets removed during conflict
   resolution and regular optimization into description of the parser
   (the option acts only with option -v). */

int removed_lr_sets_flag;

/* Parameter value of flag `-look-ahead'.  If parameter is invalid or
   nonpositive the following variable value will be 1. */

int look_ahead_number;

/* Flag of building canonical LR-sets, i.e. input grammar is processed
   as LR(k)-grammar (`-lr').  In the opposite case input grammar is
   considered as LALR(k)-grammar, i.e.  all canonical LR-sets with the
   same core are.  The defualt value is FALSE.  The opposite value
   will be when flag `-no-lr' is present on the MSTA command line. */

int lr_flag;

/* Flag (`-lalr-optimization') of extraction of LALR parts of input
   LR(k)-grammar and represent them by by adequate LR-sets
   (i.e. LR-sets obtained by merging the corresponding canonical
   LR-sets with the same core) when option `-lr' is on.  The defualt
   value is TRUE.  The value `FALSE' will be when flag
   `-no-lalr-optimization' is present on the MSTA command line. */

int lalr_optimization_flag;

/* Flag (`-regular-optimization') of extraction of regular parts of
   input grammar and implement them by by adequate methods
   (deterministic finite automaton).  The defualt value is TRUE.  The
   value `FALSE' will be when flag `-no-regular-optimization' is
   present on the MSTA command line. */

int regular_optimization_flag;

/* Flag (`-split-lr-sets') of splitting LR-sets during regular
   optimization in order to extract more regular parts.  The default
   value is FALSE.  The value `FALSE' will be when flag
   `-no-split-lr-sets' is present on the MSTA command line. */

int split_lr_sets_flag;

/* The following variable value is TRUE if any option `-split-lr-sets'
   or `-no-split-lr-sets' is present on the command line of MSTA. */

int split_lr_sets_flag_is_defined;


/* Flag (`-yacc-error-recovery') of using error recover according to
   Posix YACC standard.  Recovery procedure discards states and
   objects from the stack until it gets back to a state in which the
   `error' token is acceptable.  After that parser shall shift over
   error and reads tokens and discards them until it finds a token
   which is in look ahead set after the token `error'.

   Flag (`-local-error-recovery') means another error recovery method
   is used.  According this method look ahead set also includes look
   ahead tokens after token `error' in states which have the `error'
   token is acceptable and which are lower in the parser stack than
   the first state with acceptable token `error'.  In this case the
   feedback from the parser to the scanner could not work correctly
   because although rule actions are executed in such case the parser
   reads the tokens once.

   Flag (`-minimal-error-recovery') means usage of the minimal cost
   error recovery where the cost is overall number of tokens ignored.
   The feedback from the parser to the scanner does not work
   correctly.  So you shouldn't use this method when there is the
   feedback.  Calling yyerrok has no sense for such method because the
   parser in such recovery mode never executes the rule actions.

   The defualt value is YACC_ERROR_RECOVERY. */

int msta_error_recovery;

/* Flag of that MSTA generates parser with possible default reducing
   (without checking the look ahead) when the token error is in the
   context. (`-error-reduce').  The default value is TRUE.  The
   opposite value will be when flag `-no-error-reduce' is present on
   the MSTA command line.  That means that the parser makes reduces
   only when there is corresponding look ahead.  It results in better
   error recovery but the parser will have bigger size. */

int error_reduce_flag;

/* Flag of that MSTA reports conflicts on look ahead containing token
   error (`-error-conflict').  The default value is TRUE.  The
   opposite value will be when flag `-no-error-conflict' is present on
   the MSTA command line.  Token error is not a real token it is never
   read but many error recovery rules may generate conflicts on error.
   To avoid this you can use the option.  In this case the conflict on
   error will be not reported for LR-set which is the result of
   shifting token error. */

int error_conflict_flag;

/* Flag of that MSTA accepts input file only in the format of Posix
   YACC (`-yacc-input').  The defualt value is FALSE.  The opposite
   value will be when flag `-no-yacc-input' is present on the MSTA
   command line. */

int yacc_input_flag;

/* This flag affects only when `-yacc-input' is on.  Flag of that MSTA
   accepts input file only in the format of strict Posix YACC
   (`-strict').  The defualt value is FALSE.  The opposite value will
   be when flag `-no-yacc-input' is present on the MSTA command
   line. */

int strict_flag;

/* Flag of output files will be named according to Posix YACC.  The
   default value is FALSE.  The opposite value will be when flag
   `-no-yacc-file-names' is present on the MSTA command line.

   In the opposite case the input file name must have suffix `.y'.
   Output files will have the same name (if option `-o ...' is absent
   on the command line) and suffixes `.h', `.c', and `.output'. */

int yacc_file_names_flag;

/* Flag of that attributes & states in the generated parser will be
   expandable (`-expand').  Default value is TRUE. */

int expand_flag;

/* Flag of outputting time statistics into stderr.  Default value is
   FALSE. */

int time_flag;

#ifndef NDEBUG
/* Level of outputting debug information into stderr.  Default value
   is 0.  See flag `-debug'. */

int debug_level;
#endif

/* Name without suffix of generated files (header, code, and
   description files). See flag `-o ...'. */

const char *output_files_name;

/* Name of source file on the command line. */

const char *source_file_name;

/* Description file of generated parser.  The value is NULL if the
   file is not created. */

FILE *output_description_file;

/* Generated parser description file name. */

char *output_description_file_name;

/* Interface (header) file of generated parser.  The value is NULL if
   the file is not created. */

FILE *output_interface_file;

/* Generated parser interface file name. */

char *output_interface_file_name;

/* Implementation (code) file of generated parser.  The value is NULL
   if the file is not created. */

FILE *output_implementation_file;

/* Generated parser implementation file name. */

char *output_implementation_file_name;

/* Description (code) file of generated parser.  The value is NULL
   if the file is not created. */

FILE *output_description_file;

/* Generated parser description file name. */

char *output_description_file_name;

/* Value of the following variable is node representing description
   being processed. */

IR_node_t description;

/* Value of the following variable is node representing reserved
   terminal error.  It is set up only after the analysis. */

IR_node_t error_single_definition;

/* Maximum of look ahead on the command line and in %la constructions. */

int max_look_ahead_number;
