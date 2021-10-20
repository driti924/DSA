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

/*
node* kAppend(node* head, int k){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    if(k>=l){
        return head;
    }
    int i=l-k-1;
    temp=head;
    while(i!=0){
        temp=temp->next;
        i--;
    }
    //now temp holds the value of last node of ll before k-size-ll(needed to be shifted at first)
    node* newstart=temp->next;
    node* newlast=temp;
    temp->next=NULL;
    
    temp=newstart;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head=newstart;
    return head;

}
*/

node* kAppend(node* head,int k){
    node* newtail;
    node* newhead;
    node* temp=head;
    int l=0;         //length of ll
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    temp=head;
    k=k%l;
     
    int count=1;
    while(temp->next!=NULL){
        if(count==l-k){
            newtail=temp;
        }
        if(count==l-k+1){
            newhead=temp;
        }
        count++;
        temp=temp->next;
    }
    temp->next=head; //temp holds the value of last node of original ll, so point it to original head
    newtail->next=NULL;
    return newhead;
}

int main(){
node* head=NULL;
display(head);
insertll(head,1);
insertll(head,2);
insertll(head,3);
insertll(head,4);
display(head);
node* n=kAppend(head,3);
display(n);
}