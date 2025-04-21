#include <iostream>
#include <vector>
using namespace std;

// AVL Node structure and basic operations (same as before)
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

void inOrder(Node* root, vector<int>& result) {
    if (!root) return;
    inOrder(root->left, result);
    result.push_back(root->key);
    inOrder(root->right, result);
}

// Insertion Sort Algorithm using vector
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Generate random permutation using only vector
void generateRandomPermutation(vector<int>& arr, int n) {
    arr.resize(n);
    for (int i = 0; i < n; ++i) arr[i] = i + 1; // Fill array with 1 to n
    // Random shuffle using only vector (simple implementation)
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]); // Swap elements to shuffle
    }
}

int main() {
    // Test for different values of n
    for (int n = 1; n <= 1000; n *= 10) {
        vector<int> arr;
        generateRandomPermutation(arr, n);

        // AVL Tree Sorting
        Node* root = nullptr;
        for (int i = 0; i < n; ++i) {
            root = insert(root, arr[i]);
        }
        vector<int> sortedAVL;
        inOrder(root, sortedAVL);

        // Insertion Sort
        vector<int> arrCopy = arr;
        insertionSort(arrCopy);

        // Compare time for AVL vs Insertion Sort by counting operations
        cout << "n = " << n << endl;
        cout << "AVL Tree Sorting: ";
        for (int i = 0; i < n; ++i) cout << sortedAVL[i] << " ";
        cout << "\nInsertion Sort: ";
        for (int i = 0; i < n; ++i) cout << arrCopy[i] << " ";
        cout << "\n--------------------------\n";
    }

    return 0;
}
