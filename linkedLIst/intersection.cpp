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

void  createIntersect(node* &head1, node* &head2, int pos){
    //create intersection at "pos" of ll1( simply link end of ll2 to this pos node of ll1)
    int count=1;
    node* temp=head1;
    while(count!=pos){
        temp=temp->next;
        count++;
    }
    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    
}

int detectIntersect(node* head1, node* head2){
    int l1=length(head1);
    int l2=length(head2);
    int idx;
    node* temp1;
    node* temp2;
    if(l1>l2){
        idx=l1-l2;
        temp1=head1;
        temp2=head2;
    }
    else{
        idx=l2-l1;
        temp1=head2;
        temp2=head1;
    }
    while(idx--){
        temp1=temp1->next;
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1==temp2){
            return temp1->data;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}


int main(){
node* head=NULL;
node* head2=NULL;
display(head);
insertll(head,1);
insertll(head,2);
insertll(head,3);
insertll(head,4);
insertll(head,5);
insertll(head,6);
insertll(head2,1);
insertll(head2,2);
createIntersect(head,head2,5);
display(head);
display(head2);
int val=detectIntersect(head,head2);
cout<<val<<endl;
}