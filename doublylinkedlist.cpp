#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
};
class linkedlist
{
    node *start,*ptr,*ptr1;
    int i;
public:
    linkedlist()
    {
        start=NULL;
    }
    node *create_list(int val)
    {
        struct node *new_node=new struct node;
        new_node->prev=NULL;
        new_node->data=val;
        new_node->next=NULL;
        start=new_node;
        return new_node;
    }
    void insert_beg(int val)
    {
        if(start==NULL)
        {
            node *nn;
            nn=create_list(val);
            start=nn;
        }
        else
        {
            struct node *new_node=new struct node;
            new_node->data=val;
            new_node->next=start;
            start->prev=new_node;
            new_node->prev=NULL;
            start=new_node;
        }
        //cout<<"After inserting at beginning"<<endl;
    }
    void insert_end(int val)
    {
        if(start==NULL)
        {
            node *nn;
            nn=create_list(val);
            start=nn;
        }
        else
        {
            struct node *new_node=new struct node;
            new_node->data=val;
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            new_node->prev=ptr;
            ptr->next=new_node;
            new_node->next=NULL;
        }
        cout<<"After inserting at end list is :"<<endl;
    }
    void insert_at_pos(int val,int pos)
    {
        if(start==NULL)
        {
            node *nn;
            nn=create_list(val);
            start=nn;
        }
        else if(start->next==NULL)
        {
            insert_end(val);
        }
        else
        {
            i=0;
            if(i==pos-1)
            {
                insert_beg(val);
            }
            else
            {
                struct node *new_node=new struct node;
                new_node->data=val;
                ptr=start;
                ptr1=ptr;
                while(i!=pos-1)
                {
                    ptr1=ptr;
                    ptr=ptr->next;
                    i++;
                }
                new_node->prev=ptr1;
                new_node->next=ptr;
                ptr1->next=new_node;
                ptr->prev=new_node;
            }
        }
        cout<<"After inserting at specific location is :";
    }
    void display()
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
    }
};
int main()
{
    linkedlist l;
    l.create_list(5);
    l.display();
    l.insert_beg(11);
    l.display();
    //l.insert_end(8);
    //l.display();
    l.insert_at_pos(7,1);
    l.display();
}
