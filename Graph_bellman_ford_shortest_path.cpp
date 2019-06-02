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
Graph* CreateGraph(int v,int e)
{
    Graph* g=new Graph;
    g->e=e;
    g->v=v;
    g->ed=new edge[e];
    return g;
}
void BellmanFord(Graph* graph,int src,int *distance)
{
    int v=graph->v;
    int e=graph->e;
    for(int i=0;i<v;i++)
    {
        distance[i]=INT_MAX;
    }
    distance[src]=0;
    // Step 2: Relax all edges |V| - 1 times. A simple shortest
    // path from src to any other vertex can have at-most |V| - 1
    // edges
    for (int i = 1; i <= v-1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = graph->ed[j].src;
            int v = graph->ed[j].dest;
            int weight = graph->ed[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }
}
int main()
{
    int n,m,x,y,w,i=0;
    cin>>n>>m;
    Graph *g=CreateGraph(n+1,m);
    int *dist=new int[n+1];
    while(i<m)
    {
        cin>>x>>y>>w;
        g->ed[i].src=x;
        g->ed[i].dest=y;
        g->ed[i].weight=w;
        i++;
    }
    BellmanFord(g,1,dist);
    for(int i=2;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
}