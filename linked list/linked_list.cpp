#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000000007
#define pace ios::sync_with_stdio(false);cin.tie(0)
typedef struct LinkedList *node;//Define node as pointer of data type struct LinkedList
int k;
struct LinkedList{
    int data;
    struct LinkedList *next;
};
node createNode(){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}
void addNode(node *head, int value,node *end){   //*head contains the address of the head node   or head is pointer of pointer
    node temp;// declare two nodes temp and p
    temp = createNode();//createNode will return a new node with data = value and next pointing to NULL.
    (*temp).data = value; // add element's value to data part of node
    if(*head == NULL){
        *head = temp;          //same as int *n=&p;*n=p
        *end=temp;
        //when linked list is empty
    }
    else{

        (*end)->next=temp;
        *end=temp;
    }
    return;
}
void deleteNode(node *head,int key,node *end)
{
    //cout<<10<<key<<endl;
    node temp,prev;
    temp=*head;
    // If head node itself holds the key to be deleted
    if(temp!= nullptr&&temp->data==key)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while(temp->data!=key&&temp->next!= nullptr)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp== nullptr)
        return;
    else
    {
        prev->next=temp->next;
        free(temp);
        return;
    }
}
void printList(node n)
{
    while(n!= nullptr)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    return;
}
static void reverse(node* head_ref)
{
    node prev   = NULL;
    node current = *head_ref;
    node next = NULL;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    return;
}
//without swapping data
void swap1(node *head,int x,int y)
{
	if(x==y)
	return;
	node prevX=nullptr;
	node currX=*head;
	while(currX&&currX->data!=x)
	{
		prevX=currX;
		currX=currX->next;
	}
	node prevY=nullptr;
	node currY=*head;
	while(currY&&currY->data!=y)
	{
		prevY=currY;
		currY=currY->next;
	}
	// If either x or y is not present, nothing to do
	if (currX == NULL || currY == NULL)
       return;
    // If x is not head of linked list
	if(prevX!=nullptr)
	prevX->next=currY;
	else
	*head=currY;
	// If y is not head of linked list
	if(prevY!=nullptr)
	prevY->next=currX;
	else
	*head=currX;
	// Swap next pointers
	node temp=currX->next;
	currX->next=currY->next;
	currY->next=temp;
}
//with swapping data
void swap2(node *head,int x,int y)
{
	if(x==y)
	return;
	node currX=*head;
	while(currX&&currX->data!=x)
	{
		currX=currX->next;
	}
	node currY=*head;
	while(currY&&currY->data!=y)
	{
		currY=currY->next;
	}
	// If either x or y is not present, nothing to do
	if (currX == NULL || currY == NULL)
       return;
    // If x is not head of linked list
	// Swap next pointers
	currX->data=y;
	currY->data=x;
}

int countNodes(node head)
{
	if(head==nullptr)
	return 0;
	int c=0;
	while(head!=nullptr)
	{
		head=head->next;
		c++;
	}
	return c;
}
//sorting using selection sort
void sort(node *head)
{
	if((*head)==nullptr||(*head)->next==nullptr)
	return;
	int min;
	
	node temp=*head;
	while(temp!=nullptr)
	{
		min=temp->data;
		node temp2=temp->next;
		while(temp2!=nullptr)
		{
			if(temp2->data<min)
			min=temp2->data;
			temp2=temp2->next;
		}
		//cout<<min<<endl;
		if(min!=temp->data)
		{
		swap2(head,min,temp->data);
		//printList(head);
	}
		temp=temp->next;	
	}
	return;
}
int main()
{
    pace;
    node head= nullptr;
    node end= nullptr;
     int t,n,x;
    cin>>t;
    while(t--)
    {
        head= nullptr;
        end= nullptr;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            addNode(&head, x, &end);
        }
        printList(head);
        cout<<endl;
        //swap(&head,1,2);
        sort(&head);
       printList(head);
        cout<<endl;
        
    }
}
