#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "Puzzle.h"

using namespace std;

int main()
{
    int x = 0;
    char answ[] = "PUZEL";
    char init[] = "ZELUP";
    
    try
    {
        Puzzle A(answ, init);
        A.display();
        
        while(x == 0)
        {
            if(A.isSolved() == true)
            {
                A.display();
                x = 1;
            }
            A.swapEnds();
            if(A.isSolved() == true)
            {
                A.display();
                x = 1;
            }
            A.shiftLeft();
            if(A.isSolved() == true)
            {
                A.display();
                x = 1;
            }
            A.shiftLeft();
            if(A.isSolved() == true)
            {
                A.display();
                x = 1;
            }
            A.shiftLeft();
            if(A.isSolved() == true)
            {
                A.display();
                x = 1;
            }
        }
    }
    catch(bad_alloc)
    {
        cout << "bad_alloc" << endl;
    }
    catch(logic_error)
    {
        cout << "logic_error" << endl;
    }
    return 0;
}