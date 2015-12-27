#ifndef KOMAND_H
#define KOMAND_H

#include "main.h"

class instruction{
public:
	instruction();
	static void SetFCOS(DynTab_sint *);
	static void SetFADD(DynTab_sint *, DynTab*, AllTab*);
	static void SetFCOMP(DynTab_sint *, DynTab*);
	
private:
	static int ModR_M(DynTab_sint *, DynTab* , int);
	static int ModR_M(DynTab_sint *, DynTab*);
	static int instruction::Base(DynTab*);
	static int instruction::ChangeSeg(DynTab *);
};

int * fractional(char *str, int *outHexArr);
int * fractional(char *str, int *outHexArr, int z);
int *BINtoHEX(int *Arr, int n);

#endif