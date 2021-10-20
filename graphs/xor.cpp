#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int q;
		cin>>q;
		vector<vector<int>> lr(q, vector<int>(2,0));
		for(int i=0;i<q;i++){
			cin>>lr[i][0]>>lr[i][1];
		}//
		int ans=0;
		for(int i=0;i<q;i++){//each query
			ans=0;
			ll xoro;
			int l=lr[i][0], r=lr[i][1];
			for(int j=0;j<n;j++){
				xoro=0;
				for(int k=j;k<n;k++){
					xoro^=a[k];
					if(xoro>=l && xoro<=r)	ans++;
				}
			}
			cout<<ans<<endl;
		//output query//
		}
		

	}
}
