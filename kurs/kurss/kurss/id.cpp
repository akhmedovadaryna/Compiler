#include "id.h"

int TabIdentificator::amount = 0;

TabIdentificator::TabIdentificator()
{
	Name = 0;
	Type = 0;
	Attr = 0;
}

void TabIdentificator::name_set(char* str)
{
	Name = new char[strlen(str)];
	strcpy(Name, str);
}

void TabIdentificator::inc_1()
{
	amount++;
}

int TabIdentificator::get_1()
{
	return amount;
}

char* TabIdentificator::name_get()
{
	return Name;
}

bool TabIdentificator::name_sravnenie(char* str)
{
	if (strcmp(Name, str) == 0)
		return true;
	return false;
}

void TabIdentificator::namemetkaset(char* str)
{
	Attr = new char[strlen(str)];
	strcpy(Attr, str);
}

char* TabIdentificator::namemetkaget()
{
	return Attr;
}

void TabIdentificator::type_set(char* str)
{
	Type = new char[strlen(str)];
	strcpy(Type, str);
}

char* TabIdentificator::type_get()
{
	return Type;
}

void TabIdentificator::valuee_set(int x)
{
	Value = x;
}

int TabIdentificator::valuee_get()
{
	return Value;
}

DynTabIdentificator::DynTabIdentificator()
{
	Next = 0;
	Prev = 0;
}

void MakeTabIdent(AllTab *tab)
{
	DynTab *Run;
	DynTab_sint *RunSent;
	DynTabIdentificator *RunID, *RunID2;
	bool flagID = false;
	//Run = tab->LexTab;
	RunSent = tab->TabSentStruct;
	for (int i = 1; i <= tab_sint::Get_number_sent(); i++)
	{
		
		Run = tab->lexemfound(RunSent->Inf.Get_number_lex_field_label());
		if (Run->Inf.proverka_podstr_in_str("користувача"))
		{
			
			if (flagID == true && !tab->IsID(Run->Inf.vernut_lex()))
			{
				Run = Run->Next;
				continue;
			}
			RunID = new DynTabIdentificator;
			if (tab->TabIdentificator == 0)
			{
				tab->TabIdentificator = RunID;
				RunID->Next = RunID;
				RunID->Prev = RunID;
				flagID = true;
			}
			else
			{
				RunID->Prev = RunID2;
				RunID2->Next = RunID;
				RunID->Next = tab->TabIdentificator;
				tab->TabIdentificator->Prev = RunID;
			}

			RunID->Inf.name_set(Run->Inf.vernut_lex());
			if (Run->Inf.vernut_nomer() < tab_lex::GetIDEND("data"))
			{
				RunID->Inf.namemetkaset(tab->lexemfound(tab_lex::GetIDEND("data") - 1)->Inf.vernut_lex());
				if (Run->Inf.vernut_nomer() - 1 == tab_lex::GetIDSTART("data"))
					RunID->Inf.valuee_set(0);
				else
					RunID->Inf.valuee_set(RunSent->Prev->Inf.GetWeight());
			}
			else
			if (Run->Inf.vernut_nomer() > tab_lex::GetIDSTART("code"))
				{
				RunID->Inf.namemetkaset(tab->lexemfound(tab_lex::GetIDEND("code") - 1)->Inf.vernut_lex());
					if (Run->Inf.vernut_nomer() - 1 == tab_lex::GetIDSTART("code"))
						RunID->Inf.valuee_set(0);
					else
						RunID->Inf.valuee_set(RunSent->Prev->Inf.GetWeight());
				}
				
			RunID2 = RunID;
			TabIdentificator::inc_1();
		}
		RunSent = RunSent->Next;

	}

}