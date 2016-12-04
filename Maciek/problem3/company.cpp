#include "company.h"


ostream& operator<<(ostream& screen,const company& a)
{
	screen<<a.name<<endl;
	screen<<"Sklepy:"<<endl;
	vector<shop> lis;
	lis = a.list;
	iter<shop> wsk(lis);
	for(wsk=0;wsk<lis.position();++wsk)
	{
		screen<<*wsk<<endl;
	}

	return screen;
}
