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
int dp[1001][1001];
bool rev(string a, string b, int i, int j){
    bool ans=1;
    for(int k=i;k<=j;k++){
        if(a[k]!=b[j-k]){
            ans=0;
            return ans;
        }
    }
    return ans;
}

int helper(string a, string b, int i, int j, int c){
    if(i>j){
        return 0;
    }
    if(a[i]==b[i] && a[j]==b[j]){
        cout<<"both equal"<<endl;
        return helper(a,b,i+1, j-1,c);
    }
    else if(a[i]==b[i]){
        cout<<"1st equal"<<endl;
        return helper(a,b,i+1, j,c);
    }
    else if(a[j]==b[j]){
        cout<<"last equal"<<endl;
        return helper(a,b,i,j-1,c);
    }
    else{
        cout<<"not equal"<<endl;
        if(rev(a,b,i+1,j-1)){
            cout<<"reverse"<<endl;
            return c;
        }
        return helper(a,b,i+1,j-1,c)+2;
    }
}


int solve(string A, string B, int C) {
    return helper(A,B,0,A.length()-1,C);
}

int main(){
    //memset(dp, 0, sizeof dp);
    string a="abceda";
    string b="bdecbo",l="ajba";
    //cout<<"result rev "<<rev(l,l,0,3)<<endl;
    cout<<solve(a,b,1)<<endl;
    return 0;
}




