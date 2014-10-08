#include <bits/stdc++.h>
#include<cstdlib>
using namespace std;
int ans=1000000;
bool check=0;
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    void DFSUtil(int v, int endd, bool visited[],int old); // A function used by DFS
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void DFS(int v,int endd); // DFS traversal of the vertices reachable from v
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
Graph g1(100002);
Graph g2(100002);
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v,int endd, bool visited[],int oldcount)
{
// Mark the current node as visited and print it
    int ct=oldcount;
    //cout<<"current ct= "<<ct<<endl;
    visited[v] = true;
    //cout << v << " ";

// Recur for all the vertices adjacent to this vertex
   /*
   if(v==endd)
    {
        ans=ct;
        return;
    }*/
    list<int>::iterator i,start,endit;
    start=adj[v].begin();
    endit=adj[v].end();
    int flag=1;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(*i==endd)
        {
            flag=0;
            break;
        }
        if(!visited[*i])
        {
            flag=0;
            break;
        }
    }
   if((adj[v].empty()) || flag==1)
    {
        ct++;

        start=g2.adj[v].begin();
        endit=g2.adj[v].end();
        int fl=0;
        for(i = start; i != endit; ++i)
        {
            if(!visited[*i])
            {
                start=i;
                //cout<<"Reversing  "<<*start<<endl;
                break;
            }

        }
        if(i==endit)
        {
            ans=-1;
            return;
        }

    }
    for(i = start; i != endit; ++i)
    {

        if(*i==endd)
        {
            visited[endd]=true;
            //cout<<ct <<"  ans= "<<ans<<endl;
            if(ct<ans)
                ans=ct;
           //cout<<"Reached with "<<ans<<endl;
            if(check)
            return;
        }
        if(!visited[*i])
            {
               //cout<<"dfsing from  "<<v<<"  to  "<<*i<<endl;
                DFSUtil(*i,endd, visited,ct);
            }
    }
}

// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v,int endd)
{
// Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

// Call the recursive helper function to print DFS traversal
    DFSUtil(v,endd, visited,0);
}

int main()
{
// Create a graph given in the above diagram
    int v,e,e1,e2;
    //freopen("in","r",stdin);
    scanf("%d %d",&v,&e);
    //cout<<v<<" "<<e<<endl;
    for(int i=0; i<e; i++)
    {
        scanf("%d %d",&e1,&e2);
        //cout<<e1<<" "<<e2<<endl;
        g1.addEdge(e1, e2);
        //g2.addEdge(e1, e2);
        //g2.addEdge(e2, e1);
    }
    if(v==1)
    {
        printf("0\n");
        return 0;
    }
    check=1;
    if(e==0)
    {
        printf("-1\n");
        return 0;
    }
    g2.DFS(1,v);
    if(ans==1000000)
    {
        cout<<-1<<endl;
    }
    else
    {
        check=0;
        //cout<<"Reachable\n";
        ans=1000000;
    g1.DFS(1,v);
    cout<<ans<<endl;
    }
    return 0;
}
