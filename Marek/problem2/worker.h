#ifndef WORKER_H
#define WORKER_H

#include <iostream>

using namespace std;

class WORKER
{
protected:
    string name;
    string surname;
    int PESEL;
    int NIP;

public:
    WORKER(string n="Nie znane", string s="Nie znane", int p=0, int N=0);
    ~WORKER();
    void virtual print();
    void virtual calc()=0;
};

#endif
