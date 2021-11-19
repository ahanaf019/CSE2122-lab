#include<iostream>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

void inorder(node* x);
node* create_node(int data);
node* insert_to_bst(node *head, int data);


int main()
{
    node *head = NULL;
    
    head = insert_to_bst(head, 50);
    insert_to_bst(head, 30);
    insert_to_bst(head, 20);
    insert_to_bst(head, 40);
    insert_to_bst(head, 70);
    insert_to_bst(head, 60);
    insert_to_bst(head, 80);

    inorder(head);
    return 0;
}

node* create_node(int data)
{
    node* n = (node*)malloc(sizeof(node*));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insert_to_bst(node *head, int data)
{
    if(head == NULL)
    {   
        return create_node(data);
    }


    if(data < head->data)
    {
        head->left = insert_to_bst(head->left, data);
    }
    else
    {
        head->right = insert_to_bst(head->right, data);
    }
}

void inorder(node* x)
{
    if(x->left != NULL)
        inorder(x->left);
    cout<<x->data<<" ";
    if(x->right != NULL)
        inorder(x->right);
}