#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		ll ans=0;
		map<char, int> mp;
		for(int i=0;i<n;i++){
			mp[s[i]]++;
			ans+=(mp[s[i]]-1);
		}
		/*
		for(auto it:mp){
			it.second--;
			ans+= ( (it.second*(it.second+1))/2);
		}*/
		cout<<ans<<endl;
	}	
}

