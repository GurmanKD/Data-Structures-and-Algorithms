#include <iostream>
#include <algorithm> 

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int height(Node* root) {
    if (root == NULL)
        return 0; 
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    // Create a sample tree: 
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of the tree is: " << height(root) << endl;

    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
