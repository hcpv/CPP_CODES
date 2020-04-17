#include<bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1
vector < pair < int , int > > *v;   // each vertex has all the connected vertices with the edges weights
int *dist ;
bool *vis;

void dijkstra(int n){
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        vis[i]= false;
    }
    dist[1] = 0;
    multiset < pair < int , int > > s;          //first element is distance and second is vertex multiset do the job as a min-priority queue

    s.insert({0 , 1});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
        if( vis[x] )
            continue;                  // check if the popped vertex is visited before
        vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].first; int w = v[x][i].second;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
}
int main()
{
    int n,m,x,y,w;
    cin>>n>>m;
    v=new vector<pair<int,int>>[n+1];
    dist=new int[n+1];
    vis=new bool[n+1];
    while(--m>=0)
    {
        cin>>x>>y>>w;
        v[x].push_back(make_pair(y,w));
        //v[y].push_back(make_pair(x,w));
    }
    dijkstra(n+1);
    for(int i=2;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
}