#include<bits/stdc++.h>
 
using namespace std;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const int N=1e5+9;

vector<int>adj[N];
bool vis[N];
vector<vector<int> > cc; /// connected components
vector<int>current_cc; /// current connected components

int x, y, tmp;

void dfs(int v)
{
    vis[v]=true;
    current_cc.push_back(v); /// whenever we enter any vertes simply we store them on connected_component

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

    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        tmp=x;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;

        current_cc.clear(); /// remove previous

        dfs(i);
        cc.push_back(current_cc); /// we want to store everty node for each connected nodes
    }

    cout << cc.size() << nn; /// size of connected_component

    for(auto it:cc)
    {
        for(auto it2:it)
        cout << it2 << " ";

        cout << nn;
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
    
    solve();
    dfs(tmp);
 
    return 0;
}