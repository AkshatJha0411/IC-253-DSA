#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

int main() {
    // 3.1 Binary Tree (no BST rules — manual construction)
    Node* binaryRoot = new Node(1);
    binaryRoot->left = new Node(2);
    binaryRoot->right = new Node(3);
    binaryRoot->left->left = new Node(4);
    binaryRoot->left->right = new Node(5);

    cout << "Binary Tree Traversals:\n";
    cout << "Pre-order: ";
    preOrder(binaryRoot); cout << "\n";
    cout << "In-order: ";
    inOrder(binaryRoot); cout << "\n";
    cout << "Post-order: ";
    postOrder(binaryRoot); cout << "\n\n";

    // 3.2 Binary Search Tree (using ordered insertions)
    Node* bstRoot = nullptr;
    bstRoot = insertBST(bstRoot, 10);
    insertBST(bstRoot, 5);
    insertBST(bstRoot, 15);
    insertBST(bstRoot, 3);
    insertBST(bstRoot, 7);

    cout << "Binary Search Tree Traversals:\n";
    cout << "Pre-order: ";
    preOrder(bstRoot); cout << "\n";
    cout << "In-order: ";
    inOrder(bstRoot); cout << "\n";
    cout << "Post-order: ";
    postOrder(bstRoot); cout << "\n";

    return 0;
}
