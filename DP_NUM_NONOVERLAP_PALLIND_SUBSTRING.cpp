#include<bits/stdc++.h>
using namespace std;
int main()
{
  string A;
  cin>>A;
  int n=A.length();
  bool dp[n][n];
  memset(dp,false,sizeof(dp));
  for(int i=0;i<n;i++)
  {
    dp[i][i]=true;
  }
  for(int i=0;i<n-1;i++)
  {
    if(A[i]==A[i+1])
    {
      dp[i][i+1]=true;
    }
  }
  for(int l=2;l<n;l++)
  {
    for(int i=0;i<n-l;i++)
    {
      int j=i+l;
      if(A[i]==A[j]&&dp[i+1][j-1])
      {
        dp[i][j]=true;
      }
    }
  }
  vector<int>l(n,0);
  vector<int>r(n,0);
  l[0]=1;
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<=i;j++)
    {
      if(dp[j][i])
      l[i]++;
    }
  }
  r[n-1]=1;
  for(int i=n-2;i>=0;i--)
  {
    r[i]=r[i+1];
    for(int j=i;j<n;j++)
    {
      if(dp[i][j])
      r[i]++;
    }
  }
    int sol=0;
  for(int i=0;i<n-1;i++)
  {
    sol+=l[i]*r[i+1];
  }
  cout<<sol;
}
