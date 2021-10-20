#include<iostream>
#include<map>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

void freqCount(int a[], int n){
    map<int, int> mp;
    rep(i,0,n){
        mp[a[i]]++;
    }
    map<int, int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->ff<<" "<<it->ss<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n){
        cin>>a[i];
    }
    freqCount(a,n);
    return 0;
}