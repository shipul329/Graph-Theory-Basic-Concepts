#include<bits/stdc++.h>
#define pi acos(-1)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const ll mod=1e9+7;

const int N=1e5+9;

vector<int>adj[N];
bool vis[N];

bool dfs(int v, int par)
{
    vis[v]=true;

    bool isLoopExist=false;

    for(auto it:adj[v])
    {
        if(vis[it] && it==par) continue; /// if visited is parent

        if(vis[it]) return true; /// we find a cycle, means cycle exist or loop exist

        isLoopExist|=dfs(it, v);
    }

    return isLoopExist;
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

    bool exist=false;

    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;

        if(dfs(i, 0))
        {
            exist=true;
            break;
        }
    }

    if(exist) cout << "There is a cycle" << '\n';

    else 
    cout << "There is no cycle" << '\n';

    return 0;
}

/* 
8 5
1 2
2 3
2 4
3 5
6 7
1 5 */
