#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *get_new_node(int val)
{
    node *new_node = new struct node;
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node *insert1(node *root,int data)
{
    if(root == NULL)
    {
        root = get_new_node(data);
    }
    else if(data<=root->data)
    {
        root->left = insert1(root->left,data);
    }
    else if(data>root->data)
    {
        root->right = insert1(root->right,data);
    }
    return root;
}

node *lowestCommonAncestor(int n1,int n2,node *root)
{
    while(root!=NULL)
    {
        if(root->data>n1 && root->data>n2)
        {
            root = root->left;
        }
        else if(root->data<n1 && root->data<n2)
        {
            root = root->right;
        }
        else
        {
            break;
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    root = insert1(root,15);
    root = insert1(root,10);
    root = insert1(root,20);
    root = insert1(root,25);
    root = insert1(root,8);
    root = insert1(root,12);
    node *p = lowestCommonAncestor(10,20,root);
    cout<<p->data;
    return 0;
}
