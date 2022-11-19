/// find maximum value deleting one edge from tree
/// basically the approach is we will precompute sum of total tree then we will go for 
/// how it says, it can max_sum, product whatever! once we find and precompute it then
/// it will be very easy

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

const int N=1e5+10;
vector<int>adj[N];
int subtree_sum[N];
int val[N];

void dfs(int node, int parent)
{
    subtree_sum[node]+=val[node];
    
    for(auto child:adj[node])
    {
        if(child==parent) continue;
        
        dfs(child, node);
        subtree_sum[node]+=subtree_sum[child];
    }
}

void solve()
{
    int n;
    cin >> n;
    
    for0(i, n-1)
    {
        int u, v;
        cin >> u >> v;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for1(i, n)
    {
        int x;
        cin >> x;
        
        val[i]=x;
    }
    
    dfs(1, 0);
    
    ll ans=0;
    ll tot=subtree_sum[1]; /// total sum of the tree since 1 is root node
    
    for(int i=2; i<=n; i++)
    {
        ll tmp=subtree_sum[i];
        
        ans=max(ans, tot-tmp);
    }
    
    cout << "Maximum is : " << ans << nn;
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
4
1 2
1 4
4 3
10
5
12
6
*/