class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class lklist:
    def __init__(self):
        self.head=None

    def push(self,new_data):
        new_node=node(new_data)
        new_node.next=self.head
        self.head=new_node

    def display(self):
        temp=self.head
        while(temp):
            print(temp.data,end=" ")
            temp=temp.next
        print("\n")

    def delete_elm(self,num):
        temp=self.head
        tpr=temp
        while(temp):
            if num==temp.data :
                tpr.next=temp.next
                if self.head == temp:
                    self.head=temp.next
                self.display()
                return
            tpr=temp
            temp=temp.next
                
        print("Element is not present in the list\n")


   


if __name__ =="__main__":
    obj = lklist()
    n=int(input("Enter the number of elements you want to enter in the list: "))
    while(n!=0):
        elm=int(input("Enter the element: "))
        obj.push(elm)
        n-=1
    print("The list is: ")
    obj.display()
    obj.delete_elm(3)
