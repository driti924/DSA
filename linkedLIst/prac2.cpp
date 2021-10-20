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

void oddeven(node* &head){
    
    node* odd=head;
    node* even=head->next;
    node* evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
        
        odd->next=even->next;
        odd=odd->next;
        
        even->next=odd->next;
        even=even->next;
        
    }
    //working without this as well
    if(odd->next!=NULL){
        even->next=NULL;
    }
    odd->next=evenstart;
}

int main(){
node* head=NULL;
display(head);
insertll(head,1);
insertll(head,2);
insertll(head,3);
insertll(head,4);
insertll(head,5);
//insertll(head,6);
display(head);
oddeven(head);
display(head);
}