#include <bits/stdc++.h>
using namespace std;

void dfs(int elem, vector<bool> &vis, vector<vector<int>> adj){
    //preorder
    vis[elem]=1;
    cout<<elem<<" ";
    for(auto i: adj[elem]){
        if(vis[i]);
        else{
            dfs(i,vis,adj);
        }
    }
    //postorder
    //cout<<elem<<" ";
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //
    vector<bool> vis(n+1,0);
    dfs(1,vis,adj);

    return 0;
}
 