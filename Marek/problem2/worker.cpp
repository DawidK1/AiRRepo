#include "worker.h"

void WORKER :: print()
{
    cout << name << " " << surname << " PESEL: " << PESEL << " NIP: " << NIP << endl;
}

WORKER :: WORKER(string n, string s, int p, int N)
{
    name=n;
    surname=s;
    PESEL=p;
    NIP=N;
}

WORKER :: ~WORKER()
{
    cout << "Wywoluje destruktor ~WORKER" << endl;
}
