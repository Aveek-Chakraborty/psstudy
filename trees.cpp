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

void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        auto node=q.front();
        q.pop();
        cout<<node->val<<" ";

        if(node->left){
            q.push(node->left);
        }

        if(node->right){
            q.push(node->right);
        }
    }
}

int height(Node* root){
    if(!root) return 0;

    int l = height(root->left);
    int r = height(root->right);

    return 1+max(l,r);
}

int isbalanced(Node* root){
    if(!root) return 0;

    int l = isbalanced(root->left);
    if(l==-1) return -1;

    int r = isbalanced(root->right);
    if(r==-1) return -1;

    if(abs(l-r)>-1) return -1;

    return 1+max(l,r);
}

int maxi=0;
int diameter(Node* root){
    if(!root) return 0;

    int l = diameter(root->left);
    int r = diameter(root->right);

    int maxi = max(maxi,l+r);

    return 1+max(l,r);
}


bool same(Node* p , Node* q){
    if(!p && !q) return true;
    if(!p || !q) return false;

    return (p->val == q->val && same(p->left,q->left) && same(p->right,q->right));
}






int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    Node* templ =  root->left;
    Node* tempr = root->right;

    templ->left = new Node(4);
    templ->right = new Node(5);

    templ->right->right = new Node(8); 
    templ->right->right->right = new Node(99); 

    tempr->right = new Node(7);
    tempr->left = new Node(6);


    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    Node* templ2 =  root2->left;
    Node* tempr2 = root2->right;

    templ2->left = new Node(4);
    templ2->right = new Node(5);

    templ2->right->right = new Node(8); 
    templ2->right->right->right = new Node(9); 

    tempr2->right = new Node(7);
    tempr2->left = new Node(6);


    // inorder(root);cout<<endl;
    // preorder(root);cout<<endl;
    // postorder(root);cout<<endl;


    // levelorder(root);

    // cout<<isbalanced(root);

    cout<<same(root , root2);

    return 0;
}