#include <iostream>
using namespace std;

// Node class representing each element in the circular linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a new node with given data
    Node(int x) {
        data = x;
        next = nullptr; // Initially, the next pointer is null
    }
};

// Class representing a circular linked list
class CircularLinkedList {
public:
    Node* head; // Pointer to the head (first node) of the linked list

    // Constructor to initialize an empty circular linked list
    CircularLinkedList() : head(nullptr) {}

    // Function to construct a circular linked list from an array
    Node* construct(int arr[], int size) {
        if (size == 0) return nullptr; // Return if the array is empty
        head = nullptr; // Reset head before constructing the list
        for (int i = 0; i < size; i++) {
            insertTail(arr[i]); // Insert each element at the tail
        }
        return head;
    }

    // Function to insert a new node at the head (beginning) of the circular linked list
    void insertHead(int x) {
        Node* newNode = new Node(x);
        if (!head) { // If the list is empty
            head = newNode;
            head->next = head; // Point to itself to maintain circular property
            return;
        }
        Node* temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Update last node's next pointer
        newNode->next = head; // New node points to the old head
        head = newNode; // Update head pointer
    }

    // Function to insert a new node at the tail (end) of the circular linked list
    void insertTail(int x) {
        Node* newNode = new Node(x);
        if (!head) { // If the list is empty
            head = newNode;
            head->next = head; // Point to itself
            return;
        }
        Node* temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Update last node's next pointer
        newNode->next = head; // New node points to head, maintaining circular property
    }

    // Function to insert a new node at a given position (0-based index)
    void insertK(int x, int k) {
        if (k == 0) { // If position is 0, insert at head
            insertHead(x);
            return;
        }
        int c = 0; // Position counter
        Node* temp = head;
        Node* newNode = new Node(x);
        while (temp->next != head && c < k - 1) { // Traverse to the k-1 position
            temp = temp->next;
            c++;
        }
        if (c < k - 1) { // If position is out of bounds
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next = temp->next; // Insert new node between temp and temp->next
        temp->next = newNode;
    }

    // Function to delete the head (first node) of the circular linked list
    void deleteHead() {
        if (!head) return; // If the list is empty, do nothing
        if (head->next == head) { // If only one node is present
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) { // Find the last node
            last = last->next;
        }
        head = head->next; // Update head to next node
        last->next = head; // Last node now points to new head
        delete temp; // Delete the old head
    }

    // Function to delete the last node (tail) of the circular linked list
    void deleteTail() {
        if (!head) return; // If the list is empty, do nothing
        if (head->next == head) { // If only one node is present
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) { // Traverse to second last node
            temp = temp->next;
        }
        delete temp->next; // Delete the last node
        temp->next = head; // Update the second last node to point to head
    }

    // Function to delete a node at a given position (0-based index)
    void deleteK(int k) {
        if (!head) return; // If the list is empty, do nothing
        if (k == 0) { // If position is 0, delete head
            deleteHead();
            return;
        }
        int c = 0; // Position counter
        Node* temp = head;
        while (temp->next != head && c < k - 1) { // Traverse to the k-1 position
            temp = temp->next;
            c++;
        }
        if (temp->next == head || c < k - 1) { // If position is out of bounds
            cout << "Position out of bounds!" << endl;
            return;
        }
        Node* n = temp->next; // Node to be deleted
        temp->next = n->next; // Bypass the node to be deleted
        delete n;
    }

    // Function to print the elements of the circular linked list
    void printElements() {
        if (!head) return; // If the list is empty, do nothing
        Node* temp = head;
        while (temp) { // Traverse the list
            cout << temp->data << " "; // Print data
            temp = temp->next;
            if (temp == head) break; // Stop when we reach the head again
        }
        cout << endl;
    }

    // Function to print elements from k-th node to (k-1)-th node in the circular list
    void printKtoKminusOne(int k) {
        if (!head) { // If the list is empty, print a message
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        int count = 0;

        // Find the k-th node
        while (count < k) {
            temp = temp->next;
            count++;
            if (temp == head) { // If k is larger than the list size
                cout << "Position out of bounds!" << endl;
                return;
            }
        }

        Node* startNode = temp; // Store the starting node
        while (true) {
            cout << temp->data << " "; // Print data
            temp = temp->next;
            if (temp == startNode) break; // Stop when we reach the start node again
        }
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll; // Create a circular linked list object
    int arr[] = {5, 7, 2, 4, 8, 1}; // Array to be converted into a circular linked list
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    cll.head = cll.construct(arr, size); // Construct the list

    cll.insertHead(10); // Insert 10 at the head
    cll.insertTail(20); // Insert 20 at the tail
    cll.insertK(15, 2); // Insert 15 at index 2
    cll.deleteHead(); // Delete the head node
    cll.deleteTail(); // Delete the last node
    cll.deleteK(4); // Delete the node at index 4
    cll.printElements(); // Print the list elements
    cll.printKtoKminusOne(2); // Print elements from the 2nd node to 1st node

    return 0;
}
