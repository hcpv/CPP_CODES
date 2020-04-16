#include<bits/stdc++.h>
using namespace std;
void lps(vector<int>&l,string b)
{

  //cout<<b.length()<<endl;
  //cout<<10<<endl;
  l[0]=0;
  int i=1;
  int j=0;
  int n=b.length();
  //cout<<n<<endl;
  while(i<n)
  {
    while(i<n&&b[i]==b[j])
    {
      j++;
      l[i]=j;
      i++;
    }
    if(b[i]!=b[j])
    {
      if(j!=0)
      j=l[j-1];
      else
      {
        l[i]=0;
        i++;
      }
    }
  }

}
vector<int> match(string a,string b)
{
  int n=a.size();
  int m=b.size();
  vector<int>l(m);
  lps(l,b);
  int i=0;
  int j=0;
  vector<int>pos(n+1,0);
  while(i<n)
  {
    while(j<m&&a[i]==b[j])
    {
      j++;
      i++;
    }
    if(j==m)
    {
      pos[i]++;
      j=l[j-1];
    }
    else if(i<n&&a[i]!=b[j])
    {
      if(j!=0)
      j=l[j-1];
      else
      i++;
    }
  }
  return pos;
}
int main()
{
  string a,b;
  cin>>a>>b;
  int n=a.size();
  int m=b.size();
  int i=0;
  for(i=0;i<m;i++)
  {
    if(b[i]=='*')
    break;
  }
  string x=b.substr(0,i);
  string y=b.substr(i+1);
  vector<int>px;
  px=match(a,x);
  vector<int>py;
  py=match(a,y);
  for(i=n-1;i>=0;i--)
  {
    py[i]+=py[i+1];
  }
  int sol=0;
  for(i=1;i<=n;i++)
  {
    if(px[i])
    {
      sol+=py[i];
    }
  }
  cout<<sol<<endl;
}
