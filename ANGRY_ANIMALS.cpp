#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>A(n+1,-1);
    int t;
    cin>>t;
    int x,y;
    while(t--)
    {
      cin>>x>>y;
      if(x<y)
      {
        int temp=x;
        x=y;
        y=temp;
      }
      if(A[x]<y)
      A[x]=y;
    }
    queue<int>q;
    int sol=0;
    for(int i=1;i<=n;i++)
    {
      cout<<A[i]<<endl;
      if(A[i]==-1)
      q.push(i);
      else
      {
        while(!q.empty()&&q.front()<=A[i])
        q.pop();
        q.push(i);
      }
      sol+=q.size();
    }
    cout<<sol;
}
