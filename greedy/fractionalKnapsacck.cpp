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
    vii v(n);
    rep(i,0,n){
        cin>>v[i].ff>>v[i].ss;
        //ff is value, ss is weight
    }
    int w;
    cin>>w;

    sort(v.begin(), v.end(), [&](pii &a, pii &b){
        double v1= (double) a.ff/a.ss;
        double v2= (double) b.ff/b.ss;
        return v1 > v2;
    });

    int ansValue=0;

    rep(i, 0, n){
        if(w > v[i].ss){
            ansValue+=v[i].ff;
            w-=v[i].ss;
            continue;
        }
        else{
            double VperW= (double) v[i].ff/v[i].ss;
            ansValue+= VperW*w;
            w=0;
        }
    }
    cout<<ansValue<<endl;
    return 0;
}