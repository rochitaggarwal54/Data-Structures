#include<string.h>
#include<iostream>
using namespace std;
class stack
{
    int top,j,size1;
    char *arr;
    char *rev;
public:
    stack(int l)
    {
        size1=l;
        arr=new char[size1];
        rev=new char[size1];
        top=-1;
    }
    void push(char item)
    {
        if(top==size1-1)
        {
            cout<<"overflow"<<endl;
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
    char peek()
    {
        return arr[top];
    }
    int prec(char ch)
    {
        switch(ch)
        {
            case'+':
                return 1;
            case'-':
                return 1;
            case'*':
                return 2;
            case'/':
                return 2;
            case'^':
                return 3;
        }
        return -1;
    }
    void convert(char in[],char pre[],int l)
    {
        j=0;
        for(int i=l-1;i>=0;i--)         //reverse
        {
            rev[j]=in[i];
            j++;
        }
        int k=0;
        for(int i=0;i<j;i++)
        {
            if(rev[i]>='a' && rev[i]<='z' || rev[i]>='A' && rev[i]<='Z')
            {
                pre[++k]=rev[i];
            }
            else if(rev[i]==')')
            {
                push(rev[i]);
            }
            else if(rev[i]=='(')
            {
                while(peek()!=')' && top!=-1)
                {
                    pre[++k]=pop();
                }
                if(top==-1)
                {
                    cout<<"Invalid expression"<<endl;
                }
                pop();
            }
            else
            {
                while(top!=-1 && prec(rev[i])<=prec(peek()))
                {
                    pre[++k]=pop();
                }
                push(rev[i]);
            }
        }
        while(top!=-1)
        {
            pre[++k]=pop();
        }
        for(int i=k;i>=1;i--)
        {
            cout<<pre[i]<<" ";
        }
    }
};
int main()
{
    int l;
    //char in[]="(a-b)*(d/e)";
    char in[]="(a+b^d)/(e-f)+g";
    l=strlen(in);
    stack s(l);
    char pre[100];
    s.convert(in,pre,l);
    return 0;
}
