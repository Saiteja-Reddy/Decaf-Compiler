parser: common.h common.cpp parser.ypp scanner.l ast.h ast.cpp
		bison -d parser.ypp
		flex scanner.l
		g++ -std=c++11 -o  parser common.cpp parser.tab.cpp lex.yy.c ast.cpp -ll

clean:
	rm lex.yy.c parser parser.tab.cpp parser.tab.hpp