#include "komand.h"

int instruction::ModR_M(DynTab_sint *RunSent, DynTab* operand)
{
	int ModR_m;

	if (operand->Inf.ravna_li_str_lex("EAX"))
		{
			ModR_m = 0x00;
		}
	if (operand->Inf.ravna_li_str_lex("ECX"))
		{
			ModR_m = 0x01;
		}
	if (operand->Inf.ravna_li_str_lex("EDX"))
		{
			ModR_m = 0x02;
		}
	if (operand->Inf.ravna_li_str_lex("EBX"))
		{
			ModR_m = 0x03;
		}
	if (operand->Inf.ravna_li_str_lex("ESI"))
		{
			ModR_m = 0x06;
		}
	if (operand->Inf.ravna_li_str_lex("EDI"))
		{
			ModR_m = 0x07;
		}
		return ModR_m;
}

int instruction::ModR_M(DynTab_sint *RunSent, DynTab* operand, int base)
{
	int ModR_m;


	if (operand->Inf.ravna_li_str_lex("EAX"))
	{
		ModR_m = 0x80;
	}
	if (operand->Inf.ravna_li_str_lex("ECX"))
	{
		ModR_m = 0x81;
	}
	if (operand->Inf.ravna_li_str_lex("EDX"))
	{
		ModR_m = 0x82;
	}
	if (operand->Inf.ravna_li_str_lex("EBX"))
	{
		ModR_m = 0x83;
	}
	if (operand->Inf.ravna_li_str_lex("EBP"))
	{
		ModR_m = 0x85;
	}
	if (operand->Inf.ravna_li_str_lex("ESI"))
	{
		ModR_m = 0x86;
	}
	if (operand->Inf.ravna_li_str_lex("EDI"))
	{
		ModR_m = 0x87;
	}
	return ModR_m;

}

int instruction::Base(DynTab *reg1)
{
	if (reg1->Inf.ravna_li_str_lex("AX") || reg1->Inf.ravna_li_str_lex("AL"))
	{
		return 0x00;
	}
	if (reg1->Inf.ravna_li_str_lex("CX") || reg1->Inf.ravna_li_str_lex("CL"))
	{
		return  0x01;
	}
	if (reg1->Inf.ravna_li_str_lex("DX") || reg1->Inf.ravna_li_str_lex("DL"))
	{
		return 0x02;
	}
	if (reg1->Inf.ravna_li_str_lex("BX") || reg1->Inf.ravna_li_str_lex("BL"))
	{
		return 0x03;
	}
	if (reg1->Inf.ravna_li_str_lex("SP") || reg1->Inf.ravna_li_str_lex("AH"))
	{
		return 0x04;
	}
	if (reg1->Inf.ravna_li_str_lex("BP") || reg1->Inf.ravna_li_str_lex("CH"))
	{
		return 0x05;
	}
	if (reg1->Inf.ravna_li_str_lex("SI") || reg1->Inf.ravna_li_str_lex("DH"))
	{
		return 0x06;
	}
	if (reg1->Inf.ravna_li_str_lex("DI") || reg1->Inf.ravna_li_str_lex("BH"))
	{
		return 0x07;
	}
}

int instruction::ChangeSeg(DynTab *operand)
{
	if (operand->Inf.ravna_li_str_lex("ES"))
		return 0x26;
	if (operand->Inf.ravna_li_str_lex("CS"))
		return 0x2E;
	if (operand->Inf.ravna_li_str_lex("SS"))
		return 0x36;
	if (operand->Inf.ravna_li_str_lex("DS"))
		return 0x3E;
}

void instruction::SetFCOS(DynTab_sint *RunSent)
{
	RunSent->Inf.CreateCode(RunSent->Inf.GetWeight());
	RunSent->Inf.SetCode(0xD9, 0);
	RunSent->Inf.SetCode(0xFD, 1);
}

