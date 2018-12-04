#include<iostream>
using namespace std;
class stack
{
    int *arr;
    int top;
    int size;
    public:
    stack()
    {
        cout<<"Enter size"<<endl;
        cin>>size;
        arr=new int[size];
        top=-1;
    }
    void push(int val)
    {
        if(top>=size-1)
        {
            cout<<"Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=val;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            top--;
        }
    }
    void peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            cout<<arr[top]<<endl;
        }
    }
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    stack s1;
    s1.push(5);
    s1.push(6);
    s1.push(8);
    s1.push(9);
    s1.push(11);
    s1.display();
    s1.pop();
    s1.display();
    s1.peek();
}
