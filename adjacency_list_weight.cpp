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
    int n, m, u, v, wt;
    cin >> n >> m;

    vector<pair<int,int> >adj[n];

    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    for(int i=0; i<n; i++)
    {
        cout << "Node " << i << " connected with these" << nn;
        
        for(auto it:adj[i])
        {
            cout << "cost of " << i << "->" << it.first << " is " << it.second << nn;
        }

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
0 1 10
0 4 20
1 2 30
1 3 40
1 4 50
2 3 60
3 4 70  */
