// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
vector<int>v;
int idx=0;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
        
        
    }
    
};
void inOrder(Node* node) {
    if (node == nullptr)
        return;
        
    // Traverse the left subtree first
    inOrder(node->left);
    
    // Visit the current node
    v.push_back(node->data);
    
    // Traverse the right subtree last
    inOrder(node->right);
}
void preOrder(Node* node) {
    if (node == nullptr)
        return;

    // Visit the current node first
    cout<<node->data<<" ";

    // Traverse the left subtree
    preOrder(node->left);

    // Traverse the right subtree
    preOrder(node->right);
}
void buildMinHeap(Node *root) {
    if (root == nullptr) return;

    // Parent gets the smallest available value
    root->data = v[idx++];
    
    // Then move to children
    buildMinHeap(root->left);
    buildMinHeap(root->right);
}


int main() {
    
    Node* root = new Node(40);
    root->left = new Node(30);
    root->right = new Node(50);
    root->left->left = new Node(25);
    root->left->right = new Node(35);
    root->right->left = new Node(45);
    root->right->right = new Node(55);
    root->left->left->left = new Node(20);
    // vector<int> res;
    inOrder(root);
    cout<<"inorder"<<endl;
    for( int node :v) 
        cout << node << " ";
    cout<<endl;
    cout<<"preorder"<<endl;
     preOrder(root);
    buildMinHeap(root);
    cout<<endl;
    cout<<"min heap "<<endl;
    preOrder(root);
    
    cout<<endl;
    
    // for( int node :v) 
    //     cout << node << " ";
        
    

    return 0;
}