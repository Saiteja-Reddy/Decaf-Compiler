parser: common.h common.cpp parser.ypp scanner.l ast.h PostfixVisitor.h ast.cpp
		bison -d parser.ypp
		flex scanner.l
		g++ -std=c++11 -Wno-deprecated-register -o  decaf_compiler common.cpp parser.tab.cpp lex.yy.c ast.cpp -ll `llvm-config --cppflags --ldflags --libs core --system-libs`


clean:
	rm lex.yy.c decaf_compiler parser.tab.cpp parser.tab.hpp

