#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *lchild=NULL;
    struct node *rchild=NULL;
    int bfac;
}node;



void insert_elm(node *root,node *trail,int key);
void check_bal(node *root,int key);
node* newnode(int key);
void left_rotate(node *root);
void right_rotate(node *root);
void display(node *root);         //displays in inorder
int  bfac_node(node *root);      //to find the balance factor

int main()
{
    int c;
    cout<<"Enter the root"<<endl;
    node *head;
    cin>>c;
    head=newnode(c);
    while(1)
    {
        cout<<"Enter 1 to insert,2 to display"<<endl;
        cin>>c;
        switch(c)
        {
            case 1:
            int elm;
            cout<<"Enter the element you want to insert"<<endl;
            cin>>elm;
            insert_elm(head,head,elm);
            break;
            case 2:
            display(head);
            cout<<endl;
            break;
            default:
            cout<<"Wrong choice"<<endl;
            continue;
        }
    }
}
node* newnode(int key)
{
    node *ptr;
    ptr=new node;
    ptr->data=key;
    ptr->bfac=0;
    return ptr;
}
void insert_elm(node *root,node *trail,int key)
{
   
    if(root->lchild==NULL && key<root->data)  //base case
    {
        root->lchild=newnode(key);
        if(trail!=NULL)
        check_bal(trail,key);
        return;
    }
    if(root->rchild==NULL && key>root->data)   //base case
    {
        root->rchild=newnode(key);
        if(trail!=NULL)
        check_bal(trail,key);
        return;
    }
    if(key<root->data)
    {
        insert_elm(root->lchild,root,key);
    }
    if(key>root->data)
    {
        insert_elm(root->rchild,root,key);
    }
    if(key==root->data)
    {
        cout<<"Duplicate value, not allowed"<<endl;
        return;
    }
    trail=root;
    
}
void check_bal(node *root,int key)
{
    int bal=bfac_node(root);
   
    if(bal>1 && key<root->lchild->data)  //left left rotate case
    {
        right_rotate(root);
    }
    if(bal>1 && key>root->lchild->data)    //left right case
    {
        left_rotate(root->lchild);
        right_rotate(root);
    }
    if(bal<-1 && key>root->rchild->data)  //right right rotate case
    {
        left_rotate(root);
    }
    if(bal<-1 && key<root->rchild->data)  //right lft rotate case
    {
        right_rotate(root->rchild);
        left_rotate(root);
    }
}
int height(node *root)
{
    int l,r;
    if(root==NULL)
        return 0;
    l=height(root->lchild);
    r=height(root->rchild);
    if(l>r)
        return 1+l;
    else
        return 1+r;
    

}

int bfac_node(node *root)
{
    int lheight,rheight;
    lheight=height(root->lchild);
    rheight=height(root->rchild);

    return (lheight-rheight);
}

void display(node *root)
{
    if(root!=NULL)
    {
        display(root->lchild);
        cout<<root->data<<" ";
        display(root->rchild);
    }
}
void left_rotate(node *root)
{
    int store=root->data;
    node *temp=root->rchild;
    root->rchild=temp->rchild;
    temp->rchild=temp->lchild;
    temp->lchild=root->lchild;
    root->lchild=temp;
    root->data=temp->data;
    temp->data=store;
}
void right_rotate(node *root)
{
    cout<<"i was here"<<endl;
    int store=root->data;
    node *temp=root->lchild;
    root->lchild=temp->lchild;
    temp->lchild=temp->rchild;
    temp->rchild=root->rchild;
    root->rchild=temp;
    root->data=temp->data;
    temp->data=store;
}