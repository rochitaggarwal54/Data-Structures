#include<iostream>
using namespace std;
struct node
{
    int vertex;
    struct node *next;
};
void create_graph(struct node *adj[],int no_of_nodes)
{
    int n,val;
    struct node *new_node,*last;
    for(int i=0;i<no_of_nodes;i++)
    {
        last = NULL;
        cout<<"Enter the number of neighbours of "<<i<<endl;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cout<<"Enter the neighbour"<<j<<" of "<<i<<endl;
            cin>>val;
            new_node = new struct node;
            new_node->vertex = val;
            new_node->next = NULL;
            if(adj[i] == NULL)
            {
                adj[i] = new_node;
            }
            else
            {
                last->next = new_node;
            }
            last = new_node;
        }
    }
}
void display_graph(struct node *adj[],int no_of_nodes)
{
    struct node *ptr;
    for(int i=0;i<no_of_nodes;i++)
    {
        ptr = adj[i];
        cout<<"The neighbours of node are "<<i<<endl;
        while(ptr!=NULL)
        {
            cout<<ptr->vertex<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}
void delete_graph(struct node *adj[],int no_of_nodes)
{
    struct node *ptr,*temp;
    for(int i=0;i<no_of_nodes;i++)
    {
        ptr = adj[i];
        while(ptr!=NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            delete(temp);
        }
        adj[i] = NULL;
    }
}
int main()
{
    struct node *adj[10];
    int no_of_nodes;
    cout<<"Enter the number of nodes"<<endl;
    cin>>no_of_nodes;
    for(int i=0;i<no_of_nodes;i++)
    {
        adj[i] = NULL;
    }
    create_graph(adj,no_of_nodes);
    display_graph(adj,no_of_nodes);
    delete_graph(adj,no_of_nodes);
    return 0;
}
