import random
arr=[]

def sort_elm(arr):
    for i in range(n):
        for j in range (i+1,n):
            if(arr[j]<arr[i]):
                arr[i],arr[j]=arr[j],arr[i]
    
def display_elm(arr):
    for i in range(n):
        print(arr[i],end=" ")
    print(end="\n")



n=int(input("Enter the length of an array"))

for i in range(n):
    num=random.randrange(0,11,2)
    arr.append(num)

print("The orignal array is ")
display_elm(arr)
sort_elm(arr)
print("The array after sorting is")
display_elm(arr)


