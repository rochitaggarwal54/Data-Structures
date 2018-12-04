#include<string.h>
#include<iostream>
using namespace std;
class stack
{
    int top,k;
    char *arr;
public:
    stack(int l)
    {
        k=l;
        top=-1;
        arr=new char[l];
    }
    void push(char item)
    {
        if(top==k-1)
        {
            cout<<"Underflow"<<endl;
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
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" "<<endl;
        }
    }
    void convert(char in[],char post[],int l)
    {
        int j=0;
        for(int i=0;i<l;i++)
        {
            if(in[i]>='a' && in[i]<='z' || in[i]>='A' && in[i]<='Z')
            {
                post[++j]=in[i];
                //j++;
            }
            else if(in[i]=='(')
            {
                push(in[i]);
            }
            else if(in[i]==')')
            {
                while(peek()!='(' && top!=-1)
                {
                    post[++j]=pop();
                    //j++;
                }
                if(top==-1)
                {
                    cout<<"Invalid expression"<<endl;
                    //exit(1);
                }
                pop();
            }
            else
            {
                while(top!=-1 && prec(in[i])<=prec(peek()))
                {
                    post[++j]=pop();
                    //j++;
                }
                push(in[i]);
            }
        }
        while(top!=-1)
        {
            post[++j]=pop();
            //j++;
        }
        post[++j]='\0';
        for(int i=1;i<=j;i++)
        {
            cout<<post[i]<<" ";
        }
    }
};
int main()
{
    int l;
    //char in[]={'a','+','(','b','*','c','-','(','d','/','e','^','f',')',')','*','g',')','*','h'};
    //char in[]={'a','*','(','b','+','c',')','/','d'};
    char in[]="a*(b+c)/d";
    //char in[]={'a','*','(','b','+','d',')','/','e','-','f','*','(','g','+','h','/','k',')'};
    l=strlen(in);
    stack s(l);
    char post[101];
    s.convert(in,post,l);
    return 0;
}
