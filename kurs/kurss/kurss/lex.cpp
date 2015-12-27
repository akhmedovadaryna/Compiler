#include "main.h"
 int lex_analizing(AllTab *tab);
int lex_analizing(AllTab *tab)
{
	int i, n,nn=0, *numb;
	
	 DynTab	*Run_tab, *Run2_tab;
	FILE *file;
	char *fname = "TEST.asm";
	char str[80];
	
	numb = (int *)malloc(sizeof(int));
	*numb = 0;
	tab->number_str_lex=0;
	tab->LexTab = NULL;
	fopen_s(&file,fname, "r");
	if (file == 0)
	{
		printf("Файл  '%s' не существует", fname);
		return 0;
	}

	while (!feof(file))
	{
		fgets(str, sizeof(str), file);
		n = strlen(str);
		nn = nn + 1;
		if (strlen(str) > 120)
		{
			printf("Ошибка в стоке(%d) : Больше 120 символов\n", nn);
			system("pause");
			exit(0);

		}

		for (i = 0; i < strlen(str); i++)
		{

			if (isalpha(str[i]) == 0 && isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '$'
				&& str[i] != '@' && str[i] != '?' && str[i] != ':' && str[i] != '+' && str[i] != '-' && str[i] != '*'
				&& str[i] != '[' && str[i] != ']' && str[i] != ',' && str[i] != '(' && str[i] != ')' && str[i] != '.')
			{
				printf("Ошибка в строке(%d) : больше 120 символов\n", nn);
				system("pause");
				exit(0);
			}
		}
		i = 0;
		while (i < n-1)
		{
			Run_tab = new DynTab;
		

			if (tab->LexTab == NULL)
				tab->LexTab = Run_tab;
			else
			{
				Run2_tab->Next = Run_tab;
				Run_tab->Prev = Run2_tab;
			}
			while (str[i] == ' ' || str[i]=='\t')
				i++;
			if (str[i] == '\n' || str[i] == ';')
			{
				delete Run_tab;
				break;
			}
			if (str[i] == ':' || str[i] == ',' || str[i]=='+' || str[i]=='-' || str[i]=='[' || str[i]==']')
			{
				Run_tab->Inf.nomer(*numb);
				Run_tab->Inf.lexem_name(&str[i], 1);
				
				Run_tab->Inf.proverka_lexem_type(&str[i]);
				i++;
				
				Run_tab->Inf.nomer(*numb);
				(*numb)++;
			}
			else
				i = cuter(str, &(Run_tab->Inf), i, numb);

			Run2_tab = Run_tab;
			tab->number_str_lex++;
		}

	}
	Run_tab->Next = tab->LexTab;
	tab->LexTab->Prev = Run_tab;
	fclose(file);
	return 0;
}



