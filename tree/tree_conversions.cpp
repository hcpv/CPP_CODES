#include <bits/stdc++.h>
#include <cmath>
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef struct tree *node;
typedef struct LinkedList *link;//Define node as pointer of data type struct LinkedList
struct LinkedList{
    int data;
    struct LinkedList *next;
};
link createLink(){
    link temp; // declare a node
    temp = (link)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}
struct tree{
    int data;
    struct tree *left;
    struct tree *right;
};
void newLink(link *head,int value)
{
    link n=createLink();
    n->data=value;
    link temp=*head;
    if(temp== nullptr)
    {
        *head=n;
        return;
    }
    while(temp->next!= nullptr)
        temp=temp->next;
    temp->next=n;
    return;
}
node newNode(int value)
{
    node n=(node)malloc(sizeof(node));
    n->data=value;
    n->right=n->left= nullptr;

    return n;
}
void levelOrderTraversal(node n)
{
    if(n== nullptr)
        return;
    queue<node>a;
    a.push(n);
    int countNode;//to count number of nodes at a level
    while(1)
    {
        countNode=a.size();//a contains nodes at a particular level
        if(countNode==0)
            return;
        while(countNode>0)
        {
            node temp=a.front();
            cout<<a.front()->data<<" ";
            a.pop();
            if(temp->left)
            {
                a.push(temp->left);
            }
            if(temp->right)
            {
                a.push(temp->right);
            }
            countNode--;
        }
        cout<<endl;//to print various level IN DIFFERENT LINES
    }

}
int search(int arr[], int strt, int end, int value)
{
    int i;
    for(i = strt; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
    return -1;
}
//from inorder and preorder
node buildTree1(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if(inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder traversal using preIndex
      and increment preIndex */
    node tNode = newNode(pre[preIndex++]);

    /* If this node has no children then return */
    if(inStrt == inEnd)
        return tNode;

    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    /* Using index in Inorder traversal, construct left and
       right subtress */
    tNode->left = buildTree1(in, pre, inStrt, inIndex-1);
    tNode->right = buildTree1(in, pre, inIndex+1, inEnd);

    return tNode;
}
//from inorder and postorder
node buildTree2(int in[],int post[],int s,int end,int size)
{
    if(s>end)
        return nullptr;
    static int i=size-1;
    node root=newNode(post[i--]);
    if(s==end)
        return root;
    int pos=search(in,s,end,root->data);
    root->right=buildTree2(in,post,pos+1,end,size);
    root->left=buildTree2(in,post,s,pos-1,size);
    return root;
}
//construct complete binary tree from linked list
node constructList2Binary(link head)
{
    node root;
    queue<node>q;
    if(head== nullptr)
    {
        root= nullptr;
        return root;
    }
    root=newNode(head->data);
    head=head->next;
    q.push(root);
    while(head)
    {
        node temp=q.front();
        q.pop();
        temp->left=newNode(head->data);
        head=head->next;
        q.push(temp->left);
        if(head)
        {
            temp->right=newNode(head->data);
            head=head->next;
            q.push(temp->right);
        }
    }
    return root;

}
int convertTOSumTree(node n)
{
    if (n== nullptr)
        return 0;
    int olddata=n->data;
    n->data=convertTOSumTree(n->left)+convertTOSumTree(n->right);
    return n->data+olddata;
}
int convertTOSumLeftSubTree(node n)
{
    if (n== nullptr)
        return  0;
    if (n->left== nullptr&&n->right== nullptr)
        return n->data;
    int leftSum=convertTOSumLeftSubTree(n->left)
    int rightSum=convertTOSumLeftSubTree(n->right);
    n->data+=leftSum;
    return n->data+rightSum;
}
int main()
{
    pace;
    link head= nullptr;
    newLink(&head,10);
    newLink(&head,12);
    newLink(&head,15);
    newLink(&head,25);
    newLink(&head,30);
    newLink(&head,36);
    node root = newNode(1);
    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->right = newNode(6);

    convertTOSumLeftSubTree(root);
    levelOrderTraversal(root);
}