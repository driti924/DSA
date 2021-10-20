//Given a string, find its rank among all its permutations 
//sorted lexicographically. For example, rank of “abc” is 1, rank of “acb” is 2, and rank of 
//“cba” is 6. 
#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define MOD 1000003

map<int, int> mp;


ll power(ll x,ll y){
    ll res=1; 
    while(y){
        if(y&1) res = (res*x)%MOD; 
        y>>=1; 
        x = (x*x)%MOD;
    }
    return res;
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
    //map to store the frequenies of each char
    for(int i=0;i<n;i++){
        mp[A[i]]++;
    }
    //
    
    int rem=n-1;
    ll ans=0;

    for(int i=0;i<n;++i){
       for(auto it:mp){
           cout<<it.first<<" "<<it.second<<endl;
       }
        cout<<endl;

        //smaller than curr char
        int rank=0;
        for(auto it:mp){
           if(it.first!=A[i] && it.first<A[i]){
               rank+=it.second;
           }
        }
        //

        ll temp=1;
        ll temp2=(rank*fact(rem))%MOD;
        for(auto it: mp){
            if(it.second>1){
                temp= (temp* (power(fact(it.second), MOD-2))%MOD)%MOD;
            }
        }
        temp2*=temp;
        temp2%=MOD;
        ans= (ans+temp2)%MOD;
        rem--; 
        //updaterank(rank, A[i]);
        mp[A[i]]--;
    }
    ans++;
    return int(ans)%MOD;
}
int main(){
    ll ans=findRank("settLe");
    cout<<ans<<endl;
    
    return 0;
}           

//O(nlogn) as per my understanding