#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph
{
public:
    int V;
    Graph(int V);
    list<int>*adj;
    void addEdge(int,int);
    bool *visited;
    int fun(int,int,int);

};

Graph::Graph(int V)
{
    this->V = V;
    visited = new bool[V+1];

    adj = new list<int>[V+1];
    for ( int i = 0; i <= V; i++)
    {
        visited[i] = false;
    }


}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int LCA;


int main()
{
    int N,a,b,Q;
    cin >> N;
    Graph G(N);
    int k = N-1;
    while(k--)
    {
        cin>>a>>b;
        G.addEdge(a,b);
    }

    cin>>Q;
    int root, l,r;
    while(Q--)
    {

        cin>>root>>l>>r;
        G.fun(root,l,r);
        cout <<LCA <<endl;

        for ( int i = 0; i <= N; i++)
        {
            G.visited[i] = false;
        }

    }



}


int Graph:: fun(int root, int left, int right)
{
    visited[root] = true;

    int ct = 0;

    if ( root == left)
    {
        ct++;
    }
    else
    {
        if ( root == right)
        {
            ct++;
        }
    }

    list<int> ::iterator it = adj[root].begin();
    int m = 0;
    for ( ; it != adj[root].end(); it++)
    {
        if ( visited[*it] == false)
        {
            m = fun(*it,left,right);
            if ( m == 1)
            {
                ct++;
            }
        }
    }
    if (ct == 2)
    {
        LCA = root;
//cout << "LCA is "<<root;
        return 0;
    }

    return ct;



}
