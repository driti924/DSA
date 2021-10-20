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
        int u, v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    //
    bool cycle=0;

    for(int i=0;i<m;i++){
        int x=find_set(edges[i][0], parent);
        int y=find_set(edges[i][1], parent);
        if(x==y){
            cycle=1;
        }
        else{
            union_sets(edges[i][0], edges[i][1], size, parent);
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
 