#include <iostream>
#include <vector>
using namespace std;

// Linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert a new node at the end of the linked list
void insert(Node*& head, int value) {
    if (!head) {
        head = new Node(value);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(value);
}

// Function to find and print elements at n/2, n/3, ..., n/k positions
void findPositions(Node* head) {
    vector<Node*> pointers;
    Node* current = head;
    int index = 1;

    while (current) {
        // Dynamically track positions: n/2, n/3, ..., n/k
        for (int k = 2; k <= index + 1; k++) {
            if (index % k == 0) {
                if (pointers.size() < k - 1) {
                    pointers.push_back(head); // Initialize pointers
                }
                pointers[k - 2] = pointers[k - 2]->next;
            }
        }
        current = current->next;
        index++;
    }

    cout << "Elements at positions n/2, n/3, ..., n/k:" << endl;
    for (Node* ptr : pointers) {
        cout << ptr->data << " ";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int value;

    cout << "Enter linked list elements (enter -1 to stop):\n";
    while (cin >> value && value != -1) {
        insert(head, value);
    }

    findPositions(head);

    // Cleanup memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
