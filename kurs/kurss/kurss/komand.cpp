#include "komand.h"
using namespace std;
int BINtoDEC(char* str);
int HEXtoDEC(char*str);
extern int degree(int x, int n, int result);
void code(AllTab* tab)
{
	DynTab_sint *RunSent;
	DynTab	*RunLex, *RunLex2;
	bool flagEnd = true;
	RunSent = tab->TabSentStruct;
	for (int i = 1; i <= tab_sint::Get_number_sent(); i++)
	{	if (flagEnd == true && i  == tab_lex::GetEND("data"))
		{			
			flagEnd = false;
		}
		
		if (flagEnd == true)
		{
			RunLex = tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1());

			if (RunLex->Inf.proverka_podstr_in_str("Дробна") == true)
			{
				if (RunLex->Prev->Inf.ravna_li_str_lex("DQ"))
				{
					int *Arr = new int[32];
					int x = 0;
					Arr = fractional(RunLex->Inf.vernut_lex(), Arr);
					RunSent->Inf.CreateCode((RunSent->Inf.GetWeight() - RunSent->Prev->Inf.GetWeight()) / 2);
					for (int i = 0; i < 16; i += 2)
						RunSent->Inf.SetCodeFract(Arr[i] * 0x10 + Arr[i + 1], i / 2);
				}
				else if (RunLex->Prev->Inf.ravna_li_str_lex("DD"))
				{
					int *Arr = new int[16];
					int x = 0;
					Arr = fractional(RunLex->Inf.vernut_lex(), Arr, 0);
					RunSent->Inf.CreateCode((RunSent->Inf.GetWeight() - RunSent->Prev->Inf.GetWeight()) / 2);
					for (int i = 0; i < 8; i += 2)
						RunSent->Inf.SetCodeFract(Arr[i] * 0x10 + Arr[i + 1], i / 2);
				}
			}
			else
			{
					RunSent->Inf.CreateCode(RunSent->Inf.GetWeight());
					RunSent->Inf.SetCodeData(atoi(RunLex->Inf.vernut_lex()));
			}
		}
		else
		{
			if (RunSent->Inf.Get_number_first_lex_field_mnemocode() != -1)
			{
				RunLex = tab->lexemfound(RunSent->Inf.Get_number_first_lex_field_mnemocode());
				if (RunLex->Inf.ravna_li_str_lex("FCOS"))
				{
					instruction::SetFCOS(RunSent);
				}
		
				if (RunLex->Inf.ravna_li_str_lex("FADD"))
				{
					if (RunSent->Inf.Get_amount_lex_operand2() == -1)
						instruction::SetFADD(RunSent, tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1()), tab);
					else
						instruction::SetFADD(RunSent, tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand2()), tab);

				}
				if (RunLex->Inf.ravna_li_str_lex("FCOMP"))
				{
						instruction::SetFCOMP(RunSent, tab->lexemfound(RunSent->Inf.Get_number_first_lex_operand1()));
				}
				
			}
		}
		RunSent = RunSent->Next;
	}
}

int BINtoDEC(char* str)
{
	char *bin;
	int  dec = 0, x, n = strlen(str);
	bin = new char[n + 1];
	strcpy(bin, str);
	for (int i = n - 2; i >= 0; i--)
	{
		dec += atoi(&bin[i]) * degree(2, n - i - 2, 1);
		bin[i] = '\0';
	}
	return dec;
}

