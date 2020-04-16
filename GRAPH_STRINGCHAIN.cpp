#include<bits/stdc++.h>
using namespace std;
map<string,vector<string>>graph;
bool findAdj(string a,string b)
{
  int n=a.size();
  unordered_map<char,int>s;
  for(int i=0;i<n;i++)
  s[a[i]]++;
  for(int i=0;i<n-1;i++)
  {
    if(s.count(b[i])==0)
    return false;
    s[b[i]]--;
    if(s[b[i]]==0)
    s.erase(b[i]);
  }
  if(s.size()==1)
  return true;
  return false;
}
bool compare(string a,string b)
{
  return a.size()>b.size();
}
// void dfs(string v,unordered_set<string>&s,int l,int &sol)
// {
//
//   if(graph.count(v)==0)
//   {
//     sol=max(sol,l);
//     return;
//   }
//   s.insert(v);
//   int n=graph[v].size();
//   for(int i=0;i<n;i++)
//   {
//     dfs(graph[v][i],s,l+1,sol);
//   }
//   s.erase(s.find(v));
// }
int main()
{
  int n=6;
  vector<string>dict({"a","b","ba","bca","bda","bdca"});
  sort(dict.begin(),dict.end(),compare);
  unordered_map<string,int>dp;
  for(int i=0;i<n;i++)
  {
    dp[dict[i]]=1;
  }
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(dict[i].size()-dict[j].size()==1)
      {
        if(findAdj(dict[i],dict[j]))
        {
          dp[dict[j]]=max(dp[dict[j]],dp[dict[i]]+1);
        }
      }
      else if(dict[i].size()-dict[j].size()>1)
      {
        break;
      }
    }
  }
  // unordered_set<string>s;
  int sol=0;
  for(int i=0;i<n;i++)
  {
    // //s.clear();
    // dfs(dict[i],s,1,sol);
    sol=max(sol,dp[dict[i]]);
  }
  cout<<sol;
}
