//max heap implentation
#include<iostream>

#define SIZE 500
using namespace std;

void build_heap(int *arr, int n);
void heapify(int *arr, int i, int n);
void display(int *arr, int n);
void delete_root(int *arr, int& n);

int main()
{
    cout<<"Enter the number of elements you want to insert"<<endl;
    int n;
    cin>>n;
    int arr[SIZE];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%21;
    }
    cout<<"The orignal array is"<<endl;
    display(arr,n);
    build_heap(arr,n);
    cout<<"The array in form of a heap is"<<endl;
    display(arr,n);
    cout<<"Root is deleted"<<endl;
    delete_root(arr,n);
    cout<<"The new heap is"<<endl;
    display(arr,n);
}

void build_heap(int *arr, int n)
{
    int st=(n/2)-1;    // this is the index of the last non-leaf node

    for(int i=st ; i>=0; i--)
    {
        heapify(arr,i,n);
    }
}

void heapify(int *arr,int i, int n)
{
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;

    if(left < n && arr[left]> arr[largest])
        largest=left;

    if(right < n && arr[right]> arr[largest])
        largest=right;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
void display(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void delete_root(int *arr, int& n)
{
    int l_elm =arr[n-1];
    arr[0]=l_elm;
    n=n-1;
    heapify(arr,0,n);
}