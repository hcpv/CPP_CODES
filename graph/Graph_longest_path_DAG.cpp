//Same method for shortest path
#include <bits/stdc++.h>
using namespace std;
class AdjListNode{
    int v,weight;
public:
    AdjListNode(int _v,int w){
        v=_v;
        weight=w;
    }
    int getV(){ return v;}
    int getWeight() { return weight;}

};
class Graph
{
    int v;
    list<AdjListNode>*adj;
public:
    void topologicalSortUtil(int v,bool visited[],stack<int>&Stack);

    Graph(int V);

    void addEdge(int u,int v,int weight);

    void longestPath(int s);
};
Graph::Graph(int V)
{
    v=V;
    adj=new list<AdjListNode>[V];
}
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v,weight);
    adj[u].push_back(node);
}
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
            topologicalSortUtil(node.getV(), visited, Stack);
    }
    // Push current vertex to stack which stores topological
    // sort
    Stack.push(v);
}

// The function to find longest distances from a given vertex.
// It uses recursive topologicalSortUtil() to get topological
// sorting.
void Graph::longestPath(int s)
{
    stack<int> Stack;
    int dist[v];

    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < v; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Initialize distances to all vertices as infinite and
    // distance to source as 0
    for (int i = 0; i < v; i++)
        dist[i] = INT_MIN;
    dist[s] = 0;

    // Process vertices in topological order
    while (Stack.empty() == false)
    {
        // Get the next vertex from topological order
        int u = Stack.top();
        Stack.pop();

        // Update distances of all adjacent vertices
        list<AdjListNode>::iterator i;
        if (dist[u] != INT_MIN)
        {
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (dist[i->getV()] < dist[u] + i->getWeight())
                    dist[i->getV()] = dist[u] + i->getWeight();
        }
    }

    // Print the calculated longest distances
    for (int i = 0; i < v; i++)
        if (dist[i] == INT_MIN)
            cout << "INF ";
        else
            cout << dist[i] << " ";
}
int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from "
            "source vertex " << s <<" \n";
    g.longestPath(s);
}