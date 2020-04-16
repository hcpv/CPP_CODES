#include<bits/stdc++.h>
using  namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  int dp[b+1][a+1];
  dp[0][0]=1;
  dp[0][1]=1;
  dp[0][2]=2;
  for(int i=3;i<=a;i++)
  {
    dp[0][i]=dp[0][i-1]+dp[0][i-2];
  }
  for(int i=1;i<=b;i++)
  {
    dp[i][0]=dp[i-1][0];
    dp[i][1]=dp[i-1][1];
    dp[i][2]=dp[i-1][2];
    for(int j=3;j<=a;j++)
    {
      dp[i][j]=dp[i][j-1]+dp[i][j-2]+dp[i-1][j-3];
    }
  }
  for(int i=0;i<=b;i++)
  {
    for(int j=0;j<=a;j++)
    cout<<dp[i][j]<<" ";
    cout<<endl;
  }
  cout<<dp[b][a];
}
