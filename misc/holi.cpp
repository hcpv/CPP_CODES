#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++)
        {cin>>a[j];
        }
        sort(a,a+n);
        int ans=0;

        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(a[j]==a[k])
                    ans=ans+1;
                else if(2*(a[j]%a[k])>=a[k])
                    ans=ans+(a[j]/a[k])+1;
                else
                    ans=ans+(a[j]/a[k]);
            }
        }
        cout<<ans<<endl;
    }
}