#include<iostream>
#define SIZE 30
using namespace std;

void heapsort(int *arr, int n);
void heapify(int *arr, int n, int i);
void display(int *arr);

int main()
{
    int arr[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        arr[i]=rand()%51;
    }
    cout<<"The array is:"<<endl;
    display(arr);
    heapsort(arr,SIZE);
    cout<<"The array after sorting is "<<endl;
    display(arr);
}

void display(int *arr)
{
    for(int i=0;i<SIZE;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void heapsort(int *arr, int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void heapify(int *arr, int n, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest])
    {
        largest=l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}