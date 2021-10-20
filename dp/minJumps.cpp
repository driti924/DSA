#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<int>
const int  N= 1e5+2;

int dp[N];

int main(){
    int n;
    cin>>n;

    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }

    if(a[0]==0){
        cout<<"not possible to reach end"<<endl;
        return 0;
    }

    dp[0]=0;

    rep(i, 1, N){
        dp[i]=INT_MAX;
    }

    rep(i, 1, n){
        rep(j, 0, i){
            if(j+a[j]>= i){
                dp[i]=min(dp[i], 1+dp[j]);
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}