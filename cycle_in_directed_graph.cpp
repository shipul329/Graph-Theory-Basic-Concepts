#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

bool isCycle(int node, vector<int>adj[], int vis[], int pathVis[])
{
    vis[node]=1;
    pathVis[node]=1;

    for(auto child:adj[node])
    {
        if(!vis[child] && isCycle(child, adj, vis, pathVis))
        return true;

        else if(pathVis[child])
        return true;
    }

    pathVis[node]=0;
    return false;
}

bool iscycle(int n, vector<int>adj[])
{
    int vis[n]={0};
    int pathVis[n]={0};

    for0(i, n)
    {
        if(!vis[i] && isCycle(i, adj, vis, pathVis))
        return true;
    }

    return false;
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

    if(iscycle(n, adj))
    cout << "YES! Cycle Exist" << nn;

    else cout << "There is no cycle" << nn;
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


/* ................................................ 2nd approach..................................... */

/// find cycle in directed graph

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

bool iscycle_util(vector<int>adj[], vector<bool>vis, int cur)
{
    if(vis[cur]==true)
    return true;
    
    vis[cur]=true;
    
    for(int i=0; i<adj[cur].size(); i++)
    {
        if(iscycle_util(adj, vis, adj[cur][i]))
        return true;
    }
    
    return false;
}

bool iscycle(int n, vector<int>adj[])
{
    vector<bool>vis(n, false);
    
    for0(i, n)
    {
        vis[i]=true;
        for0(j, adj[i].size())
        {
            if(iscycle_util(adj, vis, adj[i][j]))
            return true;
        }
        
        vis[i]=false;
    }
    
    return false;
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
    
    if(iscycle(n, adj))
    cout << "YES!" << nn;
    
    else cout << "NO!" << nn;
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
intput 
1
4 4
0 1
0 2
2 3
3 3
*/
