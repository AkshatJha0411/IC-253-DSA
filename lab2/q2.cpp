#include <iostream>
using namespace std;

// Define a Node class to represent each element in the doubly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
    Node* prev;     // Pointer to the previous node in the list

    // Constructor to initialize a node with data and set next/prev to nullptr
    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

// Define a DoublyLinkedList class to manage the list of nodes
class DoublyLinkedList {
public:
    Node* head;  // Pointer to the first node in the list

    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to construct a doubly linked list from an array
    Node* construct(int arr[], int size) {
        if (size == 0) return nullptr;  // If array is empty, return nullptr

        // Create the first node with the first element of the array
        head = new Node(arr[0]);
        Node* temp = head;  // Use 'temp' to traverse and build the list

        // Loop through the array to create and link the remaining nodes
        for (int i = 1; i < size; i++) {
            Node* newNode = new Node(arr[i]);  // Create a new node
            temp->next = newNode;  // Link the new node to the list
            newNode->prev = temp;  // Link the new node back to the previous node
            temp = newNode;        // Move 'temp' to the new node
        }
        return head;  // Return the head of the constructed list
    }

    // Function to insert a new node at the head of the list
    void insertHead(int x) {
        Node* newNode = new Node(x);  // Create a new node
        if (head) {
            newNode->next = head;  // Link the new node to the current head
            head->prev = newNode;  // Link the current head back to the new node
        }
        head = newNode;  // Update head to the new node
    }

    // Function to insert a new node at the tail of the list
    void insertTail(int x) {
        Node* newNode = new Node(x);  // Create a new node
        if (!head) {
            head = newNode;  // If list is empty, set new node as head
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;  // Traverse to the last node
        }
        temp->next = newNode;  // Link the new node to the end of the list
        newNode->prev = temp;  // Link the new node back to the previous node
    }

    // Function to insert a new node at a specific position (k) in the list
    void insertK(int x, int k) {
        if (k == 0) {
            insertHead(x);  // If k is 0, insert at the head
            return;
        }
        int c = 0;
        Node* temp = head;
        Node* newNode = new Node(x);  // Create a new node

        // Traverse to the (k-1)th position
        while (temp && c < k - 1) {
            temp = temp->next;
            c++;
        }
        if (!temp) {
            cout << "Position out of bounds!" << endl;  // If k is out of bounds, print error
            return;
        }
        newNode->next = temp->next;  // Link the new node to the next node
        if (temp->next) {
            temp->next->prev = newNode;  // Link the next node back to the new node
        }
        temp->next = newNode;  // Link the previous node to the new node
        newNode->prev = temp;  // Link the new node back to the previous node
    }

    // Function to delete the head node of the list
    void deleteHead() {
        if (!head) return;  // If list is empty, do nothing
        Node* temp = head;
        head = head->next;  // Update head to the next node
        if (head) head->prev = nullptr;  // If new head exists, set its prev to nullptr
        delete temp;  // Delete the old head node
    }

    // Function to delete the tail node of the list
    void deleteTail() {
        if (!head) return;  // If list is empty, do nothing
        if (!head->next) {
            delete head;  // If only one node, delete it
            head = nullptr;
            return;
        }
        Node* temp = head;
        // Traverse to the last node
        while (temp->next) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;  // Set the next of the second last node to nullptr
        delete temp;  // Delete the last node
    }

    // Function to delete a node at a specific position (k) in the list
    void deleteK(int k) {
        if (!head) return;  // If list is empty, do nothing
        if (k == 0) {
            deleteHead();  // If k is 0, delete the head
            return;
        }
        int c = 0;
        Node* temp = head;
        // Traverse to the kth position
        while (temp && c < k) {
            temp = temp->next;
            c++;
        }
        if (!temp) {
            cout << "Position out of bounds!" << endl;  // If k is out of bounds, print error
            return;
        }
        if (temp->next) temp->next->prev = temp->prev;  // Link the next node to the previous node
        if (temp->prev) temp->prev->next = temp->next;  // Link the previous node to the next node
        delete temp;  // Delete the node
    }

    // Function to print all elements in the doubly linked list
    void printElements() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";  // Print the data of the current node
            temp = temp->next;        // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    int arr[] = {5, 7, 2, 4, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Construct the doubly linked list from the array
    dll.head = dll.construct(arr, size);

    // Insert 10 at the head of the list
    dll.insertHead(10);

    // Insert 20 at the tail of the list
    dll.insertTail(20);

    // Insert 15 at the 2nd index (0-based)
    dll.insertK(15, 2);

    // Delete the head of the list
    dll.deleteHead();

    // Delete the tail of the list
    dll.deleteTail();

    // Delete the node at the 4th index (0-based)
    dll.deleteK(4);

    // Print all elements in the list
    dll.printElements();

    return 0;
}