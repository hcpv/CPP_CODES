#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>A({1,2,3,4});
  int n=A.size();
  int sum[n+1]={0};
  for(int i=1;i<=n;i++)
  {
    sum[i]=sum[i-1]+A[i-1];
  }
  int f;
  if(n%2==0)
  f=0;
  else
  f=1;
  int dp[n][n];
  for(int i=0;i<n;i++)
  {
    if(f)
    dp[i][i]=A[i];
    else
    dp[i][i]=-A[i];
  }
  f=1-f;
  for(int l=1;l<n;l++)
  {
    for(int i=0;i<n-l;i++)
    {
      int j=i+l;
      if(f)
      dp[i][j]=sum[j+1]-sum[i]+max(dp[i+1][j],dp[i][j-1]);
      else
      dp[i][j]=sum[i]-sum[j+1]+max(dp[i+1][j],dp[i][j-1]);
    }
    f=1-f;
  }
  cout<<dp[0][n-1]<<endl;
}
