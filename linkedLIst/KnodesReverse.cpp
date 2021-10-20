#include<iostream>
using namespace std;

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

node* reverseK(node* &head, int k){
    
    node* prev=NULL;
    node* curr=head;
    node* nextptr;
    int count=0;

    while(count<k && curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reverseK(nextptr, k);
        //to point last element(old head, which is not changed) of k-size ll
        // to the new head(stored in prev) of next k-size ll
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
display(head);
node* n=reverseK(head,3);
display(n);
}