#include "tvector.h"
using namespace std;
int main()
{
    Vector<int> A;
    int B=10;
    A.push_back(B);
    int a=A.current_size();
    cout << a <<endl;
    if(A.isempty())
        cout << "A jest puste" << endl;
    if(A.isfull())
        cout << "A jest pelne" << endl;
    return 0;
}
