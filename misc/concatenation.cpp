#include <iostream>
using namespace std;
int main()
{
    long int t;
    cin>>t;
    for(long int i=0;i<t;i++)
    {
        long int n,k;
        cin>>n>>k;
        long int a[n];
        long int b[n*k];
        for(long int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(long int j=0;j<k;j++)
        {
            for(long int l=0;l<n;l++)
            {
                b[l+j*n]=a[l];
            }
        }
        long int p,s=0;
        long int max=0;
        for(long int j=0;j<n*k;j++)
        {
            if(b[j]>=0)
                s+=b[j];
            else
            {
                if(s>max)
                    max=s;
                s=0;
            }

        }
        if(s>max)
        cout<<s<<endl;
        else
            cout<<max<<endl;
    }
}