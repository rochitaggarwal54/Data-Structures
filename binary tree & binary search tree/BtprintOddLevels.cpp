#include<queue>
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
void printOdd(node *root)
{
    if(root == NULL)
    {
        return;
    }
    queue<node *>q;
    q.push(root);
    bool isOdd = true;
    while(1)
    {
        int nodeCount = q.size();
        if(nodeCount == 0)
        {
            break;
        }
        while(nodeCount>0)
        {
            node *nod = q.front();
            if(isOdd)
            {
                cout<<nod->data<<" ";
            }
            q.pop();
            if(nod->left!=NULL)
            {
                q.push(nod->left);
            }
            if(nod->right!=NULL)
            {
                q.push(nod->right);
            }
            nodeCount--;
        }
        isOdd = !isOdd;
    }
}
int main()
{
    node *root = NULL;
    root = insert1(root,6);
    root = insert1(root,4);
    root = insert1(root,8);
    root = insert1(root,2);
    root = insert1(root,5);
    root = insert1(root,7);
    printOdd(root);
    return 0;
}
