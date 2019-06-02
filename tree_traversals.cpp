#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
typedef struct tree *node;//Define node as pointer of data type struct tree
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
void printPreOrder(node n)
{
    if(n==nullptr)
        return;
    cout<<n->data<<" ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}
void printInOrder(node n)
{
    if(n==nullptr)
        return;
    printInOrder(n->left);
    cout<<n->data<<" ";
    printInOrder(n->right);
}
void printPostOrder(node n)
{
    if(n==nullptr)
        return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout<<n->data<<" ";
}
void levelOrderTraversal(node root)
{
    // Base Case
	if (root == NULL) return;

	// Create an empty queue for level order tarversal
	queue<node> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (1)
	{
		// nodeCount (queue size) indicates number of nodes
		// at current lelvel.
		int nodeCount = q.size();
		if (nodeCount == 0)
			break;

		// Dequeue all nodes of current level and Enqueue all
		// nodes of next level
		while (nodeCount > 0)
		{
			node n = q.front();
			if(nodeCount==1)
			cout << n->data << " ";
			q.pop();
			if (n->left != NULL)
				q.push(n->left);
			if (n->right != NULL)
				q.push(n->right);
			nodeCount--;
		}
		cout << endl;
	}
}
void levelOrderSpiralTraversal(node n)
{
    if(n== nullptr)
        return;
    stack<node>s1,s2;
    s1.push(n);
    while(!s1.empty()||!s2.empty())
    {
        while(!s1.empty())
        {
            if(s1.top()->left)
                s2.push(s1.top()->left);
            if(s1.top()->right)
                s2.push(s1.top()->right);

            cout<<s1.top()->data<<" ";
            s1.pop();
        }
        cout<<endl;
        while(!s2.empty())
        {
            if(s2.top()->right)
                s1.push(s2.top()->right);
            if(s2.top()->left)
                s1.push(s2.top()->left);
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
        cout<<endl;

    }

}

void reverseLevelOrderTraversal(node n)
{
    if(n== nullptr)
        return;
    node temp;
    queue<node>q;
    stack<node>s;
    q.push(n);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        s.push(temp);
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);

    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
    return;

}

int sizeOfTree(node n)
{
    if(n== nullptr)
        return 0;
    int l=sizeOfTree(n->left);
    int r=sizeOfTree(n->right);
    return 1+l+r;
}
int heightOfTree(node n)
{
    if(n== nullptr)
        return 0;
    int l=heightOfTree(n->left);
    int r=heightOfTree(n->right);
    return 1+max(l,r);
}
bool sumRootToLeaf(node n,int s)
{
    if (n== nullptr)
        return false;
    if(n->right== nullptr&&n->left== nullptr)
    {
        if(s==n->data)
            return true;
        else
            return false;
    }
    if(n->left||n->right)
    {
        return sumRootToLeaf(n->left,s-n->data)||sumRootToLeaf(n->right,s-n->data);
    }

}
void iterativePostOrder(node n)
{
    if(n== nullptr)
        return;
    stack<node>s1,s2;
    s1.push(n);
    while(!s1.empty())
    {
        node temp=s1.top();
        s1.pop();
        s2.push(temp);//s2 stores the node in the PostOrder
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);

    }
    while(!s2.empty())
    {
        node temp=s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
    return;
}
void iterativePreOrder(node n)
{
    if(n== nullptr)
        return;
    stack<node>s1;
    s1.push(n);
    while(!s1.empty())
    {
        node temp=s1.top();
        s1.pop();
        cout<<temp->data<<" ";
        if(temp->right)
            s1.push(temp->right);
        if(temp->left)
            s1.push(temp->left);


    }
    return;
}
void iterativeInOrder(node n)
{
    if (n== nullptr)
        return;
    stack<node>s;
    cout<<10;
    while(1)
    {
        if(n!= nullptr)
        {
            s.push(n);
            n=n->left;
        }
        else
        {
            if(s.empty())
                break;
            n=s.top();
            cout<<n->data<<" ";
            s.pop();
            n=n->right;
        }
    }
    return;
}
int main() {
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

    levelOrderTraversal(root);
    cout << endl;

    levelOrderSpiralTraversal(root);

}
