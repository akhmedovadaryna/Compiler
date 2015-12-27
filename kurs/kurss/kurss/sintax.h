#ifndef SINTAX_H
#define SINTAX_H

#include "lexer.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>  // For _CrtSetReportMode
#include <iostream>

class tab_sint{
	friend int cuter(char* str, tab_lex *tab_lex, tab_sint	*tab, int *numb);
public:
	tab_sint();
	~tab_sint();
	void Set_number_lex_field_label(int);
	void Set_number_first_lex_field_mnemocode(int);
	void Set_amount_lex_field_mnemocode(int);
	void Set_number_first_lex_operand1(int);
	void Set_amount_lex_operand1(int);
	void Set_number_first_lex_operand2(int);
	void Set_amount_lex_oprerand2(int);
	void check_lex(char*,DynTab*,int*,int);
	static int Get_number_sent();
	static void INC_number_sent();
	void print();
	int Get_number_lex_field_label();
	int Get_number_first_lex_field_mnemocode();
	int Get_amount_lex_field_mnemocode();
	int Get_number_first_lex_operand1();
	int Get_amount_lex_operand1();
	int Get_number_first_lex_operand2();
	int Get_amount_lex_operand2();
	void AddWeight(int);
	int GetWeight();
	int flag;
	void SetCode(int, int);
	int  GetCode(int);
	void CreateCode(int);
	void SetCodeData(int);
	void SetCodeFract(int, int);
	int Get_nCode();

private:

	int number_lex_field_label;
	int number_first_lex_field_mnemocode;
	int amount_lex_field_mnemocode;
	int number_first_lex_operand1;
	int amount_lex_operand1;
	int number_first_lex_operand2;
	int amount_lex_operand2;

	int weight;
	int *Code;
	int nCode;
	static int number_sent;
	
};

class DynTab_sint {
public:
	DynTab_sint();
	tab_sint	Inf;
	class DynTab_sint *Next;
	class DynTab_sint *Prev;
} ;

int cuter_sint(char* str, DynTab *tab_lex, tab_sint	*tab, int *numb, int number_str);
void amountWord(char *str, int* numb);
#endif 