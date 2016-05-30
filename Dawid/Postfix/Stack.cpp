#include "Stack.h"


Stack::~Stack(){
	
	if(tab != NULL)
		delete[] tab;
	}
Stack::Stack(){
	height = 0;
	tab = NULL;	
	}

void Stack::push(int a){
	if(height == 0){
		tab = new int[1];
		tab[0] = a;
		height++;		
		}
	else
		{
		int* temp = new int[height +1];
		if (temp == NULL)
			throw bad_alloc();

		memcpy(temp + 1, tab, height*sizeof(int));

		temp[0] = a;
		delete[] tab;
		tab = temp;
		height++;
		}



	}
int Stack::top(){

	if(height == 0)
		{
		cout<< "stos pusty!\n";
		return 0;
		}
	else return tab[0];
	}
void Stack::pop(){
	if(height == 0)
		{
		//cout << "stos pusty";
		return;
		}
	if(height == 1)
		{
		height--;
		delete[] tab;
		tab = NULL;
		}
	else
		{
		int* temp = new int[height - 1];
		if(temp == NULL)
			throw bad_alloc();
		memcpy(temp, tab + 1 , (height-1) * sizeof(int));
		delete[] tab;
		tab = temp;
		height--;
		}
	
	}



bool Stack::isEmpty()
	{
	if(height == 0)
		return true;
	else return false;
	}

int Stack::size()
	{
	return height;
	}






