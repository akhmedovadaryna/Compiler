#include "main.h"
#include <iostream>
#include <fstream>
#include <cstdlib>


AllTab::AllTab() //����������� ��������� ��������� ��������
{
	LexTab = NULL;
	TabSentStruct = NULL;
	SegmentTab = NULL;
	number_str_lex = 0;
	TabIdentificator = NULL;
}
AllTab::~AllTab()	
{
	delete LexTab;
}

void AllTab::print_lex()
{
		DynTab *Run_tab;
/*				printf("________________________________________________________________________________\n");
	printf("---------------------------------������� ������---------------------------------\n");
	printf("________________________________________________________________________________\n");
	printf("  |� �/�|     |�������|   |������� |            |��� �������|\n");
	printf("________________________________________________________________________________\n");
	Run_tab = LexTab;
	for (int i = 0; i < number_str_lex; i++)
	{	Run_tab->Inf.print();
		Run_tab = Run_tab->Next;
	}
	*/ 
	
}

void AllTab::print_SentStruct()
{
	DynTab_sint *Run_tab;
/*	cout << "\n______________________________________________________________________\n" 
	 << "\n---------------------------------������� ��������� �������----------------\n"
	<< "_____________________________________________________________________________\n"
	<< "|���� ����|  |      ����       |  |        1-�       |  |        2-�       |\n"
	<< "|  (����) |  |    ���������    |  |      �������     |  |      �������     |\n"
	<< "_____________________________________________________________________________\n"
	<< "|     �    |  |������|ʳ������|  |� �����|ʳ������|  |� �����|ʳ������|\n"
	<< "|  ������� |  |�������| ������  |  | �������| ������  |  | �������| ������  |\n"
	<< "|   ����   |  | ����  |  ����   |  |��������|�������� |  |��������|�������� |\n"
	<< "____________________________________________________________________________ \n"<< endl;
	Run_tab = TabSentStruct;
	for (int i = 0; i < TabSentStruct->Inf.Get_number_sent(); i++)
	{	Run_tab->Inf.print();
		Run_tab = Run_tab->Next;
	}*/
}

DynTab* AllTab::lexemfound(int number)
{
	DynTab	*Run;
	Run = LexTab;
	for (int i = 1; i < number_str_lex; i++)
	{
		if (Run->Inf.vernut_nomer() == number)
			break;
		Run = Run->Next;

	}
	return Run;
}
bool AllTab::IsID(char* str)
{
	DynTabIdentificator *RunID;
	RunID = this->TabIdentificator;
	do
	{
		if (RunID->Inf.name_sravnenie(str))
			return false;
		RunID = RunID->Next;
	} while (RunID != this->TabIdentificator);
	return true;
}

int AllTab::WeightLabel(int x)
{
	DynTab_sint *Run;
	Run = this->TabSentStruct;
	for (int i = 0; i < tab_sint::Get_number_sent(); i++)
	{
		if (Run->Inf.Get_number_lex_field_label() == x)
			return Run->Prev->Inf.GetWeight();
		Run = Run->Next;
	}
	return 0;
}
int degree(int x, int n, int result)
{
		if (n < 1)
			return result;
		return degree(x, --n, result*x);
}

double divdegree(int x, int n, double result)
{
	if (n > -1)
		return result;
	return divdegree(x, n++, result/x);
}