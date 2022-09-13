#include<bits/stdc++.h>
 
using namespace std;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'
     

const int N=1e5+9;

vector<int>adj[N];
bool vis[N];

int x, y, tmp;

void dfs(int v)
{
    vis[v]=true;

    cout << "vertext : " << v << nn;

    for(auto it:adj[v])
    {
        cout << "Parent : " << v << " child : " << it << nn;
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
        tmp=x;

        adj[x].push_back(y);
        adj[y].push_back(x);
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
    dfs(tmp); /// tmp represents here as a starting node
 
    return 0;
}