#include <iostream>
#include <vector>

using namespace std;

template <class T>
class cond 
{
public:
	bool warunek(const T& a);
};

template <class T>
bool cond<T>::warunek(const T& a)
{
	if(a>1)
		return true;
	return false;
}





template <class T>
class oper
{
public:
	void operacja(T& a);	
};

template <class T>
void oper<T>::operacja(T& a)
{
	a=a+2;
	return;
}

template <typename Iter, typename cond, typename oper>
void funktator(Iter pocz, Iter kon, cond war, oper czyn)
{
	for(Iter i=pocz; i!=kon; i++)
	{
		if(war.warunek(*i))
			czyn.operacja(*i);
	}
}

int main()
{
	cond<int> war;
	oper<int> czyn;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	funktator(v.begin(),v.end(),war,czyn);
	vector<int>::iterator i;
	for(i=v.begin(); i!=v.end(); ++i)
    	{
		cout<<*i<<endl;
    	}	
	return 0;
}


