#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int balance(Node* n) {
    return height(n->left) - height(n->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int b = balance(root);

    if (b > 1 && key < root->left->key) return rotateRight(root);      // LL
    if (b < -1 && key > root->right->key) return rotateLeft(root);     // RR
    if (b > 1 && key > root->left->key) {                               // LR
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (b < -1 && key < root->right->key) {                             // RL
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* minNode(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        Node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int b = balance(root);

    if (b > 1 && balance(root->left) >= 0) return rotateRight(root);
    if (b > 1 && balance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (b < -1 && balance(root->right) <= 0) return rotateLeft(root);
    if (b < -1 && balance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

bool search(Node* root, int key) {
    if (!root) return false;
    if (key == root->key) return true;
    return search(key < root->key ? root->left : root->right, key);
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);  // Right-heavy, will rotate
    cout << "Tree (in-order): ";
    inOrder(root); cout << "\n";

    root = insert(root, 25);  // Causes RL rotation
    cout << "After inserting 25: ";
    inOrder(root); cout << "\n";

    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inOrder(root); cout << "\n";

    cout << "Searching 25: " << (search(root, 25) ? "Found" : "Not found") << "\n";

    return 0;
}
