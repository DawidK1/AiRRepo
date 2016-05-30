#include <iostream>

#include "Calc.h"
using namespace std;
int main()
	{


	Calc c = Calc();
	c.getData();

	while(c.decode())
		{
		c.showResult();
		c.getData();
		}
}
