#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

int mark[1005];

void dfs(int node, int par, vector<bool>&vis, vector<int>&tin, 
   vector<int>&low, vector<int>adj[], int timer)
{
    vis[node]=true;
    
    tin[node]=low[node]=timer++;
    
    int child=0;
    
    for(auto it:adj[node])
    {
        if(it==par) continue; // do nothing 
        
        if(!vis[it])
        {
            dfs(it, node, vis, tin, low, adj, timer);
            
            low[node]=min(low[node], tin[it]);
            
            if(low[it] >= tin[node] && par!=-1)
            {
                mark[node]=1;
            }
            
            child++;
        }
        
        else{
            low[node]=min(low[node], tin[it]);
        }
    }
    
    if(child>1 && node==-1)
    {
        mark[node]=1;
    }
}

void solve()
{
    
    memset(mark, -1, sizeof(mark));
    
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
    
    vector<bool>vis(n+1, false);
    vector<int>tin(n+1, 0), low(n+1, 0);
    int timer=0;
    
    for0(i, n)
    {
        if(!vis[i])
        dfs(i, -1, vis, tin, low, adj, timer);
    }
    
    vector<int>ans;
    
    for0(i, n)
    {
        if(mark[i]==1)
        ans.pb(i);
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
2
5 5
0 1
1 4
4 3
4 2 
2 3
4 4
0 1
1 2
2 0
1 3

output 
1 4 
1 
*/