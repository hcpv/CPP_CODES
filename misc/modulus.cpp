/*
 * 1) K > 1
2) arr[1]%K = arr[2]%K = arr[3]%K = ... = arr[M]%K where '%' is a modulus operator
 We need to find such values of k which when divide all the input numbers gives same remainder
A%k=B%k
where k can be all the factors of (A-B)
 hence find hcf of all differeneces
 the factors of this hcf wil give various values of x
 */
#include <bits/stdc++.h>
#include<cmath>
#include <iostream>
using namespace std;
long int ans[10000];
static int x=0;
void divisor(long int n)
{

    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            ans[x++]=i;
            if(i*i!=n)
                ans[x++]=n/i;
        }

    }

}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    long int a[t],d,g;
    cin>>a[0];
    long int sub=a[0];
    for(int i=1;i<t;i++)
    {
        cin>>a[i];
        //a[i]=a[0];
        d=abs(a[i]-a[0]);
        if(i!=1)
        g=__gcd(g,d);
        else
            g=__gcd(d,d);

    }
    //long int g=1000000;
    ans[x++]=g;
    divisor(g);
    sort(ans,ans+x);
    for(int i=0;i<x;i++)
    {
        cout<<ans[i]<<" ";
    }



}


