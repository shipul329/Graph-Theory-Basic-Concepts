#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

const int N=1e5+10;
int par[N];
int sz[N];

void make(int v)
{
    par[v]=v; /// parent itself
    sz[v]=1;
}

int find(int v)
{
    if(par[v]==v) return v;
    
    /// path compression 
    return par[v]=find(par[v]); /// recursive call find parent of parent and store parent of ith node 
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    
    /// we will connecte them if both belongs from different set
    if(a!=b)
    {
        /// union by size  
        if(sz[a] < sz[b])
        swap(a, b);
        
        par[b]=a;
        sz[a]+=sz[b];
    }
}

void reset()
{
    for1(i, N) par[i]=0;
    
    for1(i, N) sz[i]=0;
}

void solve()
{
    reset();
    
    int n, m;
    cin >> n >> m;
    
    for1(i, n)
    {
        make(i);
    }
    
    for0(i, m)
    {
        int u, v;
        cin >> u >> v;
        
        Union(u, v);
    }
    
    for1(i, n)
    cout << "Parent of " << i << " " << "is " << par[i] << nn;
    
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
2
4
2
1 2
4 1
5
3
1 2
4 2
3 5

output 
Parent of 1 is 1
Parent of 2 is 1
Parent of 3 is 3
Parent of 4 is 1

Parent of 1 is 1
Parent of 2 is 1
Parent of 3 is 3
Parent of 4 is 1
Parent of 5 is 3
*/