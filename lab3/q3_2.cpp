#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int val) {
        value=val; 
        left=nullptr; 
        right=nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree(){
        root=nullptr;
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    bool search(TreeNode* node, int value) {
        if (!node) return false;
        return node->value == value || search(node->left, value) || search(node->right, value);
    }

    void findBottomRight(TreeNode* node, TreeNode* &parent, TreeNode* &bottomRight) {
        if (!node) return;
        if (node->left) { parent = node; findBottomRight(node->left, parent, bottomRight); }
        if (node->right) { parent = node; findBottomRight(node->right, parent, bottomRight); }
        bottomRight = node;
    }

    void replaceAndDelete(TreeNode* parent, TreeNode* target) {
        TreeNode *bottomRight = nullptr, *bottomRightParent = nullptr;
        findBottomRight(root, bottomRightParent, bottomRight);
        target->value = bottomRight->value;
        if (bottomRightParent->right == bottomRight) bottomRightParent->right = nullptr;
        else bottomRightParent->left = nullptr;
        delete bottomRight;
    }

    void findAndDelete(TreeNode* node, int value) {
        if (!node) return;
        if (node->left && node->left->value == value) {
            replaceAndDelete(node, node->left);
        } else if (node->right && node->right->value == value) {
            replaceAndDelete(node, node->right);
        } else {
            findAndDelete(node->left, value);
            findAndDelete(node->right, value);
        }
    }

    int countNodes(TreeNode* node) {
        return node ? 1 + countNodes(node->left) + countNodes(node->right) : 0;
    }

    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (!root) { root = newNode; return; }
        TreeNode* current = root;
        while (true) {
            if (!current->left) { current->left = newNode; return; }
            if (!current->right) { current->right = newNode; return; }
            current = countNodes(current->left) <= countNodes(current->right) ? current->left : current->right;
        }
    }

    bool search(int value) { return search(root, value); }

    void deleteNode(int value) { if (root && root->value == value) replaceAndDelete(nullptr, root); else findAndDelete(root, value); }

    void displayInorder() { inorder(root); cout << endl; }
};

int main() {
    BinaryTree bt;

    for (int v : {10, 20, 30, 40, 50, 60}) bt.insert(v);

    cout << "Inorder before deletion:\n"; bt.displayInorder();

    bt.deleteNode(30);

    cout << "Inorder after deletion:\n"; bt.displayInorder();

    cout << "Search 40: " << (bt.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (bt.search(100) ? "Found" : "Not Found") << endl;

    return 0;
}
