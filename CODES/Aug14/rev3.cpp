 #include<iostream>
#include <list>
#include <limits.h>



using namespace std;

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

class Graph
{
    int V;    // No. of vertices'
    // Pointer to an array containing adjacency lists
    list<AdjListNode> *adj;


    public:
    Graph(int V);   // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int weight);
    void get_dist(int src);
    int min_dist(int dist[],bool sptSet[],int k);


};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}

int Graph::min_dist(int dist[],bool sptSet[],int k)
{
	int min = INT_MAX, min_index,j;
 	list<AdjListNode>::iterator i;
	for(i=adj[k].begin();i!=adj[k].end();i++)
	{
		if (sptSet[i->getV()] == false && dist[i->getV()] <= min)
			{
         			min = dist[i->getV()], min_index = i->getV();
				j=i->getV();
			}
	}
	return (j);
}

void Graph::get_dist(int src)
{
	int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

	for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
      dist[src] = 0;
	sptSet[src] = true;
	static int k=src;
	list<AdjListNode>::iterator i;
		for(i=adj[src].begin();i!=adj[src].end();i++)
		{
			if(!sptSet[i->getV()] &&  (dist[i->getV()] > dist[src]+i->getWeight()))
				dist[i->getV()] = dist[src]+i->getWeight();
		}
	for(int count = 0; count < V-1; count++)
	{
		int u=min_dist(dist,sptSet,k);
		sptSet[u] = true;
		k=u;
		list<AdjListNode>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			if(!sptSet[i->getV()] && dist[u]!=INT_MAX && (dist[i->getV()] > dist[u]+i->getWeight()))
				dist[i->getV()] = dist[u]+i->getWeight();
		}
	}
	cout<<"Vertex\t\tDistance"<<endl;
for(int i=0;i<V;i++)
{
	cout<<i<<"\t\t"<<dist[i]<<"\t\t";
	cout<<endl;
}
}

int main()
{

    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, 1);

    int s = 0;
    cout << "Following are shortest distances from source " << s <<" \n";
    g.get_dist(1);

    return 0;
}
