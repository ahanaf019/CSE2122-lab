#include<iostream>

using namespace std;

const int MAXSTK = 10;

struct stack{
    
    int top = 0; 
    int data[MAXSTK];
    // stack():top(0){}; //Constractor of structure.
};


void push(stack *stk, int item);
int pop(stack *stk);


int main()
{
    stack a;
    // cout<<a.top;
    push(&a, 10);
    push(&a, 50);
    push(&a, 20);
    push(&a, 40);
    push(&a, 70);
    push(&a, 90);
    push(&a, 580);
    push(&a, 89);


    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;
    cout<<pop(&a)<<endl;

    push(&a, 8191);
    push(&a, 892);

    cout<<pop(&a)<<endl;


    return 0;
}


void push(stack *stk, int item)
{
    if(stk->top != MAXSTK)
    {
        stk->data[stk->top] = item;
        stk->top += 1;
    }

    else
        cout<<"OVERFLOW\n";
}

int pop(stack *stk)
{
    int item;
    if(stk->top <= 0)
    {
        cout<<"UNDERFLOW\n";
    }
        
    else
    {
        stk->top -= 1;
        item = stk->data[stk->top];
    }
    return item;
}

