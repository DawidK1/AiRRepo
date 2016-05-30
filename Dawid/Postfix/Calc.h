#ifndef _CALC_H_
#define _CALC_H_
#include "Stack.h"
#include <cstring>
#include <string>
#include <iostream>
#include <stdlib.h>
class Calc{

	private:
	Stack s;
	char buffer[12];
	
	string input;

	int calculate(char op);
	
	public:
	~Calc();
	void getData();
	bool decode();
	void showResult();
	};







#endif
