#include<iostream>
using namespace std;



typedef struct node{
    int info;
    struct node *next;
}node;

void insert_elm(node **start);
void search_elm(node *start);
void delete_elm(node **start);
void display(node *start);

node *head=NULL;


int main()
{
    while(1)
    {
        int c;
        cout<<"Enter 1 to insert element, 2 to search element, 3 to delete element, 4 to display list"<<endl;
        cin>>c;
        switch(c)
        {
            case 1:
                insert_elm(&head);
                break;
            case 2:
                search_elm(head);
                break;
            case 3:
                delete_elm(&head);
                break;
            case 4:
                display(head);
                break;
            default:
                cout<<"wrong choice, choose again"<<endl;
                continue;
        }
    }
}

void insert_elm(node **start)   // this fxn will insert the element at the begining of the list
{
    int n;
    cout<<"Enter the element you want to insert: "<<endl;
    cin>>n;
    node *ptr;
    ptr=new node;
    ptr->info=n;
    ptr->next=*start;
    *start=ptr;
}
void display(node *start)
{
    while(start!=NULL)
    {
        cout<<start->info<<" ";
        start=start->next;
    }
    cout<<endl;
}

void search_elm(node *start)
{
    int elm;
    cout<<"Enter the number you want to search "<<endl;
    cin>>elm;
    while(start!=NULL)
    {
        if(elm==start->info)
        {
            cout<<"element found "<<endl;
            return;
        }
        start=start->next;
    }
    cout<<"element not found "<<endl;
}

void delete_elm(node **start)
{
    int elm;
   
    display(head);
    cout<<"Enter the element you want to delete from the above list: "<<endl;
    cin>>elm;
    node *trp,*ptr;
    ptr=*start;
    trp=ptr;
    while(ptr!=NULL)
    {
        if(elm==ptr->info)
        {
           
            trp->next=ptr->next;
            if(head==ptr)
                head=ptr->next;
            free(ptr);
            cout<<"The new list is: "<<endl;
            display(head);
            return;
        }
        trp=ptr;
        ptr=ptr->next;
       
    }
    cout<<"Element was not in the list, enter a element from the list "<<endl;
}