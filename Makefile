CXX   = g++
EXE = ipl_parser
CXXDEBUG = -g
CXXSTD = -std=c++11


.PHONY: all
all: parser lexer ast.o symtab.cpp symtab.h
	$(CXX) $(CXXDEBUG) -o iplC driver.cpp symtab.cpp build/parser.o build/scanner.o build/ast.o
	mv parser.tab.cc gen/parser.tab.cc
	mv parser.tab.hh gen/parser.tab.hh
	mv stack.hh gen/stack.hh
	mv location.hh gen/location.hh
	mv position.hh gen/position.hh
	mv parser.output debug/parser.output
	mv scanner.yy.cc gen/scanner.yy.cc

.PHONY: parser
parser: parser.yy scanner.hh
	bison -d -v $<
	$(CXX) $(CXXDEBUG) -c parser.tab.cc -o build/parser.o 
.PHONY: lexer
lexer: scanner.l scanner.hh	
	bison -d -v parser.yy
	flex++ --outfile=scanner.yy.cc  $<
	$(CXX)  $(CXXDEBUG) -c scanner.yy.cc -o build/scanner.o
ast.o: ast.cpp ast.hh util.hh
	g++ -c -g ast.cpp -o build/ast.o
graph: 
	./ipl_parser main.c 2>debug_messages > output.txt
.PHONY: clean
clean:
	rm -f **/*.o
	rm -f **/*.output
	rm -f **/*.tab.*
	rm -f **/position.hh
	rm -f **/stack.hh
	rm -f **/iplC
	rm -f **/location.hh
	rm -f **/scanner.yy.cc