void instruction::SetFADD(DynTab_sint *RunSent, DynTab *operand, AllTab* tab)
{
	int weight = RunSent->Inf.GetWeight() - RunSent->Prev->Inf.GetWeight();
	int Opcode = 0xD8;
	bool flag = false;
	int segment = 0;
	int ModR_m;
	int k = 0;
	
	if (operand->Inf.proverka_podstr_in_str("співпроцесор"))
	{
		if (operand->Inf.ravna_li_str_lex("ST(0)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC0, k + 1);
			return;
		}
		if (operand->Inf.ravna_li_str_lex("ST(1)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC1, k + 1);
			return;
		}
		if (operand->Inf.ravna_li_str_lex("ST(2)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC2, k + 1);
			return;
		}
		if (operand->Inf.ravna_li_str_lex("ST(3)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC3, k + 1);
			return;
		}
		if (operand->Inf.ravna_li_str_lex("ST(4)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC4, k + 1);
			return;
		}
		if (operand->Inf.ravna_li_str_lex("ST(5)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC5, k + 1);
			return;
		}
		if (operand->Inf.ravna_li_str_lex("ST(6)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC6, k + 1);
			return;
		}
		if (operand->Inf.ravna_li_str_lex("ST(7)"))
		{
			RunSent->Inf.CreateCode(weight);
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xC7, k + 1);
			return;
		}
	}
	else
	{

		if (operand->Inf.proverka_podstr_in_str("сегментного"))
		{
			if (!((operand->Inf.ravna_li_str_lex("DS"))))
			{
				k++;
				segment = ChangeSeg(operand);
			}
			else
			{
				segment--;
				weight--;
				k++;
			}

			operand = operand->Next->Next;
		}

		DynTabIdentificator *RunID;
		RunID = tab->TabIdentificator;
		for (int i = 0; i < TabIdentificator::get_1(); i++)
		{
			if (operand->Inf.ravna_li_str_lex(RunID->Inf.name_get()))
			{
				flag = true;
				break;
			}
			RunID = RunID->Next;
		}

		if (flag == true)
		{
			RunSent->Inf.CreateCode(weight+2);
			operand = operand->Next->Next;
			if (segment != 0)
				RunSent->Inf.SetCode(segment, 0);
			if (RunID->Next->Inf.valuee_get() - RunID->Inf.valuee_get() == 8)
			{
				Opcode = 0xDC;
			}
			RunSent->Inf.SetCode(Opcode, k);
			
			RunSent->Inf.SetCode(ModR_M(RunSent, operand,1), k + 1);
			for (int q = 1; q <= 3 ; q++)
				RunSent->Inf.SetCode(0, k+1+q);
			
			RunSent->Inf.SetCode(RunID->Inf.valuee_get(), weight - 1);

		}
		else
		{

			RunSent->Inf.CreateCode(weight);
			operand = operand->Next->Next->Next;
			RunSent->Inf.SetCode(ModR_M(RunSent, operand), k + 1);

			if (segment != 0)
				RunSent->Inf.SetCode(segment, 0);
			RunSent->Inf.SetCode(Opcode, k);

		}
	}
	
}

void instruction::SetFCOMP(DynTab_sint *RunSent, DynTab *operand )
{
	RunSent->Inf.CreateCode(RunSent->Inf.GetWeight());

	int k = 0,Opcode = 0xD8;


	if (operand->Inf.ravna_li_str_lex("ST(0)"))
		{

			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xD8, k + 1);
			return;
		}
	if (operand->Inf.ravna_li_str_lex("ST(1)"))
		{
			
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xD9, k + 1);
			return;
		}
	if (operand->Inf.ravna_li_str_lex("ST(2)"))
		{
		
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xDA, k + 1);
			return;
		}
	if (operand->Inf.ravna_li_str_lex("ST(3)"))
		{
			
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xDB, k + 1);
			return;
		}
	if (operand->Inf.ravna_li_str_lex("ST(4)"))
		{
			
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xDC, k + 1);
			return;
		}
	if (operand->Inf.ravna_li_str_lex("ST(5)"))
		{
	
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xDD, k + 1);
			return;
		}
	if (operand->Inf.ravna_li_str_lex("ST(6)"))
		{
			
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xDE, k + 1);
			return;
		}
	if (operand->Inf.ravna_li_str_lex("ST(7)"))
		{
		
			RunSent->Inf.SetCode(Opcode, k);
			RunSent->Inf.SetCode(0xDF, k + 1);
			return;
		}
	
}
