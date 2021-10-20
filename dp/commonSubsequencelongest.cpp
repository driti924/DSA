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

int dp[N][N];

//memoization method
int longestCommonSubsequence(string s1, string s2, int n, int m){
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    //if any 1 string is null we cant make any subsequence from it, thus no common subsequence
    if(n==0 || m==0){
        return 0;
    }
    if(s1[n-1] == s2[m-1]){
        dp[n][m]=1 +(longestCommonSubsequence(s1, s2, n-1, m-1));
    }
    else{
        dp[n][m]=max(longestCommonSubsequence(s1, s2, n, m-1), longestCommonSubsequence(s1, s2, n-1, m));
    }
    return dp[n][m];
}

int main(){
    string s1, s2;
    cin>>s1;
    cin>>s2;

    int n=s1.length();
    int m=s2.length();

    rep(i,0,N){
        rep(j,0,N){
            dp[i][j]=-1;
        }
    }

    cout<<longestCommonSubsequence(s1, s2, n, m)<<endl;
    
    rep(i,0,N){
        rep(j,0,N){
            dp[i][j]=0;
        }
    }

    //tabulation approach
    rep(i,1,n+1){
        rep(j,1,m+1){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    
    return 0;
}