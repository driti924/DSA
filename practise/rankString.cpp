//Given a string, find its rank among all its permutations 
//sorted lexicographically. For example, rank of “abc” is 1, rank of “acb” is 2, and rank of 
//“cba” is 6. 
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define MOD 1000003

void updaterank(vector<int> &rank, char c){
    for(int i=c;i<256;++i){
        --rank[i];
    }
}
ll fact(ll n){
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}
int findRank(string A) {
    int n=A.size();
    vector<int> rank(256,0); //0-25indexes
    
    for(int i=0;i<n;++i){
        ++rank[A[i]];
    }
    for(int i=1;i<256;++i){
        rank[i]+=rank[i-1];
    }
    int rem=n-1;

    ll ans=0;
    for(int i=0;i<n;++i){
        ans= (ans+(rank[A[i]-1]*fact(rem))%MOD)%MOD;
        rem--; 
        updaterank(rank, A[i]);
    }
    ans++;
    return int(ans)%MOD;
}
int main(){
    ll ans=findRank("gTFAMYjxCewRlftmGOKJHUuhSBVDZnbqyoPQadEkLrpNsv");
    cout<<ans<<endl;
    
    return 0;
}