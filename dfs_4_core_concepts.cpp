/// when and how to implement dfs on a question. basically this concept will help to implement why, when and how we use dfs

#include<bits/stdc++.h>
 
using namespace std;

const int N=1e5+10;

vector<int>adj[N];
bool vis[N];

void dfs(int vertex)
{
    // setp 1: take action on vertex after entering the vertex 

    for(auto child:adj[vertex])
    {
        // step 2: take action on child before entering the child node

        dfs(child);
        {
            // setp 3: take action on child after exiting childe node
        }
    }

    // setp 4: take action on vertex before exiting the vertex
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

    return 0;
}
