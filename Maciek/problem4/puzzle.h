#ifndef PUZZLE
#define PUZZLE
#include "List.h"


class puzzle
{
	List<char> solution;
	List<char> puzle;
public:
	puzzle(char answ[], char init[]); 
	void shiftLeft();
	void swapEnds();
	void display();
	bool isSolved();
	void reverse();
};



#endif
