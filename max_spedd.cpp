#include <iostream>
using namespace std;
int count=0;
void merge(int *a,int s,int m,int e)
{
    int j=m+1;
    int i=s;
    int p=e-s+1;
    int *b=new int[p];
    int *d=new int[p];
    int k=0;
    while(i<=m&&j<=e)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=m)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for(int i=s;i<=e;i++)
    {
        a[i]=b[i-s];
    }
}
void merge_sort(int *a,int s,int e)
{
    if(s<e)
    {
        int m = (s + e) / 2;
        merge_sort(a, s, m);
        merge_sort(a, m + 1, e);
        merge(a, s, m, e);
    }
}
int main()
{
    int n;
    cin>>n;
    int l=2*n;
    int *a=new int[l];
    for(int i=0;i<l;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,l-1);
    int s=0;
    for(int i=0;i<l;i+=2)
        s=s+a[i];
    cout<<s;
}