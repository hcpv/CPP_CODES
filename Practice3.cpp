#include<bits/stdc++.h>
using namespace std;
int dp[101][100][2];
int solve(string str, int idx, int flag, int s, int d, int n,set<string> &hash,string &A){
if(s > n || s < 0)
return 0;
int len = str.length();
if(idx >= len)
return 0;
if (dp[idx][s][flag] != -1)
return dp[idx][s][flag];
int res = 0;
if (flag == 1)
{
  int f = 1;
  if (str[idx] == 'l')
  f = -1;
  //A.push_back(str[idx]);

  if (s+f == d )
  {
    res++;
    //cout << A << endl;
    //hash.insert(A);
  }
  res += solve(str,idx+1,0,s+f,d,n,hash,A) + solve(str,idx+1,1,s+f,d,n,hash,A);
  //A.pop_back();
}
else
{
  res += solve(str,idx+1,0,s,d,n,hash,A);
}
dp[idx][s][flag] = res;
return res;
}
int main(){
string str="rrlrlr";
int len = str.length();
int n=6;
int s=1, d=4;
memset(dp, -1, sizeof(dp));
set<string> hash;
string A;
int res = solve(str, 0 , 0, s, d, n,hash,A) + solve(str, 0, 1, s, d, n,hash,A);
//for (auto i = hash.begin();i != hash.end();++i)
//cout << *i << endl;
cout << res << endl;
}
