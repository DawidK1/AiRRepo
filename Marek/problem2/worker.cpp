#include "worker.h"

/* KLASA Worker */
Worker :: Worker(string n, string s, int p, int N)
{
    name=n;
    surname=s;
    PESEL=p;
    NIP=N;
}

Worker :: ~Worker()
{
    cout << "Wywoluje destruktor ~WORKER" << endl;
}

void Worker :: print()
{
    cout << name << " " << surname << endl << "\tPESEL: ";
   
    if(PESEL)
        cout << PESEL;
    else
        cout << "brak danych";
    
    cout << " NIP: ";

    if(NIP)
        cout << NIP;
    else  
        cout << "brak danych" <<endl;
    cout << endl;
}

/* Klasa FullTime */

FullTime :: FullTime(string n, string s, int p, int N, int per_m, int m)
    : Worker(n, s, p, N)
{
    per_month=per_m;
    months=m;
}

FullTime :: ~FullTime()
{
    cout << "Wywoluje destruktor ~FullTime" << endl;
}

int FullTime :: calculate()
{
    return per_month*months;
}

void FullTime :: print()
{
    cout << "Umowa o prace:" << endl;
    Worker :: print();
    cout << "Przepracowanych miesiecy:" << months << endl;
    cout << "Wynagrodzenie: " << calculate() <<" PLN" << "\n" << endl;
}

/* Klasa PartTime */

PartTime :: PartTime(string n, string s, int p, int N, int per_h, int h)
    : Worker(n, s, p, N)
{
    per_hour=per_h;
    hours=h;
}

PartTime :: ~PartTime()
{
    cout << "Wywoluje destruktor ~PartTime" << endl;
}

int PartTime :: calculate()
{
    return per_hour*hours;
}

void PartTime :: print()
{
    cout << "Umowa zlecenie:" << endl;
    Worker :: print();
    cout << "Przepracowanych godzin:" << hours << endl;
    cout << "Wynagrodzenie: " << calculate() <<" PLN" << "\n" << endl;
}

/* Klasa Traders */

Traders :: Traders(string n, string s, int p, int N, int per_of_sales, int sal)
    : Worker(n, s, p, N)
{
    percent_of_sales=per_of_sales;
    sales=sal;
}

Traders :: ~Traders()
{
    cout << "Wywoluje destruktor ~Traders" << endl;
}

int Traders :: calculate()
{
    return static_cast<int>(sales * percent_of_sales);
}

void Traders :: print()
{
    cout << "Handlowiec:" << endl;
    Worker :: print();
    cout << "Liczba sprzedaży: " << sales << endl;
    cout << "Wynagordzenie: " << calculate() << " PLN" << "\n" << endl;
}