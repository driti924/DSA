//find the number of vertices on the longest path in the tree such that no pair of adjacent 
//vertices on the path would contain same letter
#include <bits/stdc++.h>
using namespace std;
int maxx=0;
int twodirection=0; //discard this variable
int dfs(int src,  vector<bool> &vis, vector<vector<int>> &adj, string data){
    vis[src]=1;
    vector<int> adjpaths;
    for(int i=0;i<adj[src].size();i++){
        if(!vis[adj[src][i]]){
            int temp=dfs(adj[src][i], vis, adj, data);//call has to be done no matter what
            if(data[src]!=data[adj[src][i]])
                adjpaths.push_back(temp);
            else    adjpaths.push_back(0);
        }
        
    }
    //finding top two(if possible esle 1) max values in adjpaths
    sort(adjpaths.begin(), adjpaths.end(), greater<int>());
    //adjpaths.erase(unique(adjpaths.begin(), adjpaths.end()), adjpaths.end());
    if(adjpaths.size()==0){
        if(maxx<1) {
            maxx=1;
            twodirection=0;
        }
        return 1;
    }
    if(adjpaths.size()==1){
        
        if(adjpaths[0]+1 > maxx){
            //cout<<"hey"<<endl;
            maxx=adjpaths[0]+1;
            twodirection=0;
        }
        return 1+adjpaths[0];
    }
    if(adjpaths.size()>=2){
        //cout<<adjpaths[0]<<" "<<adjpaths[1]<<endl;
        if(1+adjpaths[0]+adjpaths[1] > maxx){
             //cout<<"hello"<<endl;
            maxx=1+adjpaths[0]+adjpaths[1];
            twodirection=1;
        }
        return 1+adjpaths[0]+adjpaths[1]; //adjpaths[0]; this represents the max of all paths starting from adj[src]
    }
    return 0;
}

int longestPath(vector<int> &graph, string s){
    if(graph.size()==0 || graph.size()==1) return graph.size();
    vector<vector<int>> adj(graph.size());
    for(int i=1;i<graph.size();i++){
        adj[i].push_back(graph[i]);
        adj[graph[i]].push_back(i);
    }
    vector<bool> vis(graph.size(), 0);
    int res=dfs(0, vis, adj, s);
    //return res;
    return maxx;
}

int main()
{
    vector<int> graph={-1, 2, 0, 1};
    string data="abab";
    int ans = longestPath(graph, data);
    cout<<ans<<endl;
    //
    maxx=0;
    graph={-1, 0, 0, 0, 2};
    data="abbab";
    ans = longestPath(graph, data);
    cout<<ans<<endl;
    //
    maxx=0;
    graph={-1, 0};
    data="ab";
    ans = longestPath(graph, data);
    cout<<ans<<endl;
    //
    maxx=0;
    graph={-1, 0, 0, 0, 2};
    data="ababb";
    ans = longestPath(graph, data);
    cout<<ans<<endl;
    //
    maxx=0;
    graph={-1, 0, 0, 0, 2};
    data="abbba";
    ans = longestPath(graph, data);
    cout<<ans<<endl;
     //
    maxx=0;
    graph={-1};
    data="a";
    ans = longestPath(graph, data);
    cout<<ans<<endl;
    //
    maxx=0;
    graph={-1, 0, 0, 0, 2, 3, 5};
    data="ababbab";
    ans = longestPath(graph, data);
    cout<<ans<<endl;
    return 0;
}
 