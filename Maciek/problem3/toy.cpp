#include "toy.h"


ostream& operator<<(ostream& screen,const toy& a)
{
	screen<<"	"<<a.name<<"      "<<a.price<<endl;
	return screen;
}
