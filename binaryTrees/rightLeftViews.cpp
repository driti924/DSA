#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void rightView(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int n=q.size();
        for(int i=0;i<n;i++){

            Node* node=q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            if(i==n-1){
                cout<<node->data<<" ";
            }
        }
        
    }
}

void leftView(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int n=q.size();
        for(int i=0;i<n;i++){

            Node* node=q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            if(i==0){
                cout<<node->data<<" ";
            }
        }
        
    }
}


int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->left=new Node(8);
    rightView(root);
    cout<<endl;
    leftView(root);
    return 0;
}