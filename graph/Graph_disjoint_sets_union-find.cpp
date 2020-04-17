#include <bits/stdc++.h>
using namespace std;
struct edge{
    int src,des;
};
struct graph
{
    int v,e;
    edge *ed;

};
struct subset
{
    int parent;
    int rank;
};
// Creates a graph with V vertices and E edges
graph* CreateGraph(int v,int e)
{
    graph* g=new graph;
    g->e=e;
    g->v=v;
    g->ed=new edge[e];
    return g;
}
// A utility function to find the subset of an element i
int find(subset s[],int i)
{
    // find root and make root as parent of i (path compression)
    if(s[i].parent!=i)
      s[i].parent=find(s,s[i].parent);
    return s[i].parent;
}
// A utility function to do union of two subsets
void Union(subset s[],int x,int y)
{
    int yroot=find(s,y);
    int xroot=find(s,x);
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if(s[xroot].rank>s[yroot].rank)
        s[yroot].parent=xroot;
    else if(s[yroot].rank>s[xroot].rank)
        s[xroot].parent=yroot;
        // If ranks are same, then make one as root and increment
        // its rank by one
    else
    {
        s[yroot].parent=xroot;
        s[xroot].rank++;
    }
}
bool isCyclic(graph* Graph)
{
    subset s[Graph->v];
    for(int i=0;i<Graph->v;i++)
    {
        s[i].parent=i;
        s[i].rank=0;
    }
    for(int i=0;i<Graph->e;i++)
    {
        int x=find(s,Graph->ed->src);
        int y=find(s,Graph->ed->des);
        if(x==y)
            return true;
        Union(s,x,y);
    }
    return false;
}
int main()
{
    int V = 3, E = 3;
    graph* Graph = CreateGraph(V, E);

    // add edge 0-1
    Graph->ed[0].src = 0;
    Graph->ed[0].des = 1;

    // add edge 1-2
    Graph->ed[1].src = 1;
    Graph->ed[1].des = 2;

    // add edge 0-2
    Graph->ed[2].src = 0;
    Graph->ed[2].des = 2;
    if (isCyclic(Graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );

}

