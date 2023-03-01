/// note that floyd warshall algo deals with negative edges
/// but don't deal with negavive cycle. If negative cycle exixst then it will fail


#include<bits/stdc++.h>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
#define nn '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    
    int dis[n+1][n+1];
    
    for1(i, n)
    {
        for1(j, n)
        {
            if(i==j) dis[i][j]=0;
            
            else dis[i][j]=1e9;
        }
    }
    
    for0(i, m)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        
        dis[u][v]=wt;
    }
    
    for1(k, n)
    {
        for1(i, n)
        {
            for1(j, n)
            {
                if(dis[i][k]!=1e9 && dis[k][j]!=1e9)
                {
                    dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
    }
    
    for1(i, n)
    {
        for1(j, n)
        {
            if(dis[i][j]==1e9)
            cout << -1 << " "; /// doesn't exist path
            
            else cout << dis[i][j] << " ";
        }
        
        cout << nn;
    }
    
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
6 9
1 2 1
1 3 5
2 3 2 
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2

output
0 1 3 3 2 4 
-1 0 2 2 1 3 
-1 -1 0 -1 2 4 
-1 -1 -1 0 3 1 
-1 -1 -1 -1 0 2 
-1 -1 -1 -1 -1 0
*/