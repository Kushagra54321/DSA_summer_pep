// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v)
    {
        this->data = v;
        this->left = this->right = NULL;
    }
};
void inorder(Node* v){
    if(v==nullptr){
        return ;
    }
    inorder(v->left);
    cout<<v->data<<" ";
    inorder(v->right);
    // cout<<v->data<<" "<<"down"<<endl;
}
void stack_preorder(Node* v){
    if(v==nullptr){
        return;

    }
    stack<Node*>s;
    s.push(v);

    while(!s.empty()){
        Node*curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right!=nullptr){
            s.push(curr->right);
        }
        if(curr->left!=nullptr){
            s.push(curr->left);
        }
    }
}
 void stack_inorder(Node* v){
    if(v==nullptr){
        return;

    }
    
        stack<Node*> st;
    Node* curr = v;

    while (curr != NULL || !st.empty()) {

        // Go to the leftmost node
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // Visit the node
        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // Move to right subtree
        curr = curr->right;
    }
 }
int main() {
     // Build the tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    // Function call
    cout << "Inorder Traversal: "<<endl;
    inorder(root);
    cout << endl;
    cout << "Stack Preorder Traversal: "<<endl;
    stack_preorder(root);
    cout<< endl;
    cout<< "stack inorder traversal"<<endl;
    stack_inorder(root);


    return 0;

}