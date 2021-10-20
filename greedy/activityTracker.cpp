//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<vector<int>>
#define pb push_back

//question: max no of activities that 1 can performe given schedules of many activities.

int main(){
    int n;
    cin>>n;
    vi acti;
    rep(i,0,n){
        int start, end;
        cin>>start>>end;
        acti.pb({start, end});
    }
    
    sort(acti.begin(), acti.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    /*rep(i,0,n){
        cout<<acti[i][0]<<", "<<acti[i][1]<<endl;
    }
    */

    int ans=1;
    int endTime=acti[0][1];

    rep(i,1,n){
        if(acti[i][0] >= endTime){
            ans++;
            endTime=acti[i][1];
        }
    }
    cout<<ans<<endl;

    return 0;
}