#include<string.h>
#include<iostream>
using namespace std;
class stack
{
    int top,size1;
    int *arr;
public:
    stack(int l)
    {
        size1=l;
        top=-1;
        arr=new int[size1];
    }
    void push(char item)
    {
        if(top==size1-1)
        {
            cout<<"Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=item;
        }
    }
    char pop()
    {
        char temp;
        temp=arr[top];
        top--;
        return temp;
    }
    void evaluate(char post[],int l)
    {
        int a,b;
        int res=0;
        for(int i=0;i<l;i++)
        {
            if(isdigit(post[i]))
            {
                push(post[i]-'0');
            }
            else if(post[i]=='+')
            {
                b=pop();
                a=pop();
                res=a+b;
                //cout<<res<<endl;
                push(res);
            }
            else if(post[i]=='-')
            {
                b=pop();
                a=pop();
                res=a-b;
                //cout<<res<<endl;
                push(res);
            }
            else if(post[i]=='*')
            {
                b=pop();
                a=pop();
                res=a*b;
                //cout<<res<<endl;
                push(res);
            }
            else if(post[i]=='/')
            {
                b=pop();
                a=pop();
                res=a/b;
                //cout<<res<<endl;
                push(res);
            }
        }
        cout<<res<<endl;
    }
};
int main()
{
    int l;
    char post[]="934*8+4/-";
    l=strlen(post);
    stack s(l);
    s.evaluate(post,l);
    return 0;
}
