#include "tab_seg.h"

tab_segment::tab_segment()
{
	Name = 0;
	Length = 0x0;
	Align = 0;
	CombineClass = 0;
}

void tab_segment::SetName(char* str)
{
	Name = new char[strlen(str)];
	strcpy(Name, str);
}

char* tab_segment::GetName()
{
	return Name;
}

void tab_segment::SetLength(int x)
{
	Length = x;
}

int tab_segment::GetLength()
{
	return Length;
}

dyn_tab_segment::dyn_tab_segment()
{
	Next = 0;
	Prev = 0;
}
void Segs(AllTab *tab)
{
	DynTab *Run;
	DynTab_sint *RunSent;
	dyn_tab_segment *RunSeg,*RunSeg2;
	bool flagData = true;
	Run = tab->LexTab;
	for (int i = 1; i < tab->number_str_lex; i++)
	{
		if (Run->Inf.ravna_li_str_lex("SEGMENT"))
		{
			RunSeg = new dyn_tab_segment;
			if (tab->SegmentTab == 0)
				tab->SegmentTab = RunSeg;
			else
			{
				RunSeg->Prev = RunSeg2;
				RunSeg2->Next = RunSeg;
				RunSeg->Next = tab->SegmentTab;
				tab->SegmentTab->Prev=RunSeg;
			}
			RunSeg->Inf.SetName(Run->Prev->Inf.vernut_lex());
			RunSent = tab->TabSentStruct;
			if (flagData == true)
			{
				for (int j = 0; j < tab_lex::GetEND("data"); j++)
				{
					RunSent = RunSent->Next;
				}
				flagData = false;
			}
			else
				for (int j = 0; j < tab_lex::GetEND("code"); j++)
				{
					RunSent = RunSent->Next;
				}
			RunSeg->Inf.SetLength(RunSent->Prev->Inf.GetWeight());

			RunSeg2 = RunSeg;
		}
		Run = Run->Next;
	}
}