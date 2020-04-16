#include<bits/stdc++.h>
using namespace std;
class graph{
  public:
  int V;
  vector<int>*g;
  vector<int>ind;
  graph(int v)
  {
    V=v;
    g=new vector<int>[V];
    ind.resize(V,0);
  }
  void addEdge(int u,int v)
  {
    g[u].push_back(v);
    ind[v]++;
  }
  void allTopo(bool visited[],vector<int>res)
  {
    bool f=false;
    for(int i=0;i<V;i++)
    {
      if(!visited[i]&&ind[i]==0)
      {
        visited[i]=true;
        res.push_back(i);
        for(int j=0;j<g[i].size();j++)
        {
          ind[g[i][j]]--;
        }
        allTopo(visited,res);
        visited[i]=false;
        res.pop_back();
        for(int j=0;j<g[i].size();j++)
        {
          ind[g[i][j]]++;
        }
        f=true;
      }
    }
  if(!f)
  {
    for(int i=0;i<res.size();i++)
    {
      cout<<res[i]<<" ";
    }
    cout<<endl;
  }
}
};
int main()
{
  graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  vector<int>res;
  bool visited[g.V]={false};
  g.allTopo(visited,res);
}
