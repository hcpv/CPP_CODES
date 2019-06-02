#include <bits/stdc++.h>
#define INF 199999
using namespace std;
const int V=4;
void floydWarshall(int graph[][V])
{
    int dist[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            dist[i][j]=graph[i][j];

    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF\t";
            else
                cout<<dist[i][j]<<"\t";
        }
        printf("\n");
    }
    //printSolution(dist);
}
int main()
{
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}};
    floydWarshall(graph);
}