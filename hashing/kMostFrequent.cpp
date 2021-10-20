//32.7 problem
#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 

void kMostFrequent(int a[], int n, int k){
    mii mp;
    rep(i,0,n){
        int size=mp.size();
        if(mp[a[i]]==0 && size==k){
            mp.erase(a[i]); //unwantedly we add another element when we check mp[a[i]]==0, so we erase it
                            //as it is k+1th distinct element
            break;
        }
        mp[a[i]]++;
    }
    vii ans;
     
    mii :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        ans.push_back({it->ss, it->ff});
    }
    sort(ans.begin(), ans.end(), greater<pii>());

    vii :: iterator i;
    for(i=ans.begin();i!=ans.end();i++){
        cout<<i->ss<<"-> "<<i->ff<<endl;

    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    rep(i,0,n){
        cin>>a[i];
    }
    kMostFrequent(a,n,k);
    return 0;
}