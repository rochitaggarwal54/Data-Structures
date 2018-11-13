#include<iostream>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};
node *get_new_node(char data)
{
    node *new_node = new struct node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
node *insert1(node *root,char data)
{
    if(root == NULL)
    {
        root = get_new_node(data);
    }
    else if(data<=root->data)
    {
        root->left = insert1(root->left,data);
    }
    else
    {
        root->right = insert1(root->right,data);
    }
    return root;
}
void preorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void inorder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
    node *root = NULL;
    root = insert1(root,'M');
    root = insert1(root,'B');
    root = insert1(root,'Q');
    root = insert1(root,'Z');
    root = insert1(root,'A');
    root = insert1(root,'C');
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    return 0;
}
