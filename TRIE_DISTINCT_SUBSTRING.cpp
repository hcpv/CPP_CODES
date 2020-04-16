#include<bits/stdc++.h>
#define Trie struct TrieNode*
using namespace std;
struct TrieNode{
  Trie child[26];
  bool isEnd;
  TrieNode()
  {
    for(int i=0;i<26;i++)
    child[i]=NULL;
    isEnd=false;
  }
};
void insert(Trie A,string s)
{
  int n=s.length();
  for(int i=0;i<n;i++)
  {
    int t=s[i]-'a';
    if(A->child[t]==NULL)
    A->child[t]=new TrieNode();
    A=A->child[t];
  }
  A->isEnd=true;
}
int count(Trie A)
{
  int sol=1;
  for(int i=0;i<26;i++)
  {
    if(A->child[i])
    sol+=count(A->child[i]);
  }
  return sol;
}
int main()
{
  string s;
  cin>>s;
  int n=s.size();
  Trie root=new TrieNode();
  for(int i=0;i<n;i++)
  {
    insert(root,s.substr(i));
  }
  cout<<count(root)<<endl;
}
