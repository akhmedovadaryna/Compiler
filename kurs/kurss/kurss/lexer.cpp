#include "lexer.h"

using std::cout;
using std::endl;
// объявление статических переменных
int tab_lex::datasegmentend = 0;
int tab_lex::start_ds = 0;
int tab_lex::endsegmentcode = 0;
int tab_lex::str_sc = 0;
int tab_lex::numb_lex_st_sc = 0;
 int tab_lex::numb_lex_end = 0;
 int tab_lex::numb_lex_ds = 0;
 int tab_lex::numb_lex_sc = 0;

tab_lex::tab_lex()
{
	number = 0;
	lex = new char[1];
	lex[0] = '\0';
	len_lex = 0;
	type_lex = new char[1];
	type_lex[0] = '\0';

	
}

 void tab_lex::SetEND(char* seg, int x)
{
	if (!strcmp(seg, "data"))
		datasegmentend = x;
	else
		endsegmentcode = x;
}

 void tab_lex::SetIDEND(char* seg, int x)
 {
	 if (!strcmp(seg, "data"))
		 numb_lex_end = x;
	 else
		 numb_lex_sc = x;
	
		
 }

void tab_lex::SetSTART(char* seg, int x)
{
	if (!strcmp(seg, "data"))
		start_ds = x;
	else
		str_sc = x;
}

void tab_lex::SetIDSTART(char* seg, int x)
{
	if (!strcmp(seg, "data"))
		numb_lex_ds = x;
	else
		numb_lex_st_sc = x;
}

int tab_lex::GetIDSTART(char* seg)
{
	if (!strcmp(seg, "data"))
		return numb_lex_ds;
	else
		return numb_lex_st_sc;
}

int tab_lex::GetIDEND(char* seg)
{
	if (!strcmp(seg, "data"))
		return numb_lex_end;
	else
		return numb_lex_sc;
}

int tab_lex::GetEND(char* seg)
{
	if (!strcmp(seg, "data"))
		return datasegmentend;
	else
		return endsegmentcode;
}

int tab_lex::GetSTART(char* seg)
{
	if (!strcmp(seg, "data"))
		return start_ds;
	else
		return str_sc;
}

tab_lex::~tab_lex()
{
	
	delete[] lex;
	delete[] type_lex;
}

void tab_lex::lexem_name(char* string, int n)//передаем размер n
{
	
	lex = new char[n+1];
	strncpy(lex, string, n);
	lex[n]='\0';
	len_lex = n;
}

char* tab_lex::vernut_lex()
{
	return lex;
}

void tab_lex::lexem_type(char* string)
{
	/*если тип ексемы пустой, то записываем заново. если что-то есть, то запоминаем все 
	в буферную строку, удаляем и создаем с новым размером и переписываем то, что было раньше
	из буферной строки с дописыванием в конец того, что добавляется*/
	
	char *bufStr;
	int size_type_lex = strlen(type_lex);
	if (size_type_lex != 0)
	{
		bufStr = new char[size_type_lex+1];
		strcpy(bufStr,type_lex);
		delete[] type_lex;
		type_lex = new char[size_type_lex + strlen(string) +1];
		strcpy(type_lex,bufStr);
		strcat(type_lex,string);
		delete[] bufStr;
	}
	else
	{
		delete[] type_lex;
		type_lex = new char[strlen(string) +1];
		strcpy(type_lex,string);
		
	}
}



