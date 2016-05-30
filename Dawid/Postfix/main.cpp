#include <iostream>
#include "Stack.h"
using namespace std;
int main()
	{
	Stack s = Stack();
	for(int i = 0 ; i < 100 ; i++)
		s.push(i);
	for(int i = 0 ; i < 150 ; i++)
		{
		cout << s.top();
		s.pop();
		}
	}
