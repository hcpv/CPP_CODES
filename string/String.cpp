#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    string s1;
    stringstream str(s);
    s="";
    while(str>>s1)
    {
        if(s=="")
        s=s1;
        else
        s=s1+" "+s;
    }
    cout<<s<<endl;
    
}
//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
int calculate(string A[],int n)
{
    stack<string>s;
    stringstream str1;
    string s1,s2;
    int a,b;
    for(int i=0;i<n;i++)
    {
        //cout<<A[i]<<endl;
        if(A[i]=="+"||A[i]=="-"||A[i]=="*"||A[i]=="/")
        {
            s1=s.top();
            s.pop();
            str1.clear();
            str1<<s1;
            str1>>a;
            s1=s.top();
            s.pop();
            str1.clear();
            str1<<s1;
            str1>>b;
            if(A[i]=="+")
            a=a+b;
            else if(A[i]=="-")
            a=b-a;
            else if(A[i]=="*")
            a=a*b;
            else if(A[i]=="/")
            a=b/a;
            str1.clear();
            str1<<a;
            str1>>s1;
            //cout<<s1<<endl;
            s.push(s1);
        }
        else
        {
            s.push(A[i]);
        }
    }
    s1=s.top();
    str1.clear();
    str1<<s1;
    str1>>a;
    return a;
		
}
int prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		
	}
	return -1;
}
void infixToPostfix(string exp)
{
	int n=exp.length();
	stack<char>s,op;
	for(int i=0;i<n;i++)
	{
	    //cout<<exp[i]<<endl;
		if((exp[i]>='a'&&exp[i]<='z')||(exp[i]>='A'&&exp[i]<='Z'))
		s.push(exp[i]);
		else if(exp[i]=='(')
		op.push(exp[i]);
		else if(exp[i]==')')
		{
			while(!op.empty()&&op.top()!='(')
			{
				s.push(op.top());
				op.pop();
	  		}  
	  		op.pop();
		}
		else
		{
			while(!op.empty()&&prec(exp[i])<=prec(op.top()))
			{
				s.push(op.top());
				op.pop();
				}	
				op.push(exp[i]);
	    }	
	}
   while(!op.empty())
	{
	    s.push(op.top());
	    op.pop();
	}
	exp="";
	while(!s.empty())
	{
	    //cout<<s.top();
		exp+=s.top();
		s.pop();
	}
	reverse(exp.begin(),exp.end());
	cout<<exp;
}
int main() {
	char exp[] = "a*b+c";
    infixToPostfix(exp);
	/*int t;
	cin>>t;
	cin.ignore();
	string s;
	while(--t>=0)
	{
	    getline(cin,s);
	    reverse(s);
	}*/
}
