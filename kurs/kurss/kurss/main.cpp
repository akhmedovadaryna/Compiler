#include "main.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{ 
	AllTab TAB;
	int KeyRegime;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
			 lex_analizing(&TAB);		
			 sint_analizing(&TAB);
			 weight(&TAB);
			 Segs(&TAB);
			 MakeTabIdent(&TAB);
			 code(&TAB);
			 writeListing1(&TAB);
	system("pause");
}