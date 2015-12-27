#ifndef LEXER_H
#define LEXER_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>  // For _CrtSetReportMode
#include <iostream>
 class tab_lex{
	friend int cuter(char* str, tab_lex	*tab, int i, int *numb);
public:
	tab_lex();
	~tab_lex();
	void lexem_name( char*, int);  //задает лексемы(имя)
	void lexem_type(char*);   //тип лексемы
	void proverka_lexem_type(char*); // проверка типа лексемы
	void nomer(int);       //задаем номер 
	int vernut_nomer();           //возвращаем номер
	bool ravna_li_str_lex(char*);         //проверяем равна ли строка лексеме
	char* vernut_lex();             //возвращаем лексему
	int vernu_dlinu_lex();          //возвращаем длину лексемы
	char* vernut_lexsem_type();       //возвращаем тип лексемы
	bool proverka_podstr_in_str(char*);      //проверка(есть ли в типе подстрока)
	static void SetEND(char*, int);
	static void SetSTART(char*, int);
	static int GetEND(char*);
	static int GetSTART(char*);
	static void SetIDEND(char*, int);
	static void SetIDSTART(char*, int);
	static int GetIDEND(char*);
	static int GetIDSTART(char*);
	void print();
private:
	int		number;  //номер
	char	*lex;    //лексема
	int		len_lex; //длина лексемы
	char	*type_lex; //тип лексемы
	static int datasegmentend; //номер строки, где заканчивается datasegment
	static int numb_lex_end; //номер лексемы конца datasegment
	static int start_ds; // номер стоки, где начинается DS
	static int numb_lex_ds; //номер лексемы начала DS
	static int endsegmentcode;     // номер cтроки, где заканчивается segment cod
	static int numb_lex_sc;   // номер лексемы конца SC
	static int str_sc;   // номер стоки, где начинается SC
	static int numb_lex_st_sc;//номер лексемы начала SC
};

 class DynTab {
public:
	DynTab();
	tab_lex		Inf;
	class DynTab *Next;
	class DynTab *Prev;
} ;

#endif