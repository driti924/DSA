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

int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }

    int cur=0;
    int maxTillNow=a[0]; //they did 0

    rep(i, 0, n){
        cur+=a[i];
        maxTillNow=max(maxTillNow, cur);
        if(cur<0){
            cur=0;
        }

    }
    cout<<maxTillNow<<endl;
    return 0;
}