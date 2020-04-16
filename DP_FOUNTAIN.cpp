#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>A({2,0,0,0});
  int n=A.size();
  vector<int>dp(n,0);
  for(int i=0;i<n;i++)
  {
    int l=max(0,i-A[i]);
    int r=min(n,i+A[i]+1);
    dp[l]=max(dp[l],r);
  }
  int sol=1;
  int lMax=dp[0];
  int gMax=dp[0];
  for(int i=0;i<n;i++)
  {
    gMax=max(gMax,dp[i]);
    if(i==lMax)
    {
      sol++;
      lMax=gMax;
    }
  }
  cout<<sol<<endl;
}
