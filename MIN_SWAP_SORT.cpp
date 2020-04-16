#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>A({1,5,4,3,2});
  int n=A.size();
  vector<pair<int,int>>B;
  for(int i=0;i<n;i++)
  {
    B.push_back({A[i],i});
  }
  sort(B.begin(),B.end());
  vector<int>vis(n,false);
  int sol=0;
  for(int i=0;i<n;i++)
  {
    if(vis[i]||B[i].second==i)
    continue;
    int j=i;
    int c=0;
    while(!vis[j])
    {
      c++;
      vis[j]=true;
      j=B[j].second;
    }
    if(c>1)
    sol+=(c-1);
  }
  cout<<sol;
}
