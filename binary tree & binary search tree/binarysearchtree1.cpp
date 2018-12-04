#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
node* get_new_node(int data)
{
    node *new_node = new struct node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}
node* insert1(node* root,int data)
{
    if(root==NULL)
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
bool search(node* root,int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data<=root->data)
    {
        return search(root->left,data);
    }
    else
    {
        return search(root->right,data);
    }
}
int main()
{
    node* root = NULL;
    root = insert1(root,15);
    root = insert1(root,10);
    root = insert1(root,20);
    root = insert1(root,25);
    root = insert1(root,8);
    root = insert1(root,12);
    int num;
    cout<<"Enter number to be searched"<<endl;
    cin>>num;
    if(search(root,num) == true)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
}
