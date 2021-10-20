#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

map<int, vector<int>> mp;

struct Node{
    int data;
    Node* left,*right;
    public:
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void verticalView(Node* root, int hdis){
    if(root==NULL){
        return;
    }
    mp[hdis].push_back(root->data);
    verticalView(root->left, hdis-1);
    verticalView(root->right, hdis+1);

}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(10);
    root->left->right=new Node(20);
    
    verticalView(root, 0);

    map<int, vector<int>> :: iterator it;

    for(it=mp.begin();it!=mp.end();it++){
        for(int i=0;i < (it->ss).size();i++){
            cout<<(it->ss)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}