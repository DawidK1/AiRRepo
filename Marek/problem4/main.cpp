#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "Puzzle.h"

using namespace std;

int main()
{
    List<int> lista;
    lista.insert(1);
    lista.insert(2);
    lista.showStructure();

    return 0;
}