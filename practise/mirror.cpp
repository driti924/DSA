#include<iostream>
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

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* mirror(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node* left=mirror(root->right);
    Node* right=mirror(root->left);
    root->left=left;
    root->right=right;
    return root;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
   
    inorder(root);
    cout<<"\n";
    Node* root2=mirror(root);
    inorder(root2);
    cout<<"\n";

    return 0;
}