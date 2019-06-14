
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50


void mergesort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
void display(int *arr);

int main()
{
    int arr[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        arr[i]=rand()%101;
    }
    display(arr);
    mergesort(arr,0,SIZE-1);
    display(arr);
}

void mergesort(int *arr, int l, int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void merge(int *arr, int l, int m, int r)
{   
     int i,j,k=l;
     int n1=m-l+1;
     int n2=r-m;
     int L[n1] , R[n2];  // temp arrays
     /*copy data to temp arrays*/
     for(i=0;i<n1;i++)
        L[i]=arr[l+i];
     for(j=0;j<n2;j++)
        R[j]=arr[m+j+1];
     i=0;
     j=0;
     k=l;
     while(i<n1 && j<n2)
     {
         if(L[i]<=R[j])
         {
             arr[k]=L[i];
             i++;
         }
         else
         {
            arr[k]=R[j];
            j++;
         }
         k++;
         
     }
     while(i<n1)
     {
         arr[k]=L[i];
         i++;
         k++;
     }
     while(j<n2)
     {
         arr[k]=R[j];
         j++;
         k++;
     }

}
void display(int *arr)
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",arr[i]);
    }
     printf("\n");
}