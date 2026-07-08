#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert using BFS
Node* insert(Node* root, int value) {

    // If tree is empty
    if (root == NULL) {
        return new Node(value);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        // Left child
        if (temp->left == NULL) {
            temp->left = new Node(value);
            return root;
        } else {
            q.push(temp->left);
        }

        // Right child
        if (temp->right == NULL) {
            temp->right = new Node(value);
            return root;
        } else {
            q.push(temp->right);
        }
    }

    return root;
}

// Level Order Traversal
void levelOrder(Node* root) {

    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}

int main() {

    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}