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

    int zero[n];
    int one[n];

    zero[0]=1;
    one[0]=1;

    rep(i, 1 ,n){
        zero[i]=zero[i-1]+one[i-1];
        one[i]=zero[i-1];
    }

    cout<<one[n-1]+zero[n-1]<<endl;

    //its actually a fibonacci sequence;
    int fib[n+2];
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<n+2;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    cout<<fib[n+1]<<endl;
    return 0;
}