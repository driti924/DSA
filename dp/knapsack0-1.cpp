#include<iostream>
#include<vector>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int  N= 1e3+2;

int dp[N][N];

//consider n as the size, and last index would be n-1.
int knapsack(vector<int> &w, vector<int> &v, int wt, int n){
    if(wt<=0 || n<=0){
        return 0;
    }
    if(dp[wt][n]!=0){
        return dp[wt][n];
    }
    if(wt < w[n-1]){
        dp[wt][n]=knapsack(w,v,wt,n-1);
    }
    else{
        dp[wt][n]=max( knapsack(w,v,wt,n-1), knapsack(w,v,wt-w[n-1], n-1)+v[n-1]);
    }

    return dp[wt][n]; 
}
    

int main(){
    
    int n;
    cin>>n;
    vector<int> w(n);
    vector<int> v(n);

    rep(i,0,n){
        cin>>w[i];
    }
    rep(i,0,n){
        cin>>v[i];
    }
     
    rep(i,0,n){
        rep(j,0,n)
            dp[i][j]=-1;
    }
    
    //weight of sack
    int wt;
    cin>>wt;

    cout<<knapsack(w,v,wt,n)<<endl;
    return 0;
}