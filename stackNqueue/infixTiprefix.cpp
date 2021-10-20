#include<iostream>
#include<stack>
using namespace std;

int precedance(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else
        return -1;
}

string infixTopostfix(string s){
    string result="";
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if ((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='(' ){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{//operator case

            while( !st.empty() && precedance(st.top()) > precedance(s[i])){
                result+=st.top();
                st.pop();
            }
            
            st.push(s[i]);
            
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}

int main(){
    cout<<infixTopostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}