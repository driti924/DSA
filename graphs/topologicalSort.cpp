#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    //
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int elem=q.front();
        q.pop();
        cout<<elem<<" ";
        for(auto it:adj[elem]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    return 0;
}
 