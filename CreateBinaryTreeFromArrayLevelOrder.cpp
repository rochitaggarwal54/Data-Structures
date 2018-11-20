#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node * create_new_node(int val)
{
    node *new_node = new struct node;
    new_node->data = val;
    new_node->left = new_node->right = NULL;
    return new_node;
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

node *insertLevelOrder(int arr[],node *root,int i,int n)
{
    if(i<n)
    {
        node *temp = create_new_node(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr,root->left,2*i+1,n);
        root->right = insertLevelOrder(arr,root->right,2*i+2,n);
    }
    return root;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    node* root = insertLevelOrder(arr, root, 0, n);
    inorder(root);
}
