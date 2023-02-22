/// https://www.codechef.com/problems/REVERSE?tab=statement

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define nn '\n'

const int N=1e5+10;
const int INF=1e9+10;
vector<pair<int,int> >adj[N];
vector<int>level(N, INF);

int n, m;

int bfs()
{
    deque<int>q;

    q.pb(1);
    level[1]=0;

    while(!q.empty())
    {
        int cur_node=q.front();

        q.pop_front();

        for(auto child:adj[cur_node])
        {
            int child_v=child.first;
            int wt=child.second;
            
            /// level[cur_node]+wt = level of child node 
            /// level[cur_node]= level of current node 

            if(level[cur_node]+wt < level[child_v])
            {
                level[child_v]=level[cur_node]+wt;
                
                if(wt==1) q.pb(child_v);
                
                else q.push_front(child_v);
            }
        }
    }

    return level[n]==INF ? -1 : level[n];
}

void solve()
{
    cin >> n >> m;

    for0(i, m)
    {
        int u, v;
        cin >> u >> v;

        if(u==v) continue;

        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }

    cout << bfs() << nn;
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