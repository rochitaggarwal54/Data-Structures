#include<iostream>
using namespace std;
int hash(int key,int n,int i)
{
    return ((key%n)+i)%n;
}
int lp(int a[],int key,int n)
{
    int loc = hash(key,n,0);
    if(a[loc] == 0)
    {
        return loc;
    }
    else
    {
        for(int i=1;i<n;i++)
        {
            loc = hash(key,n,i);
            if(a[loc]==0)
            {
                break;
            }
        }
        return loc;
    }
}
int main()
{
    int n,loc;
    cout<<"Enter size of table"<<endl;
    cin>>n;
    int table[n] = {0};
    int x,key;
    cout<<"Enter no.of keys"<<endl;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>key;
        loc = lp(table,key,n);
        table[loc] = key;
    }
    for(int i=0;i<n;i++)
    {
        cout<<table[i]<<endl;
    }
    return 0;
}
