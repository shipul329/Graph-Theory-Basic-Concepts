#include<bits/stdc++.h>
using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

const int N=1e5+10; 

vector<int>adj[N];
int par[N];

void dfs(int node, int parent)
{
    par[node]=parent; /// store parent

    for(auto child:adj[node])
    {
        if(child==parent) continue;

        dfs(child, node);
    }
}

vector<int>path(int node) /// finding path
{
    vector<int>ans;

    while(node!=0)
    {
        ans.pb(node);
        node=par[node];
    }

    reverse(all(ans));

    return ans;
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

    dfs(1, 0);

    int x, y;
    cin >> x >> y;

    vector<int>path_x=path(x); /// path of x node
    vector<int>path_y=path(y); /// path of y node

    int mn_sz=min(path_x.size(), path_y.size()); /// it will be fine to check with minimum size

    int LCA=-1;

    for0(i, mn_sz)
    {
        if(path_x[i]==path_y[i])
        {
            LCA=path_x[i];
        }

        else break;
    }

    cout << "LCA is : " << LCA << nn;
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

/*
input
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
9 11 
*/

