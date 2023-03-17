#include <cstring>
#include <cstddef>
#include <istream>
#include <iostream>
#include <fstream>

#include "scanner.hh"
#include "parser.tab.hh"
#include "symtab.h"
int main(const int argc, const char **argv)
{

  using namespace std;
  fstream in_file, in_file1;
  in_file.open(argv[1], ios::in);
  // Generate a scanner
  IPL::Scanner scanner(in_file);
  // Generate a Parser, passing the scanner as an argument.
  // Remember %parse-param { Scanner  &scanner  }
  IPL::Parser parser(scanner);
  
  #ifdef YYDEBUG
   parser.set_debug_level(1);
  #endif 

  parser.parse();
  in_file.close();
  
  in_file1.open(argv[1], ios::in);
  // Generate a scanner
  IPL::Scanner scanner2(in_file1);
  // Generate a Parser, passing the scanner as an argument.
  // Remember %parse-param { Scanner  &scanner  }
  IPL::Parser parser2(scanner2);
  
  #ifdef YYDEBUG
   parser2.set_debug_level(1);
  #endif 
  cerr<<"Parsing round 1 done"<<endl;
  parser2.parse();


}

