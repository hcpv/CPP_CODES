#include<bits/stdc++.h>
using namespace std;
struct vertex
{
    int v,val;
};
bool comparator(vertex a,vertex b)
{
    if(a.val==b.val)
    {
        return (a.v<b.v);
    }
    else
    {
        return (a.val>b.val);
    }
}
int main()
{
    int n,m,k,x,y;
    cin>>n>>m>>k;
    int val[n+1];
    for(int i=1;i<=n;i++)
    cin>>val[i];
    vector<vector<vertex>>a(n+1);
    while(--m>=0)
    {
        cin>>x>>y;
        struct vertex temp1={y,val[y]};
        struct vertex temp2={x,val[x]};
        a[x].push_back(temp1);
        a[y].push_back(temp2);
    }
    for(int i=1;i<=n;i++)
    {
        sort(a[i].begin(),a[i].end(),comparator);
        //reverse(a[i].begin(),a[i].end());
        if(a[i].size()<k-1)
        cout<<-1<<endl;
        else
        {
            cout<<a[i][k-1].v<<endl;
        }
    }
    
}
