#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *lchild=NULL;
    struct node *rchild=NULL;
}node;

node *head=NULL;

void insert_node(node **root);
void display(node *root);
void search_elm(node *root, int key);
void delete_elm(node **root, int key);
node* inorder_sxs(node *root);

int main()
{
    int c,elm;
    while(1)
    {
        cout<<"Enter 1 to insert, 2 to search, 3 to display in inorder traversal,4 to delete element"<<endl;
        cin>>c;
        switch(c)
        {
        case 1:
            insert_node(&head);
            break;
        case 2:
            cout<<"Enter the element you want to search: "<<endl;
            cin>>elm;
            search_elm(head,elm);
            break;
        case 3:
            cout<<"The BST in inorder traversal is: "<<endl;
            display(head);
            cout<<endl;
            break;
        case 4:
            cout<<"Enter the element you want to delete"<<endl;
            cin>>elm;
            delete_elm(&head,elm);
            break;

        default:
            continue;
        }
    }
}

void insert_node(node **root)
{
    int elm;
    cout<<"Enter the element you want to insert: "<<endl;
    cin>>elm;
    node *ptr,*trav,*temp;

    ptr= new node;
    ptr->data=elm;
    trav=*root;
    if(trav==NULL)
    {
        head=ptr;
        return;
    }
    while(trav!=NULL)
    {
        temp=trav;
        if(elm < trav->data)
            trav=trav->lchild;
        else if(elm > trav->data)
            trav=trav->rchild;
        else
        {
            cout<<"Duplicate value, violates BST so element cannot be added"<<endl;
            return;
        }
    }
    if(elm < temp->data )
        temp->lchild=ptr;
    if(elm > temp->data) 
        temp->rchild=ptr;
}
void search_elm(node *trav, int key)
{
    if(key < trav->data)
       search_elm(trav->lchild,key);
    if(key > trav->data)
        search_elm(trav->rchild,key);
    if(key==trav->data)
    {
       cout<<"Element found"<<endl;
       return;
    }
}

void display(node *trav)
{
    if(trav!=NULL)
    {
        display(trav->lchild);
        cout<<trav->data<<" ";
        display(trav->rchild);
    }
}

void delete_elm(node **root, int key)
{
    node *trail,*trav;
    trav=*root;
    trail=trav;
    while(trav!=NULL)
    {
        if(trav->data==key)
            break;
        trail=trav;
        if(key < trav->data)
            trav=trav->lchild;
        if(key > trav->data)
            trav=trav->rchild;
    }
    if(trav==NULL)
    {
        cout<<"Element not found"<<endl;
        return;
    }
    if(trav->data==key)
    {
        if(trav->lchild==NULL && trav->rchild==NULL)
        {
            if(head==trav)
            {
                head=NULL;
                free(trav);
                return;
            }
            if(trail->lchild!=NULL && trail->lchild->data==key)
                trail->lchild=NULL;
            if(trail->rchild!=NULL && trail->rchild->data==key)
                trail->rchild=NULL;
            free(trav);
            return;
        }
        if(trav->lchild==NULL && trav->rchild!=NULL)
        {
            if(head==trav)
            {
                head=trav->rchild;
                free(trav);
                return;
            }
            if(trail->rchild!=NULL && trail->rchild==trav)
                trail->rchild=trav->rchild;
            if(trail->lchild!=NULL && trail->lchild==trav)
                trail->lchild=trav->rchild;
            free(trav);
            return;
        }
        if(trav->lchild!=NULL && trav->rchild==NULL)
        {
            if(head==trav)
            {
                head=trav->lchild;
                free(trav);
                return;
            }
            if(trail->rchild!=NULL && trail->rchild==trav)
                trail->rchild=trav->lchild;
            if(trail->lchild!=NULL && trail->lchild==trav)
                trail->lchild=trav->lchild;
            free(trav);
            return;

        }
        if(trav->lchild!=NULL && trav->rchild!=NULL)
        {
            node *insxs;
            insxs=inorder_sxs(trav->rchild);
            trav->data=insxs->data;
            if(insxs->rchild!=NULL)
            {
                delete_elm(&head,insxs->rchild->data);
                return;
            }
            if(trav->rchild==insxs)
                trav->rchild=NULL;
            free(insxs);
            return;
        }
    }
    

}
node *inorder_sxs(node *trav)
{
    while(trav->lchild!=NULL)
        trav=trav->lchild;
    return trav;
}