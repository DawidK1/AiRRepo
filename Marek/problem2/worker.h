#ifndef WORKER_H
#define WORKER_H

#include <iostream>

using namespace std;

class Worker
{
protected:
    string name;
    string surname;
    int PESEL;
    int NIP;

public:
    Worker(string n="Nie znane", string s="Nie znane", int p=0, int N=0);
    ~Worker();
    virtual void print();
    virtual int calculate()=0;
};


class FullTime : public Worker
{
protected:
    int per_month;
    int months;

public:
    FullTime(string n="Nie znane", string s="Nie znane", int p=0, int N=0, int per_m=1500, int m=1);
    ~FullTime();
    int calculate();
    void print();
};

class PartTime : public Worker
{
protected:
    int per_hour;
    int hours;

public:
    PartTime(string n="Nie znane", string s="Nie znane", int p=0, int N=0, int per_h=8, int h=10);
    ~PartTime();
    int calculate();
    void print();

};

class Traders : public Worker
{
protected:
    int percent_of_sales;
    int sales;

public:
    Traders(string n="Nie znane", string s="Nie znane", int p=0, int N=0, int per_of_sales=0.05, int sal=1000);
    ~Traders();
    int calculate();
    void print();
};

#endif
