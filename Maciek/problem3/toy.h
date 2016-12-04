#ifndef TOY
#define TOY
#include <iostream>
#include "vector.h"
using namespace std;
class toy
{

	string name;
	float price;
public:
	toy():name("brak"),price(0){}
	toy(string n, float p):name(n),price(p){}
	friend ostream& operator<<(ostream& screen,const toy& a);
	~toy(){};
};



#endif
