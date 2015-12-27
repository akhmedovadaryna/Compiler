#include "sintax.h"
	using std::cout;
	using std::endl;
	int tab_sint::number_sent = 0;
tab_sint::tab_sint()
{
	 number_lex_field_label=-1;
	 number_first_lex_field_mnemocode=-1;
	 amount_lex_field_mnemocode=-1;
	 number_first_lex_operand1=-1;
	 amount_lex_operand1=-1;
	 number_first_lex_operand2=-1;
	 amount_lex_operand2=-1;
	 Code = NULL;
	 nCode = 0;
	 weight = 0x0000;
}

void tab_sint::CreateCode(int x)
{
	Code = new int[x];
	for (int i = 0; i < x; i++)
		Code[i] = 0;
}

int tab_sint::Get_nCode()
{
	return nCode;
}

void tab_sint::SetCode(int x, int n)
{
	Code[n] = x;
	nCode++;
}

void tab_sint::SetCodeData(int x)
{
	Code[0] = x;
	nCode = 1;
}

void tab_sint::SetCodeFract(int x, int n)
{
	Code[n] = x;
	nCode++;
}

int tab_sint::GetCode(int i)
{
	return Code[i];
}

void tab_sint::AddWeight(int x)
{
	weight += x;
}

int tab_sint::GetWeight()
{
	return weight;
}

tab_sint::~tab_sint()
{}

void tab_sint::Set_number_first_lex_field_mnemocode(int a)
{
	number_first_lex_field_mnemocode = a;
}

void tab_sint::Set_number_lex_field_label(int a)
{
	number_lex_field_label = a;
}

void tab_sint::Set_amount_lex_field_mnemocode(int a)
{
	amount_lex_field_mnemocode = a;
}

void tab_sint::Set_number_first_lex_operand1(int a)
{
	number_first_lex_operand1 = a;
}

void tab_sint::Set_amount_lex_operand1(int a)
{
	amount_lex_operand1 = a;
}

void tab_sint::Set_number_first_lex_operand2(int a)
{
	number_first_lex_operand2 = a;
}

void tab_sint::Set_amount_lex_oprerand2(int a)
{
	amount_lex_operand2 = a;
}

int tab_sint::Get_number_sent()
{
	return number_sent;
}

int tab_sint::Get_number_lex_field_label()
{
	return number_lex_field_label;
}

int tab_sint::Get_number_first_lex_field_mnemocode()
{
	return number_first_lex_field_mnemocode;
}

int tab_sint::Get_amount_lex_field_mnemocode()
{
	return amount_lex_field_mnemocode;
}

int tab_sint::Get_number_first_lex_operand1()
{
	return number_first_lex_operand1;
}

int tab_sint::Get_amount_lex_operand1()
{
	return amount_lex_operand1;
}

int tab_sint::Get_number_first_lex_operand2()
{
	return number_first_lex_operand2;
}

int tab_sint::Get_amount_lex_operand2()
{
	return amount_lex_operand2;
}

void tab_sint::INC_number_sent()
{
	number_sent++;
}
void tab_sint::print()
{ 
	if (number_lex_field_label != -1)
		printf("%7d",number_lex_field_label);
	else
		printf("      -");
	if (number_first_lex_field_mnemocode != -1)
		printf("%12d",number_first_lex_field_mnemocode);
	else
		printf("           -");
	if (amount_lex_field_mnemocode != -1)
		printf("%9d",amount_lex_field_mnemocode);
	else
		printf("        -");
	if (number_first_lex_operand1 != -1)
		printf("%13d",number_first_lex_operand1);
	else
		printf("            -");
	if (amount_lex_operand1 != -1)
		printf("%10d",amount_lex_operand1);
	else
		printf("         -");
	if (number_first_lex_operand2 != -1)
		printf("%11d",number_first_lex_operand2);
	else
		printf("          -");
	if (amount_lex_operand2 != -1)
		printf("%10d",amount_lex_operand2);
	else
		printf("         -");
	cout << endl;
	/*
	cout <<  number_lex_field_label << "	"
	<< number_first_lex_field_mnemocode << "	"
	<< amount_lex_field_mnemocode << "	"
	<< number_first_lex_operand1 << "	"
	<< amount_lex_operand1 << "	"
	<< number_first_lex_operand2 << "	"
	<< amount_lex_operand2 <<endl;
	*/
}

DynTab_sint::DynTab_sint()
	:Inf()
{
	Next=NULL;
	Prev=NULL;
}

