    #include <bits/stdc++.h>
    using namespace std;
    class Graph {
        int V;
        list<int> *adj;
    public:
        int *distance;//for level of node from parent
        Graph(int v);

        void addEdge(int v, int w);

        void BFS(int s);

        void printGraph();

        void DFS();

        void DFSIterative(int s);

        void DFSUtil(int v,bool visited[]);

        int motherVertex();

        int pathCount(int s,int d);

        void countPathUtil(int s,int d,bool visited[],int &pathCount);

        bool isCyclicUtil(int v,bool visited[],bool recStack[]);

        bool isCyclic();

        void topologicalSort();

        void topologicalSortUtil(int v,bool visited[],stack<int>&s);

        void topologicalSort2();

    };
    Graph::Graph(int v)
    {
        V=v;
        adj=new list<int>[V];
        distance=new int[V];
        memset(distance,INT_MAX,V);
    }
    void Graph::addEdge(int v,int w)
    {
        adj[v].push_back(w);
        //adj[w].push_back(v); //for undirected graph
    }
void Graph::printGraph()
{
    //cout<<V<<endl;
    for(int i=0;i<V;i++)
    {
        for(auto x:adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void Graph::BFS(int s)
{
    bool visited[V]={false};
    queue<int>q;
    visited[s]= true;
    distance[s]=0;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        cout<<s<<" ";
        for(auto x:adj[s])
        {
            if(!visited[x])
            {
                visited[x]=true;
                distance[x]=distance[s]+1;//to get shortest distance between nodes
                q.push(x);
            }
        }
    }
}
void Graph::DFSUtil(int v, bool *visited)
{
    visited[v]=true;
    cout<<v<<" ";
    for(auto i=adj[v].begin();i!=adj[v].end();i++)
    {
        if(!visited[*i])
        {
            DFSUtil(*i,visited);
        }
    }
}
void Graph::DFS()
{
    bool visited[V]={false};

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            DFSUtil(i,visited);//for disconnected nodes
    }
}
void Graph::DFSIterative(int s)
{
    bool visited[V]={false};
    stack<int>a;
    a.push(s);
    visited[s]=true;
    while(!a.empty())
    {
        int d=a.top();
        cout<<d<<" ";
        a.pop();
        for(auto i=adj[d].rbegin();i!=adj[d].rend();i++)
        {
            if(!visited[*i])
            {
                a.push(*i);
                visited[*i]=true;
            }
        }
    }
}
int Graph::motherVertex()
{
    bool *visited=new bool[V];
    memset(visited, false,V);
    int v;
    for(int i=0;i<V;i++)
    {
        if(!visited[i]) {
            DFSUtil(i, visited);
            v=i;
        }
    }
    memset(visited, false,V);
    DFSUtil(v,visited);
    for(int i=1;i<V;i++)
    {
        if(!visited[i])
            return -1;
    }
    return v;

}
void Graph::countPathUtil(int s, int d, bool *visited, int &pathCount)
{
    visited[s]=true;
    if(s==d)
        pathCount++;
    else
    {
        for(auto i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
                countPathUtil(*i,d,visited,pathCount);
        }
    }
    visited[s]=false;
}
int Graph::pathCount(int s, int d)
{
    bool visited[V]={false};
    int pathCount=0;
    countPathUtil(s,d,visited,pathCount);
    for(int i=1;i<V;i++)
        cout<<visited[i]<<endl;
    return pathCount;
}
    void Graph::topologicalSortUtil(int v, bool *visited, stack<int> &s)
    {
        visited[v]= true;
        for(auto i=adj[v].begin();i!=adj[v].end();i++)
        {
            if(!visited[*i])
                topologicalSortUtil(*i,visited,s);
        }
        s.push(v);
    }
    void Graph::topologicalSort()
    {
        bool visited[V]={false};
        stack<int>s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                topologicalSortUtil(i,visited,s);
        }
         while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
//Kahn's Algorithm
void Graph::topologicalSort2()
{
    vector<int>in_degree(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            in_degree[*it]++;
        }
    }
    vector<int>topo;
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }
    int cnt=0;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        topo.push_back(s);
        for(auto i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(--in_degree[*i]==0)
                q.push(*i);
        }
        cnt++;
    }
    if(cnt!=V)
    {
        cout << "There exists a cycle in the graph\n";
        return;
    }

    for(int i=0;i<topo.size();i++)
    {
        cout<<topo[i]<<" ";
    }
}
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    //g.DFS();
    g.topologicalSort2();
}