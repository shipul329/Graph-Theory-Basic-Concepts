/// Minimum Spanning Tree using Prims algorithm

#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

const int N=1e5+10;

int par[N];
int sz[N];

void make(int v)
{
    par[v]=v;
    sz[v]=1;
}

int find(int v)
{
    if(par[v]==v) return v;
    
    /// path compression
    return par[v]=find(par[v]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    
    /// if both belong from different set 
    
    if(a!=b)
    {
        if(sz[a] < sz[b])
        swap(a, b);
        
        /// union by size 
        par[b]=a;
        sz[a]+=sz[b];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    for0(i, n) /// 1 instead of 0 for 1 base indexing 
    make(i);
    
    vector<pair<int, pair<int, int> > > edges;
    
    for0(i, m)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        
        edges.pb({wt, {u, v}}); /// to deal with cost wt(weight) insert first 
    }
    
    sort(all(edges));
    
    int tot=0;
    
    for(auto it:edges)
    {
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        
        if(find(u)==find(v)) continue;
        
        Union(u, v); /// to get edges need to print u & v 
        tot+=wt;
    }
    
    cout << tot << nn;
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
3 3
0 1 5
1 2 3
0 2 1
6 9
4 3 9
0 3 1
4 0 4 
3 2 5
3 1 3
0 1 2
2 1 3 
2 5 8
1 5 7

output 
4 
17

*/