void tab_sint::check_lex(char *str, DynTab *lex_tab,int *kol, int number_str)
{
	DynTab *Run;
	int n = lex_tab->Prev->Inf.vernut_nomer();
	Run = lex_tab;
	for (int i = 0; i < *kol; i++)
		Run=Run->Next;

	if (Run->Inf.ravna_li_str_lex(str) == true)
		{
			if (flag == 0 && Run->Inf.proverka_podstr_in_str("Ідентифікатор") == false)
				{ cout << "SINTACSIC ERROR IN LINE(" << number_str << ")" << endl;
					system("pause");
					exit(1);
			}
			if (flag == 0 && Run->Inf.proverka_podstr_in_str("користувача") == true)
			{
				number_lex_field_label = Run->Inf.vernut_nomer();
			
				flag = 1;
				return;
			}
			if (flag == 0)
				flag = 1;
			
			if (Run->Inf.ravna_li_str_lex(":") && Run->Prev->Inf.proverka_podstr_in_str("користувача") == true)
				return;

			if (Run->Inf.proverka_podstr_in_str("мнемокод") == true || Run->Inf.proverka_podstr_in_str("директиви") == true)
			{
				number_first_lex_field_mnemocode = Run->Inf.vernut_nomer();
				amount_lex_field_mnemocode = 1;
				return;
			}
			
			if (Run->Inf.proverka_podstr_in_str("константа") == true || Run->Inf.proverka_podstr_in_str("розміру") == true || Run->Inf.proverka_podstr_in_str("регістр") == true
				|| Run->Inf.proverka_podstr_in_str("односимвольна") == true || Run->Inf.proverka_podstr_in_str("визначення типу") == true
				|| Run->Inf.proverka_podstr_in_str("користувача"))
			{
				if (Run->Inf.proverka_podstr_in_str("константа") == true)
				{
					if (Run->Prev->Inf.proverka_podstr_in_str("DQ"))
					if (atof(Run->Inf.vernut_lex()) > 4294967295)
					{
						printf("Ошибка в строке(%d) : слишком большая константа\n", number_str);
						system("pause");
						exit(0);
					}
					else
					{
						if (atof(Run->Inf.vernut_lex()) > 65535)
						{
							printf("Ошибка в строке(%d) : слишком большая константа\n", number_str);
							system("pause");
							exit(0);
						}
					}
				}
				if (str[0] == ',')
				{
					flag = 2;
					return;
				}
				if (flag == 1 && number_first_lex_operand1 == -1)
				{
					number_first_lex_operand1 = Run->Inf.vernut_nomer();
					amount_lex_operand1 = 1;
					return;
				}
				else
				{ 
					if (flag == 1 && number_first_lex_operand1 != -1)
					{
						amount_lex_operand1++;
						return;
					}
					
					if (flag == 2 && number_first_lex_operand2 == -1)
					{
						number_first_lex_operand2 = Run->Inf.vernut_nomer();
						amount_lex_operand2 = 1;
						return;
					}
					else
					{ 
						if (flag == 2 && number_first_lex_operand1 != -1)
						{
							amount_lex_operand2++;
							return;
						}
					}
				}
			}
	
	}
}


	int cuter_sint(char* str, DynTab *tab_lex, tab_sint	*tab, int *numb, int number_str)
{
	char substr[80];
	int k1,i=0, k2 = 0, j=0, n = strlen(str);
	tab->flag = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	k1=i;
	for ( i=i; i< n; i++)
	{		
		if (i == n-1 || str[i] == ' ' || str[i] == '\t' || str[i-1] == ':' || str[i-1] == ',' || str[i] == ','
			|| str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '[' || str[i-1] == ']' )
			{
				
				k2 = i;
				j = k2 - k1;
			
				if (str[i-1] == ':' || str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '[' || str[i-1] == ']')
				{ char c[2];
					c[0]=str[i-1];
						c[1] = '\0';
						if (str[i - 2] != ' ')
						{
							
					strncpy_s(substr, &str[k1], j-1);
					_strupr_s(substr, sizeof(substr));
					tab->check_lex(substr, tab_lex, numb, number_str);
					
							(*numb)++;
						}
					tab->check_lex(&c[0], tab_lex, numb, number_str);
					(*numb)++;
				}
				else
				{
				strncpy_s(substr, &str[k1], j);
				k1=k2+1;
				_strupr_s(substr, sizeof(substr));
				
				tab->check_lex(substr, tab_lex, numb, number_str);
			
				(*numb)++;
				}
				while (str[i] == ' ' || str[i] == '\t')
					i++;
				
				
				k1=i;
			}
	}
	return i;
}

void amountWord(char *str, int* numb)
{
		int k1=0,k2,i=0,j,n=strlen(str);
		char substr[30];

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	for (i = i; i < n; i++)
		{
			if (i == n-1 || str[i] == ' ' || str[i] == '\t' || str[i-1] == ':' || str[i-1] == ',' || str[i] == ','
			|| str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '[' || str[i-1] == ']' )
			{
				(*numb)++;
				if ( str[i-1] == ':' || str[i-1] == ',' || str[i-1] == ','
					|| str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '[' || str[i-1] == ']')
					(*numb)++;
				while (str[i] == ' ' || str[i] == '\t')
					i++;
				k1 = i;
			}
		}
	}