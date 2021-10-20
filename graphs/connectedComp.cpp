#include <bits/stdc++.h>
using namespace std;

int get_comp(int vertex, vector<vector<int>> &adj, vector<bool> &vis){
    if(vis[vertex]){
        return 0;
    }
    int ans=1;
    vis[vertex]=1;
    for(auto i: adj[vertex]){
        ans+=get_comp(i, adj, vis);
        vis[i]=1;
    }
    return ans;
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1, 0);
    vector<int> connectedcomp;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    //

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            connectedcomp.push_back(get_comp(i, adj, vis));
        }
    }
    for(auto i: connectedcomp){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
  