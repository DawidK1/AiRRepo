#ifndef SHOP
#define SHOP
#include <iostream>
#include "vector.h"
#include "iter.h"
#include "toy.h"
                                 
using namespace std;

class shop
{
	string street;
	int number;
	vector<toy> list;
public:
	shop();
	shop(string s, int n,vector<toy> l):street(s), number(n), list(l){}
	~shop(){}
	friend ostream& operator<<(ostream& screen,const shop& a);
};

#endif
