#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<int>

int dp[10006][10006];

/*
bool helper(string s, int i, int j){
    if(i>j){
        dp[i][j]=0;
        return true;
    }
    if(dp[i][j]!=0){
        return true;
    }
    if(i==j){
        dp[i][j]=1;
        return true;
    }
    if(s[i]==s[j]){
        if(helper(s,i+1, j-1)){
            dp[i][j]=dp[i+1][j-1]+2;
        }
        return true;
    }
    else{
        if(helper(s, i+1, j)){
            dp[i][j]=dp[i+1][j];
        }
        if(helper(s,i,j-1)){
            dp[i][j]=max(dp[i][j], dp[i][j-1]);
        }
            return true;
    }
    return false;

}

int solve(string s) {
    memset(dp, 0, sizeof dp);
    int n=s.length();

    helper(s,0,n-1);

    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans, dp[i][j]);
        }
    }
    return ans;
}
*/
int solve(string s, int i, int j){
    if(i==j){
        dp[i][j]=1;
        return dp[i][j];
    }
    if(i>j){
        dp[i][j]=0;
        return dp[i][j];
    }

    if(dp[i][j]!=0){
        return dp[i][j];
    }

    if(s[i]==s[j]){
        dp[i][j]=2+solve(s, i+1, j-1);
    }
    else{
        int t=solve(s, i+1, j);
        int t2=solve(s, i, j-1);
        dp[i][j]=max(t, t2);
    }
    return dp[i][j];
}

int main(){
    memset(dp, 0, sizeof dp);
    string s1;
    cin>>s1;
    int n=s1.length();

    cout<<solve(s1, 0, n-1)<<endl;
    return 0;
}