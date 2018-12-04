#include<iostream>
using namespace std;
class queue
{
    int *arr,l,front,rear;
public:
    queue(int size)
    {
        l=size;
        arr=new int[l];
        front=-1;
        rear=-1;
    }
    void insert1(int val)
    {
        if((rear+1)%l==front)
        {
            cout<<"Overflow"<<endl;
        }
        else if(front==-1 && rear==-1)
        {
            front=rear=0;
            arr[rear]=val;
        }
        else
        {
            rear=(rear+1)%l;
            arr[rear]=val;
        }
    }
    void delete1()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"queue is empty"<<endl;
        }
        else if(front==rear)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            front=(front+1)%l;
        }
    }
    void display()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    queue q(3);
    q.insert1(2);
    q.insert1(3);
    q.display();
    q.delete1();
    q.display();
}
