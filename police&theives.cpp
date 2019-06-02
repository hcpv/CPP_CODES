#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,k;
        cin>>n>>k;
        int a[n][n];
        char s;
        for(int j=0;j<n;j++)
        {
            for(int l=0;l<n;l++)
            {
                cin>>s;
                if(s=='P')
                    a[j][l]=0;
                else
                    a[j][l]=1;
            }
        }
        int l1,u1;
        int c=0;
        for(int j=0;j<n;j++)
        {
            for(int l=0;l<n;l++)
            {
                if(a[j][l]==1)
                {
                    if(l+k>=n-1)
                        u1=n-1;
                    else
                        u1=l+k;
                    if(l-k<=0)
                        l1=0;
                    else
                        l1=l-k;
                    for(int p=l1;p<=u1;p++)
                    {
                        if(a[j][p]==0)
                        {
                            c++;
                            a[j][p]=2;
                            break;
                        }
                    }

                }
            }
        }
        cout<<c<<endl;


    }

}//
// Created by himanshu on 26/2/18.
//

