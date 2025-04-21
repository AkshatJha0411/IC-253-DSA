#include <iostream>
using namespace std;

int comparisons = 0;

struct PQNode {
    int priority;
    string value;
    PQNode* left;
    PQNode* right;
    PQNode(int p, string v) : priority(p), value(v), left(nullptr), right(nullptr) {}
};

PQNode* insertPQ(PQNode* root, int priority, string value) {
    if (!root) return new PQNode(priority, value);
    if (priority < root->priority)
        root->left = insertPQ(root->left, priority, value);
    else
        root->right = insertPQ(root->right, priority, value);
    return root;
}

bool searchPQ(PQNode* root, int priority) {
    while (root) {
        comparisons++;
        if (priority == root->priority) return true;
        root = (priority < root->priority) ? root->left : root->right;
    }
    return false;
}

PQNode* findMin(PQNode* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

PQNode* deleteMin(PQNode* root) {
    if (!root) return nullptr;
    if (!root->left) {
        PQNode* temp = root->right;
        delete root;
        return temp;
    }
    root->left = deleteMin(root->left);
    return root;
}

void inOrderPQ(PQNode* root) {
    if (!root) return;
    inOrderPQ(root->left);
    cout << "(" << root->priority << ", " << root->value << ") ";
    inOrderPQ(root->right);
}

int main() {
    PQNode* root = nullptr;

    // Insert elements
    cout << "Inserting (3, TaskA)...\n";
    root = insertPQ(root, 3, "TaskA");
    inOrderPQ(root); cout << "\n\n";

    cout << "Inserting (1, TaskB)...\n";
    root = insertPQ(root, 1, "TaskB");
    inOrderPQ(root); cout << "\n\n";

    cout << "Inserting (5, TaskC)...\n";
    root = insertPQ(root, 5, "TaskC");
    inOrderPQ(root); cout << "\n\n";

    // Search for a priority
    cout << "Searching for priority 3...\n";
    comparisons = 0;
    if (searchPQ(root, 3))
        cout << "Found. Comparisons: " << comparisons << "\n";
    else
        cout << "Not found. Comparisons: " << comparisons << "\n";
    cout << endl;

    // Delete the highest-priority element (smallest number)
    cout << "Deleting highest-priority task...\n";
    root = deleteMin(root);
    inOrderPQ(root); cout << "\n";

    return 0;
}
