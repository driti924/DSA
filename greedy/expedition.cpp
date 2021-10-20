//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
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
        //ff is distance of stop from town, ss is the fuel unit
    }
    
    int l,p;
    cin>>l>>p;

    int currFuel=p;
    bool flag=0;
    priority_queue<int, vector<int>> mp;

    rep(i, 0, n){
       v[i].ff=l-v[i].ff;
    }

    sort(v.begin(), v.end());

    int ans=0;

    rep(i, 0, n){
        if(currFuel >= l){
           break;
        }
        
        while(currFuel < v[i].ff){
            if(mp.empty()){
                // if u cant even reach at the nearest fuel-stop then return -1;
                flag=1;
                break;
            }
            //else think that while passing from previous stops u filled the fuel from the fuel-stop of "max unit"
            ans++;
            currFuel+=mp.top();
            mp.pop();
        }
        if(flag==1){
            break;
        }
        mp.push(v[i].ss); 
    }
    if(flag==1){
        cout<<"-1"<<endl;
        //return 0;
    }
    while(!mp.empty() && currFuel<l){
        currFuel+=mp.top();
        mp.pop();
        ans++;
    }
    if(currFuel<l ){
        cout<<"not"<<endl;
        return 0;
    }
    
    cout<<ans<<endl;
    
    return 0;
}