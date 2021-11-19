#include<iostream>

using namespace std;

const int MAXSTK = 10;

struct stack{
    
    int top = 0; 
    char data[MAXSTK];
};


void push(stack *stk, char item);
char pop(stack *stk);
void infix_to_postfix(char c, stack *stk);
int precedence(char x);
char top_item(stack *stk);

int main()
{
    char exp[20] = "a+(b*c-(d/e^f)*g)*h";
    char c;
    stack stk;
    push(&stk, '(');

    // do
    // {
    //     if(c != 'q')
    //     {
    //         cin>>c;
    //         infix_to_postfix(c, &stk);
    //     }
    // } while (c != 'q');

    for (int i = 0; exp[i] != '\0' ; i++)
    {
            infix_to_postfix(exp[i], &stk);
    }

    while (top_item(&stk) != '(')
    {
        cout<<pop(&stk);
    }



    return 0;
}

int precedence(char x)
{
    switch (x)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    }
}


void infix_to_postfix(char c, stack *stk)
{
    
    if (c == '(')
    {
        push(stk,'('); 
    }
    
    else if((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'))
    {
        int pr = precedence(c);

        while(precedence(top_item(stk)) >= pr)
        {
            cout<<pop(stk);
        } 
        push(stk,c);
    }
        
    
    else if(c == ')')
    {
        char item = pop(stk);
        while (item != '(')
        {
            cout<<item;
            item = pop(stk);
        }
    }
 
    else
        cout<<c;
    
}


void push(stack *stk, char item)
{
    if(stk->top != MAXSTK)
    {
        stk->data[stk->top] = item;
        stk->top += 1;
    }

    else
        cout<<"OVERFLOW\n";
}

char pop(stack *stk)
{
    char item;
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

char top_item(stack *stk)
{
    char item = stk->data[stk->top - 1];
    return item;
}