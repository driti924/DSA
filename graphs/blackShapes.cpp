#include <bits/stdc++.h>
using namespace std;

vector<int> x={0, -1, 0, 1}, y={-1, 0, 1, 0};

int helper(int i, int j, vector<vector<char>> &graph, vector<vector<bool>> &vis){
    int ans=1;
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int u=i+x[k], v=j+y[k];
        if(u>=0 && u<graph.size() && v>=0 && v<graph[0].size() && !vis[u][v] && graph[u][v]=='X'){
            ans+=helper(u, v, graph, vis);
            vis[u][v]=1;
        }
    }
    return ans;
}
/*
int black(vector<string> &A) {
    int r=A.size();
    int c=A[0].size();
    //0=white, X=black
    vector<vector<char>> graph;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            graph[i][j]=A[i][j];
        }
    }
    vector<int> comps;
    vector<vector<bool>> vis(r, vector<bool>(c, 0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!vis[i][j] && graph[i][j]=='X'){
                    comps.push_back(helper(i, j, graph, vis));
            }
        }
    }
    return comps.size();
}
*/

int main()
{
    vector<string> A={
        {"OOOXOOO"}, {"OOXXOXO"}, {"OXOOOXO"}
    };
    cout<<"c= "<<A[0].size()<<endl;

    int r=A.size();
    int c=A[0].size();
    vector<vector<char>> graph(r, vector<char>(c, 'X'));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            graph[i][j]=A[i][j];
        }
    }
    //
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    //
    vector<int> comps;
    vector<vector<bool>> vis(r, vector<bool>(c, 0));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!vis[i][j] && graph[i][j]=='X'){
                    comps.push_back(helper(i, j, graph, vis));
            }
        }
    }
    cout<<"ans= "<<comps.size()<<endl;
    //cout<<black(A)<<endl;
    return 0;
}
  

