import random

def mergesort(arr):
    if len(arr)>1:
        mid =len(arr)//2
        L=arr[:mid]
        R=arr[mid:]

        mergesort(L)
        mergesort(R)

        i=j=k=0
        while i<len(L) and j<len(R):
            if L[i]<R[j]:
                arr[k]=L[i]
                i+=1
            else:
                arr[k]=R[j]
                j+=1
            k+=1
        
        while i<len(L):
            arr[k]=L[i]
            i+=1
            k+=1
        while j<len(R):
            arr[k]=R[j]
            j+=1
            k+=1


def display(arr):
    for i in range(n):
        print(arr[i],end=" ")
    print(end="\n")

if __name__=='__main__':
    n=int(input("Enter the lenght of an array"))
    arr=[]
    for i in range(n):
        arr.append(random.randrange(0,51,2))
    print("The orignal array is ")
    display(arr)
    mergesort(arr)
    print("The sorted array is ")
    display(arr)