#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<int>
const int  N= 1e3+2;

int dp[N];

int longestSubsequence(vi &a, int n){
    //cout<<"a[i]="<<a[n]<<endl;
    if(dp[n]!=-1){
        //cout<<"ans"<<dp[n]<<endl;
        return dp[n];
    }
    //single element is also a subsequence
    dp[n]=1;

    for(int i=0;i<n;i++){
        if(a[n] > a[i]){
            dp[n]=max(dp[n], 1 + longestSubsequence(a,i));
        }
    }
    //cout<<"ans"<<dp[n]<<endl;
    return dp[n];
}

int main(){
    
    int n;
    cin>>n;
    vi a(n);

    rep(i,0,n){
        cin>>a[i];
    }
     
    rep(i,0,N){
            dp[i]=-1;
    }
    int ans=0;

    cout<<longestSubsequence(a, n-1)<<endl;

    //tabulation
    rep(i,0,N){
            dp[i]=1;
    }
    rep(i,1,n){
        rep(j,0,i){
            if(a[i]>a[j]){
                dp[i]=max(dp[i], 1+dp[j]);
            }
        }
        ans=max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}