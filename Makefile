CXX   ?= g++-8
EXE = ipl_parser
CXXDEBUG = -g -Wall
CXXSTD = -std=c++11


.PHONY: all
all: parser lexer
	$(CXX) $(CXXDEBUG) -o iplC driver.cpp parser.o scanner.o 

.PHONY: parser
parser: parser.yy scanner.hh
	bison -d -v $<
	$(CXX) $(CXXDEBUG) -c parser.tab.cc -o parser.o 
.PHONY: lexer
lexer: scanner.l scanner.hh	
	bison -d -v parser.yy
	flex++ --outfile=scanner.yy.cc  $<
	$(CXX)  $(CXXDEBUG) -c scanner.yy.cc -o scanner.o
graph: 
	./ipl_parser aj-sample1.c 2>debug_messages > graph.dot
	dot -Tpng graph.dot > graph.png
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
