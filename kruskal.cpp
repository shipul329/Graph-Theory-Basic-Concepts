#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    par[v]=v; /// parent itself 
    sz[v]=1;
}

int find(int v)
{
    if(par[v]==v) return v;
    
    /// path compression
   return par[v]= find(par[v]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    
    if(a!=b)
    {
        /// Union by size
        if(sz[a] < sz[b])
        {
            swap(a, b);
        }
        
        par[b]=a;
        sz[a]+=sz[b];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    for1(i, n)
    make(i);
    
    /// now we wnat to implement kruskal alrithm 
    
    vector<pair<int, pair<int, int> > > edges; /// 
    
    for0(i, m)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        
        edges.pb({wt, {u, v}});
    }
    
    int tot_cost=0;
    
    sort(all(edges));
    
    for(auto edge:edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        
        if(find(u)==find(v)) continue; /// belong from the same set 
        
        cout << u << " " << v << nn;
        Union(u, v);
        
        tot_cost+=wt;
    }
    
    cout << tot_cost << nn;
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
6 9
5 4 9
1 4 1
5 1 4 
4 3 5
4 2 3
1 2 2
3 2 3 
3 6 8
2 6 7

output 
1 4
1 2
3 2
5 1
2 6
17
*/