#include<iostream>
using namespace std;
//append last k nodes in the starting
class node{
    public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
        }
};
void insertll(node* &head, int val){
    node* temp=new node(val);
    if(head==NULL){
        head=temp;
        return;
    }
    node* n=head;
    while(n->next!=NULL){
        n=n->next;
    }
    n->next=temp;
}
void display(node* head){
    if(head==NULL){
        cout<<"emptylist"<<endl;
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* kreverse(node* head, int k){
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    int cnt=k;
    while(cnt-- && curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    if(curr!=NULL){
        node* t=kreverse(nextptr, k);
        head->next=t;
    }
    return prev;
}

int main(){
node* head=NULL;
display(head);
insertll(head,1);
insertll(head,2);
insertll(head,3);
insertll(head,4);
insertll(head,5);
insertll(head,6);
display(head);
node* n=kreverse(head,3);
display(n);
}