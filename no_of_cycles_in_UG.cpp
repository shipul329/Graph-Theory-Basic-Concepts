#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const ll N=2*1e5+9;

vector<int>adj[N];
ll Dtimer[N];
bool vis[N];
ll timer=1, cnt=0;

void dfs(int v, int par)
{
    Dtimer[v]=timer;
    timer++;
    vis[v]=true;

    for(auto it:adj[v])
    {
        if(vis[it] && it==par) continue; /// if visited is parent

        if(vis[it] && Dtimer[it]<Dtimer[v])
        {
            cnt++;
        }

        if(!vis[it])
        dfs(it, v);
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

    int n, e; /// no of nodes and edges 
    cin >> n >> e;

    for(int i=0; i<e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
    
    cout << cnt << nn; // no of cycles in undirected graph

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
