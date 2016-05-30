#ifndef _MY_STACK_
#define _MY_STACK_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <new>

using namespace std;

class Stack{
	private:
	
	int height;	
	int* tab;
	
	public:
	

	void push(int a);
	void pop();
	int top();
	bool isEmpty();
	int size();
	~Stack();
	Stack();
	};



#endif
