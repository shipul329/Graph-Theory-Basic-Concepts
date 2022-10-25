/// Representation of Adjacency Matrix

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define nn '\n'

const int N=1e3+10;

int graph[N][N];

int n, m, u, v;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        
        graph[u][v]=1;
        graph[v][u]=1;
    }
    
    cout << "Adjacency Matrix : " << nn;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << graph[i][j] << " ";
        }
        
        cout << nn;
    }
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

/* intput 
1
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4  */
