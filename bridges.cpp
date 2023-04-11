#include<bits/stdc++.h>
using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

void dfs(int node, int par, vector<int>&vis, vector<int>&tin, vector<int>&low, int &timer, vector<int>adj[])
{
    vis[node]=1;

    tin[node]=low[node]=timer++;

    for(auto it:adj[node])
    {
        if(it==par) continue;

        if(!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj);

            low[node]=min(low[node], low[it]);

            if(low[it] > tin[node])
            {
                cout << node << " " << it << nn; /// find bridge
            }
        }

        else{
            low[node]=min(low[node], low[it]);
        }
    }
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
        adj[v].pb(u);
    }
    
    vector<int>tin(n, -1), low(n, -1), vis(n, 0);
    
    int timer=0;
    
    for0(i, n)
    {
        if(!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin >> t;

    while(t--)
    solve();

    return 0;
}

/*
input 
4 4
0 1
1 2
2 0
1 3

output
1 3 

*/
