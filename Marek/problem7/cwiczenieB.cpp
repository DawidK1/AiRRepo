 //Problem 7, cwiczenie B, Marek Piekarz AiR II rok

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Condition
{
    public:
        bool warunek(const T& a);
};

template <class T>
bool Condition<T> :: warunek(const T& a)
{
    if(a>2)
        return true;
    return false;
}

template <class T>
class Operation
{
    public:
        void operacja(T& a);
};

template <class T>
void Operation<T> :: operacja(T& a)
{
    a = a + 3;
    return;
}

template <typename Iter, typename Condition, typename Operation>
void funktator(Iter start, Iter end, Condition war, Operation oper)
{
    for(Iter i = start; i != end; i++)
    {
        if(war.warunek(*i))
            oper.operacja(*i);
    }
}

int main()
{
    Condition<int> war;
    Operation<int> oper;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
   funktator(v.begin(), v.end(), war, oper);
   vector<int> :: iterator i;
   for(i = v.begin(); i != v.end(); ++i)
   {
       cout << *i << endl;
   } 
   return 0;
}