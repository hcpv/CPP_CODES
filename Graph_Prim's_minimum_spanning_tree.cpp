//Dijkstra's algo and Prim's algo approximately same
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
bool *marked;
vector<PII> *adj;
int prim(int s)
{
    priority_queue<PII,vector<PII>,greater<PII>>q;
    int result=0;
    PII p;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        // Select the edge with minimum weight
        p=q.top();
        q.pop();
        // Checking for cycle
        if(marked[p.second])
            continue;
        marked[p.second]=true;
        result+=p.first;
        for(int i=0;i<adj[p.second].size();i++)
        {
            if(!marked[adj[p.second][i].second])
                q.push(adj[p.second][i]);
        }
    }
    return result;
}
int main()
{
    int n,e,x,y,w;
    cin>>n>>e;
    adj=new vector<PII>[n+1];
    marked=new bool[n+1];
    while(--e>=0)
    {
        cin>>x>>y>>w;
        adj[x].push_back(make_pair(w,y));
        adj[y].push_back(make_pair(w,x));
    }
    int minimumCost=prim(1);
    cout<<minimumCost;
}