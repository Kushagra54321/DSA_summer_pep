// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
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
};

vector<vector<int>> level(Node* root){
    if(root==nullptr){
        return {};
    }
    queue<Node*>q;
     vector<vector<int>> res;
    q.push(root);
    int l=0;
    
    while(!q.empty()){
        int len=q.size();
        res.push_back({});
        for(int i=0;i<len;i++){
            Node *n=q.front();
            q.pop();
            res[l].push_back(n->data);
        
            if(n->left!=nullptr){
                q.push(n->left);
            
            }
            if(n->right!=nullptr){
                q.push(n->right);
            
            }
        
        }
        l++;
        
    }
    return res;
}


int main() {
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
    
    
    cout<<"level order:"<<endl;
    vector<vector<int>>res=level(root);
    for(vector<int> l:res){
        for(int a:l){
            cout<<a<<" ";
            
        }
        cout<<endl;
    }
    return 0;
}