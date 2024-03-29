AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = msta
msta_SOURCES = common.h common.c tab.h tab.c yacc.h anal.h anal.c\
	       gen-comm.h gen-comm.c output.h output.c contexts.h contexts.c\
               relation.h relation.c lr-sets.h lr-sets.c lr.h lr.c\
               regular.h regular.c la-trie.h la-trie.c descript.h descript.c\
               parser.h parser.c gen.h gen.c main.c \
               AMMUNITION/vlobject.c \
               AMMUNITION/hashtab.c \
               AMMUNITION/allocate.c \
               AMMUNITION/objstack.c \
               AMMUNITION/position.c \
               AMMUNITION/errors.c \
               AMMUNITION/bits.c \
               AMMUNITION/ticker.c \
               AMMUNITION/commline.c \
               ird.c ird.h

nodist_msta_SOURCES = yacc.c
CLEANFILES = yacc.c
msta_CFLAGS = -I$(srcdir)/AMMUNITION
dist_doc_DATA = msta.txt msta.info msta.html msta-1.html msta-2.html msta-3.html\
	        msta-4.html msta-5.html msta-6.html msta-7.html msta-8.html msta-9.html\
	        msta.pdf msta.dvi msta.ps
dist_man_MANS = msta.1
EXTRA_DIST =  yacc.y ird.sprut msta.tst.in quality.tst.in\
	      c5.y cpp5.y fcalc.y fcalc1.y fparse.y gram.y java.y lex.y m2c.y\
	      oberon2-gram.y oberon2-kw.shilka oberon2-lex.y p-yacc.y pascal.y sql1.y\
	      README INSTALL msta.sgml.in
ACLOCAL_AMFLAGS = -I m4
SPRUT = ../SPRUT/sprut

check : test

all-local:
dist-local:

# Delete all not needed for distribution.
distclean-local:
	rm -f msta.sgml msta.tmp msta.tex msta.log msta.aux msta.toc quality.tst msta.tst msta.out
	rm -rf *a.out.dSYM

ird.c ird.h : $(srcdir)/ird.sprut
	$(SPRUT) @START_SPRUT_OPTIONS@ -access -set -new -copy $(srcdir)/ird.sprut

msta-common.$(OBJEXT) msta-anal.$(OBJEXT) msta-gen.$(OBJEXT) msta-tab.$(OBJEXT) msta-main.$(OBJEXT)\
  msta-yacc.$(OBJEXT) msta-contexts.$(OBJEXT) msta-descript.$(OBJEXT) msta-gen-comm.$(OBJEXT)\
  msta-la-trie.$(OBJEXT) msta-lr.$(OBJEXT) msta-lr-sets.$(OBJEXT) msta-output.$(OBJEXT)\
  msta-parser.$(OBJEXT) msta-regular.$(OBJEXT) msta-relation.$(OBJEXT): ird.h

yacc.c: $(srcdir)/yacc.y
	@echo must be because of error recovery \"conflicts: 6 shift/reduce\"
	$(YACC) $(srcdir)/yacc.y
# This is necessary for MS-DOS YACC (BISON) and VMS POSIX YACC
	if test ! -f y.tab.c && test -f y_tab.c;then mv y_tab.c $@;\
	elif test ! -f y.tab.c && test -f ytab.c;then mv ytab.c $@;\
	else mv y.tab.c $@;fi

test: msta
	$(SHELL) msta.tst
	$(SHELL) quality.tst
# Deremer LALR(1) & regular optimization
	./msta $(srcdir)/yacc.y
	cp yacc.c temp.c
	make msta
	./msta $(srcdir)/yacc.y
	cmp yacc.c temp.c
# LR(1) & LALR(1) optimization & regular optimization
	./msta -lr $(srcdir)/yacc.y
	cp yacc.c temp.c
	make msta
	./msta -lr $(srcdir)/yacc.y
	cmp yacc.c temp.c
# classic LALR(1) & regular optimization
	./msta -lr-situation-context -v $(srcdir)/yacc.y
	cp yacc.c temp.c
	make msta
	./msta -lr-situation-context -v $(srcdir)/yacc.y
	cmp yacc.c temp.c
# yacc emulation
	./msta -yacc $(srcdir)/yacc.y
	cp y.tab.c temp.c
	make msta
	./msta -yacc $(srcdir)/yacc.y
	cmp y.tab.c temp.c
	rm -f yacc.c temp.c y.tab.c yacc.output
	$(SHELL) ../AMMUNITION/compare_parsers.tst

# Creation of documentation

doc :
	nroff -man $(srcdir)/msta.1 | $(AWK) '{gsub (/.\b/,"");gsub (/.\200\230/,"\140");gsub (/.\200\231/,"\047");gsub (/\033\[[140]m/,"");gsub (/\033\[2[24]m/,"");print;}' > msta.tmp
	$(AWK) '{if($$0 == "%%%")\
                     {while ((getline line < "msta.tmp") > 0)\
                        print line;close("msta.tmp")}\
                 else print;}' $(srcdir)/msta.sgml.in > msta.sgml
	rm -f msta.tmp
	linuxdoc -B txt --papersize=letter -f msta.sgml
	mv msta.txt $(srcdir)
	linuxdoc -B html --papersize=letter msta.sgml
	if test -f msta-1.html;then\
  	  for i in msta-*.html;do\
   	    mv $$i $(srcdir)/$$i;\
	  done;\
        fi
	mv msta.html $(srcdir)/msta.html
	linuxdoc -B info --papersize=letter msta.sgml
	if test -f msta.info;then\
	  for i in msta.info*;do\
   	    mv $$i $(srcdir)/$$i;\
	  done;\
        fi
	linuxdoc -B latex --papersize=letter msta.sgml
	if test ! -f msta.dvi\
           -o -f msta.tex -a msta.tex -nt msta.dvi; then\
    	        latex msta.tex; latex msta.tex;\
        fi
	mv msta.dvi $(srcdir)/msta.dvi
	dvips -o $(srcdir)/msta.ps $(srcdir)/msta.dvi
	ps2pdf $(srcdir)/msta.ps $(srcdir)/msta.pdf

