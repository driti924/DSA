#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include <cstring>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 
#define vi vector<int>
const int  N= 1e2+2;

int dp[N][N];

int main(){
    string s;
    cin>>s;
    int n=s.length();

    int e=1;
    int a=0, ab=0, abc=0;
    rep(i, 0, n){
        if(s[i]=='a'){
            a+=e;
        }
        else if(s[i]=='b'){
            ab+=a;   
        }
        else if(s[i]=='c'){
            abc+=ab;
        }
        else if(s[i]=='?'){
            abc=3*abc + ab;
            ab=3*ab + a;
            a=3*a + e;
            e=e*3;
        }
        else{
            continue;
        }
    }
    cout<<abc<<endl;
    return 0;
}