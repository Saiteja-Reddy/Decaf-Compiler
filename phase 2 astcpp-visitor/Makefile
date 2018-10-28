calc: calc.yy calc.ll driver.cc ast.cc ast.h driver.h scanner.h PostFixVisitor.h
		bison -d calc.yy
		flex calc.ll
		g++ -Wno-c++11-extensions -g -o calc driver.cc ast.cc calc.tab.cc lex.decaf.cc -ll

clean: 
		rm calc.tab.cc calc.tab.hh lex.decaf.cc location.hh  position.hh stack.hh