#include<iostream>

using namespace std;

const int MAXSTK = 10;

struct stack{
    
    int top = 0; 
    int data[MAXSTK];
};

int main()
{



    return 0;
}


void push(stack *stk, int item)
{
    if(stk->top != MAXSTK)
    {
        stk->data[stk->top];
        stk->top += 1;
    }

    else
        cout<<"OVERFLOW";
}