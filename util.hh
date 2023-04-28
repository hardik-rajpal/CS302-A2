#ifndef UTIL_HH
#define UTIL_HH
#include "ast.hh"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstdarg>

using namespace std;
inline void printAst(const char *astname, const char *fmt...) // fmt is a format string that tells about the type of the arguments.
{   
	typedef vector<abstract_astnode *>* pv;
	va_list args;
	va_start(args, fmt);
	if ((astname != NULL) && (astname[0] != '\0'))
	{
		cout << "{ ";
		cout << "\"" << astname << "\"" << ": ";
	}
	cout << "{" << endl;
	cout << "# ";
	while (*fmt != '\0')
	{
		if (*fmt == 'a')
		{
			char * field = va_arg(args, char *);
			abstract_astnode *a = va_arg(args, abstract_astnode *);
			cout << "\"" << field << "\": " << endl;
	cout << "# ";
			
			a->print();
		}
		else if (*fmt == 's')
		{
			char *field = va_arg(args, char *);
			char *str = va_arg(args, char *);
			cout << "\"" << field << "\": ";
			cout << "\"" << str << "\"\n# ";
		}
		else if (*fmt == 'i')
		{
			char * field = va_arg(args, char *);
			int i = va_arg(args, int);
			cout << "\"" << field << "\": ";

			cout << i;
		}
		else if (*fmt == 'f')
		{
			char * field = va_arg(args, char *);
			double f = va_arg(args, double);
			cout << "\"" << field << "\": ";
			cout << f;
		}
		else if (*fmt == 'l')
		{
			char * field = va_arg(args, char *);
			pv f =  va_arg(args, pv);
			cout << "\"" << field << "\": ";
			cout << "[" << endl;
			cout << "# ";
			for (int i = 0; i < (int)f->size(); ++i)
			{
				if ((*f)[i]) {
					(*f)[i]->print();
					if (i < (int)f->size() - 1){
						cout << "," << endl;
						cout << "# ";
					}
					else{
						cout << endl;
						cout << "# ";
					}
				}
			}
			cout << endl;
			cout << "# ]" << endl;
			cout << "# ";
		}
		++fmt;
		if (*fmt != '\0'){
			cout << "," << endl;
			cout << "# ";
		}
	}
	cout << "}" << endl;
	cout << "# ";
	if ((astname != NULL) && (astname[0] != '\0')){
		cout << "}" << endl;
		cout << "# ";
	}
	va_end(args);
}
#endif