#include "shop.h"


shop::shop()
{
	street = "brak";
	number = 0;
	vector<toy> l(5);
	vector<toy> list=l;
}

ostream& operator<<(ostream& screen,const shop& a)
{
	screen<<a.street<<"      "<<a.number<<endl;
	screen<<"Produkty:"<<endl;
	vector<toy> lis;
	lis = a.list;
	iter<toy> wsk(lis);
	for(wsk=0;wsk<lis.position();++wsk)
	{
		screen<<*wsk<<endl;
	}

	return screen;
}

