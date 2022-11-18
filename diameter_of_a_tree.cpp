#include<bits/stdc++.h>
using namespace std;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

const int N=1e5+10; 

vector<int>adj[N];
int depth[N];

void dfs(int node, int parent)
{
    for(auto child:adj[node])
    {
        if(child==parent) continue;

        depth[child]=depth[node]+1;

        dfs(child, node);
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

    dfs(1, 0);

    int mx_dpth=0;
    int mx_nod;

    for1(i, n)
    {
        if(mx_dpth<depth[i])
        {
            mx_dpth=depth[i];
            mx_nod=i;
        }

        depth[i]=0; /// we have to reset this cuz we gonna run dfs one more time
    }

    dfs(mx_nod, 0); /// here we run again with end of diameter node

    for1(i, n)
    {
        if(mx_dpth<depth[i])
        {
            mx_dpth=depth[i];
        }
    }

    cout << mx_dpth << nn;
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
*/

