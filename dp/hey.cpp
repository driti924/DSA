#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k,x;
		cin>>n>>k>>x;
		int v[n];
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		map<int, int> mp;
		for(int i=0;i<n;i++){
			mp[v[i]]++;
		}
		int s=mp.size();
		int ans=max(0, s-k);
		cout<<ans*x<<endl;
		
	}
	return 0;
}

