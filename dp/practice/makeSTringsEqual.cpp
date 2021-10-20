//Q- edit distance

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

//#define rep(i, a, b) for(int i=a;i<b;i++)
int dp[451][451];

int helper(string &s1, string &s2, int n, int m){
    //n and m at any point of time denoted the size of remaining strings
    if(n==0){
        dp[n][m]=m;
        return dp[n][m];
    }

    if(m==0){
        dp[n][m]=n;
        return dp[n][m];
    }
    if(dp[n][m]!=0){
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1]){
        dp[n][m]=helper(s1, s2,n-1, m-1);
    }
    else{
        //first insertion, then replace, then deletion
        dp[n][m]=1+ min( min(helper(s1, s2, n,m-1) , 
                             helper(s1, s2, n-1,m-1)), helper(s1,s2, n-1,m) );
    }
    return dp[n][m];
}

int minDistance(string A, string B) {
    memset(dp, 0, sizeof dp);
    int n=A.length();
    int m=B.length();
    int ans= helper(A, B, n ,m);
    return ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;

    cout<<minDistance(s1, s2)<<endl;

    return 0;
}
