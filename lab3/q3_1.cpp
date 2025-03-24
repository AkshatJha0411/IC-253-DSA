#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 100 // Maximum size of the binary tree

class BinaryTree {
public:
int tree[MAX_SIZE];
int size;
    BinaryTree() : size(0) {
        for (int i = 0; i < MAX_SIZE; i++) {
            tree[i] = -1; // Initialize tree with -1 (indicating empty)
        }
    }

    // Insert a node in the binary tree
    void insert(int value) {
        if (size >= MAX_SIZE) {
            cout << "Tree is full!" << endl;
            return;
        }
        tree[size++] = value; // Add to the next available position
    }

    // Search for a node in the binary tree
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (tree[i] == value) return i;
        }
        return -1; // Not found
    }

    // Delete a node by replacing it with the bottom-most and rightmost node
    void deleteNode(int value) {
        int index = search(value);

        if (index == -1) {
            cout << "Value not found in the tree." << endl;
            return;
        }

        // Replace with the last node
        tree[index] = tree[size - 1];
        tree[size - 1] = -1;
        size--;
    }

    // Display the binary tree
    void display() {
        cout << "Binary Tree (Array Representation): ";
        for (int i = 0; i < size; ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(30);
    bt.insert(40);
    bt.insert(50);

    cout << "After insertion: ";
    bt.display();

    int value = 30;
    int pos = bt.search(value);
    if (pos != -1)
        cout << value << " found at index " << pos << endl;
    else
        cout << value << " not found." << endl;

    bt.deleteNode(30);
    cout << "After deletion of 30: ";
    bt.display();

    bt.deleteNode(100);

    return 0;
}
