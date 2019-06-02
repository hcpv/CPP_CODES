#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
typedef struct tree *node;//Define node as pointer of data type struct LinkedList
int k,c=0;
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
void findMinMax(node n,int *min,int *max,int hd)
{
    if(n== nullptr)
        return;
    if(hd<*min)
        *min=hd;
    else if(hd>*max)
        *max=hd;
    findMinMax(n->left,min,max,hd-1);
    findMinMax(n->right,min,max,hd+1);

}
void printVerticalLine(node n,int line_no,int hd)
{
    if(n==nullptr)
        return;
    if(hd==line_no)
        cout<<n->data<<" ";
    printVerticalLine(n->left,line_no,hd-1);
    printVerticalLine(n->right,line_no,hd+1);
}
void verticalOrder(node n)
{
    int min=10000,max=0;
    findMinMax(n,&min,&max,0);
   for(int i=min;i<=max;i++)
    {
        printVerticalLine(n,i,0);
        cout<<endl;
    }
}
void boundaryLeft(node n)
{
    if(n== nullptr)
        return;
    if(n->left)
    {
        cout << n->data << " ";
        boundaryLeft(n->left);
    }
    else if(n->right)
    {
        cout<<n->data<<" ";
        boundaryLeft(n->right);
    }
}
void boundaryRight(node n)
{
    if(n== nullptr)
        return;
    if(n->right)
    {
        boundaryRight(n->right);
        cout << n->data << " ";
    }
    else if(n->left)
    {
        boundaryLeft(n->left);
        cout<<n->data<<" ";
    }
}
void leafTraversal(node n)
{
    if(n== nullptr)
        return;
    leafTraversal(n->left);
    if(!n->left&&!n->right)
    {
        cout<<n->data<<" ";
    }

    leafTraversal(n->right);
}
void boundaryTraversal(node n)
{
    if(n==nullptr)
        return;
    cout<<n->data<<" ";
    boundaryLeft(n->left);
    leafTraversal(n);
    boundaryRight(n->right);
}
void printSpecificLevelOrder(node n)
{
    if(n== nullptr)
        return;
    stack<node>s;
    s.push(n);
    if(n->left)
    {
        s.push(n->right);
        s.push(n->left);
    }
    if(!n->left->left)
        return;
    queue<node>q;

    node a,b;
    q.push(n->left);
    q.push(n->right);
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        b=q.front();
        q.pop();

        s.push(b->left);
        s.push(a->right);
        s.push(b->right);
        s.push(a->left);
        if(a->left->left)
        {
            q.push(a->left);
            q.push(b->right);
            q.push(a->right);
            q.push(b->left);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}
int main() {
    pace;
    node root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);

    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);
    printSpecificLevelOrder(root);

}