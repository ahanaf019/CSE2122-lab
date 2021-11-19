#include<iostream>

using namespace std;

unsigned long long factorial(unsigned long long x);

int main()
{
    cout<<factorial(2)<<endl;
    cout<<factorial(3)<<endl;
    cout<<factorial(4)<<endl;
    cout<<factorial(5)<<endl;


    return 0;
}

unsigned long long factorial(unsigned long long x)
{
    if(x == 1)
    {
        return 1;
    }
    return factorial(x -1) * x;
}