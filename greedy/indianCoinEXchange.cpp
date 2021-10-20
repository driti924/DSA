#include<iostream>
#include<algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 

int main(){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n){
        cin>>a[i];
    }
    int value;
    cin>>value;
    int ans=0;
    sort(a, a+n, greater<int>());

    rep(i,0,n){
        //see next 2 lines, important shirtcut way!
        ans+=value/a[i];
        value-= value/a[i] * a[i];
        if(value==0)
            break;
    }
    cout<<ans<<endl;

    return 0;
}