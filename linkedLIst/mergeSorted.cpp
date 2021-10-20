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

int length(node* head){
    int l=0;
    while(head!=NULL){
        head=head->next;
        l++;
    }
    return l;
}

node* mergeSortedll(node* head1, node* head2){
    node* ptr1=head1;
    node* ptr2=head2;
    node* newnode=new node(-1);
    node* ptr3=newnode;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data < ptr2->data){
            ptr3->next=ptr1;
            ptr3=ptr3->next;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr3=ptr3->next;
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr3=ptr3->next;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr3=ptr3->next;    
        ptr2=ptr2->next;
    }
    return newnode->next;
}
//try to merge recursively by urself now!


int main(){
node* head=NULL;
node* head2=NULL;
display(head);
insertll(head,1);
insertll(head,2);
insertll(head,4);
insertll(head,7);
insertll(head,9);
insertll(head,11);
insertll(head2,3);
insertll(head2,5);
display(head);
display(head2);
node* n=mergeSortedll(head,head2);
display(n);
}