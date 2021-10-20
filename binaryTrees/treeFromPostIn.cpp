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

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int search(int inorder[], int start, int end, int curr){
    
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;

}
Node* buildTree(int inorder[], int postorder[], int start, int end){
    static int idx=4;//last index of postorder, size of tree-1

    if(start > end){
        return NULL;
    }
    
    int curr=postorder[idx];
    idx--;

    Node* node = new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder, start, end, curr);

    node->right=buildTree(inorder, postorder, pos+1, end);
    node->left=buildTree(inorder, postorder, start, pos-1);

    return node;
}

int main(){
     
    int inorder[]={4,2,1,5,3};
    int postorder[]={4,2,5,3,1};

    Node* ans = buildTree(inorder, postorder , 0, 4);
    preorder(ans);
    cout<<"\n";
    return 0;
}