#include<iostream>
#include<cmath>

using namespace std;

const int MAXSTK = 25;

struct stack
{
    int top = 0;
    char data[MAXSTK];
};

struct int_stack{
    int top = 0;
    int data[MAXSTK];
};

void push(int_stack *stk, char item);
void push(stack *stk, char item);
int pop(int_stack *stk);
char pop(stack *stk);
void postfix_eval(char chs[], stack *stk);
char top_item(stack *stk);
int precedence(char c);
void infix_to_postfix(char exp[]);


int main()
{
    char exp[20] = "1+(2*3-(8/2^3)*7)*4";
    // char exp[20] = "5*(6+2)-8/4";
    
    infix_to_postfix(exp);
    return 0;
}


void push(stack *stk, char item)
{
    if(stk->top >= MAXSTK)
    {
        cout<<"OVERFLOW\n";
    }

    else
    {
        stk->data[stk->top] = item;
        stk->top += 1;
    }


}

char pop(stack *stk)
{
    if(stk->top <= 0)
    {
        cout<<"UNDERFLOW\n";
        return -1;
    }
    
    stk->top -= 1;
    return stk->data[stk->top];
}

char top_item(stack *stk)
{
    char item = stk->data[stk->top - 1];
    return item;
}

void postfix_eval(char chs[])
{
    int p,q;
    int m,n;
    cout<<endl;
    // stack stk;
    int_stack stk;
    for (int i = 0; chs[i] != '\0'; i++)
    {
        cout<<"->"<<chs[i]<<endl;

        switch (chs[i])
        {
        case '+':
            p = pop(&stk);
            q = pop(&stk);
            m = p;
            n = q;
            cout<<"====>"<<n+m<<endl;
            push(&stk, (n+m));
            break;
        case '-':
            p = pop(&stk);
            q = pop(&stk);
            m = p;
            n = q;
            cout<<"====>"<<n-m<<endl;
            push(&stk, (n-m));
            break;
        case '*':
            p = pop(&stk);
            q = pop(&stk);
            m = p;
            n = q;
            cout<<n<<" "<<m<<endl;
            cout<<"====>"<<n*m<<endl;
            push(&stk, (n*m));
            break;
        case '/':
            p = pop(&stk);
            q = pop(&stk);
            m = p;
            n = q;
            cout<<"====>"<<n/m<<endl;
            push(&stk, (n/m));
            break;
        case '^':
            p = pop(&stk);
            q = pop(&stk);
            m = p;
            n = q;
            cout<<"====>"<<pow(n,m)<<endl;
            push(&stk, (pow(n,m)));
            break;
        default:
            int x = chs[i] - '0';
            push(&stk, x);
            break;
        }
    }
    
    // return pop(stk);
}

int precedence(char c)
{
    if((c == '+') || (c == '-'))
        return 1;

    else if((c == '/') || (c == '*'))
        return 2;
    else if(c == '^')
        return 3;
    else return 0;
}

void infix_to_postfix(char exp[])
{
    stack result;
    stack stk;
    push(&stk, '(');
    for(int i = 0; exp[i] != '\0'; i++)
    {
        // cout<<i<<endl;
        char c = exp[i];

        if(c == '(')
        {
            push(&stk, '(');
        }

        else if((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='^'))
        {
            int pre = precedence(c);

            while(precedence(top_item(&stk)) >= pre)
            {
                push(&result, pop(&stk));
            }
            push(&stk, c);
        }

        else if(c == ')')
        {
            char item;
            do
            {
                item = pop(&stk);
                if(item != '(')
                    push(&result, item);
            } while (item != '(');
            
            
        }

        else
        {
            push(&result, c);
        }
    }

    while(top_item(&stk) != '(')
    {
        push(&result, pop(&stk));
    }
    int i; 
    char arr[40];
    for(i = 0; i < result.top; i++)
    {
        arr[i] = result.data[i];
        cout<<result.data[i];
    }
        
    arr[i] = '\0';


    postfix_eval(arr);
}

void push(int_stack *stk, char item)
{
    if(stk->top >= MAXSTK)
    {
        cout<<"OVERFLOW\n";
    }

    else
    {
        stk->data[stk->top] = item;
        stk->top += 1;
    }


}

int pop(int_stack *stk)
{
    if(stk->top <= 0)
    {
        cout<<"UNDERFLOW\n";
        return -1;
    }
    
    stk->top -= 1;
    return stk->data[stk->top];
}