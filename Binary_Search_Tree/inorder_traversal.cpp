// Online C++ compiler to run C++ program online
#include <iostream>
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
    cout<<v->data<<" "<<"up"<<endl;
    inorder(v->right);
    cout<<v->data<<" "<<"down"<<endl;
}
int main() {
     // Build the tree
    Node* root = new Node(100);
    root->left = new Node(20);
    root->right = new Node(200);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(150);
    root->right->right = new Node(300);

    // Function call
    cout << "Inorder Traversal: "<<endl;
    inorder(root);
    return 0;

}