#include <iostream>
#include "main.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using std::cout;
using std::cin;
using std::ios;
using std::cerr;
using std::endl;
using std::ofstream;
using std::setw;

void writeListing1(AllTab *tab)
{
	DynTab_sint *RunSent;
	DynTab	*RunLex, *RunLex2;
	int j,i = 0;
	bool flagR = false;
	bool flagData = true;
	bool flagCodeStart = true;
	bool flagEQU = true;
	ofstream outClientFile("test.lst", ios::out);
	if (!outClientFile)
	{
		cerr << "Файл не мог быть открыт" << endl;
		exit(1);
	}
	time_t lt;
	RunSent = tab->TabSentStruct;
	RunLex = tab->LexTab;

	for (j = 1; j <= tab_sint::Get_number_sent(); j++)
	{
		if (j == tab_lex::GetSTART("data"))
		{
			int  n;
			if (RunSent->Inf.Get_number_lex_field_label() > -1)
				n = RunSent->Inf.Get_number_lex_field_label();
			else
				n = RunSent->Inf.Get_number_first_lex_field_mnemocode();

			outClientFile << "			0000" << "    ";
		
			outClientFile << tab->lexemfound(tab_lex::GetIDSTART("data") - 1)->Inf.vernut_lex() << "	"
				<< tab->lexemfound(tab_lex::GetIDSTART("data"))->Inf.vernut_lex() << endl;;
		}
		
		if (j == tab_lex::GetEND("data"))
		{
			outClientFile.unsetf(ios::dec);
			outClientFile.setf(ios::hex);
			outClientFile.setf(ios::uppercase);
			outClientFile << (RunSent->Prev->Inf.GetWeight() >= 16 ? "			00" : "			000") << RunSent->Prev->Inf.GetWeight() << "	";
			outClientFile.setf(ios::dec);
			outClientFile << tab->lexemfound(tab_lex::GetIDEND("data") - 1)->Inf.vernut_lex() << "	"
				<< tab->lexemfound(tab_lex::GetIDEND("data"))->Inf.vernut_lex() << '\n' << endl;;
			flagData = false;

		}
		if (j == tab_lex::GetSTART("code"))
		{
			outClientFile << "			0000" << "	";
			outClientFile << tab->lexemfound(tab_lex::GetIDSTART("code") - 1)->Inf.vernut_lex() << "	"
				<< tab->lexemfound(tab_lex::GetIDSTART("code"))->Inf.vernut_lex() << endl;
			flagCodeStart = false;
			outClientFile << "			0000" << "	";
		}
		else
		{
			outClientFile.unsetf(ios::dec);
			outClientFile.setf(ios::hex);
			outClientFile.setf(ios::uppercase);
			if (RunSent == tab->TabSentStruct)
				outClientFile << "			0000" << "	";
			else
				outClientFile << (RunSent->Prev->Inf.GetWeight() >= 16 ? "			00" : "			000") << RunSent->Prev->Inf.GetWeight() << "	";
			outClientFile.setf(ios::dec);
		}
		outClientFile.unsetf(ios::dec);
		outClientFile.setf(ios::hex);
		outClientFile.setf(ios::uppercase);
		bool f = false;
		if (tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("сегментного")
			|| tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand2())->Inf.proverka_podstr_in_str("сегментного"))
			f = true;
	
		for (int q = 0; q < RunSent->Inf.Get_nCode(); q++)
		{	

			if (f == true)
			{
				f = false;
				if (RunSent->Inf.GetCode(q) != -1)
					outClientFile << RunSent->Inf.GetCode(q) << ": ";
				
			}
			else
				if ((RunSent->Inf.GetCode(q) == 0))
				{
					if (flagData == true)
						outClientFile << "00";
					else
					{
						flagR = true;
						outClientFile << "00";
					}
				}
				else
					if (RunSent->Inf.GetCode(q) < 16)
						outClientFile << "0" << RunSent->Inf.GetCode(q) << " ";
					else
						outClientFile << RunSent->Inf.GetCode(q) << " ";
		}

		if (flagR == true)
		{
			outClientFile << "R" << "	";
			flagR = false;
		}

		outClientFile << (RunSent->Inf.Get_number_lex_field_label() != -1 ?
			tab->lexemfound(RunSent->Inf.Get_number_lex_field_label())->Inf.vernut_lex() : "") << "	";

		outClientFile << (RunSent->Inf.Get_number_first_lex_field_mnemocode() != -1 ?
			tab->lexemfound(RunSent->Inf.Get_number_first_lex_field_mnemocode())->Inf.vernut_lex() : "") << "	";
		if (RunSent->Inf.Get_amount_lex_field_mnemocode() > 1)
		{
			for (i = 1; i < RunSent->Inf.Get_amount_lex_field_mnemocode(); i++)
			{
				outClientFile << tab->lexemfound(RunSent->Inf.Get_number_first_lex_field_mnemocode() + i)->Inf.vernut_lex() << ' ';
			}
		}

		outClientFile << (RunSent->Inf.Get_number_first_lex_operand1() != -1 ?
			tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1())->Inf.vernut_lex() : "");
		if (RunSent->Inf.Get_amount_lex_operand1() > 1)
		{
			for (i = 1; i < RunSent->Inf.Get_amount_lex_operand1(); i++)
			{
				if (i < RunSent->Inf.Get_amount_lex_operand1() - 1 &&
					(tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1() + i)->Inf.ravna_li_str_lex("PTR")))
					outClientFile << ' ';
				outClientFile << tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1() + i)->Inf.vernut_lex();

			}
		}

		if (RunSent->Inf.Get_number_first_lex_operand2() != -1)
		{
			outClientFile << ',';
			outClientFile << tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand2())->Inf.vernut_lex();
		}
		if (RunSent->Inf.Get_amount_lex_operand2() > 1)
		{
			for (i = 1; i < RunSent->Inf.Get_amount_lex_operand2(); i++)
			{
				if (i < RunSent->Inf.Get_amount_lex_operand2() - 1 &&
					(tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand2() + i)->Inf.ravna_li_str_lex("PTR")))
					outClientFile << ' ';
				outClientFile << tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand2() + i)->Inf.vernut_lex();

			}
		}
		
		outClientFile << endl;
		RunSent = RunSent->Next;
		
	}

		outClientFile.unsetf(ios::dec);
		outClientFile.setf(ios::hex);
		outClientFile.setf(ios::uppercase);
		outClientFile << (RunSent->Prev->Inf.GetWeight() >= 16 ? "			00" : "			000") << RunSent->Prev->Inf.GetWeight() << "	";
		outClientFile.setf(ios::dec);
		outClientFile << tab->lexemfound(tab_lex::GetIDEND("code") - 1)->Inf.vernut_lex() << "	"
			<< tab->lexemfound(tab_lex::GetIDEND("code"))->Inf.vernut_lex()
			<< '\n' << "			end" << endl;
		

		outClientFile << "\n" << endl;

		outClientFile << "			Identificators : \n" << endl;

		DynTabIdentificator *RunID;
		RunID = tab->TabIdentificator;
		for (i = 0; i < TabIdentificator::get_1(); i++)
		{   
			outClientFile << "			" << RunID->Inf.name_get() << "	";
		//	<< "............................................	";
			outClientFile.unsetf(ios::dec);
			outClientFile.setf(ios::hex);
			outClientFile.setf(ios::uppercase);
			outClientFile << (RunID->Inf.valuee_get() >= 16 ? "00" : "000") << RunID->Inf.valuee_get() << "	";
			outClientFile.setf(ios::dec);
			outClientFile << RunID->Inf.namemetkaget() << endl;
			RunID = RunID->Next;
			}
		}
	
void writeSegments(AllTab *tab)
{
	dyn_tab_segment *RunSeg, *RunSeg2;
	ofstream outClientFile("testing.lst", ios::out);
	if (!outClientFile)
	{
		cerr << "Файл не мог быть открыт" << endl;
		exit(1);
	}
	RunSeg = tab->SegmentTab;
	do
	{
		outClientFile << RunSeg->Inf.GetName() << "........................";
		outClientFile.unsetf(ios::dec);
		outClientFile.setf(ios::hex);
		outClientFile.setf(ios::uppercase);
		outClientFile << (RunSeg->Inf.GetLength() >= 16 ? "00" : "000") << RunSeg->Inf.GetLength() << "	" << endl;
		outClientFile.setf(ios::dec);
		RunSeg = RunSeg->Next;
	} while (RunSeg != tab->SegmentTab);
}
