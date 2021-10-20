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
        return helper(a,b,i+1, j-1,c);
    }
    else if(a[i]==b[i]){
        return helper(a,b,i+1, j,c);
    }
    else if(a[j]==b[j]){
        return helper(a,b,i,j-1,c);
    }
    else{
        if(rev(a,b,i,j)){
            return c;
        }
        else{
            return 2+helper(a,b,i+1,j-1,c);
        }
        
    }
    
}


int solve(string A, string B, int C) {
    return helper(A,B,0,A.length()-1,C);
}

int main(){
    string a="abceda";
    string b="bdecbo";
    solve(a,b,1);
    return 0;
}




