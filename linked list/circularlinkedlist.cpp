#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class linkedlist
{
    node *start,*ptr,*ptr1,*ptr2;
    int num;
public:
    linkedlist()
    {
        start=NULL;
    }
    void create_node(int val)
    {
        node *new_node=new struct node;
        new_node->data=val;
        if(start==NULL)
        {
            new_node->next=new_node;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=start;
        }
    }
    void insert_beg(int val)
    {
        struct node *new_node=new struct node;
        new_node->data=val;
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next=start;
        start=new_node;
        cout<<"After inserting value at beginning"<<endl;
    }
    void insert_after_given_node(int val)
    {
        struct node *new_node=new struct node;
        cout<<"Enter the value for node";
        cin>>num;
        new_node->data=num;
        ptr=start;
        ptr1=ptr;
        while(ptr1->data!=val)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->next=ptr1;
        cout<<"After insert value list is :";
    }
    void delete_beg()
    {
        ptr=start;
        ptr1=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr1->next;
        start=start->next;
        delete(ptr1);
        cout<<"After deleting at beginning list is :"<<endl;
    }
    void delete_end()
    {
        ptr=start;
        ptr1=ptr;
        while(ptr->next!=start)
        {
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=start;
        delete(ptr);
        cout<<"After deleting at last list is :"<<endl;
    }
    void delete_at_specific_position(int val)
    {
        ptr=start;
        ptr1=start;
        ptr2=start;
            while(ptr->data!=val)
            {
                ptr1=ptr;
                ptr=ptr->next;
            }
            if(start==ptr)
            {
                while(ptr2->next!=start)
                {
                    ptr2=ptr2->next;
                }
                start=ptr->next;
                ptr2->next=ptr1->next;
                delete(ptr);
            }
            else if(ptr->next==start)
            {
                ptr1->next=start;
                delete(ptr1);
            }
            else if(ptr==start)
            {
                delete(ptr);
                start=NULL;
            }
            else
            {
                ptr1->next=ptr->next;
                delete(ptr);
            }
        cout<<"After deleting at specific position is :"<<endl;
    }
    void display()
    {
        ptr=start;
        while(ptr->next!=start)
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
        l.create_node(5);
        l.create_node(7);
        l.create_node(12);
        l.create_node(17);
        l.display();
        l.insert_beg(3);
        l.display();
        //l.insert_after_given_node(7);
        //l.display();
        l.delete_beg();
        l.display();
        l.delete_end();
        l.display();
        l.delete_at_specific_position(12);
        l.display();
        l.delete_end();
        l.display();
        l.delete_at_specific_position(5);
        return 0;
    }
