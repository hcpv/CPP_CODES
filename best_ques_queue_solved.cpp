#include <bits/stdc++.h>
using namespace std;
#define ull long long int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ull q,x,y;
    cin>>q;
    char ch;
    queue <ull>a,b,c,d,k;
    for(ull h=0;h<q;h++)
    {
        cin>>ch;
        if(ch=='E')
        {
            cin>>x>>y;
            if(x==1) {
                if(a.empty())
                    k.push(x);
                a.push(y);
            }
            if(x==2) {
                if(b.empty())
                    k.push(x);
                b.push(y);
            }
            if(x==3) {
                if(c.empty())
                    k.push(x);
                c.push(y);
            }
            if(x==4) {
                if(d.empty())
                    k.push(x);
                d.push(y);
            }

        }
        else
        {
            if(k.front()==1)
            {
                cout << 1 << " " << a.front()<<endl;
                a.pop();
                if(a.empty())
                    k.pop();
                continue;
            }
            if(k.front()==2)
            {
                cout << 2 << " " << b.front()<<endl;
                b.pop();
                if(b.empty())
                    k.pop();
                continue;
            }
            if(k.front()==3)
            {
                cout << 3 << " " << c.front()<<endl;
                c.pop();
                if(c.empty())
                    k.pop();
                continue;
            }
            if(k.front()==4)
            {
                cout << 4 << " " << d.front()<<endl;
                d.pop();
                if(d.empty())
                    k.pop();
                continue;
            }

        }

    }

}