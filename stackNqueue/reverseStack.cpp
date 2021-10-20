#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int topele=st.top();
    st.pop();
    InsertAtBottom(st, val);
    st.push(topele);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int val=st.top();
    st.pop();
    reverseStack(st);
    InsertAtBottom(st,val);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}