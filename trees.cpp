#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int value){
        val=value;
        left=NULL;
        right=NULL;
    }
};

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(!root) return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(!root) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}





int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Node* templ =  root->left;
    Node* tempr = root->right;

    templ->left = new Node(4);
    templ->right = new Node(5);

    // templ->right->right = new Node(8); 
    // templ->right->right->right = new Node(9); 

    tempr->right = new Node(7);
    tempr->left = new Node(6);


    inorder(root);cout<<endl;
    preorder(root);cout<<endl;
    postorder(root);cout<<endl;

    return 0;
}