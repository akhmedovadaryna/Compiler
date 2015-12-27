#ifndef MAIN_H
#define MAIN_H

#include "lexer.h"
#include "sintax.h"
#include "tab_seg.h"
#include "id.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>  // For _CrtSetReportMode
#include <iostream>

class AllTab{
public:
	AllTab();
	~AllTab();
// ������
	void print_lex(); // �������� ������� ������
	void print_SentStruct(); // �������� ������� �������� �����������
	DynTab* lexemfound(int);    // ���������� �������, ���������� ��������� �� �������
	bool IsID(char*);        // �������� ��������������� � ������� �� ����������
	int	 WeightLabel(int);   // ���������� ��� ������ �� �����
	
//������

	class DynTab *LexTab;  // ������� ������
	int number_str_lex;    // ���-�� ������
	class DynTab_sint *TabSentStruct;   // ������� �������� �����������
	class dyn_tab_segment *SegmentTab;   // ������� ���������
	class DynTabIdentificator *TabIdentificator;    //  ������� ���������������
};
   // �������

double divdegree(int x, int n, double result);
extern int lex_analizing(AllTab *tab);
extern int sint_analizing(AllTab *tab);
extern void Segs(AllTab *tab);
extern void weight(AllTab *tab);
extern void writeListing1(AllTab *tab);
extern void writeSegments(AllTab *tab);
extern void MakeTabIdent(AllTab *tab);
extern void code(AllTab* tab);

#endif