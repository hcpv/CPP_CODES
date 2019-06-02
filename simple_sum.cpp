#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    string s;
    while(getline(cin,s))
    {
        int l=s.length();
        int pos;
        int c=0;
        if (s.find("//") != string::npos)
            pos=s.find("//");
        else
            pos=l;
        string str1=s.substr(pos,l-pos+1);
        int a[pos]={0};
        for(int i=0;i<pos;i++)
        {
            if (s[i] == '-' && s[i + 1] == '>') {
                a[i] = 1;
                a[i+1]=2;
            } else
            {
                if(a[i-1]==1)
                    continue;
                else
                    a[i]=0;
            }

        }

        string str="";
        for(int i=0;i<pos;i++)
        {
            if(a[i]==0)
                str+=s[i];
            else
            {
                if(a[i-1]==1)
                    continue;
                str+='.';
            }
        }
        cout<<(str+str1)<<endl;
    }
}