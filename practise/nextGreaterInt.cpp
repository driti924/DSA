//
#include <bits/stdc++.h>
using namespace std;
void swap(char* a, char*b){
    char t=*a;
    *a=*b;
    *b=t;
}
string nextGreater(string s){
    int i=0;
    for(i=s.length()-1;i>0;i--){
        if(s[i-1]<s[i]){
            break;
        }
    }
    if(i==0){
        return "-1";
    }
    int mini=INT_MAX, minv=INT_MAX;
    for(int j=s.length()-1; j>=i;j--){
        if(s[j]<minv && s[j]>s[i-1]){
            minv=s[j];
            mini=j;
        }
    }
    swap(&s[i-1], &s[mini]);
    sort(s.begin()+i, s.end());
    return s;
}

// Driver code
int main()
{
    string s = "534976";
    cout<<nextGreater(s)<<endl;
    return 0;
    
}