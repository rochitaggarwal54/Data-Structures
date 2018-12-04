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

bool isSubtreeLesser(node *root,int val)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data<=val && isSubtreeLesser(root->left,val) && isSubtreeLesser(root->right,val))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSubtreeGreater(node *root,int val)
{
    if(root == NULL)
    {
        return true;
    }
    if(root->data>val && isSubtreeGreater(root->right,val) && isSubtreeGreater(root->right,val))
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
    if(root == NULL)
    {
        return true;
    }
    if(isSubtreeLesser(root->left,root->data) && isSubtreeGreater(root->right,root->data) && isBinarySearchTree(root->left) && isBinarySearchTree(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
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
