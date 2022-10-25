
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

void solve()
{
    int n, m, u, v;
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
        cout << "Node " << i << " connected with";
        for(auto it:adj[i])
        cout << "->" << it;

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
5 7 
0 1
0 4
1 2 
1 3 
1 4
2 3 
3 4  */
