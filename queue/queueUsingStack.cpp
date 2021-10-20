#include<iostream>
#include<stack>
using namespace std;

//Stack(using 2 stack) implementation of queue
//pop is expensive

class queue{
    stack<int> s1;
    stack<int> s2;

    public:
    
    void enqueue(int x){
        s1.push(x);     
    }

    int dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topele=s2.top();
        s2.pop();
        return topele;

    }

    int peek(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topele=s2.top();
        return topele;
    }

    bool empty(){
        return (s1.empty() && s2.empty());
    }

};  
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.peek()<<endl;

   
    cout<<q.dequeue()<<endl;
    cout<<q.peek()<<endl;

    cout<<q.empty()<<endl;
   cout<<q.dequeue()<<endl;
   cout<<q.dequeue()<<endl;
   cout<<q.dequeue()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;

    return 0;
}