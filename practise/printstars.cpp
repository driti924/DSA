#include<iostream>
using namespace std;

int main(){
    bool b=true;
    string s="";
    for(int i=1;i<=7;i++){
        if(i==5){
            b=false;
        }
        if(b){
            s+="*";
            cout<<s<<endl;
        }
        
        else{
            s=s.substr(0,s.length()-1);
            cout<<s<<endl;
        }
    }
    
    cout<<"   *"<<endl;
    return 0;
}