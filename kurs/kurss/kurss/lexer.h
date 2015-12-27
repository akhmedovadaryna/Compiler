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
	void lexem_name( char*, int);  //������ �������(���)
	void lexem_type(char*);   //��� �������
	void proverka_lexem_type(char*); // �������� ���� �������
	void nomer(int);       //������ ����� 
	int vernut_nomer();           //���������� �����
	bool ravna_li_str_lex(char*);         //��������� ����� �� ������ �������
	char* vernut_lex();             //���������� �������
	int vernu_dlinu_lex();          //���������� ����� �������
	char* vernut_lexsem_type();       //���������� ��� �������
	bool proverka_podstr_in_str(char*);      //��������(���� �� � ���� ���������)
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
	int		number;  //�����
	char	*lex;    //�������
	int		len_lex; //����� �������
	char	*type_lex; //��� �������
	static int datasegmentend; //����� ������, ��� ������������� datasegment
	static int numb_lex_end; //����� ������� ����� datasegment
	static int start_ds; // ����� �����, ��� ���������� DS
	static int numb_lex_ds; //����� ������� ������ DS
	static int endsegmentcode;     // ����� c�����, ��� ������������� segment cod
	static int numb_lex_sc;   // ����� ������� ����� SC
	static int str_sc;   // ����� �����, ��� ���������� SC
	static int numb_lex_st_sc;//����� ������� ������ SC
};

 class DynTab {
public:
	DynTab();
	tab_lex		Inf;
	class DynTab *Next;
	class DynTab *Prev;
} ;

#endif