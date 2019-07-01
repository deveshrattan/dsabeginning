// basic implementation of hashing

#include<iostream>
using namespace std;
#define SIZE 50

void hash_elm(int key,int* arr);
void search_elm(int key, int *arr);

int main()
{
    int n,elm,arr[SIZE];
    cout<<"enter the number of elements you want to enter"<<endl;
    cin>>n;
    for(int i=0;i<SIZE;i++)
    {
        arr[i]=-1;
    }
    while(n--)
    {
        cout<<"enter element"<<endl;
        cin>>elm;
        hash_elm(elm,arr);

    }
   while(1)
   {
       cout<<"Enter the elemnt you want to search"<<endl;
       cin>>elm;
       search_elm(elm,arr);
   }

}

void hash_elm(int key,int *arr)
{
    int pos,flag=0;
    pos=key%(SIZE);
    while(arr[pos]!=-1 && flag<2)
    {
        if(pos==SIZE-1)
        {
            pos=-1;
            flag++;
        }
        pos++;
    }
    if(arr[pos]==-1)
    {
        arr[pos]=key;
    }
    else
    {
        cout<<"Element cannot be inserted as array is full"<<endl;
    }
    
   
}
void search_elm(int key,int *arr)
{
    int pos=key%(SIZE);
    int flag=0;
    while(arr[pos]!=key && flag<2)
    {
        if(pos==SIZE-1)
        {
            pos=-1;
            flag++;
        }
        pos++;
    }
    if(arr[pos]==key)
    {
        cout<<"Element found"<<endl;
    }
    else
    {
        cout<<"element not found"<<endl;
    }
    
}