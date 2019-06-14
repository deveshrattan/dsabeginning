#include<iostream>
#define SIZE 50
using namespace std;

void display(int *arr);
void quicksort(int *arr, int l, int r);
int partition(int *arr, int l, int r);

int main()
{
    int arr[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        arr[i]=rand()%101;
    }
    cout<<"The orignal array "<<endl;
    display(arr);
    quicksort(arr,0,SIZE-1);
    cout<<"The sorted array is "<<endl;
    display(arr);
}
void quicksort(int *arr, int l, int r)
{
    if(l<r)
    {
       int p= partition(arr, l,r);
       quicksort(arr, l, p-1);
       quicksort(arr,p+1, r);
    }
}

int partition(int *arr, int l, int r)
{
    int pivot =arr[r];
    int i=l;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(arr[j],arr[i]);
            i++;
        }
    }
    swap(arr[i],arr[r]);
    return i;
    
}
void display(int *arr)
{
    for(int i=0;i<SIZE;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}