#include<iostream>

using namespace std;

unsigned long long fib(unsigned long long x);

int main()
{
    
    cout<<fib(10)<<" ";


    return 0;
}

unsigned long long fib(unsigned long long x)
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == 2) return 1;

    return fib(x - 2) + fib(x - 1);
    
}