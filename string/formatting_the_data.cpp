#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    cin.ignore();
    for(int h=0;h<t;h++)
    {
        string s,s1="";
        getline(cin,s);
        int l = s.length();
        int c=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]!=32)
            {
                s[c++]=s[i];
            }
        }
        s[c]='\0';
        l=c;
        for (int i = 0; i < l; i++) {
            int p = (int) s[i];
            if (p < 91 && p > 64) {
                s1 += s[i];
                s[i] = 'a';
                int j = i + 1;
                while (j<l) {
                    if(s[j]<91&&s[j]>64)
                    {
                        s1 += s[j];
                        s[j] = 'a';
                        j++;
                    }
                    else
                        break;
                }
                s1 += " ";
            }
            else if (s[i] < 58 && s[i] > 47) {
                s1 += s[i];
                s[i] = 'a';
                int j=i+1;
                while (j<l) {
                    if(s[j]<58&&s[j]>47)
                    {
                        s1 += s[j];
                        s[j] = 'a';
                        j++;
                    }
                    else
                        break;
                }
                s1 += " ";
            }
            else {
                if(p!=97) {
                    s1 += s[i];
                    s[i] = 'a';
                    int j = i + 1;
                    while (j < l) {
                        if (p!=97) {
                            if((s[j]<91&&s[j]>64)||(s[j]<58&&s[j]>47))
                            {
                                break;
                            }
                            else {
                                s1 += s[j];
                                s[j] = 'a';
                                j++;
                            }
                        }
                        else
                            break;
                    }
                    s1 += " ";
                }
            }
        }
        l=s1.length();
        s1=s1.erase(l-1,1);
        cout<<s1<<endl;
    }
}