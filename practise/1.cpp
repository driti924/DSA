//
#include <bits/stdc++.h>
 
using namespace std;

#define ll long long int
//const ll MOD=10e9+7;
#define MOD 1000000007
ll fact(ll n){
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    return ans;
}

ll power(ll x,ll y){
    ll res=1; 
    while(y){
        if(y&1) res = (res*x)%MOD; 
        y>>=1; 
        x = (x*x)%MOD;
    }
    return res;
}

int solve(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    int m=B.size();
    int unvis=A-m;
    vector<int> gaps;
    gaps.push_back(B[0]-1);
    for(int i=1;i<m;i++){
        gaps.push_back(B[i]-B[i-1]-1);
    }
    gaps.push_back(A-B[m-1]);
    
    ll ans=fact(unvis);
    for(int i=0;i<gaps.size();i++){
        ll f=fact(gaps[i])%MOD;
        ll temp=(power(f, MOD-2)) % MOD;
        ans*=temp;
        ans%=MOD;
    }
    for(int i=0;i<gaps.size();i++){
        if(i==0 || i==gaps.size()-1){
            continue;
        }
        else if(gaps[i]>=2){
            ll p=power(2, gaps[i]-1)%MOD;
            ans*=p;
            ans%=MOD;
        }
    }
    return ans;
}

// Driver function
int main()
{   vector<int> a={10, 6, 9, 3, 2};
    cout<<solve(10,a)<<endl;
    cout<<'z'-'a'<<endl;
    return 0;
}
