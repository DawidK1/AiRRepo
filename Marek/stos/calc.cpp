#include "calc.h"

Calc :: Calc()
{
	stos = new Stack();
}

Calc :: ~Calc()
{
	if(stos)
		stos -> ~Stack();
}

bool Calc :: isoperator(char op)
{
	if(op == '+' || op == '-' || op == '*')
		return true;
	else
		return false;
}

int Calc :: dzialanie(int op1, int op2, char op)
{
	int wynik;
	switch(op)
	{
		case '+':
			wynik = op1 + op2;
			break;
		case '-':
			wynik = op1 - op2;
			break;
		case '*':
			wynik = op1 * op2;
			break;
	}
	return wynik;
}

void Calc :: pokaz()
{
	cout << stos->top() << endl;
}

void Calc :: wejscie(char* input)
{
	int len = strlen(input);
	char buffer[15];
	int j = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(input[i]>='0' && input[i]<='9')
		{
			buffer[j++] = input[i];
		}
		else if(input[i] == ' ')
		{
			if(j>0)
			{
				buffer[j] = '\0';
				int x = atoi(buffer);
				stos->push(x);
				j=0;
			}
		}
		else if(isoperator(input[i]))
		{
			if(stos->size() >= 2)
			{
				int op1 = stos->top();
				stos->pop();
				int op2 = stos->top();
				stos->pop();
				cout << op2 << input[i] << op1 << endl;
				stos->push(dzialanie(op2, op1, input[i]));
			}
		}
	}
	this->pokaz();
}






























