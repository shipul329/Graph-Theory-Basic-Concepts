/// find depth and height of a Tree using dfs

#include<bits/stdc++.h>
#define pi acos(-1)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define pb push_back
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const int N=1e5+10;
vector<int>adj[N];

int depth[N], height[N];

void dfs(int node, int parent)
{
    for(auto child:adj[node])
    {
        if(child==parent) continue;
        
        depth[child]=depth[node]+1;
        
        dfs(child, node);
        height[node]=max(height[node], height[child]+1);
    }
}

void solve()
{
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);

    for(int i=1; i<=n; i++)
    {
        cout << depth[i] << " " << height[i] << nn;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }

    return 0;
}

/* input
1
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/