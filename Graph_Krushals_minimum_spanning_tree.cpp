#include <bits/stdc++.h>
using namespace std;
struct edge{
    int src,dest,weight;
};
struct Graph
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
Graph* CreateGraph(int v,int e)
{
    Graph* g=new Graph;
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
bool compare(edge a,edge b)
{
    return a.weight<b.weight;
}
void KruskalMST(Graph *graph)
{
    edge MST[graph->v];
    sort(graph->ed,graph->ed+graph->e,compare);
    subset s=new subset[graph->v];
    int e=0;
    for(int i=0;i<graph->v;i++)
    {
        s[i].parent=i;
        s[i].rank=0;
    }
    int i=0;
    edge temp;
    while(e<graph->v-1)
    {
        temp=graph->ed[i++];
        int x=find(s,temp.src);
        int y=find(s,temp.dest);
        if(x!=y)
        {
            Union(s,x,y);
            MST[e++]=temp;
        }
    }
    for(int i=0;i<e;i++)
    {
        cout<<MST[i].src<<"-->"<<MST[i].dest<<"  "<<MST[i].weight<<endl;
    }
}

int main()
{
    int V,E,x,y,w,i=0;  // Number of vertices in graph
    cin>>V>>E;
    Graph *graph =CreateGraph(V, E);
    while (i<E)
    {
        cin>>x>>y>>w;
        graph->ed[i].src=x;
        graph->ed[i].dest=y;
        graph->ed[i].weight=w;
        i++;
    }
    cout<<isCyclic(graph)<<endl;
   // KruskalMST(graph);

}

