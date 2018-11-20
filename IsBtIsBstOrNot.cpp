#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *newNode(int val)
{
    node *new_node = new struct node;
    new_node->data = val;
    new_node->left = new_node->right = NULL;
}

bool isBstUtil(node *root,int min1,int max1)
{
    if(root == NULL)
    {
        return true;
    }
    if((root->data>min1 && root->data<max1) && isBstUtil(root->left,min1,root->data) && isBstUtil(root->right,root->data,max1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBinarySearchTree(node *root)
{
    return isBstUtil(root,INT_MIN,INT_MAX);
}

int main()
{
    node *root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    if(isBinarySearchTree(root))
    {
        cout<<"Binary Search Tree"<<endl;
    }
    else
    {
        cout<<"Not a binary search tree"<<endl;
    }
    return 0;
}
