CC=gcc
CFLAGS=-Iinclude -g -Wall -Wno-unused-function
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
			objfiles/synthesizer.o


rasm.exe: $(OBJFILES)
	$(CC) -o $@ $^ $(CFLAGS)

objfiles/%.o: source/%.c include/ast.h $(DATA_STR_INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

objfiles/addresser.o  objfiles/parser.tab.o: include/cmpAndDstrFuncs.h
objfiles/lex.yy.o objfiles/main.o: include/y.tab.h
objfiles/replacer.o: include/error.h
objfiles/synthesizer.o objfiles/main.o: include/synthesizer.h
objfiles/main.o: include/addresser.h include/replacer.h

source/lex.yy.c: lexer.l
	flex -o$@ $<
source/parser.tab.c include/y.tab.h: parser.y
	bison -t -v -osource/parser.tab.c --defines=include/y.tab.h parser.y

.PHONY: clean
clean : 
	rm -f objfiles/*.o