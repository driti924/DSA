#include<iostream>
#include<vector>
using namespace std;

int subseg(vector<int> A, int n){
    int mx=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(A[i]==1){
            mx++;
            ans=max(ans,mx);
        }
        else{
            ans=max(ans,mx);
            mx=0;
        }
    }
    return ans;
}

int helper(vector<int> a,int n, int i, int b){
    if(i>=n || b<=0){
        return subseg(a,n);
    }
    if(a[i]==1){
        return helper(a,n,i+1,b);
    }
    else{
        int no=helper(a,n,i+1,b);
        vector<int> c=a;
        c[i]=1;
        int y=helper(c,n,i+1,b-1);
        return max(no,y);
    }
    
}

int solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> copy=A;
    int ans=helper(copy,n,0,B);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl; 
    return ans;
}

int main(){
vector<int> a={ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    cout<<subseg(a,a.size())<<endl;
    cout<<solve(a,2)<<endl;
    return 0;
}
