#include<iostream>
#include<cmath>
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

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void flatten(Node* root){

    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        Node* n=root->right;
        while(n->right!=NULL){
            n=n->right;
        }
        n->right=temp;
    }
    flatten(root->right);
    

}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    flatten(root);
    inorder(root);//inorder of the new flattened tree
    return 0;
}
/*
       1
      / \
     2   3
    / \  / \
   4   5 6  7
   
*/

