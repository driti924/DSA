#include <iostream>
#include <string>
#include<vector>
using namespace std;

string ArrayChallenge(string strArr[], int arrLength) {
  int n=stoi(strArr[0]);
  vector<vector<int>> v(arrLength-1, vector<int>(2, -1));
  for(int i=1;i<arrLength;i++){
    string s=strArr[i];
    string t="";
    int j=0;
    while(s[j]!=':'){
      t+=s[j];
      j++;
    }

    v[i-1][0]=stoi(t);
    j++;
    t="";
    while(s[j]){
      t+=s[j];
      j++;
    }
    v[i-1][1]=stoi(t);
  }
  //
  int gas=0;
  for(int i=0;i<n;i++){
    gas=0;
    bool ans=1;
    int step=0;
    int k=i;
    while(step!=n){
      step++;
      if(gas+v[k][0]<v[(k+step)%n][1]){
        ans=0;
        break;
      }
      if(gas+v[k][0]>=v[(k+step)%n][1]){
        gas=gas+v[k][0]-v[(k+step)%n][1];
      }
      k=(k+step)%n;

    }
    if(ans && step==n){
      string res=to_string(i+1);
      return res;
    }
  }
  return "impossible";

}
 


int main(void) { 
   string s[5]={"4","1:1","2:2","1:2","0:1"};
  cout << ArrayChallenge(s, 5);
  return 0;
    
}