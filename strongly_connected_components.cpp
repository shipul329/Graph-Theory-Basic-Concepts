    /// three step to find scc
    /// 1. order the vertices in decreasing order of hteir finish time in DFS
    /// 2. reverse all the edges of the graph
    /// 3. do dfs of the reversed graph in the order obtained in step 1
    /// 4. and for every dfs call increase the scc by one 

#include<bits/stdc++.h>
using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

vector<int>con_cc;
vector<vector<int>>ans;

void dfs(int node, vector<int>&vis, vector<int>adj[], stack<int>&st)
{
    vis[node]=1;

    for(auto it:adj[node])
    {
        if(!vis[it])
        dfs(it, vis, adj, st);
    }

    st.push(node);
}

void dfs2(int node, vector<int>&vis, vector<int>adjT[])
{
    vis[node]=1;
    con_cc.pb(node);

    for(auto it:adjT[node])
    {
        if(vis[it]) continue;

        if(!vis[it])
        {
            dfs2(it, vis, adjT); 
        }
    }
}

void kosaraju(int n, vector<int>adj[])
{
    vector<int>vis(n, 0);

    stack<int>st;
    
    /// step 1 
    for0(i, n)
    {
        if(!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    /// now transpose the paths -> step 2 

    vector<int>adjT[n];
    
    for0(i, n)
    {
        vis[i]=0;

        for(auto it:adj[i])
        {
            adjT[it].pb(i);
        }
    }

    int scc=0;

    while(!st.empty())
    {
        int node=st.top();
        st.pop();

        if(!vis[node])
        {
            scc++;
            
            /// step 3 
            dfs2(node, vis, adjT); 
            
            ans.pb(con_cc); /// store connected componentes 
            con_cc.clear(); 
        }
    }

    cout << scc << nn;

    for(auto it:ans)
    {
        for(auto it2:it)
        {
            cout << it2 << " ";
        }

        cout << nn;
    }

    ans.clear();
    cout << nn;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int>adj[n];

    for0(i, m)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v); 
    }

    kosaraju(n, adj);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout); 
    #endif

    int t;
    cin >> t; 

    while(t--)
    solve();

    return 0;
}

/*
input 
3
5 5
1 0
0 2
2 1
0 3
3 4
3 3
0 1
1 2 
2 0
8 10
0 1
1 2
2 0
2 3
3 4
4 5
5 6
6 4
4 7
6 7

output 
3
0 1 2 
3 
4 

1
0 2 1 

4
0 2 1 
3 
4 6 5 
7 

*/