void tab_lex::proverka_lexem_type(char *str)
{
	if ((str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_' || str[0] == '@' || str[0] == '?' || str[0] == '$')
	{
		

		if (!strcmp(str, "EAX") || !strcmp(str, "EBX") || !strcmp(str, "ECX") || !strcmp(str, "ESP")
			|| !strcmp(str, "EDX") || !strcmp(str, "ESI") || !strcmp(str, "EDI") || !strcmp(str, "EBP"))
		{
			lexem_type("Ідентифікатор 32- розрядного регістра");
			return;
		}
		if (!strcmp(str, "ES") || !strcmp(str, "CS") || !strcmp(str, "SS") || !strcmp(str, "DS")
			|| !strcmp(str, "FS") || !strcmp(str, "GS"))
		{
			lexem_type("Ідентифікатор сегментного регістра ");
			return;
		}
		if (!strcmp(str, "ST(0)") || !strcmp(str, "ST(1)") || !strcmp(str, "ST(2)") || !strcmp(str, "ST(3)") 
			|| !strcmp(str, "ST(4)")|| !strcmp(str, "ST(5)") || !strcmp(str, "ST(6)") || !strcmp(str, "ST(7)"))
		{
			lexem_type("Ідентифікатор регістру співпроцесора ");
			return;
		}
		if (!strcmp(str, "FCOS") || !strcmp(str, "FADD") || !strcmp(str, "FCOMP"))
		{
			lexem_type("Ідентифікатор мнемокоду машинної інструкції ");
			return;
		}
		if (!strcmp(str, "SEGMENT") || !strcmp(str, "ENDS") || !strcmp(str, "END"))
		{
			lexem_type(" Ідентифікатор директиви ");
				if (!strcmp(str, "ENDS"))
				if (GetIDEND("data") == 0)
					SetIDEND("data", this->number);
				else
					if (GetIDEND("code") == 0)
						SetIDEND("code", this->number);
			
			if (!strcmp(str, "SEGMENT") )
				if (GetIDSTART("data") == 0)
					SetIDSTART("data", this->number);
				else
					if ( GetIDSTART("code") == 0)
						SetIDSTART("code", this->number);
						
			return;
		}
		if (!strcmp(str, "PTR"))
		{
			lexem_type(" Ідентифікатор оператора визначення типу ");
			return;
		}
		if (!strcmp(str, "DQ") || !strcmp(str, "DD"))
		{
			switch (str[1])
			{
			case 'Q':{lexem_type(" Ідентифікатор директиви даних тип 8"); break; }
			case 'D':{lexem_type(" Ідентифікатор директиви даних тип 4"); break; }
			}
			return;
		}
		if (!strcmp(str, "BYTE") || !strcmp(str, "WORD") || !strcmp(str, "DWORD"))
		{
			switch (str[0])
			{
			case 'B':{lexem_type(" Ідентифікатор розміру 1"); break; }
			case 'W':{lexem_type(" Ідентифікатор розміру 2"); break; }
			case 'D':{lexem_type(" Ідентифікатор розміру 4"); break; }
			}
			return;
		}
		lexem_type("Ідентифікатор користувача або не визначений ");
	}

	if ((str[0] >= '0' && str[0] <= '9') || str[0] == '\'' || str[0] == '\"')
	{
		if (str[0] == '\'' || str[0] == '\"')
		{
			lexem_type("text константа"); return;
		}
		for (int j = 0; j < strlen(str); j++)
		if (str[j] == '.')
		{
			lexem_type(" Дробна десяткова константа");
			return;
		}
		if (str[strlen(str) - 1] >= '0' && str[strlen(str) - 1] <= '9')
			lexem_type(" Десяткова константа");


	}
		if (str[0] == ':' || str[0] == ',' || str[0] == '+' || str[0] == '-' || str[0] == '[' || str[0] == ']')
		{
			lexem_type("односимвольна");
		}
	
}

void tab_lex::nomer(int numb)
{
	number=numb;
}

int tab_lex::vernut_nomer()
{
	return number;
}

int tab_lex::vernu_dlinu_lex()
{
	return len_lex;
}

char* tab_lex::vernut_lexsem_type()
{
	return type_lex;
}

bool tab_lex::ravna_li_str_lex(char *str)
{ 
	if (strcmp(str,lex) == 0)
		return true;
	return false;

}

bool tab_lex::proverka_podstr_in_str(char *str)
{ char *s;
s=strstr(type_lex, str);
	if ( s == 0)
		return false;
	return true;
}


void tab_lex::print()
{
	

	cout <<  number << "	";
	cout << "	" << lex;
	cout << "		" << len_lex;
	cout << "	" << type_lex << endl;
}

DynTab::DynTab()
	:Inf()
{
	Next=NULL;
	Prev=NULL;
}

int cuter(char* str, tab_lex	*tab, int i, int *numb)
{
	char substr[80];
	int k1=i, k2 = 0, j, n = strlen(str), flag = 0;
	tab->number = *numb;

	if (str[i] == '\'' || str[i] == '"')
	{
		i++;
		while (i<n && (str[i] != '\'' && str[i] != '"'))
		{
			i++;
		}
		if (i == n)
			i--;
		k2 = i;
		(*numb)++;
		j = k2 - k1;
		strncpy_s(substr, &str[k1], j);
		tab->proverka_lexem_type(substr);
		j--;
		strncpy_s(substr, &str[k1+1], j);
		i++;
	}
	else
	{
		for (i = i; i < n; i++)
		if (str[i] == ' ' || str[i] == '\t' || str[i] == ':' || str[i] == ','
			|| str[i] == '+' || str[i] == '-' || str[i] == '[' || str[i] == ']')
			{
				break;
			}
		if (i == n && str[i - 1] == '\n')
			i--;
		k2 = i;
		(*numb)++;
		j = k2 - k1;
		strncpy_s(substr, &str[k1], j);
		_strupr_s(substr, sizeof(substr));
		tab->proverka_lexem_type(substr);
	}
	
	tab->lexem_name(substr, j);
	tab->len_lex = j;

	return i;
}