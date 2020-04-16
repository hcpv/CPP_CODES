#include<bits/stdc++.h>
using namespace std;
int main()
{
  int d=15,c=5;
  vector<int>pos({2,4,10});
  vector<int>cap({9,8,6});
  vector<int>cost({20,15,5});
  pos.insert(pos.begin(),0);
  cap.insert(cap.begin(),5);
  cost.insert(cost.begin(),0);
  int n=pos.size();
  int dp[n];
  for(int i=n-1;i>=0;i--)
  {
    if(pos[i]+cap[i]>=d)
    {
      dp[i]=cost[i];
    }
    else
    {
      dp[i]=INT_MAX;
    }
    for(int j=i+1;j<n;j++)
    {
      if(pos[i]+cap[i]>=pos[j]&&dp[j]!=INT_MAX)
      {
        dp[i]=min(dp[i],cost[i]+dp[j]);
      }
      else
      {
        break;
      }
    }
  }
  cout<<dp[0]<<endl;
}
