#ifndef WORKERS_H
#define WORKERS_H


#include <iostream>
#include <string>

#define OVERTIME 40

using namespace std;


class Worker{

 protected:
  
    string fname;
    string sname;

    int PESEL;
    int NIP;

  public:

    Worker(string f="Nie podano", string s="Nie podano", int P=0, int N=0);
    virtual ~Worker();


    virtual int calc_wage()=0;
    virtual void print();

};


class FulltimeWorker : public Worker{
    int payment;
    int months_worked;

    public:
    FulltimeWorker(string f="Nie podano", string s="Nie podano"
    , int P=0, int N=0,int pment = 3000 ,int mw = 1);
    
    ~FulltimeWorker();
    int calc_wage();
    void print();



};


class HourPaidWorker : public Worker{

    int perHour;
    int hoursWorked;

    public:
    HourPaidWorker(string f="Nie podano", string s="Nie podano"
    , int P=0, int N=0,int ph = 15 ,int hw = 80);
    ~HourPaidWorker();
    int calc_wage();
    void print();


};

class Dealer : public Worker{

    int sales;
    float PercentForDealer;

    public:
    Dealer(string f="Nie podano", string s="Nie podano"
    , int P=0, int N=0,int sls = 60000 ,float pfd = 0.1);
    ~Dealer();
    int calc_wage();
    void print();

};

#endif
