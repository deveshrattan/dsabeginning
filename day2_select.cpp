#include<iostream>
using namespace std;

void selection_sort(int *arr);
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
    selection_sort(arr);
    

}
void display(int *arr)
{
    
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<"\t";
    }
cout<<endl;
}
void selection_sort(int *arr)
{
    int min;
    for(int i=0;i<10;i++)
    {
        min=arr[i];
        for(int j=i+1;j<10;j++)
        {
            if(arr[j]<arr[i])
            {
                swap(arr[j],arr[i]);
            }
        }
    }
    cout<<"The array after sorting is"<<endl;
    display(arr);
    
}
