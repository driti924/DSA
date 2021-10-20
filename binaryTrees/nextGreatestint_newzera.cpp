#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b){
  char t=*a;
  *a=*b;
  *b=t;
}

int MathChallenge(int num) {
  
  string hh=to_string(num);
  cout<<hh<<endl;
  char* s;
  
  s=&hh[0];
  for(int k=0;k<hh.length();k++){
      cout<<s[k]<<" ";
  }
  int n=hh.length();

  int i, j;
  for( i=n-1;i>0;i--){
    if(s[i]>s[i-1]){
      break;
    }
  }
  if(i==0){
    return -1;
  }
  int x=s[i-1], small=i;
  for(j=i+1;j<n;j++){
    if(s[j]>x && s[j]<s[small]){
        i=j;
    }
  }
  swap(&s[small], &s[i-1]);
  sort(s+i, s+n);
    cout<<"s= "<<s<<endl;
    cout<<s[0]-'0'<<endl;
 int ans=0;
  for( i=0;i<n;i++){
    ans = (ans*10 + (s[i]-'0'));
  }
  return ans;

}

int main(void) { 
   
  // keep this function call here
  cout << MathChallenge(11121);
  return 0;
    
}