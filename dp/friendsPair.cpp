#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include <cstring>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repB(i, a, b) for(int i=a; i>=b;i--)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<int>
const int  N= 1e2+2;



int main(){
    int n;
    cin>>n;

    vi dp(n+1, 0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+ (i-1) * dp[i-2];
    }
    
    cout<<dp[n]<<endl;
    return 0;
}