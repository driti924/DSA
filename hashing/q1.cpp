#include<iostream>
#include<map>
#include<vector>
#include<climits>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mp map<int, vector<int>>

//#define rep(i,a,b) for(int i=a;i<b;i++)

int solve(vector<int> &a) {
    int n=a.size();
    int unb[3]={0};
    int cnt[3]={0};
    int dp[3][3]={0};
    
    rep(i, 0, n){
        if(i%3 != a[i]%3){
            unb[i%3]++;
            cnt[a[i]%3]++;
            dp[i%3][a[i]%3]++;
        }
    }
    rep(i,0,3){
        if(unb[i]!=cnt[i]){
            cout<<"impo"<<endl;
            return -1;
        }
    }
    int ans=0;
    rep(i,0,3){
        rep(j,0,3){
            if(dp[i][j]==dp[j][i]){
                ans+=dp[i][j];
                dp[i][j]=0;
                dp[j][i]=0;
            }
            if(dp[i][j]>dp[j][i]){
                ans+=dp[i][j];
                dp[i][j]-=dp[j][i];
                dp[j][i]=0;
            }
            else{
                ans+=dp[i][j];
                dp[j][i]-=dp[i][j];
                dp[i][j]=0;
            }
        }
    }
    bool flag=1;
    rep(i,0,3){
        rep(j,0,3){
            ans+=dp[i][j];
            if(dp[i][j]!=0){
                flag=0;
                
            }
        }
    }
    if(flag)
        return ans;
    else{
        ans-=1;
        return ans;
    }
}


int main(){
    vector<int> a={4,3,3,7,8,9,28,27,4,10};
    cout<<solve(a);
    return 0;
}