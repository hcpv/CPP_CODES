#include<bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
typedef struct tree *node;
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
node newNode(int value)
{
    node n=(node)malloc(sizeof(node));
    n->data=value;
    n->right=n->left= nullptr;

    return n;
}
node findNode(node n,int k)
{
    if(n== nullptr)
        return nullptr;
    if(n->data==k)
        return n;
    node l=findNode(n->left,k);
    node r=findNode(n->right,k);
    return l!= nullptr?l:r;
}
bool findPath(node n,vector<char> *a,int k)
{
    if(n== nullptr)
        return false;
    if(n->data==k)
        return true;
    if(n->left&&findPath(n->left,a,k))
    {
        a->push_back('L');
        return true;
    }
    if(n->right&&findPath(n->right,a,k))
    {
        a->push_back('R');
        return true;
    }
    return false;

}

int main()
{
    pace;
    int n,q,p,c,x,z;
    char k;
    cin>>n>>q;
    node root=newNode(1);
    n--;
    while(n--)
    {
        cin>>p>>c>>k;
        node temp=findNode(root,p);
        if(k=='L')
            temp->left=newNode(c);
        else if(k=='R')
            temp->right=newNode(c);
    }
    vector<char>a;
    while(q>0)
    {
        cin>>x;
        if(findPath(root,&a,x))
        {
            for(int i=0;i<a.size();i++)
            {
                if(a[i]=='L')
                    a[i]='R';
                else
                    a[i]='L';
            }
        }
        n=0;
        node temp=root;
        if(a.size()==0)
            z=root->data;
        else
        {
            while(!a.empty())
            {
                if(a.back()=='L')
                {
                    temp=temp->left;
                    a.pop_back();
                }
                else if(a.back()=='R')
                {
                    temp=temp->right;
                    a.pop_back();
                }
                if(temp== nullptr)
                {
                    n=1;
                    z=-1;
                    break;
                }
            }
            if(n!=1) {
                z = temp->data;
            }

        }
        while(!a.empty())
            a.pop_back();
        cout<<z<<endl;
        q--;

    }
}