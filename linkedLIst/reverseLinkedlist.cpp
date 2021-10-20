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
void insertAtHead(node* &head,int val){
    node* temp=new node(val);
    temp->next=head;
    head=temp;
}
/*node* reverse(node* head){
    node* start=NULL;
    node* temp=head;
    while(temp!=NULL){
        insertAtHead(start,temp->data);
        temp=temp->next;
    }
    return start;
}*/
//iterative method...
node* reverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*  prev=NULL;
    node* curr=head;
    node* nextptr;

    while(curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        //basecase ex, here 3->NULL => we wont do anything in this case but return 3(i.e last node,
        //which will be saved in newnode and keep on transfering from function to function and 
        //finally returned from "reverseRecursive(1)" = first node).
        return head;
    }
    node* newnode = reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newnode;

}

int main(){
node* head=NULL;
display(head);
insertll(head,1);
insertll(head,2);
insertll(head,3);
display(head);
//node* reversedll=reverse(head);
//display(reversedll);
node* reversedRecursivly=reverseRecursive(head);
display(reversedRecursivly);
}