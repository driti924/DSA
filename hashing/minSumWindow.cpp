#include<iostream>
#include<map>
#include<vector>
#include<climits>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mp map<int, vector<int>>

//minimum sum of k size windows of a given array
int minSumInWindow(int a[], int n, int k){
    int minSum=INT_MAX;
    int sum=0;
    rep(i,0,k){
        sum+=a[i];
    }
    minSum=min(minSum, sum);
    rep(i,1,n-k+1){
        sum-=a[i-1];
        sum+=a[i+k-1];
        minSum=min(minSum, sum);
    }
    return minSum;
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    rep(i,0,n){
        cin>>a[i];
    }
    cout<<minSumInWindow(a,n,k);
    return 0;
}