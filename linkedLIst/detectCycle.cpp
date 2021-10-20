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

void makeCycle(node* head, int pos){
    int count=1;
    node* temp=head;
    node* startOfCycle;
    while(temp->next!=NULL){
        if(count==pos){
            startOfCycle=temp;
        }
        count++;
        temp=temp->next;
    }
    temp->next=startOfCycle;
}
bool detectCycle(node* head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node* head){
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);

    fast=head;

    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;

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
cout<<detectCycle(head)<<endl;
makeCycle(head,3);
cout<<detectCycle(head)<<endl;
removeCycle(head);
cout<<detectCycle(head)<<endl;
}