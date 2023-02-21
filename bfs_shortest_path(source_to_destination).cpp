#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

bool bfs(vector<int>adj[], int s, int dst, int par[], int dis[], bool vis[], int n)
{
    queue<int>q;

    q.push(s);
    vis[s]=true;
    dis[s]=0;

    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();

        for(auto it:adj[tmp])
        {
            if(!vis[it])
            {
                vis[it]=true;
                dis[it]=dis[tmp]+1; /// count distance 

                par[it]=tmp; /// store parent
                q.push(it);

                if(it==dst){ // once we get our distance, simply break over there
                    return true;
                }
            }
        }
    }

    return false;
}

void S_Dis(vector<int>adj[], int s, int dst, int n)
{
    int par[n], dis[n];
    
    bool vis[n];

    for0(i, n)
    {
        dis[i]=INT_MAX;
        par[i]=-1;
        vis[i]=false;
    }

    if(bfs(adj, s, dst, par, dis, vis, n)==false) /// source and destination not connected
    {
        cout << "Given source and destination are not connected" << nn;
        return;
    }

    vector<int>ans;
    
    int cur=dst;
    ans.push_back(cur); /// we know parent of source node parent itself

    while(par[cur]!=-1)
    {
        ans.pb(par[cur]);
        cur=par[cur];
    }

    reverse(all(ans));

    cout << "Shortest Path is : " << dis[dst] << nn;

    cout << "Path is : ";

    for(auto it:ans)
    cout << it << " ";

    cout << nn;
}

void solve()
{
    int n, m; // nodes and edges 
    cin >> n >> m;
    
    int source, dest; // source and destination
    cin >> source >> dest;

    vector<int>adj[n+5];

    for0(i, m)
    {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    S_Dis(adj, source, dest, n); // call Shortest Distand function
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
3
8 10 
0 6
0 1
0 3
1 2
3 4
3 7
4 5
4 6
4 7
5 6
6 7
10 10
1 8
1 2 
1 3
2 5
3 6
5 7
6 10
6 9
9 4
4 8
7 8
5 6
1 8
1 2
1 3
5 6 
6 9
4 8
5 7

output
Shortest Path is : 3
Path is : 0 3 4 6 
Shortest Path is : 4
Path is : 1 2 5 7 8 
Given source and destination are not connected

*/