int HEXtoDEC(char*str)
{
	char *hex;
	int  dec = 0, x, n = strlen(str);
	hex = new char[n + 1];
	strcpy(hex, str);
	hex[n - 1] = '\0';
	n--;
	for (int i = 0; i < n; i++)
		switch (str[i])
	{
		case '0':{	dec += 0;	                        	break;}
		case '1': {	dec += 1 * degree(16, n - i - 1, 1);	break;}
		case '2':{	dec += 2 * degree(16, n - i - 1, 1);	break;}
		case '3':{	dec += 3 * degree(16, n - i - 1, 1);	break;}
		case '4':{	dec += 4 * degree(16, n - i - 1, 1);	break;}
		case '5':{	dec += 5 * degree(16, n - i - 1, 1);	break;}
		case '6':{	dec += 6 * degree(16, n - i - 1, 1);	break;}
		case '7':{	dec += 7 * degree(16, n - i - 1, 1);	break;}
		case '8':{	dec += 8 * degree(16, n - i - 1, 1);	break;}
		case '9':{	dec += 9 * degree(16, n - i - 1, 1);	break;}
		case 'A':{	dec += 10 * degree(16, n - i - 1, 1);	break;}
		case 'B':{	dec += 11 * degree(16, n - i - 1, 1);	break;}
		case 'C':{	dec += 12 * degree(16, n - i - 1, 1);	break;}
		case 'D':{	dec += 13 * degree(16, n - i - 1, 1);	break;}
		case 'E':{	dec += 14 * degree(16, n - i - 1, 1);	break;}
		case 'F':{	dec += 15 * degree(16, n - i - 1, 1);	break;}
	}

	return dec;
}

int DECtoBIN(int whole, int* Arr)
{
	int bufArr[100];
	int mod = 0, div = 0, nArr = 0;
	int i = 0;
	while (whole >= 2)
	{
		mod = whole % 2;
		div = whole / 2;
		bufArr[i] = mod;
		nArr++;
		i++;
		whole = div;
	}
	if (div != 0)
	{
		bufArr[i] = div;
		nArr++;
	}
	for (i = 0; i < nArr; i++)
		Arr[i] = bufArr[nArr - i - 1];
	return nArr;
}


int *BINtoHEX(int *Arr,int n)
{
	int j = 0,i = 0;
	int x;
	int outArr[100];
	while (i < n)
	{
		x = 0;
		x += Arr[i++] * 1000;
		x += Arr[i++] * 100;
		x += Arr[i++] * 10;
		x += Arr[i++] ;
		switch (x)
		{
			case 0:{	outArr[j] = 0x0;			break;		}
			case 1:{	outArr[j] = 0x1;			break;		}
			case 10:{	outArr[j] = 0x2;			break;		}
			case 11:{	outArr[j] = 0x3;			break;		}		
			case 100:{	outArr[j] = 0x4;			break;		}
			case 101:{	outArr[j] = 0x5;			break;		}
			case 110:{	outArr[j] = 0x6;			break;		}
			case 111:{	outArr[j] = 0x7;			break;		}
			case 1000:{	outArr[j] = 0x8;			break;		}
			case 1001:{	outArr[j] = 0x9;			break;		}
			case 1010:{	outArr[j] = 0xA;			break;		}
			case 1011:{ outArr[j] = 0xB;			break;		}
			case 1100:{	outArr[j] = 0xC;			break;		}
			case 1101:{	outArr[j] = 0xD;			break;		}
			case 1110:{	outArr[j] = 0xE;			break;		}
			case 1111:{	outArr[j] = 0xF;			break;		}	
		}		
		j++;	}
	return outArr;
}


void rounding(int* arr,int n,int i)
{
	
		if (arr[n - i] == 0)
		{
			arr[n - i]++;
			return ;
		}
		else
		{
			arr[n - i]--;
			return rounding(arr,n, ++i);
		}
}

