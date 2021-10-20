#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<int> dis(n, INF);
    //INT_MAX not working at place of INF, dont know why... 

    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
    }

    int src;
    cin>>src;

    dis[src]=0;
    
    for(int i=0;i<n-1;i++){
        for(auto it: edges){
            int a=it[0];
            int b=it[1];
            int w=it[2];
            dis[b]=min(dis[b], (w+dis[a]));
        }
    }

    for(auto i: dis){
        cout<<i<<" ";
    }
    cout<<"\n";
    
    
    
    return 0;
}
