#include<iostream>

using namespace std;

struct node{
    char data;
    node *left;
    node *right;
};

typedef struct node *nodeptr;

nodeptr create_node(char data);
void preorder(node* x);
void postorder(node* x);
void inorder(node* x);

int main()
{
    node* a = create_node('a');
    node* b = create_node('b');
    node* c = create_node('c');
    node* d = create_node('d');
    node* e = create_node('e');
    node* f = create_node('f');
    node* g = create_node('g');
    node* h = create_node('h');
    node* i = create_node('i');
    node* j = create_node('j');
    node* k = create_node('k');
    node* l = create_node('l');
    node* m = create_node('m');
    node* n = create_node('n');

    a->left = b;
    a->right = i;
    b->left = c;
    b->right = d;
    c->left = e;
    d->left = f;
    d->right = g;
    g->right = h;
    i->left = j;
    i->right = k;
    k->left = l;
    k->right = m;
    j->right = n;

    preorder(a);
    cout<<endl;
    inorder(a);
    cout<<endl;
    postorder(a);
    cout<<endl;

    return 0;
}

nodeptr create_node(char data)
{
    node* n = (struct node*)malloc(sizeof(struct node*));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(node* x)
{
    cout<<x->data;
    if(x->left != NULL)
        preorder(x->left);
    if(x->right != NULL)
        preorder(x->right);
}

void inorder(node* x)
{
    if(x->left != NULL)
        inorder(x->left);
    cout<<x->data;
    if(x->right != NULL)
        inorder(x->right);
}

void postorder(node* x)
{
    if(x->left != NULL)
        postorder(x->left);
    if(x->right != NULL)
        postorder(x->right);
    cout<<x->data;    
}