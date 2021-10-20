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



void KdistanceInsubtree(Node* root, int k){

    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    if(root=NULL){
        return;
    }
    KdistanceInsubtree(root->left, k-1);
    KdistanceInsubtree(root->right, k-1);
    
}
int printKDist(Node* root, Node* target, int k){

    if(root==NULL){
        return -1;
    }
    if(root==target){
        KdistanceInsubtree(root,k);
        return 0;
    }

    int dl=printKDist(root->left, target, k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";

        }
        else{
            KdistanceInsubtree(root->right, k-dl-2);
        }
        return 1+dl;
    }

    int dr=printKDist(root->right, target, k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";

        }
        else{
            KdistanceInsubtree(root->left, k-dr-2);
        }
        return 1+dr;
    }

    return -1;

}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->left->left=new Node(8);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    int k=printKDist(root,root->left,2);
    return 0;
}
/*
       1
      / \
     2   3
    / \  / \
   4   5 6  7
  /
 8
   
*/

