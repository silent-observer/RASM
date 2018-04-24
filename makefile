CC=gcc
CFLAGS=-Iinclude -g -Wall -Wno-unused-function -Wno-unused-label
DATA_STR_INCLUDE =	include/data_structures/dynamicarray_g.h \
					include/data_structures/linkedlist_g.h \
					include/data_structures/redblacktree_g.h \
					include/data_structures/redblacktree_g_insert.h \
					include/data_structures/redblacktree_g_remove.h
OBJFILES = 	objfiles/addresser.o \
			objfiles/cmpAndDstrFuncs.o \
			objfiles/lex.yy.o \
			objfiles/main.o \
			objfiles/parser.tab.o \
			objfiles/replacer.o \
			objfiles/synthesizer.o \
			objfiles/userMacroReplacer.o \
			objfiles/includeReplacer.o

win: rasm.exe
linux: rasm

rasm.exe: $(OBJFILES)
	$(CC) -o $@ $^ $(CFLAGS)

rasm: $(OBJFILES)
	$(CC) -o $@ $^ $(CFLAGS)

objfiles/%.o: source/%.c include/ast.h $(DATA_STR_INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

objfiles/addresser.o  objfiles/parser.tab.o objfiles/includeReplacer.o objfiles/main.o: include/cmpAndDstrFuncs.h
objfiles/lex.yy.o objfiles/main.o, objfiles/includeReplacer.o: include/y.tab.h
objfiles/replacer.o objfiles/userMacroReplacer.o objfiles/includeReplacer.o: include/error.h
objfiles/synthesizer.o objfiles/main.o: include/synthesizer.h
objfiles/main.o: include/addresser.h include/replacer.h include/userMacroReplacer.h include/includeReplacer.h

source/lex.yy.c: lexer.l
	flex -o$@ $<
source/parser.tab.c include/y.tab.h: parser.y
	bison -t -osource/parser.tab.c --defines=include/y.tab.h parser.y

.PHONY: clean
clean :
	rm -f objfiles/*.o
