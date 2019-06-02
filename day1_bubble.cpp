#include<iostream>
using namespace std;

void bubble_sort(int *arr);
void display(int *arr);

int main()
{
    
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=rand()%11;
    }
    cout<<"The array before sorting is"<<endl;
    display(arr);
    bubble_sort(arr);
    

}
void display(int *arr)
{
    //int l=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<"\t";
    }
cout<<endl;
}
void bubble_sort(int *arr)
{
    int temp;
    int l=10;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<l-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"The array after sorting is"<<endl;
    display(arr);
    
}
