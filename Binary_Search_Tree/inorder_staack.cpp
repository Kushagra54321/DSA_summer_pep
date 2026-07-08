// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
     Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
    
} *root=nullptr;
void inorder_stack(Node *root){
    stack<Node*>st;
    while((root!=nullptr) || !st.empty()){
        while(root!=nullptr){
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
}
int main() {
    Node* root=new Node(1);
     root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->left = new Node(7);
    inorder_stack(root);
    

    return 0;
}