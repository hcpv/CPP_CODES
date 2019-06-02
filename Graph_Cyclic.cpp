#include <bits/stdc++.h>
using namespace std;
enum Color {white,gray,black};
class Graph {
    int V;
    list<int> *adj;
public:
    int *distance;//for level of node from parent
    Graph(int v);

    void addEdge(int v, int w);

    void BFS(int s);

    void printGraph();

    void DFS();

    void DFSIterative(int s);

    void DFSUtil(int v,bool visited[]);

    int motherVertex();

    int pathCount(int s,int d);

    void countPathUtil(int s,int d,bool visited[],int &pathCount);

    bool isCyclicUtil(int v,bool visited[],bool recStack[]);

    bool isCyclic();

    bool isCyclic2();

    bool isCyclic3();

    bool isCyclicUtil(int v,int color[]);

    bool isCyclicUtil(int v,bool visited[],int parent);




};
Graph::Graph(int v)
{
    V=v;
    adj=new list<int>[V];
    distance=new int[V];
    memset(distance,INT_MAX,V);
}
void Graph::addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v); //for undirected graph
}
//for directed graph
bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack)
{
    if(!visited[v]) {
        visited[v] = true;
        recStack[v] = true;
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            if (recStack[*i])
                return true;
        }
    }
    recStack[v]= false;
    return false;

}
bool Graph::isCyclic()
{
    bool visited[V]={false};
    bool recStack[V]={false};
    for(int i=1;i<V;i++)
    {
        if(isCyclicUtil(i,visited,recStack))
            return true;
    }
    return false;
}
bool Graph::isCyclicUtil(int v, int *color)
{
    color[v]=gray;
    for(auto i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(color[*i]==gray)
            return true;
        if(color[*i]==white&&isCyclicUtil(*i,color))
            return true;
    }
    color[v]=black;
    return false;
}
bool Graph::isCyclic3()
{
    int color[V]={white};
    for(int i=0;i<V;i++)
    {
        if(color[i]==0)
        {
            if(isCyclicUtil(i,color))
                return true;
        }
    }
    return false;
}
//for undirected graph
bool Graph::isCyclicUtil(int v, bool *visited, int parent)
{
    visited[v]=true;
    for(auto i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
        {if(isCyclicUtil(*i,visited,v))
                return true;}
        else if(*i!=parent)
            return true;
    }
    return false;
}
bool Graph::isCyclic2()
{
    bool visited[V]={false};
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            if(isCyclicUtil(i,visited,-1))
                return true;
    }
    return false;
}
int main()
{ Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";

}

