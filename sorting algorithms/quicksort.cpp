//Program to implement quick sort

#include<iostream>
using namespace std;

class Quick_sort
{
    public:
    int pivot,curr,index;

    int divide(int arr[],int low,int high)
    {
        pivot=high;
        int i=0;
        curr=low;
        index=low;

        while(curr!=pivot)
        {

            if(arr[curr]>arr[pivot])
            {
                curr++;
            }
            else
            {
                int temp=arr[curr];
                arr[curr]=arr[index];
                arr[index]=temp;
                 curr++;
                index++;
            }
            i++;
        }
         int t=arr[pivot];
            arr[pivot]=arr[index];
            arr[index]=t;
        return index;
    }

    void quick_sort(int arr[],int low,int high)
    {
        int indx;
        if(arr[low]<arr[high])
        {
            indx=divide(arr,low,high);
            quick_sort(arr,low,indx-1);
            quick_sort(arr,indx+1,high);
        }
    }
};

int main()
{
    Quick_sort qs;
    int arr[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }

    qs.quick_sort(arr,0,4);
    cout<<"\n\n";
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
}
