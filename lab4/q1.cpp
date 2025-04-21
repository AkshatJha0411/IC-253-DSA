#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

int comparisons = 0;

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    comparisons++;
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

bool search(Node* root, int key) {
    while (root) {
        comparisons++;
        if (key == root->key) return true;
        root = (key < root->key) ? root->left : root->right;
    }
    return false;
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* remove(Node* root, int key) {
    if (!root) return nullptr;
    comparisons++;
    if (key < root->key)
        root->left = remove(root->left, key);
    else if (key > root->key)
        root->right = remove(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = remove(root->right, temp->key);
    }
    return root;
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert values
    cout << "Inserting 50...\n";
    comparisons = 0;
    root = insert(root, 50);
    cout << "Comparisons: " << comparisons << endl;
    inOrder(root); cout << "\n\n";

    cout << "Inserting 30...\n";
    comparisons = 0;
    root = insert(root, 30);
    cout << "Comparisons: " << comparisons << endl;
    inOrder(root); cout << "\n\n";

    cout << "Inserting 70...\n";
    comparisons = 0;
    root = insert(root, 70);
    cout << "Comparisons: " << comparisons << endl;
    inOrder(root); cout << "\n\n";

    cout << "Inserting 20...\n";
    comparisons = 0;
    root = insert(root, 20);
    cout << "Comparisons: " << comparisons << endl;
    inOrder(root); cout << "\n\n";

    cout << "Searching for 30...\n";
    comparisons = 0;
    bool found = search(root, 30);
    cout << (found ? "Found" : "Not Found") << ", Comparisons: " << comparisons << "\n\n";

    cout << "Deleting 30...\n";
    comparisons = 0;
    root = remove(root, 30);
    cout << "Comparisons: " << comparisons << endl;
    inOrder(root); cout << "\n";

    return 0;
}