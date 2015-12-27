#ifndef ID_H
#define ID_H

#include "main.h"
class TabIdentificator{
public:
	TabIdentificator();
	void name_set(char*);
	char* name_get();
	bool name_sravnenie(char*);
	void namemetkaset(char*);
	char* namemetkaget();
	void type_set(char*);
	char* type_get();
	void valuee_set(int);
	int valuee_get();
	static void inc_1();
	static int get_1();

private:
	char* Name;
	char* Type;
	int	  Value;
	char* Attr;
	static int amount;
};

class DynTabIdentificator{
public:
	DynTabIdentificator();
	class TabIdentificator Inf;
	class DynTabIdentificator *Next;
	class DynTabIdentificator *Prev;
};
#endif