#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int> > pqmax;

void insert(int val){

    if(pqmin.size() == pqmax.size()){
        if(pqmax.size()!=0){
            if(val < pqmax.top()){
                pqmax.push(val);
            }
            else{
                pqmin.push(val);
            }
        }
        else{
            pqmax.push(val);
            return;
        }
    }
    else{
        if(pqmax.size() < pqmin.size()){
            if(val <= pqmin.top()){
                pqmax.push(val);
            }
            else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(val);
            }
        }
        else{
            if(val >= pqmax.top()){
                pqmin.push(val);
            }
            else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(val);
            }
        }
    }

}

double findMedian(){
    if(pqmax.size() == pqmin.size()){
        return (pqmin.top() + pqmax.top())/2.0;
    }
    else if(pqmax.size() > pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main(){
   insert(10);
   cout<<findMedian()<<endl;
   insert(15);
   cout<<findMedian()<<endl;
   insert(21);
   cout<<findMedian()<<endl;
   insert(30);
   cout<<findMedian()<<endl;
   insert(18);
   cout<<findMedian()<<endl;
   insert(19);
   cout<<findMedian()<<endl;

    

    return 0;
}