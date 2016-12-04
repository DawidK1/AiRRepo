#ifndef COMPANY
#define COMPANY
#include <iostream>
#include "vector.h"
#include "iter.h"
#include "shop.h"
#include "toy.h"

class company
{
	string name;
	vector<shop> list;
public:
	company(string n,vector<shop> l):name(n), list(l){}
	~company(){}
	friend ostream& operator<<(ostream& screen,const company& a);
};

#endif
