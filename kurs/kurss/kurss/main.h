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
// методы
	void print_lex(); // печается таблица лексем
	void print_SentStruct(); // печатает таблицу структур предложений
	DynTab* lexemfound(int);    // нахождение лексемы, возвращает указатель на лексему
	bool IsID(char*);        // проверка идентификаторов в таблице на повторения
	int	 WeightLabel(int);   // возвращает вес строки по метке
	
//данные

	class DynTab *LexTab;  // таблица лексем
	int number_str_lex;    // кол-во лексем
	class DynTab_sint *TabSentStruct;   // таблица структур предложений
	class dyn_tab_segment *SegmentTab;   // таблица сегментов
	class DynTabIdentificator *TabIdentificator;    //  таблица идентификаторов
};
   // функции

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