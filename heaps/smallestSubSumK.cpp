#include<iostream>
#include<queue>
using namespace std;
//smallest subsequence with sum k

int main(){
    //max heap
    priority_queue<int, vector<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    //minheap
    priority_queue<int, vector<int>, greater<int> > pqm;
    pqm.push(1);
    pqm.push(2);
    pqm.push(3);
    cout<<pqm.top()<<endl;
    pqm.pop();
    cout<<pqm.top()<<endl;

    return 0;
}