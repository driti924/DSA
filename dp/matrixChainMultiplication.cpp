#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<cstring>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<int>
const int  N= 1e2+2;

int dp[N][N];

//memoization approach
int mcm(vi &a, int i, int j){
    if(i==j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];
    
    dp[i][j]=INT_MAX;
    rep(k, i, j){
        dp[i][j]=min(dp[i][j], mcm(a, i, k) + mcm(a, k+1, j) + a[i-1]*a[k]*a[j]);
    }
    return dp[i][j];
}

int main(){
    
    int n;
    cin>>n;
    vi a(n);

    rep(i, 0, n){
        cin>>a[i];
    }

    memset(dp, -1, sizeof dp);

    cout<<mcm(a, 1,n-1)<<endl;

    //tabulation
    rep(i, 0, n){
        dp[i][i]=0;
    }

    rep(l, 2, n){ //length can go upto n-1
        rep(i, 1, n-l+1){// we have to cover length n ahead of i
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            rep(k, i , j){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+ a[i-1]*a[k]*a[j]);
            }
        }
    }

    cout<<dp[1][n-1]<<endl;
    return 0;
}