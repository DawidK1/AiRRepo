#ifndef CALC
#define CALC

#include "stack.h"
#include <string.h>
#include <cstdlib>
#include <cstdio>

class Calc
{
private:
	Stack *stos;

public: 
	Calc();
	~Calc();
	
	bool isoperator(char op);
	int dzialanie(int op1, int op2, char op);
	void pokaz();
	void wejscie(char* input);
};

#endif
