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
multiset<int>st;

void make(int v)
{
    par[v]=v;
    sz[v]=1;
    st.insert(1);
}

int find(int v)
{
    if(par[v]==v) return v;
    
    // path compression 
    return par[v]=find(par[v]);
}

void merge(int a, int b)
{
    st.erase(st.find(sz[a]));
    st.erase(st.find(sz[b]));
    
    st.insert(sz[a]+sz[b]);
}

void Union(int a, int b)
{
    a=find(a);
    b=find(b);
    
    if(a!=b)
    {
        if(sz[a] < sz[b])
        {
            swap(a, b);
        }
        
        par[b]=a;
        merge(a, b);
        
        sz[a]+=sz[b];
    }
}

void solve()
{
    int n, q;
    cin >> n >> q; /// nodes and queries
    
    for1(i, n)
    {
        make(i);
    }
    
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        
        Union(u, v);
        
        if(st.size()==1)
        {
            cout << 0 << nn;
        }
        
        else{
            int mx=*(--st.end());
            int mn=*(st.begin());
            
            cout << mx - mn << nn;
        }
    }
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
intput 
6 4
1 2
2 5
2 6
3 4

output
1
2
3
2

*/