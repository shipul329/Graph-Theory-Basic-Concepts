/// find shortest path from a single source with negative edges
/// bellman ford algo will help to find shortest path
/// since dijkstra algo don't deal with negative edges
/// that is why we can't find shortest path using dijkstra algo 
/// but the advantage of bellmang ford algo we can detect a negative cycle 

#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

struct node{
    int u;
    int v;
    int wt;
    
    node(int first, int second, int third)
    {
        u=first;
        v=second;
        wt=third;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<node>edges;
    
    for0(i, m){
        int u, v, wt;
        cin >> u >> v >> wt;
        
        edges.pb(node(u, v, wt));
    }
    
    int source;
    cin >> source;
    
    vector<int>dis(n, 1e9);
    
    dis[source]=0;
    
    for0(i, n-1)
    {
        for(auto it:edges)
        {
            if(dis[it.u] + it.wt < dis[it.v])
            {
                dis[it.v]=dis[it.u]+it.wt;
            }
        }
    }
    
    bool flag=false;
    
    for(auto it:edges)
    {
        if(dis[it.u]+it.wt < dis[it.v])
        {
            flag=true;
            break;
        }
    }
    
    if(flag)
    {
        cout << "Negative Cycle exist!" << nn;
    }
    
    else{
        for0(i, n)
        cout << dis[i] << " ";
        
        cout << nn;
    }
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
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0

output
0 5 3 3 1 2 
*/