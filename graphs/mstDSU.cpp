#include <bits/stdc++.h>
using namespace std;
//Disjoint set implementation{
//
void make_set(int v, vector<int> &parent){
    parent[v]=v;
}
//
int find_set(int v, vector<int> &parent){
    if(v==parent[v]){
        return v;
    }
    //path compression
    return parent[v]=find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int> &size, vector<int> &parent){
    a=find_set(a, parent);
    b=find_set(b, parent);
    if(a!=b){
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}
//All this was dsu code}
/*
A minimum spanning tree or minimum weight spanning tree is a subset of the edges of a connected, 
edge-weighted graph that connects all the vertices together, without any cycles and with 
the minimum possible total edge weight. 
*/
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<int> parent(n+1);
    //
    for(int i=1;i<=n;i++){
        make_set(i, parent);
    }
    //

    vector<int> size(n+1, 1);

    for(int i=0;i<m;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    //
    sort(edges.begin(), edges.end());
    int cost =0;

    for(int i=0;i<m;i++){
        int w=edges[i][0];
        int x=find_set(edges[i][1], parent);
        int y=find_set(edges[i][2], parent);
        if(x==y){
            //if cycle skip the edge
            continue;
        }
        else{
            //else add cost and aedge in the mst by doing union set
            cout<<edges[i][1]<<" "<<edges[i][2]<<endl; 
            cost+=w;
            union_sets(edges[i][0], edges[i][1], size, parent);
        }
    }
    cout<<"cost is: "<<cost<<endl;
    return 0;
}
/*
test case:
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1  
8 5 1
output:
7 8
8 5
4 3
1 2
3 5
2 3
6 7
cost is: 27
*/
 