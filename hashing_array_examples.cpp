#include <bits/stdc++.h>
using namespace std;
bool checkDuplicatesWithinK(int a[],int n,int k)
{
    set<int>b;
    for(int i=0;i<n;i++)
    {
        if(b.find(a[i])!=b.end())
            return true;
        b.insert(a[i]);
        if(i>=k)
            b.erase(a[i-k]);

    }
    return false;
}
int maxDistanceBetweenSameElements(int arr[],int n)
{
    unordered_map<int,int>a;
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(a[arr[i]]==0)
            a[arr[i]]=i;
        else
        {
            if(i-a[arr[i]]>max)
                max=i-a[arr[i]];

        }
    }
    return max;
}
//using merge
bool isSubset(int arr1[],int arr2[],int n,int m)
{
    if(n<m)
        return false;
    int i=0,j=0;
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    while(i<n&&j<m)
    {
        if(arr2[j]>arr1[i])
        {
            i++;
        }
        else if(arr2[j]==arr1[i])
        {
            j++;
            i++;
        }
        else
            return false;
    }
    if(j==m)
        return true;
    else
        return false;
}
//using hashmap
bool isSubset2(int arr1[],int arr2[],int n,int m)
{
    unordered_map<int,int>a;
    for(int i=0;i<n;i++)
    {
        a[arr1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        if(a.find(arr2[i])==a.end()||a[arr2[i]]==0)
            return false;
        a[arr2[i]]--;
    }
    return true;
}
string secMostRepeated(vector<string>a)
{
    unordered_map<string,int>b;
    for(int i=0;i<a.size();i++)
    {
        b[a[i]]++;
    }
    unordered_map<string,int> ::iterator it;
    int first_max=0;
    int second_max=0;
    string d1="",d2="";
    for(int i=0;i<a.size();i++)
    {
        it=b.find(a[i]);
        if(it->second>first_max)
        {
            second_max=first_max;
            d2=d1;
            first_max=it->second;
            d1=it->first;
        }
        else if(it->second<first_max&&it->second>second_max)
        {
            second_max=it->second;
            d2=it->first;
        }
    }
    return d2;
}

int main()
{

    vector<string> seq = { "ccc", "aaa", "ccc",
                           "ddd", "aaa", "aaa" };
    cout << secMostRepeated(seq);
    return 0;

}