#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int n=s.size();
  int min,max,u;
  cin>>min>>max>>u;
  vector<vector<int>>freq;
  vector<int>A(26,0);
  freq.push_back(A);
  unordered_map<string,int>m;
  for(int i=0;i<n;i++)
  {
    A[s[i]-'a']++;
    freq.push_back(A);
  }
  for(int i=0;i<n-min+1;i++)
  {
    int j=i+min-1;
    int c=0;
    for(int k=0;k<26;k++)
    {
      if(freq[j+1][k]-freq[i][k]>0)
      c++;
    }
    if(c<=u)
    m[s.substr(i,min)]++;
  }
  int sol=0;
  for(auto it=m.begin();it!=m.end();it++)
  {
    if(it->second>sol)
    sol=it->second;
  }
  cout<<sol<<endl;

}
