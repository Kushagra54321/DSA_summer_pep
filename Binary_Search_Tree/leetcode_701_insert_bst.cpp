#include<iostream>
using namespace std;
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=new TreeNode(val);
        TreeNode* temp=root;
        if(temp==nullptr){
            return curr;
        }
        while(true){
            if(val>temp->val){
                if(temp->right==nullptr){
                    temp->right=curr;
                    break;
                }
                temp=temp->right;
            }else if(val < temp->val){
                if(temp->left==nullptr){
                    temp->left=curr;
                    break;
                }
                temp=temp->left;

            }else{
                temp=curr;
            }

        }
        return root;

    }
};