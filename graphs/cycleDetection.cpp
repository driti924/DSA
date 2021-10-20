#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &vis, int parent){
    vis[src]=1;
    for(auto i:adj[src]){
        if(i!=parent){
            if(vis[i]){
                return true;
            }
            if(!vis[i] && isCycle(i, adj, vis, src)){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1, 0);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //
    bool cycle=0;

    for(int i=1;i<=n;i++){
        if(!vis[i] && isCycle(i, adj, vis, -1)){
            cycle=1;
        }
    }
    if(cycle){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present"<<endl;
    }
    return 0;
}
 