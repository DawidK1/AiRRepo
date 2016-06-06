#include "Calc.h"


Calc::~Calc()
	{
	//s.~Stack();
	}
void Calc::getData()
	{
	
	fgets(input, ROZMIAR, stdin);
	}

bool Calc::decode()
	{
	int j = 0;
	int i;
	for(i = 0 ; i < (int)strlen(input) ; i++)
		{
			if(input[i] == ' ')
				{
				buffer[j] = '\0';
				s.push(atoi(buffer));
				j = 0;
				continue;
				}

			if(input[i] == 'q' || input[i] == 'Q')
				return false;

			if(input[i] >= '0' && input[i] <= '9')
				{
					
				if(j < 11)
					{
					buffer[j] = input[i];
					j++;
					
					}
				continue;
				}

			if(input[i] == '+' || input[i] == '-' || input[i] == '*')
				{
				s.push(calculate(input[i]));	
				continue;
				}
			//else cout << "Nierozpoznany znak, pomijam!\n";
		}
	return true;
	}
int Calc::calculate(char op)
	{
	int result = 0;
	int a = 0;
	int b = 0;
	if(!s.isEmpty()){
	
		a = s.top();
		s.pop();
		}
	else{
	cout << "Pusty stos" ; 
	return -1;
	}
	if(!s.isEmpty()){
	
		b = s.top();
		s.pop();
		}
	else{
	cout << "Pusty stos" ; 
	return -1;
	}

	switch(op)
		{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;			
			
		}
	return result;

	}
void Calc::showResult()
	{
	cout << " Wynik to: " << s.top() << endl;
	}
