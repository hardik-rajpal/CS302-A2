CXX   = g++
EXE = ipl_parser
CXXDEBUG = -g
CXXSTD = -std=c++11


.PHONY: all
all: parser lexer ast.o symtab.cpp symtab.h
	$(CXX) $(CXXDEBUG) -o iplC driver.cpp symtab.cpp parser.o scanner.o ast.o
.PHONY: parser
parser: parser.yy scanner.hh
	bison -d -v $<
	$(CXX) $(CXXDEBUG) -c parser.tab.cc -o parser.o 
.PHONY: lexer
lexer: scanner.l scanner.hh	
	bison -d -v parser.yy
	flex++ --outfile=scanner.yy.cc  $<
	$(CXX)  $(CXXDEBUG) -c scanner.yy.cc -o scanner.o
ast.o: ast.cpp ast.hh util.hh
	g++ -c -g ast.cpp 
graph: 
	./ipl_parser main.c 2>debug_messages > output.txt
.PHONY: clean
clean:
	rm *.o
	rm *.output
	rm *.tab.*
	rm position.hh
	rm scanner.yy.cc
	rm stack.hh
	rm iplC
	rm location.hh
