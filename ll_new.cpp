#include<iostream>

using namespace std;

struct node{
    int info;
    struct node *next;
};

typedef struct node *nodeptr;

nodeptr getnode(void);
nodeptr insertnode(nodeptr ptr, int value);
void traverse(nodeptr ptr);
void insert_to_pos(nodeptr start,int pos, int data);
int find(nodeptr start, int item);
void delete_node(nodeptr start, int item);
int length(nodeptr start);
 
int main()
{
    int i, n, value;
    nodeptr start, ptr;
    ptr = start;

    do
    {
        cin>>n;
        if(n>=0) ptr = insertnode(ptr, n);
    } while (n>=0);
    ptr->next = NULL;
    // start = start->next;
    
    
    // insert_to_pos(start, 1, 400);
    traverse(start);
    cout<<endl;
    // cout<<find(start, 50)<<endl;
    delete_node(start, 5);
    traverse(start);
    return 0;
}

nodeptr getnode(void)
{
    nodeptr p;
    p = (nodeptr) malloc(sizeof(struct node));
    return p;
}

nodeptr insertnode(nodeptr ptr, int value)
{
    nodeptr q;
    q = getnode();
    q->info = value;
    ptr->next = q;
    return q;
}

void traverse(nodeptr start)
{
    nodeptr ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        cout<<ptr->info<<" ";    
    }
}

void insert_to_pos(nodeptr start,int pos, int data)
{
    nodeptr ptr = start;
    nodeptr q = getnode();
    q->info = data;
    
    if(pos <1)
    {
        return;
    }

    if(pos == 1)
    {
        q->next = ptr->next;
        ptr->next = q;
    }

    else
    {
        for (int i = 2; i <= pos; i++)
        {
            if(ptr->next == NULL)
                break;

            ptr = ptr->next;
        }
        q->next = ptr->next;
        ptr->next = q;   
    }   
}

int find(nodeptr start, int item)
{   
    int c = 0;
    nodeptr ptr = start;
    while(ptr != NULL)
    {
        if(ptr->info == item)
        {
            return c;
        }
        c++;
        ptr = ptr->next;        
    }
    return -1;
}

int length(nodeptr start)
{
    int c = 0;
    nodeptr ptr = start;
    while(ptr->next != NULL)
    {
        c++;
        ptr = ptr->next;
    }
    return c;
}

void delete_node(nodeptr start, int item)
{
    int loc = find(start, item);
    int size = length(start);

    if(loc == 1)
    {
        start = start->next;        
    }


}