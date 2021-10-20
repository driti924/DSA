#include <bits/stdc++.h>
using namespace std;

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
    for(int i=1;i<=n;i++){
        cout<<i<<"-> ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }//
    //
    vector<bool> vis(n+1,0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int elem=q.front();
        q.pop();
        cout<<elem<<endl;
        for(auto i: adj[elem]){
            if(vis[i]==0){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    cout<<'a'-'a'<<" "<<'z'-'a'<<endl;
    return 0;
}
 