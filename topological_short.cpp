#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back 
#define nn '\n'

void dfs(int node, vector<int>&vis, vector<int>adj[], stack<int>&st)
{
    vis[node]=1;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    
    st.push(node);
} 

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<int>adj[n+3];
    
    for0(i, m)
    {
        int u, v;
        cin >> u >> v;
        
        adj[u].pb(v);
    }
    
    vector<int>vis(n+3, 0);
    
    stack<int>st;
    
    for0(i, n+1)
    {
        if(!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    
    vector<int>ans;
    
    while(!st.empty())
    {
        ans.pb(st.top());
        st.pop();
    }
    
    for(auto it:ans)
    cout << it << " ";
    
    cout << nn;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}

/*
input 
1
5 6 
5 0 
5 2 
2 3 
1 3
4 1 
4 0

output 
5 4 2 1 3 0 
*/