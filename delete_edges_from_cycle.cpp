/// How many edges should be deleted from the undirected 
/// graph so that given graph does not contain any cycle
/// so the tecnique is (node+connected_components-edges)
/// which is n+cnt-m

/// This is similar problem from atcoder 
/// https://atcoder.jp/contests/abc288/tasks/abc288_c

#include<bits/stdc++.h>
 
using namespace std;

typedef long long ll;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'
     

const ll N=2*1e5+9;

vector<int>adj[N];
bool vis[N];

int x, y, tmp;

void dfs(int v)
{
    vis[v]=true;

    for(auto it:adj[v])
    {
        if(vis[it]) continue;

        dfs(it);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int cnt=0;

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;

        dfs(i);
        cnt++;
    }

    cout << m-n+cnt << nn;
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
    
    solve();
    dfs(tmp);
 
    return 0;
}

/*

6 7
1 2
1 3
2 3
4 2
6 5
4 6
4 5
*/