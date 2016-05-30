#include "Stack.h"


Stack::~Stack(){
	
	if(tab != NULL)
		delete[] tab;
	}
Stack::Stack(){
	size = 0;
	tab = NULL;	
	}
void Stack::push(int a){
	if(size = 0){
		tab = new int[1];
		tab[0] = a;		
		}
	else
		{
		int* temp = new int[size +1];
		if (temp == NULL)
			throw bad_alloc();
		memcpy(
		}



	}
