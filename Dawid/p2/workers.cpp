#include "workers.h"



Worker::Worker(string f, string s, int P, int N){
    fname = f;
    sname = s;
    NIP = N;
    PESEL = P;
}

Worker:: ~Worker()
{
    cout << "Destruktor klasy Worker"<<endl;
}

void Worker::print(){
    cout << "Imie: " << fname << endl;
    cout << "Nazwisko" << sname << endl;
    cout << "PESEL: ";

    if(!PESEL)  cout << "Nie podano";
    else cout << PESEL;

    cout << endl << "NIP: ";
    
    if(!NIP)  cout << "Nie podano"<<endl;
    else cout << NIP << endl;
}
/////////////////////////////////////////

FulltimeWorker::FulltimeWorker(string f, string s,int P, int N, int pment ,int mw) 
: Worker(f,s, P, N){

    payment = pment;
    months_worked = mw;
}


HourPaidWorker::HourPaidWorker(string f, string s,int P, int N, int ph ,int hw) 
: Worker(f,s, P, N){
    
    perHour = ph;
    hoursWorked = hw;
}


Dealer::Dealer(string f, string s,int P, int N, int sls ,float pfd) 
: Worker(f,s, P, N){
    
    sales = sls;
    PercentForDealer = pfd;
}
////////////////////////////////
FulltimeWorker::~FulltimeWorker()
{
    cout << "Destruktor Full time worker"<<endl;
}

HourPaidWorker::~HourPaidWorker()
{
    cout << "Destruktor HourPaidWorker"<<endl;
}


Dealer::~Dealer()
{
    cout << "Destruktor Dealer"<<endl;
}

/////////////
int FulltimeWorker::calc_wage(){
    return payment * months_worked;
}

int HourPaidWorker::calc_wage(){
    return perHour * hoursWorked;
}

int Dealer::calc_wage(){
    return static_cast<int>(sales * PercentForDealer);
}

//////////////

void FulltimeWorker:: print(){
    cout << "Pracownik etatowy" << endl;
    Worker::print();
    cout << "Placa miesieczna: " << payment << endl;
    cout << "Do zaplaty: "  << calc_wage() << endl;

}

void HourPaidWorker:: print(){
    cout << "Pracownik rozliczany godzinowo" << endl;
    Worker::print();
    cout << "Placa za godzine: " << perHour << endl;
    cout << "Do zaplaty: "  << calc_wage() << endl;

}

void Dealer:: print(){
    cout << "Sprzedawca" << endl;
    Worker::print();
    cout << "Procent od sprzedazy " << PercentForDealer*100 << "%" << endl;
    cout << "Do zaplaty: "  << calc_wage() << endl;

}
////////////////////////////////