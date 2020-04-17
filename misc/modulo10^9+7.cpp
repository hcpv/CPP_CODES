#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
ull fact(ull n)
{
    if(n==1 || n==0) return 1;
    return ((n%mod)*(fact(n-1)%mod)%mod);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull t;
    cin>>t;
    for(ull h=0;h<t;h++)
    {
        ull n;
        cin>>n;
        ull a[n];
        for(ull i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n,greater<int>());
        ull j=0,c=0;
        for(ull i=0;i<n;i++)
        {
            //cout<<a[i]<<endl;
            c=c+((a[i]%mod)*(fact(i+1)))%mod;
            //cout<<c<<endl;
        }
        cout<<c<<endl;
    }
}