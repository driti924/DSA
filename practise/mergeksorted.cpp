#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        a[i] = vector<int>(m); 
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    //
    vector<int> ans;
    //index array
    vector<int> idx(n,0);

    priority_queue<pair<int,int>, vector< pair<int,int>>, greater< pair<int,int> > > pq;
    for(int i=0;i<n;i++){
        pq.push({a[i][0], i});
    }
    //
    while(!pq.empty()){
        pair<int, int> p=pq.top();
        pq.pop();
        ans.push_back(p.first);
        if(idx[p.second]+1 < a[p.second].size()){
            pq.push({a[p.second][idx[p.second]+1], p.second});
            idx[p.second]=idx[p.second]+1;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}