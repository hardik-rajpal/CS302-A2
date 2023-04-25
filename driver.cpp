#include <cstring>
#include <cstddef>
#include <istream>
#include <iostream>
#include <fstream>

#include "scanner.hh"
#include "parser.tab.hh"
#include "symtab.h"
#undef YYDEBUG
void doAPass(string fname){
  fstream in_file;
  in_file.open(fname, ios::in);
  IPL::Scanner scanner(in_file);
  IPL::Parser parser(scanner);
  #ifdef YYDEBUG
   parser.set_debug_level(1);
  #endif 
  parser.parse();
  in_file.close();

}
int main(const int argc, const char **argv)
{

  using namespace std;
  string fname = string(argv[1]);
  doAPass(fname);
  cerr<<"Parsing round 1 done"<<endl;
  doAPass(fname);
  cerr<<"Symtabs and ASTs done."<<endl;
  doAPass(fname);
}

