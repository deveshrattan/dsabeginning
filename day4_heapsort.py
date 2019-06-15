import random

def heapify(arr, n, i):
    largest = i
    l= 2*i+1
    r= 2*i+2
    if l<n and arr[l]>arr[largest]:
        largest = l
    if r<n and arr[r]>arr[largest]:
        largest = r
    if largest != i :
        arr[largest], arr[i]=arr[i],arr[largest]
        heapify(arr,n,largest)



def heapsort(arr):
    start=(n//2)-1
    for i in range(start,-1,-1):
        heapify(arr,n,i)
    for i in range(n-1,-1,-1):
        arr[i],arr[0]=arr[0],arr[i]
        heapify(arr,i,0)

def display(arr):
    for i in  range(n):
        print(arr[i],end=" ")
    print(end="\n")


if __name__ =="__main__":
    arr=[]
    n=int(input("Enter the size of the array: "))
    for i in range(n):
        arr.append(random.randrange(0,51,2))
    print("The array is: ")
    display(arr)
    heapsort(arr)
    print("The array after sorting is: ")
    display(arr)