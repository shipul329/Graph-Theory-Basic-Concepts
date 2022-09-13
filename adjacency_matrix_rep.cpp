/// This is about adjacency_matrix representation 
/// also we find no of connected components by using adj_matrix

#include<bits/stdc++.h>

using namespace std;

int dx[]={0, 1, 1, 1, 0, -1, -1, -1};
int dy[]={1, 1, 0, -1, -1, -1, 0, 1};

void dfs(int i, int j, vector<vector<bool> >&vis, vector<vector<char> > &grid)
{
    int n=grid.size();
    int m=grid[0].size();

    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;

    if(grid[i][j]=='0') return;

    if(!vis[i][j])
    {
        vis[i][j]=true;

        for(int k=0; k<8; k++)
        {
            dfs(i+dx[k], j+dy[k], vis, grid);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > grid(n, vector<char>(m, '&'));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int cnt=0;

    vector<vector<bool> > vis(n, vector<bool>(m, false));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!vis[i][j] && grid[i][j]!='0')
            {
                dfs(i, j, vis, grid);
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}

/*
2 7
0 1 1 1 0 0 0
0 0 1 1 0 1 0 

ans=2 

*/