#include<iostream>
#include<stack>
using namespace std;


int prefixEval(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;   
            }
        }
    }
    int ans=st.top();
    st.pop();
    return ans;
}

int main(){
    string exp="-+7*45+20";
    cout<<prefixEval(exp)<<endl;
    return 0;
}