#ifndef PUZZLE
#define PUZZLE
#include "List.h"

class Puzzle
{
    List<char> solution;
    List<char> puzzle;

public:
    Puzzle(char answ[], char init[]);
    void shiftLeft();
    void swapEnds();
    void display();
    bool isSolved();
    void reverse();
};

#endif
