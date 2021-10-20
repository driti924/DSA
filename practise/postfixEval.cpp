#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;



string eval(string s){
    stack<char> st;
    for(int i=0;s[i];i++){
        char c=s[i];
        if('a'<=c && c<='z' || 'A'<=c && c<='Z'){
            st.push(c);
        }
        else{
            char oper2=st.top();
            st.pop();
            char oper2=st.top();
            st.pop();

        }
    }
}

int main(){
    string postfix="abc*d/+";
    string res=eval(postfix);
    cout<<res<<endl;
    return 0;
}
//
   