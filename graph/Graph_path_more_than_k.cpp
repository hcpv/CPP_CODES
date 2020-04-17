#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
class graph
{
    int v;
    list<pii>*adj;
public:
    graph(int V);

    void addEdge(int v,int u,int w);

    bool pathMoreThanK(int src,int k);

    bool pathMoreThanKUtil(int src,int k,bool path[]);

};
graph::graph(int V)
{
    v=V;
    adj=new list<pii>[V];
}
void graph::addEdge(int v, int u, int w)
{
    adj[v].push_back(make_pair(u,w));
    adj[u].push_back(make_pair(v,w));
}
bool graph::pathMoreThanK(int src, int k)
{
    bool path[v]={false};
    path[src]=true;
    return pathMoreThanKUtil(src,k,path);
}
bool graph::pathMoreThanKUtil(int src, int k, bool *path)
{
    if(k<0)
        return true;

    // Get all adjacent vertices of source vertex src and
    // recursively explore all paths from src.
    for(auto i=adj[src].begin();i!=adj[src].end();i++)
    {
        int w=(*i).second;
        int s=(*i).first;

        // If vertex v is already there in path, then
        // there is a cycle (we ignore this edge)
        if(path[(*i).first])
            continue;
        // If weight of is more than k, return true
        if(w>k)
            return true;
        // Else add this vertex to path
        path[(*i).first]=true;
        // If this adjacent can provide a path longer
        // than k, return true.
        if(pathMoreThanKUtil(s,k-w,path))
            return true;
        // Backtrack
        path[s]=false;
    }
    return false;
}
// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;
    if(g.pathMoreThanK(src, k))
        cout << "Yes\n";
    else
        cout << "No\n";

    k = 60;
    if(g.pathMoreThanK(src, k))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}