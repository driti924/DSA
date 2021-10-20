#include<iostream>
using namespace std;

//Linkedlist implementation of queue

class node{
    public:
    node* next;
    int data;
    node(int x){
        data=x;
        next=NULL;
    }
};

class queue{
    node* front;
    node* back;

    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    void enqueue(int x){
        node* n=new node(x);
        if(front==NULL){
            front=n;
            back=n;
        }
        back->next=n;
        back=n;
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }
        if(front->next==NULL){
            back=back->next;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;

    }

    int peek(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        return (front==NULL);
    }

};  
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.peek()<<endl;

   
    q.dequeue();
    cout<<q.peek()<<endl;

    cout<<q.empty()<<endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;

    return 0;
}