#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

void dfs(int node, vector<bool>&vis, vector<int>adj[]) // we run a simple dfs 
{
    vis[node]=true;

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it, vis, adj);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int>adj[n+1];

    vector<bool>vis(n+1, false);

    for0(i, m)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    // first we need to find out root node
    // think about why? or maybe we select any randome node 

    int node=-1;

    for0(i, n)
    {
        if(adj[i].size()>0)
        {
            node=i;
            break;
        }
    }

    if(node==-1) // no edges and no node so it's always Eulerian
    {
        cout << "Graph is a Euler Graph" << nn;
        return;
    }

    dfs(node, vis, adj);

    // now check no of components 

    bool flag=true;

    for0(i, n)
    {
        if(!vis[i] && adj[i].size()>0) // found multi components 
        {
            flag=false;
            break;
        }
    }

    if(flag==false)
    {
        cout << "Graph is not Eulerin" << nn;
        return;
    }

    // now count odd degree nodes 
    int cnt=0;

    for0(i, n)
    {
        if(adj[i].size()&1)
        cnt++;
    }

    if(cnt==2) 
    cout << "Graph is Semi_Eulerin" << nn;

    else if(cnt==0)
    cout << "Graph is Eulerian" << nn;

    else cout << "Graph is not Eulerian" << nn;
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
3
5 6
0 1
0 2
0 3
1 2
1 3
3 4
5 6
0 1
0 2
0 3
0 4
1 2
3 4
5 5
0 1
0 3
0 2
1 2
3 4

output
Graph is not Eulerian
Graph is Eulerian
Graph is Semi_Eulerin

*/