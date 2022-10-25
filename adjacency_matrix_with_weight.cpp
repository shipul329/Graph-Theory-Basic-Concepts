
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define nn '\n'

const int N=1e3+10;

int graph[N][N];

int n, m, u, v, wt;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> wt; /// wt is weight here
        
        graph[u][v]=wt;
        graph[v][u]=wt;
    }
    
    cout << "Adjacency Matrix with weights : " << nn;
    
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

/* input 
1
5 7 
0 1 6
0 4 7
1 2 12
1 3 32
1 4 9
2 3 11
3 4 14  */
