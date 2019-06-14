import random

def partition(arr, low ,high):
    pivot=arr[high]
    i=low
    for j in range(i,high):
        if (arr[j]<=pivot):
            arr[j],arr[i]=arr[i],arr[j]
            i+=1
    arr[i],arr[high]=arr[high],arr[i]
    return i

def quicksort(arr, low, high):
    if(low<high):
        p=partition(arr,low,high)
        quicksort(arr,low,p-1)
        quicksort(arr,p+1,high)



def display(arr):
    for i in range(n):
        print(arr[i],end=" ")
    print(end="\n")


if __name__=="__main__":
    arr=[]
    n=int(input("Enter the lenght of an array "))
    for i in range(n):
        arr.append(random.randrange(0,101,2))
    print("The orignal array is ")
    display(arr)
    quicksort(arr,0,n-1)
    print("The array after sorting is ")
    display(arr)