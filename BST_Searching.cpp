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
node insert(node n,int k)
{
    if(n== nullptr)
        return newNode(k);
    if(k>n->data)
        n->right=insert(n->right,k);
    else if(k<n->data)
        n->left=insert(n->left,k);
    return n;

}
//using same concept as for greatest element using stack
bool canRepresentBST(int pre[],int n)
{
    stack<int>s;

    int root=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(pre[i]<root)
            return false;
        while(!s.empty()&&s.top()<pre[i])
        {
            root=s.top();
            s.pop();
        }

        s.push(pre[i]);
    }
    return root;
}
node LCA(node n,int n1,int n2)
{
    if(n== nullptr)
        return n;
    if(n1<n->data&&n2<n->data)
        return LCA(n->left,n1,n2);
    else if(n1>n->data&&n2>n->data)
        return LCA(n->right,n1,n2);
    return n;
}
void kthSmallestElement(node n,int &k)
{
    if(n==nullptr||k<0)
        return;
    kthSmallestElement(n->left,k);
    k--;
    if(k==0) {
        cout << n->data;
        return;
    }
    kthSmallestElement(n->right,k);
}
struct Info{
    int size;
    int min;
    int max;
    int ans;
    bool isBst;
};
Info largestBst(node n)
{
    if(n== nullptr)
        return {0,INT_MIN,INT_MAX,0,true};
    if(n->left== nullptr&&n->right== nullptr)
        return {1,n->data,n->data,1,true};
    Info l=largestBst(n->left);
    Info r=largestBst(n->right);
    Info root;
    root.size=1+l.size+r.size;
    if(l.isBst&&r.isBst&&l.max<n->data&&r.min>n->data)
    {
        root.min=l.min;
        root.max=r.max;
        root.ans=root.size;
        root.isBst=true;
        return root;
    }
    root.ans=max(l.size,r.size);
    root.isBst= false;
    return root;

}
int distanceFromRoot(node n,int k)
{
    if(n->data==k)
        return 0;
    if(n->data>k)
        return 1+distanceFromRoot(n->left,k);
    return 1+distanceFromRoot(n->right,k);
}
//n1>n2
int distanceBST(node n,int n1,int n2)
{
    if(n== nullptr)
        return 0;
    if(n->data>n1&&n->data>n2)
        return distanceBST(n->left,n1,n2);
    if(n->data<n1&&n->data<n2)
        return distanceBST(n->right,n1,n2);
    if(n->data<n1&&n->data>n2)//n is LCA
        return distanceFromRoot(n,n2)+distanceFromRoot(n,n1);
}
int main()
{
    node root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);
    int a = 5, b = 55;
    cout << distanceBST(root, 35, 5);
    return 0;
}