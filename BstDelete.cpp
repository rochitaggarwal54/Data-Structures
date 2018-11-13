#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *get_new_node(int data)
{
    node *new_node = new struct node();
    new_node->data = data;
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
    else
    {
        root->right = insert1(root->right,data);
    }
    return root;
}
node *FindMin(node *root)
{
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}
node *delete1(node *root,int data)
{
    if(root == NULL)
    {
        return root;
    }
    else if(data<root->data)
    {
        root->left = delete1(root->left,data);
    }
    else if(data>root->data)
    {
        root->right = delete1(root->right,data);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = delete1(root->right,temp->data);
        }
    }
    return root;
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
    root = insert1(root,5);
    root = insert1(root,10);
	root = insert1(root,3);
	root = insert1(root,4);
	root = insert1(root,1);
	root = insert1(root,11);
    root = delete1(root,5);
    inorder(root);
    return 0;
}