int * fractional(char *str, int *outHexArr)
{
	double x1,x = atof(str);
	int bin[52];
	int whole;
	int Arr[100],outArr[100];
	int mod = 0;
	int div = 0;
	double fract,fract1;
	int i = 0;
	int nArr = 0;
	int exp;
	whole = static_cast<int>(x);
	fract = x - whole;
	nArr = DECtoBIN(whole, Arr);
	//fract = fract * ;
	
	for (i = 0; i < 52; i++)
	{
		fract = fract * 2;
		whole = fract ;
		Arr[nArr + i ] = whole;
		fract = fract * 100000000000000;
		fract = floor(fract);
		fract = fract / 100000000000000;
		if (fract >= 1)
			fract = fract - 1;
	}
	/*
	for (i = 0; i < 52 +nArr; i++)
		if ((i + 1) % 4 != 0)
			cout << Arr[i];
		else
			cout << Arr[i] << endl;
	getchar();
	*/

	exp = nArr - 1;
	//for (i = 0; i < 52; i++)
	//	Arr[i + nArr] = bin[i];

	exp = exp + 1023;
	int expArr[100];
	int nExpArr;
	nExpArr = DECtoBIN(exp, expArr);

	outArr[0] = 0;
	for (i = 0; i < nExpArr; i++)
		outArr[i + 1] = expArr[i];
	nArr = nArr + 52;
	for (i = 1; i < 64-nExpArr; i++)
		outArr[nExpArr + i ] = Arr[i];
	//int *PointerArr = outArr;
	//for (i = 1; i < 64; i++)
//		cout << PointerArr[i];
//	cout << endl;
	if (Arr[64-nExpArr] == 1)
		rounding(outArr,64, 1);
//	for (i = 1; i < 64; i++)
//		cout << PointerArr[i];
//	cout << endl;
	int HexArr[100];
	outHexArr = BINtoHEX(outArr, nArr + nExpArr + 1);
	for (i = 0; i < 32; i=i+2)
	{
		HexArr[i ] = outHexArr[16 - i - 2];
		HexArr[i+1] = outHexArr[16 - i - 1];
	}
	for (i = 0; i < 32; i++)
		outHexArr[i] = HexArr[i];
	return HexArr;
}

int * fractional(char *str, int *outHexArr,int z)
{
	double x1, x = atof(str);
	int bin[52];
	int whole;
	int Arr[100], outArr[100];
	int mod = 0;
	int div = 0;
	double fract, fract1;
	int i = 0;
	int nArr = 0;
	int exp;


	whole = static_cast<int>(x);
	fract = x - whole;
	nArr = DECtoBIN(whole, Arr);
	//fract = fract * ;

	for (i = 0; i < 23; i++)
	{
		fract = fract * 2;
		whole = fract;
		Arr[nArr + i] = whole;
		fract = fract * 1000000;
		fract = floor(fract);
		fract = fract / 1000000;
		if (fract >= 1)
			fract = fract - 1;
	}
	/*
	for (i = 0; i < 52 +nArr; i++)
	if ((i + 1) % 4 != 0)
	cout << Arr[i];
	else
	cout << Arr[i] << endl;
	getchar();
	*/
	exp = nArr - 1;
	//for (i = 0; i < 52; i++)
	//	Arr[i + nArr] = bin[i];
	exp = exp + 127;
	int expArr[100];
	int nExpArr;
	nExpArr = DECtoBIN(exp, expArr);

	outArr[0] = 0;
	for (i = 0; i < nExpArr; i++)
		outArr[i + 1] = expArr[i];
	nArr = nArr + 23;
	for (i = 1; i < 32 - nExpArr; i++)
		outArr[nExpArr + i] = Arr[i];
	//int *PointerArr = outArr;
	//for (i = 1; i < 64; i++)
	//		cout << PointerArr[i];
	//	cout << endl;
	if (Arr[64 - nExpArr] == 1)
		rounding(outArr, 32, 1);
	//	for (i = 1; i < 64; i++)
	//		cout << PointerArr[i];
	//	cout << endl;
	int HexArr[100];
	outHexArr = BINtoHEX(outArr, nArr + nExpArr + 1);
	for (i = 0; i < 16; i = i + 2)
	{
		HexArr[i] = outHexArr[8 - i - 2];
		HexArr[i + 1] = outHexArr[8 - i - 1];
	}
	for (i = 0; i < 16; i++)
		outHexArr[i] = HexArr[i];
	return HexArr;
}