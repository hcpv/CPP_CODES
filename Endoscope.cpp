#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>B({{1,1,1,1},{1,1,0,0},{0,0,1,1},{1,0,1,0},{0,1,1,0},{0,1,0,1},{1,0,0,1}});
vector<vector<int>>C({{-1,0},{1,0},{0,1},{0,-1}});
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y,l,xd,yd,d;
        cin>>n>>m>>x>>y>>l;
        vector<vector<int>>D(n,vector<int>(m));
        vector<vector<int>>A(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>D[i][j];
                A[i][j]=D[i][j];
            }
        }
        if(l==0)
        {
            cout<<0<<endl;
            continue;
        }

        queue<pair<int,int>>q;
        q.push({x,y});
        if(A[x][y]==0)
        {
            cout<<0<<endl;
            continue;
        }
        A[x][y]=0;
        int sol=0,c;
        pair<int,int>temp;
        while(l>0)
        {
            int s=q.size();
            sol+=s;
            while(s--)
            {
                temp=q.front();
                q.pop();
                x=temp.first;
                y=temp.second;
                c=D[x][y];
                c--;
                if(B[c][0])
                {
                    xd=x+C[0][0];
                    yd=y+C[0][1];
                    if(xd>=0&&xd<n&&yd>=0&&yd<m&&A[xd][yd]!=0)
                    {
                        d=D[xd][yd]-1;
                        if(B[d][1])
                        {
                            q.push({xd,yd});
                            A[xd][yd]=0;
                        }

                    }
                }
                if(B[c][1])
                {
                    xd=x+C[1][0];
                    yd=y+C[1][1];
                    if(xd>=0&&xd<n&&yd>=0&&yd<m&&A[xd][yd]!=0)
                    {
                        d=D[xd][yd]-1;
                        if(B[d][0])
                        {
                            q.push({xd,yd});
                            A[xd][yd]=0;
                        }

                    }
                }
                if(B[c][2])
                {
                    xd=x+C[2][0];
                    yd=y+C[2][1];
                    if(xd>=0&&xd<n&&yd>=0&&yd<m&&A[xd][yd]!=0)
                    {
                        d=D[xd][yd]-1;
                        if(B[d][3])
                        {
                            q.push({xd,yd});
                            A[xd][yd]=0;
                        }

                    }
                }
                if(B[c][3])
                {
                    xd=x+C[3][0];
                    yd=y+C[3][1];
                    if(xd>=0&&xd<n&&yd>=0&&yd<m&&A[xd][yd]!=0)
                    {
                        d=D[xd][yd]-1;
                        if(B[d][2])
                        {
                            q.push({xd,yd});
                            A[xd][yd]=0;
                        }

                    }
                }
            }
            l--;
        }
        cout<<sol<<endl;

    }
}
