#include <iostream>
#include "vector.h"
#include "iter.h"
#include "toy.h"
#include "shop.h"
#include "company.h"
#include <fstream>
using namespace std;


int main()
{
	ifstream file;
	file.open("toys1.txt");
	vector<toy> list1;
	if(file)
	{
		string name;
		float price;
		while(file.eof() != true)
		{
			file >> name;
			file >> price;
			toy t(name,price);
			list1.add(t);
		}
	}
	file.close();
	shop s1("dluga",13,list1);


	ifstream file1;
	file1.open("toys2.txt");
	vector<toy> list2;
	if(file1)
	{
		string name;
		float price;
		while(file1.eof() != true)
		{
			file1 >> name;
			file1 >> price;
			toy t(name,price);
			list2.add(t);
		}
	}
	file1.close();
	shop s2("krotka",5,list2);
	vector<shop> shops;
	shops.add(s1);
	shops.add(s2);
	company firm("Najlepsze zabawki",shops);
	cout<< firm << endl;
	
	return 0;
}
