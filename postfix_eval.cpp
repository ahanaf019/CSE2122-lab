#include<iostream>

using namespace std;

const int MAXSTK = 10;

struct stack{
    
    int top = 0; 
    int data[MAXSTK];
};

void push(stack *stk, int item);
int pop(stack *stk);
void eval(char x, stack *stk);

int main()
{
    stack a;
    char x;

    do
    {
        cin>>x;
        if(x != 'q') 
        {
            cout<<"-->"<<x<<endl;
            eval(x, &a);
        }
    } while (x != 'q');
    
    cout<<pop(&a)<<endl;
    return 0;
}

void eval(char x, stack *stk)
{
    int p,q;
    switch (x)
    {
    case '+':
        p = pop(stk);
        q = pop(stk);
        cout<<"====>"<<p+q<<endl;
        push(stk, (p+q));
        break;
    case '-':
        p = pop(stk);
        q = pop(stk);
        cout<<"====>"<<q-p<<endl;
        push(stk, (q-p));
        break;
    case '*':
        p = pop(stk);
        q = pop(stk);
        cout<<"====>"<<p*q<<endl;
        push(stk, (p*q));
        break;
    case '/':
        p = pop(stk);
        q = pop(stk);
        cout<<"====>"<<q/p<<endl;
        push(stk, (q/p));
        break;
    default:
        int m = x - '0';
        push(stk, m);
        break;
    }
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

