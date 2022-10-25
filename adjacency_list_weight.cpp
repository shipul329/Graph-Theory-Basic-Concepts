#include<bits/stdc++.h>
#define pi acos(-1)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const ll mod=1e9+7;

const int N=1e3+10;
int g[N][N];

int u, v;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int>adj[n];

    for(int i=0; i<m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++)
    {
        for(auto it:adj[i])
        cout << it << "->";

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

    return 0;
}
