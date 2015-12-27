#ifndef TAB_SEG_H
#define TAB_SEG_H
#include "main.h"
class tab_segment{
public:
	tab_segment();
	void SetName(char*);
	char* GetName();
	void SetLength(int);
	int GetLength();
private:
	char	*Name;
	int		Length;
	char	*Align;
	char	*CombineClass;
};

class dyn_tab_segment{
public:
	dyn_tab_segment();
	tab_segment Inf;
	dyn_tab_segment *Next;
	dyn_tab_segment *Prev;
};
#endif