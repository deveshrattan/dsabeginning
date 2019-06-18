class node:
    def __init__(self,data):
        self.data=data
        self.lchild=None
        self.rchild=None

class tree:
     
    def insert_node(self,root,new_node):
        if new_node.data < root.data :
            if root.lchild==None:
                root.lchild=new_node
            else:
                self.insert_node(root.lchild,new_node)
        if new_node.data >root.data :
            if root.rchild ==None:
                root.rchild=new_node
            else:
                self.insert_node(root.rchild,new_node)

    def display(self,root):
        if root :
            self.display(root.lchild)
            print(root.data,end=" ")
            self.display(root.rchild)

    def search_elm(self,root,key):
        if(root!=None):
            if key == root.data:
                print("Element found")
                return 1
            if key < root.data:
                self.search_elm(root.lchild,key)
            if key > root.data:
                self.search_elm(root.rchild,key)
        else:
            print("Element not found")





if __name__ == "__main__":
    obj = tree()
    n=int(input("Enter the number of elements you want to enter in the list: "))
    elm=int(input("Enter the element: "))
    r=node(elm)
    n-=1
    while(n!=0):
        elm=int(input("Enter the element: "))
        obj.insert_node(r,node(elm))
        n-=1
    print("The list is: ")
    obj.display(r)
    print("\n")
    while(1):
        elm=int(input("Enter the element you want to search: "))
        obj.search_elm(r,elm)
    



