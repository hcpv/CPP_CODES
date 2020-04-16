#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,g;
  cin>>n>>g;
  int A[n];
  int sum[n+1];
  sum[0]=0;
  for(int i=0;i<n;i++)
  {
    cin>>A[i];
    sum[i+1]=sum[i]+A[i];
  }
  double dp[g+1][n];
  for(int i=0;i<n;i++)
  {
    dp[1][i]=(double)sum[i+1]/(i+1);
  }
  for(int k=2;k<=g;k++)
  {
    for(int i=0;i<n;i++)
    {
      if(i<k-1)
      dp[k][i]=dp[k-1][i];
      else
      {
        dp[k][i]=0;
        for(int j=k-1;j<i;j++)
        {
          dp[k][i]=max(dp[k][i],dp[k-1][j]+(double)(sum[i+1]-sum[j+1])/(i-j));
        }
      }
    }
  }
  cout<<dp[g][n-1]<<endl;
}
