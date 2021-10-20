#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include <cstring>
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

int optimalGS(vi &a, int i, int j){
    if(i==j){
        return a[i];
    }
    if(i>j)
        return 0;
        
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int l=a[i]+min(optimalGS(a, i+2, j), optimalGS(a, i+1, j-1));
    int r=a[j]+min(optimalGS(a, i+1, j-1), optimalGS(a, i, j-2));
    dp[i][j]=max(l,r);
    return dp[i][j];
}

int main(){
    memset(dp, -1, sizeof(dp));
    
    int n;
    cin>>n;

    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    cout<<optimalGS(a, 0, n-1)<<endl;
    return 0;
}