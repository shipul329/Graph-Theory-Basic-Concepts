/// print shortest path

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

void dijkstra(vector<pair<int,int> > adj[], int src, int dis[], int par[], int n)
{
    bool vis[n+5];
    
    for1(i, n) vis[i]=false;
    
    set<pair<int,int> > st;
    st.insert({0, src});
    dis[src]=0;
    par[src]=src;
    
    while(!st.empty())
    {
        auto it=*st.begin();
        st.erase(st.begin());
        
        int nod=it.second;
        
        if(vis[nod]) continue;
        
        vis[nod]=true;
        
        for(auto it2:adj[nod])
        {
            int child=it2.first;
            int wt=it2.second;
            
            if(dis[nod]+wt < dis[child])
            {
                dis[child]=dis[nod]+wt;
                st.insert({dis[child], child});
                par[child]=nod;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<pair<int,int> > adj[n+5];
    
    for0(i, m)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        
        adj[u].pb({v, wt});
        adj[v].pb({u, wt});
    }
    
    int src;
    cin >> src;
    
    int dis[n+5], par[n+5];
    
    for1(i, n)
    {
        dis[i]=1e9;
        par[i]=-1;
    }
    
    dijkstra(adj, src, dis, par, n);
    
    vector<int>path;
    
    int tmp=n;
    
    while(par[tmp]!=tmp)
    {
        path.pb(tmp);
        
        tmp=par[tmp];
    }
    
    path.pb(1);
    
    reverse(all(path));
    
    cout << "Shortest Path is : ";
    
    for(auto it:path)
    cout << it << " ";
    
    cout << nn;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}

/*
input 
5 6
1 2 2
1 4 1
2 5 5
2 3 4
4 3 3
3 5 1
1

output
Shortest Path is : 1 4 3 5 
*/