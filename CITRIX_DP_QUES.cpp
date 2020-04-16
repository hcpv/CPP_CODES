#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<vector<vector<int>>>dp;
int find(int n,int k,int max)
{
  if(n<0)
  return 0;
  if(dp[n][k][max]!=-1)
  return dp[n][k][max];
  if(n==0)
  {
    if(k==0)
    {
      dp[n][k][max]=1;
      return 1;
    }
    else
    {
      dp[n][k][max]=0;
      return 0;
    }
  }
  if(k==0)
  {
    dp[n][k][max]=0;
    return 0;
  }
  int sol=0;
  for(int i=1;i<=max;i++)
  {
    sol+=find(n-i,k-1,i);
  }
  dp[n][k][max]=sol;
  return sol;
}
int main()
{
    int n,k;
    cin>>n>>k;
    dp.resize(n+1);
    for(int i=0;i<=n;i++)
    dp[i].resize(k+1,vector<int>(n-k+2,-1));
    int t=find(n,k,n-k+1);
    int sol=0;
    cout<<t<<endl;
}
