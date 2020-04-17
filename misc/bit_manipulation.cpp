#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int h=0;h<t;h++)
    {
        int n,q;
        cin>>n>>q;
        int a[n]={0};
        for(int z=0;z<q;z++)
        {
            int t,x,y,l,r;
            cin>>t>>x>>y;
            if(t==1)
            {
                cin>>l>>r;
                int p=r-l+1;
                int b=0;
                b=(int)pow(2,p)-1;
                // cout<<b;
                //cout<<b<<endl;
                b=b<<l;
                //cout<<b<<endl;
                for(int i=x-1;i<=y-1;i++)
                {
                    a[i]=a[i]^b;
                }
            }
            else
            {
                if(a[x-1]==a[y-1])
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        }
    }
}