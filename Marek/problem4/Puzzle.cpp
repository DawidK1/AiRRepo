#include <iostream>
#include "Puzzle.h"

using namespace std;


Puzzle :: Puzzle(char answ[], char init[])
{
    for(int i = 0; answ[i] != '\0'; i++)
    {
        solution.insert(answ[i]);
    }

    for(int i = 0; init[i] != '\0'; i++)
    {
        puzzle.insert(init[i]);
    }
}

void Puzzle :: display()
{
    cout << "\nSzukane rozwiazanie: ";
    solution.showStructure();
    cout << "Puzzle: ";
    puzzle.showStructure();
}

bool Puzzle :: isSolved()
{
    char end;
    solution.gotoEnd();
    end = solution.getCursor();
    solution.gotoBeginning ();
    puzzle.gotoBeginning ();
    while(solution.getCursor() != end)
    {
        if(solution.getCursor() != puzzle.getCursor())
            return false;
        solution.gotoNext();
        puzzle.gotoNext();
    }
    return true;
}

void Puzzle :: reverse()
{
    int i = 0;
    List<char> temp;
    char begin;
    puzzle.gotoBeginning();
    begin = puzzle.getCursor();
    puzzle.gotoEnd();
    while(puzzle.getCursor() != begin)
    {
        temp.insert(puzzle.getCursor());
        puzzle.gotoPrior();
        i++;
    }
    temp.gotoBeginning();
    puzzle.gotoBeginning();
    int j = 0;
    while(j <= i)
    {
        puzzle.replace(temp.getCursor());
        temp.gotoNext();
        puzzle.gotoNext();
        j++;
    }
    temp.clear();
    puzzle.gotoEnd();
    puzzle.replace(begin);
}

void Puzzle :: shiftLeft()
{
    char begin, temp;
    puzzle.gotoBeginning();
    begin = puzzle.getCursor();
    int i = 0;
    puzzle.gotoEnd();
    while(puzzle.getCursor() != begin)
    {
        puzzle.gotoPrior();
        i++;
    }
    puzzle.gotoBeginning();
    int j = 0;
    while(j < i)
    {
        puzzle.gotoNext();
        temp = puzzle.getCursor();
        puzzle.gotoPrior();
        puzzle.replace(temp);
        puzzle.gotoNext();
        j++;
    }
    puzzle.gotoEnd();
    puzzle.replace(begin);
}

void Puzzle :: swapEnds()
{
    char a,b;
    puzzle.gotoEnd();
    a = puzzle.getCursor();
    puzzle.gotoPrior();
    b = puzzle.getCursor();
    puzzle.replace(a);
    puzzle.gotoNext();
    puzzle.replace(b);
}










