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

int dp[N][N];

int main(){
    int n;
    cin>>n;

    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    vi incre(n,1);
    vi decre(n,1); 

    rep(i, 1, n){
        rep(j, 0, i){
            if(a[i] > a[j]){
                incre[i]=max(incre[i], 1 + incre[j]);
            }
        }
    }

    repB(i, n-2, 0){
        for(int j=n-1; j>i;j--){
            if(a[i] > a[j]){//i<j
                decre[i]=max(decre[i], 1 + decre[j]);
            }
        }
    }

    int ans=0;
    rep(i, 0, n){
        ans=max(ans, incre[i]+decre[i]-1);
    }

    cout<<ans<<endl;

    return 0;
}