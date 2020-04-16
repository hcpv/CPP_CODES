#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll find(string s)
{
  int n=s.length();
  ll sol=0;
  for(int i=0;i<n;i++)
  {
    sol=sol*10+(s[i]-'0');
  }
  return sol;
}
int main()
{
  string s;
  int k;
  cin>>s;
  cin>>k;
  int n=s.size();
  ll dp[k+1][n];
  for(int i=0;i<n;i++)
  {
    dp[0][i]=find(s.substr(0,i+1));
  }
  for(int l=1;l<=k;l++)
  {
    for(int i=0;i<n;i++)
    {
      if(i<l)
      {
        dp[l][i]=dp[l-1][i];
      }
      else
      {
        dp[l][i]=0;
        for(int j=l-1;j<i;j++)
        {
          dp[l][i]=max(dp[l][i],max(dp[l-1][j],find(s.substr(j+1,i-j))));
        }
      }
    }
  }
  // for(int i=0;i<=k;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  cout<<dp[k][n-1]<<endl;
}
