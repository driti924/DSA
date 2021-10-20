#include <bits/stdc++.h>
using namespace std;
bool bipar;
void givecolor(int i, int curcolor, vector<int> &color, vector<vector<int>> &adj, vector<bool> &vis){
    if(color[i]!=-1 && curcolor!=color[i]){
        bipar=false;
        return;
    }
    if(vis[i]){
        return;
    }
    vis[i]=1;
    color[i]=curcolor;
    for(auto it: adj[i]){
        if(color[it]!=-1)
            givecolor(it, (curcolor xor 1), color, adj, vis);

    }


}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> color(n+1, -1);
    vector<bool> vis(n+1, 0);

    //-1- not colored
    // 0- red color
    // 1- blue color

    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //
    bipar=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            givecolor(i, 0, color, adj, vis);
            //color i with red
        }
    }
    if(bipar){
        cout<<"bipartite"<<endl;
    }
    else{
        cout<<"not bipartite"<<endl;
    }
    return 0;
}
  