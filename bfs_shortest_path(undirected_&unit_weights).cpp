#include<bits/stdc++.h>
using namespace std;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'
const int N=1e6+10;

vector<int>adj[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    int src;
    cin >> src;

    for0(i, m)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    int dis[n];

    for0(i, n)
    dis[i]=1e9;

    queue<int>q;

    dis[src]=0;

    q.push(src);

    while(!q.empty())
    {
        int tmp=q.front();

        q.pop();

        for(auto it:adj[tmp])
        {
            if(dis[tmp]+1<dis[it])
            {
                dis[it]=dis[tmp]+1;
                q.push(it);
            }
        }
    }

    vector<int>ans(n, -1);

    for0(i, n)
    {
        if(dis[i]!=1e9)
        ans[i]=dis[i];
    }

    for(auto it:ans)
    cout << it << " ";

    cout << nn; 
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
9 10 0
0 1
0 3
3 4
4 5
5 6
1 2
2 6
6 7
7 8
6 8

output
0 1 2 1 2 3 3 4 4 
*/
