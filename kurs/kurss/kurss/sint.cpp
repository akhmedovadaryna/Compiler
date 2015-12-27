#include "main.h"
#include "sintax.h"

int sint_analizing(AllTab *tab);

int sint_analizing(AllTab *tab)
{	int i, n, *numb, number_str=0;
	int numbEnter = 0;
	DynTab_sint	*Run_tab, *Run2_tab;
	FILE *file;
	char *fname = "TEST.asm";
	char str[80];
	int IFflag = -1;
	numb= new int;
	*numb=0;
	tab->TabSentStruct = NULL;
	fopen_s(&file,fname, "r");
	if (file == 0)
	{
		printf("Файл  '%s' не существует", fname);
		return 0;
	}

	while (!feof(file))
	{
		fgets(str, sizeof(str), file);

		if (strstr(str, "Segment") != 0 || strstr(str, "segment") != 0 || strstr(str, "SEGMENT") != 0)
		{


			if (tab_lex::GetSTART("data") == 0)
				if (number_str == 0)
					tab_lex::SetSTART("data", 1);
				else
					tab_lex::SetSTART("data", number_str);
			else
				tab_lex::SetSTART("code", number_str - numbEnter);

			
			fgets(str, sizeof(str), file);
			number_str++;
			(*numb) += 2;
		}
		while (strcmp(str,"\n") == 0 || strstr(str,"ends") !=0 || strstr(str,"ENDS") !=0 )
		{
			if (strstr(str, "ends") != 0 || strstr(str, "ENDS") != 0)
			{
				if (tab_lex::GetEND("data") == 0)
					tab_lex::SetEND("data", number_str);
				else
					tab_lex::SetEND("code", number_str - numbEnter-1);
			}
			
				numbEnter++;
			fgets(str, sizeof(str), file);

			number_str++;
			(*numb)++;
		}	
		while (strcmp(str,"\n") == 0 || strstr(str,"Segment") !=0 || strstr(str,"segment") !=0 || strstr(str,"SEGMENT") !=0 )
		{
			if (strstr(str, "Segment") != 0 || strstr(str, "segment") != 0 || strstr(str, "SEGMENT") != 0)
			if (tab_lex::GetSTART("data") == 0)
				tab_lex::SetSTART("data", number_str);
			else
				tab_lex::SetSTART("code", number_str - numbEnter);
			fgets(str, sizeof(str), file);
			numbEnter++;
			number_str++;
			(*numb)++;
		}

		if (strcmp(str,"end") == 0)
			break;
		n = strlen(str);
			Run_tab = new DynTab_sint;
			if (tab->TabSentStruct == NULL)
				tab->TabSentStruct = Run_tab;
			else
			{
				Run2_tab->Next = Run_tab;
				Run_tab->Prev = Run2_tab;
			}
			cuter_sint(str, tab->LexTab, &(Run_tab->Inf), numb, number_str);
			tab_sint::INC_number_sent();
			Run2_tab = Run_tab;
			number_str++;
			if (Run_tab->Inf.Get_amount_lex_field_mnemocode() == -1)
			if (tab->lexemfound(Run_tab->Inf.Get_number_lex_field_label())->Next->Inf.ravna_li_str_lex(":") == false)
			{
				printf("Ошибка в строке(%d) : неправильная команда\n", number_str);
				system("pause");
				exit(0);
			}
			if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_field_mnemocode())->Inf.ravna_li_str_lex("FCOS"))
			{
				if (Run_tab->Inf.Get_amount_lex_operand2() != -1)
				{
					printf("Ошибка в строке(%d) : лишние операнды\n", number_str);
					system("pause");
					exit(0);
				}
				if (Run_tab->Inf.Get_amount_lex_operand1() > 1)
				{
					printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
					system("pause");
					exit(0);
				}
			}
			if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_field_mnemocode())->Inf.ravna_li_str_lex("FCOMP"))
			{
				if (Run_tab->Inf.Get_amount_lex_operand2() != -1)
				{
					printf("Ошибка в строке(%d) : лишние операнды\n", number_str);
					system("pause");
					exit(0);
				}
				if (Run_tab->Inf.Get_amount_lex_operand1() > 1)
				{
					printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
					system("pause");
					exit(0);
				}
				if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("співпроцесор") == false)
				{
					printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
					system("pause");
					exit(0);
				}
			}
			if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_field_mnemocode())->Inf.ravna_li_str_lex("FADD"))
			{
				if (Run_tab->Inf.Get_amount_lex_operand2() != -1)
				{
					if (Run_tab->Inf.Get_amount_lex_operand2() == 1)
					{
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("співпроцесор") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand2())->Inf.proverka_podstr_in_str("співпроцесор") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}

					}
				}
				else
				{
					if (Run_tab->Inf.Get_amount_lex_operand1() == 5)
					{

						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("розміру") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 1)->Inf.ravna_li_str_lex("PTR") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.ravna_li_str_lex("[") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.proverka_podstr_in_str("розрядного регістра") == true)
						{
							if (!(strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.vernut_lex(), "EAX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.vernut_lex(), "ECX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.vernut_lex(), "EDX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.vernut_lex(), "EBX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.vernut_lex(), "ESI")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.vernut_lex(), "EDI")))
							{
								printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
								system("pause");
								exit(0);
							}
						}
						else
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.ravna_li_str_lex("]") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
					}
					else if (Run_tab->Inf.Get_amount_lex_operand1() == 7)
					{
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("сегментного") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 1)->Inf.ravna_li_str_lex(":") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.proverka_podstr_in_str("розміру") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.ravna_li_str_lex("PTR") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.ravna_li_str_lex("[") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.proverka_podstr_in_str("розрядного регістра") == true)
						{
							if (!(strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.vernut_lex(), "EAX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.vernut_lex(), "ECX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.vernut_lex(), "EDX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.vernut_lex(), "EBX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.vernut_lex(), "ESI")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.vernut_lex(), "EDI")))
							{
								printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
								system("pause");
								exit(0);
							}
						}
						else
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 6)->Inf.ravna_li_str_lex("]") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}

					}
					else if (Run_tab->Inf.Get_amount_lex_operand1() == 6)
					{
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("сегментного") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 1)->Inf.ravna_li_str_lex(":") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.proverka_podstr_in_str("не визначений") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.ravna_li_str_lex("[") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.proverka_podstr_in_str("розрядного регістра") == true)
						{
							if (!(strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.vernut_lex(), "EAX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.vernut_lex(), "ECX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.vernut_lex(), "EDX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.vernut_lex(), "EBX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.vernut_lex(), "ESI")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 4)->Inf.vernut_lex(), "EDI")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "EBP")))
							{
								printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
								system("pause");
								exit(0);
							}
						}
						else
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 5)->Inf.ravna_li_str_lex("]") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
					}
					else if (Run_tab->Inf.Get_amount_lex_operand1() == 4)
					{
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1())->Inf.proverka_podstr_in_str("не визначений") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 1)->Inf.ravna_li_str_lex("[") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.proverka_podstr_in_str("розрядного регістра") == true)
						{
							if (!(strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "EAX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "ECX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "EDX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "EBX")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "ESI")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "EDI")
								|| strcmp(tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 2)->Inf.vernut_lex(), "EBP")))
							{
								printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
								system("pause");
								exit(0);
							}
						}
						else
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
						if (tab->lexemfound(Run_tab->Inf.Get_number_first_lex_operand1() + 3)->Inf.ravna_li_str_lex("]") == false)
						{
							printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
							system("pause");
							exit(0);
						}
					}
					else
					{
						printf("Ошибка в строке(%d) : ожидалось другое\n", number_str);
						system("pause");
						exit(0);
					}
				}
			}
		}
	Run_tab->Next = tab->TabSentStruct;
	tab->TabSentStruct->Prev = Run_tab;
}




