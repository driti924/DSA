
#include <iostream>
#include<vector>
#include<climits>
#include <cstring>
#include<math.h>
using namespace std;
int dp[1001][1001][2];

int calc(vector<int> &v, vector<int>&p, int M, int n, int used){
	if(n<0 || M<=0){
		return 0;
	}
	if(dp[M][n][used]==-1){
        if(used==1){
            if(M>=p[n]){
				dp[M][n][used]=max(calc(v,p,M,n-1,used), calc(v,p,M-p[n],n-1,used)+v[n]);
			}
			else{
				dp[M][n][used]=calc(v,p,M,n-1,used);
			}
        }
		//
		else{//used==0
			if(M>=p[n]){
				dp[M][n][used]=max(max(calc(v,p,M,n-1,used), calc(v,p,M-p[n],n-1,used)+v[n]), 
								calc(v,p,M-floor(p[n]/2),n-1,1)+v[n]);
			}
			else{
				if(floor(p[n]/2)<=M){
					dp[M][n][used]=max(calc(v,p,M,n-1,used), calc(v,p,M-floor(p[n]/2),n-1,1)+v[n]);
				}
				else{
					dp[M][n][used]=calc(v,p,M,n-1,used);
				}
			}
		}
		
	}
	
	return dp[M][n][used];
}

int main() {
	int T;
	cin >> T;
	while(T--){
		memset(dp,-1,sizeof dp);
		int N,M;
		cin>>N>>M;
		vector<int> v(N);
		vector<int> p(N);
		for(int i=0;i<N;i++){
			cin>>v[i]>>p[i];
		}
		//algo
		int ans=calc(v,p,M,N-1,0);
		cout<<ans<<endl;
	}
}

