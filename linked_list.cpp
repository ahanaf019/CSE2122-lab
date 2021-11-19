#include<stdio.h>
#include<iostream>

using namespace std;

class node
{
public:
    node *next;
    int data;
    node(int data);
};

node::node(int data)
{
    this->data = data;
    this->next = NULL;
}

void traverse(node* ptr);
void insert(int data, int pos, node** start);

int main()
{
    node* x1 = new node(1);
    node* x2 = new node(2);
    node* x3 = new node(5);
    node* x4 = new node(6);
    node* x5 = new node(8);
    x1->next = x2;
    x2->next = x3;
    x3->next = x4;
    x4->next = x5;

    node* head = x1;
    node* ptr;
    

    // insert(50,1, x1);
    traverse(x1);

    int pos = 5;
    node* n = new node(20);

    ptr = head;
    

    if (head->data > n->data)
    {
        n->next = head;
        head = n;
    }
    
    else
    {
        node *save;
        while(ptr->data <= n->data && ptr != NULL)
        {
            cout<<ptr->data<<" "<<n->data<<endl;
            save = ptr;
            if(ptr->next == NULL)
            {
                ptr = NULL;
                break;
            }
            ptr = ptr->next;
        }
        save->next = n;
        n->next = ptr;
    }
    ptr = head;
    
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }


    return 0;
}

void traverse(node* ptr)
{
    while (ptr != NULL)
        {
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
}

void insert(int data, int pos, node* start)
{
    node* x = new node(data);
    node* ptr = start;
    int count = 0;

    if(pos == 1)
    {
        x->next = start;
        start = x;

        // traverse(start);
    }

    while (ptr != NULL)
    {
        // cout<<count<<endl;
        if(count==(pos-2))
        {
            node* nn = ptr->next;
            ptr->next = x;
            x->next = nn;
            break;
        }
        // cout<<ptr->data<<endl;
        ptr = ptr->next;
        count++;
    }

}