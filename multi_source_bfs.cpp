#include<bits/stdc++.h>
using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int>adj[n+5];

    for0(i, m)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    } 

    // multiple sources 

    int sources;
    cin >> sources;

    queue<int>q;

    vector<int>vis(n+5, 0), dis(n+5, 1e9);

    for0(i, sources) // push all the sources into the queue with 0th level 
    {
        int src;
        cin >> src;

        dis[src]=0;
        vis[src]=1;
        q.push(src);
    }

    int dst;
    cin >> dst;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                
                if(dis[node]+1 < dis[it])
                {
                    dis[it]=dis[node]+1;
                    q.push(it);
                }
            }
        }
    }

    if(dis[dst]==1e9) cout << -1 << nn; // not reachable 

    else cout << dis[dst] << nn;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    solve();

    return 0;
}


/*
input 
1
9 10  // nodes & edges 
7 1
7 4
1 2 
2 9
4 6
4 5
3 6
3 5
3 8
5 8
4 // sources 
9
3
5
8
7 // destination 

output 
2 
*/