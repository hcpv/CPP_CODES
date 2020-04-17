#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000003
#define pace ios::sync_with_stdio(false);cin.tie(0)
ull b[1000003];
int main()
{
    pace;
    b[1]=1;
    //b is factorial matrix
    for(ull i=2;i<1000003;i++)
    {
        b[i]=((i%mod)*(b[i-1]%mod))%mod;
    }
    ull t,n,x,result;
    cin>>t;
    while(t>0)
    {
        cin>>n>>x;
        if(n<mod&&x<mod)
            result=((b[n])*(x%mod))%mod;
        else
            result=0;
        cout<<result<<endl;
        t--;
    }

}