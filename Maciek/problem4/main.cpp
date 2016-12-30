#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "puzzle.h"

using namespace std;

int main()
{
	int x=0;
	char c[]="auto";
	char b[]="otua";
	try
	{
		puzzle a(c,b);
		a.display();
		cout<<endl;
		while(x==0)
		{
			if(a.isSolved()==true)
			{
				a.display();		
				x=1;
			}
			a.shiftLeft();
			if(a.isSolved()==true)
			{
				a.display();		
				x=1;
			}
			a.shiftLeft();
			if(a.isSolved()==true)
			{
				a.display();		
				x=1;
			}
			a.swapEnds();
			if(a.isSolved()==true)
			{
				a.display();		
				x=1;
			}
		}
	}
	catch(bad_alloc)
	{
		cout<<"bad_alloc"<<endl;
	}
	catch (logic_error)   
   	{  
    		 cout <<"logic_error"<< endl;   
  	}
	return 0;
}
