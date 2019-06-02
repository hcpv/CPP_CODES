#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
bool solveMaze(int a[4][4],int x,int y,int sol[4][4])
{
    if(x==3&&y==3) {
        sol[x][y]=1;
        return true;
    }
    else
    {
        if(x<0||x>3|y<0||y>3||a[x][y]==0)
            return false;
        sol[x][y]=1;
        if(solveMaze(a,x+1,y,sol))
            return true;
        if(solveMaze(a,x,y+1,sol))
            return true;
        sol[x][y]=0;
        return false;

    }
    return false;
}
int main()
{
    int maze[4][4]  =  { {1, 0, 0, 0},
                         {1, 1, 0, 1},
                         {0, 1, 0, 0},
                         {1, 1, 1, 1}
    };

    int sol[4][4]={0};
    if(solveMaze(maze,0,0,sol))
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }

}