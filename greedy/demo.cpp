//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<vector<int>>
#define pb push_back

//question: max no of activities that 1 can performe given schedules of many activities.

vector<int> solve(vector<int> &A, int B) {
    vector<int> ans;
    
    int n=A.size();
    vector<int> a(n+1);

    priority_queue<int, vector<int>> pq;

    for(int i=0;i<A.size();i++){
        pq.push(A[i]);
        ans.push_back(A[i]);
        a[A[i]]=i;
    }
    long int swap=0;

    for(int i=0;i<n;i++){
        if(ans[i]!=pq.top()){
            int temp=ans[i];
            ans[i]=pq.top();
            //cout<<"ans[i] "<<ans[i];
            ans[a[pq.top()]]=temp;
            swap++;
            a[A[i]]=a[pq.top()];
            a[pq.top()]=a[A[i]];
            if(swap>=B){
                break;
            }
        }
        pq.pop();
    }
    return ans;
}


int main(){
    vector<int> a={3, 2, 4, 1, 5};
    vector<int> b;
    b=solve(a,3);
    cout<<endl<<"answer= "<<endl;
    for(int i=0;i<5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}

#define rep(i,a,b) for(int i=a;i<b;i++)
vector<int> Solution::solve(vector<int> &A, int B) {
   
    
    int n=A.size();
    if(B>=n){
        sort(A.begin(),A.end(),greater<int>());
        return A;
    }
    
    vector<int> sorted=A;
    sort(sorted.begin(),sorted.end());
    
    
    vector<int> pos(n+1);
    rep(i,0,n){
        pos[A[i]]=i;
    }
    
    int i=0;
    while(B-- && i<n){
        if(A[i]!=sorted[n-i-1]){
            int temp=A[i];
            A[i]=sorted[n-i-1];
            A[pos[sorted[n-i-1]]]=temp;
            
            
            pos[A[i]]=pos[sorted[n-i-1]];
            pos[sorted[n-i-1]]=i;
            i++;
        }
    }
    
    return A;
}
