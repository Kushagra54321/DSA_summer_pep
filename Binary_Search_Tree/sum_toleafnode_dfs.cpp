#include<iostream>
using namespace std;
class Node{
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
void preorder(Node* v,int sum,int &total){
    if(v==nullptr){
        return ;
    }
    sum+=v->data;
    if(v->left==nullptr && v->right==nullptr){
        total+=sum;
    }
    preorder(v->left,sum,total);
    preorder(v->right,sum,total);
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
    int total=0;
    preorder(root,0,total);
    cout << "Sum of all leaf nodes: "<<total<<endl;
    return 0;

}