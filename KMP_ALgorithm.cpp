//Watch video on youtube
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string p;
    cin>>p;
    string t;
    cin>>t;
    int l=p.length();
    int f[l]={0};
    int j=0;
    for(int i=1;i<l;i++)
    {
        if(p[i]==p[j])
        {
            j++;
            f[i]=j;
        } else
        {
            if(j>0)
            {
                j=f[j-1];
                i--;
            }
        }

    }
    vector<int>a;
    /* for(int i=0;i<l;i++)
         cout<<f[i]<<endl;*/
    int l1=t.length();
    j=0;
    int pos=0,c=0;
    for(int i=0;i<l1;i++)
    {
        if(t[i]==p[j])
        {
            j++;
            if(j==l)//for repeated letters
            {
                c++;
                a.push_back(i-l+1);
                j=f[j-1];
            }
        } else{
            j=f[j-1];
            if(t[i]==p[j])//compare current character
            {
                //pos=i-j;
                j++;
            } /*else{
                pos=i;
            }*/
        }
    }
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<c;

}