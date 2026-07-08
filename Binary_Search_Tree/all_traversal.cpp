// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
        
    }
    Node *add
};
void inorder(Node *root){
    if(root==nullptr){
        return;
        
    }
    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);
    
    
}
void preorder(Node *root){
    if(root==nullptr){
        return;
        
    }
    cout<<root->data<<"->";
    preorder(root->left);
    preorder(root->right);
    
    
    
}
void postorder(Node *root){
    if(root==nullptr){
        return;
        
    }
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"->";
    
    
    
}


int main() {
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
    cout<<"inorder traversal:"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal:"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal:"<<endl;
    postorder(root);
    
    
    
    
    
    
    return 0;
}