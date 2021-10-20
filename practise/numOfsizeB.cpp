//
#include <bits/stdc++.h>
using namespace std;
void swap(char* a, char*b){
    char t=*a;
    *a=*b;
    *b=t;
}
int digitsCount(int n){
    int ans=0;
    while(n){
        n/=10;
        ans++;
    }
    return ans;
}
vector<int> getdigits(int C){
    vector<int> ans;
    while(C){
        ans.push_back(C%10);
        C/=10;
    }
    if(ans.size()==0){
        ans.push_back(0);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int calc(vector<int> &A, int B, int C){
    int na=A.size();
    int nc=digitsCount(C);
    //cout<<"nc: "<<nc<<endl;
    if(nc<B || na==0){
        return -1;
    }
    else if(nc>B){
        if(A[0]==0 && B!=1){
            return pow(na, B-1)*(na-1); 
        }
        else    
            return pow(na,B);
    }
    else{
        vector<int> cdigits=getdigits(C);
        /*for(int i=0;i<cdigits.size();i++)
            cout<<cdigits[i]<<" ";
            */
        cout<<endl;
        int dp[B+1]={0};
        int lower[11]={0}; //lower[10] will detone nos less than 10
        for(int i=0;i<na;i++)
            lower[A[i] + 1]=1;
        for(int i=1;i<=10;i++){
            lower[i]+=lower[i-1];
        }
        dp[0]=0;//nos of length 0 less than first 0 digits of C=0
        bool flag=1;
        for(int i=1;i<=B;i++){
            int ld=lower[cdigits[i-1]];//
            dp[i]=dp[i-1]*na;

            // For first index we can't use 0
            if(i==1 && A[0]==0 && B!=1)
                ld-=1;
            
            if(flag)    
                dp[i]+=ld;

            //check if digit[i-1] present in A
            flag= (flag) && (lower[cdigits[i-1] + 1] == (lower[cdigits[i-1]] +1) );

        }
        return dp[B];

    }
}

// Driver code
int main()
{
    vector<int> A={0,1,5};
    int B=1, C=2;
    cout<<calc(A, B,C)<<endl;
    string s="128";
    s[1]=s[1]+1;
    cout<<s<<endl;
    return 0;
    
}