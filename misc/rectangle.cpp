#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a[4];
        for(int j=0;j<4;j++)
            cin>>a[j];
        sort(a,a+4);
        if(a[0]==a[1]&&a[2]==a[3])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}