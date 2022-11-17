/// DFS Subtree questions 
/// Precomputation using DFS
/// Subtree Sum queries 
/// Even Odd count in Subtree

/* 
Given Q queires Q<=10^5 
     * in each query given value
     * print subtree sum of value & number of even numbers in subtree of value
*/

#include<bits/stdc++.h>
#define pi acos(-1)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define pb push_back
 
#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(),v.end()
#define nn '\n'

const int N=1e5+10;

vector<int>adj[N];
int subtree_sum[N];
int Val[N];
int even_count[N];
vector<int>v(N);

void dfs(int node, int parent)
{
    if(node%2==0)
    {
        even_count[node]++; /// this means node is even itself 
    }
    
    subtree_sum[node]+=Val[node]; /// as per step no 4
    
    for(auto child:adj[node])
    {
        if(child==parent) continue;
        
        dfs(child, node);
        
        subtree_sum[node]+=subtree_sum[child]; /// setp no 3
        even_count[node]+=even_count[child];
    }
    
    /// or we can do the same thing over there for step no 4
}

void solve()
{
    int n;
    cin >> n;
    
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    /// value of vertex/node
    
    for0(i, n)
    {
        int x;
        cin >> x;
        
        Val[i]=x;
    }
    
    dfs(1, 0);
    
   // for1(i, n)
   // cout << subtree_sum[i] << " " << even_count[i] << nn;
   
   
   /// queires 
   
    int q;
    cin >> q;
    
    while(q--)
    {
        int x;
        cin >> x;
        
        cout << subtree_sum[x] << " " << even_count[x] << nn;
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
13  /// adjacency list 
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

/// value of nodes
18
45
76
87
36
23
55
28
54
91
88
12
19

/// queires
5
4
7
9
1
3
*/