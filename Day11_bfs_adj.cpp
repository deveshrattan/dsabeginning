#include<iostream>
#include<list>
using namespace std;

class graph
{
    int numvertices;
    list<int> *adj;

    public:
    
    graph(int v);
    void add_edge(int src, int dest);
    void BFS(int s);
};

graph :: graph(int v)
{
    numvertices=v;
    adj= new list<int>[v];
}

void graph :: add_edge(int src, int dest)
{
    adj[src].push_back(dest);
}
void graph :: BFS(int s)
{
    bool * visited =new bool[numvertices];
    for(int i=0;i<numvertices;i++)
    {
        visited[i]=false;
    }
    list<int> queue;

    visited[s]=true;
    queue.push_back(s);
    list<int> :: iterator i;

    while(!queue.empty())
    {
        s =queue.front();
        cout<< s <<" ";
        queue.pop_front();

        for(i=adj[s].begin(); i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }

}
int main()
{
    graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 

    cout<<"Enter the starting vertex for bfs"<<endl;
    int key;
    cin>>key;
    cout<<"The bfs traversal from "<<key<<" is "<<endl;
    g.BFS(key);
    cout<<endl;


}