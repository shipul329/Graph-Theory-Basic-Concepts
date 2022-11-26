#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define nn '\n'

const int N=1e5+10;
vector<int>adj[N];
bool vis[N];
int level[N];

void bfs(int node)
{
    queue<int>q;
    
    q.push(node);
    vis[node]=1;
    
    while(!q.empty())
    {
        int cur_node=q.front();
        q.pop();
        
        cout << cur_node << " ";
        
        for(auto child:adj[cur_node])
        {
            if(!vis[child])
            {
                vis[child]=1;
                
                q.push(child);
                level[child]=level[cur_node]+1;
            }
        }
    }
    
    cout << nn;
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
    
    bfs(1);
    
    for1(i, n)
    cout << "Level of " << i << " is : " << level[i] << nn;
    
    cout << nn;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
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