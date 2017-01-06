#ifndef _PUZZLE_H_
#define _PUZZLE_H_

#include <iostream>
#include "List.h"
#include <cstring>
#include <unistd.h>
#include <cstdlib>
class Puzzle{

    private:
        int size;
        List<char> answer, actual;

    public:
        Puzzle(string init, string ans);
        ~Puzzle();
        bool solved();
        void display();
        void shiftLeft();
        void swapEnds();
        void execute_cmd(char cmd);
        void debug();

};




#endif
