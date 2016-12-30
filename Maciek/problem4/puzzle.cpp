#include <iostream>
#include "puzzle.h"

using namespace std;


puzzle::puzzle(char answ[], char init[])
{
	int i;
	for(i=0;answ[i]!='\0';i++)
	{
		solution.insert(answ[i]);
	}
	for(i=0;init[i]!='\0';i++)
	{
		puzle.insert(init[i]);
	}
}


void puzzle::display()
{
	solution.showStructure ();
	cout<<endl<<endl;
	puzle.showStructure ();
	return;
}

bool puzzle::isSolved()
{
	char end;
	solution.gotoEnd ();
	end=solution.getCursor();
	solution.gotoBeginning ();
	puzle.gotoBeginning ();
	while(solution.getCursor() != end)
	{
		if(solution.getCursor() != puzle.getCursor())
			return false;
	solution.gotoNext ();
	puzle.gotoNext();
	}
	return true;
}

void puzzle::reverse()
{
	List<char> a;
	int i=0;
	char begin;
	puzle.gotoBeginning();
	begin=puzle.getCursor();
	puzle.gotoEnd();
	while(puzle.getCursor() != begin)
	{
		a.insert(puzle.getCursor());
		puzle.gotoPrior();
		i++;
	}
	a.gotoBeginning ();
	puzle.gotoBeginning ();
	int j=0;
	while(j<=i)
	{
		puzle.replace(a.getCursor());
		a.gotoNext ();
		puzle.gotoNext();
		j++;
	}
	puzle.gotoEnd();
	puzle.replace(begin);
}


void puzzle::shiftLeft()
{
	char begin,a;
	puzle.gotoBeginning();
	begin=puzle.getCursor();
	int i=0;
	puzle.gotoEnd();
	while(puzle.getCursor() != begin)
	{
		puzle.gotoPrior();
		i++;
	}
	puzle.gotoBeginning();
	int j=0;
	while(j<i)
	{
		puzle.gotoNext();
		a=puzle.getCursor();
		puzle.gotoPrior();
		puzle.replace(a);
		puzle.gotoNext();
		j++;
	}
	puzle.gotoEnd();
	puzle.replace(begin);
	return;
}

void puzzle::swapEnds()
{
	char a,b;
	puzle.gotoEnd();
	a=puzle.getCursor();
	puzle.gotoPrior();
	b=puzle.getCursor();
	puzle.replace(a);
	puzle.gotoNext();
	puzle.replace(b);
	return;
	
}





















