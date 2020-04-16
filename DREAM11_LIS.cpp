#include <bits/stdc++.h>
using namespace std;
bool compare(const pair<pair<int,int>,int>&a,const pair<pair<int,int>,int>&b)
{
  return a.first.second<b.first.second;
}
int main()
{
  vector<int>s({10,5,25,45,20});
  vector<int>d({10,12,15,25,30});
  vector<int>val({50,25,51,28,30});
  int n=s.size();
  vector<pair<pair<int,int>,int>>v;
  for(int i=0;i<n;i++)
  {
    v.push_back({{s[i],s[i]+d[i]},val[i]});
  }
  sort(v.begin(),v.end(),compare);
  vector<int>dp(n,0);
  int sol=v[0].second;
  dp[0]=v[0].second;
  for(int i=1;i<n;i++)
  {
    dp[i]=v[i].second;
    for(int j=0;j<i;j++)
    {
      if(v[j].first.second<v[i].first.first&&dp[j]+v[i].second>dp[i])
      {
        dp[i]=v[i].second+dp[j];
        sol=max(sol,dp[i]);
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<dp[i]<<" "<<endl;
  }
  cout<<sol<<endl;
}
