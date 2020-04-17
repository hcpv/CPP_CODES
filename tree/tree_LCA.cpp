#include <bits/stdc++.h>
#include <cmath>
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
using namespace std;
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
//to find path of a node from root.Path is stored in a vector
bool findPath(node n,vector<int>&path,int k)
{
    if (n== nullptr)
        return false;
    path.push_back(n->data);
    if(n->data==k)
        return true;
    if(n->left&&findPath(n->left,path,k)||n->right&&findPath(n->right,path,k))
        return true;
    path.pop_back();
    return false;
}
//to find Lowest Common Ancestors using using path method
int findLCA1(node n,int n1,int n2)
{
    vector<int>p1,p2;
    if(!findPath(n,p1,n1)||!findPath(n,p2,n2))
        return -1;
    int i;
    for(i=0;i<p1.size()&&i<p2.size();i++)
    {
        if(p1[i]!=p2[i])
            break;
    }
    return p1[i-1];
}
//to find lca without vector
node findLCA2(node n,int n1,int n2)
{
    if(n== nullptr)
        return nullptr;
    if(n->data==n1||n->data==n2)
        return n;
    node l=findLCA2(n->left,n1,n2);
    node r=findLCA2(n->right,n1,n2);
    if(l&&r)
        return n;
    if(!l&&!r)
        return nullptr;
    return l!=nullptr?l:r;
}
//to find level of a given node
int findLevel(node n,int k,int level)
{
    if(n== nullptr)
        return -1;
    if(n->data==k)
        return level;
    int left=findLevel(n->left,k,level+1);//level+1 is important
    if(left==-1)
        return findLevel(n->right,k,level+1);
    return left;
}
//to find distance between two nodes
int findDistance(node n,int a,int b)
{
    node lca=findLCA2(n,a,b);
    int levela=findLevel(lca,a,0);
    int levelb=findLevel(lca,b,0);//calculate the distance by calculating the level of each node from LCA
    return (levela+levelb);
}
//to get ancestors of anode in vector
bool ancestors(node n,vector<int>*a,int k)
{
    if(n== nullptr)
        return false;
    if(n->data==k)
    {
        (*a).push_back(n->data);
        return true;
    }
    if(ancestors(n->left,a,k))
    {
        (*a).push_back(n->data);
        return true;
    }
    if(ancestors(n->right,a,k))
    {
        (*a).push_back(n->data);
        return true;
    }
    return false;
}
//to print common nodes using ancestors&LCA
bool printCommonNodes(node n,int n1,int n2)
{
    if(findLCA2(n,n1,n2))
    {
        int k=findLCA2(n,n1,n2)->data;
        vector<int>a;
        if(ancestors(n,&a,k))
        {
            for(int i=0;i<a.size();i++)
                cout<<a[i]<<" ";
        }
    }
    return false;
}
int main()
{
    pace;
    node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left=newNode(8);
    root->left->right->left=newNode(9);
    root->right->right->right=newNode(10);
    cout<<findLCA2(root,4,9);
}
