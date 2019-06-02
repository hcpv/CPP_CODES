#include <iostream>
#include <cstring>
using namespace std;
int order(string n1,string n2)
{
    int l1=n1.length();
    int l2=n2.length();
    int l=min(l1,l2);
    int c=0;
    int d=0;
    int e=0;
    for(int i=0;i<l;i++)
    {
        int a=(int)n1[i];
        int b=(int)n2[i];
        if(a>b)
        {
            c++;
            break;
        }
        else if(a<b)
        {
            d++;
            break;
        } else
            e++;
    }
    if(d==1)
        return 1;
    if(c==1)
    {
        return 2;
    }
    if(e==l)
    {
        if(l1!=l2)
        {
            if (l1 == l)
                return 1;
            else if (l2 == l)
                return 2;
        }
        else
            return 3;
    }
}
int main()
{
    int n;
    cin>>n;
    char **a=new char*[n];
    char **b=new char*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new char[5];
        b[i]=new char[5];
        cin>>a[i];
    }
    char *c=new char[5];

    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i;j<n;j++)
        {
            if(order(a[j],a[min])==1)
            {
                min=j;
            }
        }
        c=a[min];
        a[min]=a[i];
        a[i]=c;
    }
    int d=0;
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=0;j<i;j++)
        {
            if(order(a[i],a[j])==3)
            {
                s++;
                break;
            }
        }
        if(s==0)
        {
            b[d]=a[i];
            d++;
        }
    }
    cout<<d<<endl;
    for(int i=0;i<d;i++)
        cout<<b[i]<<endl;
}