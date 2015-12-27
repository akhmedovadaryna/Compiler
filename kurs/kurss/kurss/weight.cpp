#include "main.h"

void weight(AllTab *tab)
{
	DynTab_sint *RunSent;
	DynTab	*RunLex, *RunLex2;
	bool flagEnd = true;
	RunSent = tab->TabSentStruct;
	for (int i = 1; i <= tab_sint::Get_number_sent(); i++)
	{
		if (flagEnd == true && i == tab_lex::GetEND("data"))
		{
			flagEnd = false;
		}
		else
			if (i != 0)
				RunSent->Inf.AddWeight(RunSent->Prev->Inf.GetWeight());

			RunLex = tab->lexemfound(RunSent->Inf.Get_number_first_lex_field_mnemocode());
		if (RunLex->Inf.proverka_podstr_in_str("директиви даних"))
		{
			switch (RunLex->Inf.vernut_lexsem_type()[strlen(RunLex->Inf.vernut_lexsem_type()) - 1])
			{
				
			case '4':{
				int k = 4;
				int x = 1;
				RunLex = tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1());
				RunSent->Inf.AddWeight(k * x);
				break;
			}
			case '8':{
				int k = 8;
				int x = 1;
				RunLex = tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1());
				
				RunSent->Inf.AddWeight(k * x);
				break;
			}
		}
	}

		if (RunLex->Inf.proverka_podstr_in_str("мнемокод"))
		{
			if (RunLex->Inf.ravna_li_str_lex("FCOMP") || RunLex->Inf.ravna_li_str_lex("FCOS"))
				RunSent->Inf.AddWeight(2);
			if (RunLex->Inf.ravna_li_str_lex("FADD"))
			{
				if (RunSent->Inf.Get_number_first_lex_operand2() == -1)
				if (tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("користувача"))
						RunSent->Inf.AddWeight(6);
					else
					if (tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("сегментного") &&
						!tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1())->Inf.ravna_li_str_lex("DS"))
								RunSent->Inf.AddWeight(3);
						else
								RunSent->Inf.AddWeight(2);
				else
				{
					RunSent->Inf.AddWeight(2);
				}
			}
		}
	
		RunSent = RunSent->Next;
	}
}
