#include<bits/stdc++.h>
using  namespace std;
int main()
{
  string s="aeiaaioooaauuaeiou";
  int n=s.size();
  map<int,int>m;
  int a=0,e=0,i=0,o=0,u=0;
  for(int j=0;j<n;j++)
  {
    if(s[j]=='a')
    {
      m['a']++;
      a++;
    }
    else if(s[j]=='e'&&a)
    {
      m['e']=max(m['e']+1,m['a']+1);
      e++;
    }
    else if(s[j]=='i'&&e)
    {
      m['i']=max(m['e']+1,m['i']+1);
      i++;
    }
    else if(s[j]=='o'&&i)
    {
      m['o']=max(m['i']+1,m['o']+1);
      o++;
    }
    else if(s[j]=='u'&&o)
    {
      m['u']=max(m['u']+1,m['o']+1);
      u++;
    }
  }
  if(a&&e&&i&&o&&u)
  {
    cout<<a<<" "<<e<<" "<<i<<" "<<o<<" "<<u<<endl;
    cout<<m['u']<<endl;
  }
}
