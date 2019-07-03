/*This is an implementation of bfs using a adjacency matrix */
/*This implenetation is refered from the book - DS in depth */
#include<iostream>
#define initial 1
#define waiting 2
#define visited 3
#define MAX 20

int adj[MAX][MAX];  // global adjacency matrix
int state[MAX];     // this is an open addresing list, it represents the particular states of vertices.
int queue[MAX];     // global queue
int front =-1,rear =-1;
int n;               //number of vertices in the graph
void insert_queue(int vertex);
int delete_queue();
int isempty();
void create_graph(); // This is used to create a graph
void BFS(int v);     // bfs traversal, where v is the starting vertex
void bfs_trav();     // this is used to select the starting vertex

using namespace std;

int main()
{
    create_graph();
    bfs_trav();
}

void create_graph()
{
    int max_edges, origin, dest;
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    max_edges=n*(n-1);
    for(int i=1;i<=max_edges;i++)
    {
        cout<<"Enter edge -1,-1 to exit"<<endl;
        cin>>origin;
        cin>>dest;
        if((origin==-1) && (dest==-1))
            break;
        if((origin>=n) || (origin < 0) || (dest>=n) || (dest<0))
        {
            cout<<"Invalid edge"<<endl;
            i--;
        }
        else
        {
           adj[origin][dest]=1;
        }
        
    }

}
void bfs_trav()
{
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    cout<<"Enter the starting vertex of bfs"<<endl;
    cin>>v;
    BFS(v);
}

void BFS(int v)
{
    int i;
    insert_queue(v);
    state[v]=waiting;
    while(! isempty())
    {
        v=delete_queue();
        cout<<v<<" ";
        state[v]=visited;
        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                insert_queue(i);
                state[i]=waiting;
            }
        }
    }
    cout<<endl;

}

void insert_queue(int vertex)
{
    if(rear==MAX-1)
        cout<<"Queue overflow"<<endl;
    else
    {
        if((front ==-1))
            front=0;
        rear++;
        queue[rear]=vertex;
    }
      
}

int isempty()
{
    if(front ==-1 || front > rear)
        return 1;
    else
        return 0; 
}

int delete_queue()
{
    int del_item;
    if(front == -1 || front > rear)
    {
        cout<<"Queue underflow"<<endl;
        exit(1);
    }
    del_item=queue[front];
    front =front+1;
    return del_item;
}