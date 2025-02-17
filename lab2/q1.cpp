#include <iostream>
using namespace std;

// Define a Node class to represent each element in the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize a node with data and set next to nullptr
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Define a LinkedList class to manage the list of nodes
class LinkedList {
public:
    Node* head = nullptr;  // Pointer to the first node in the list

    // Function to construct a linked list from an array
    Node* construct(int arr[], int size) {
        if (size == 0) return nullptr;  // If array is empty, return nullptr

        // Create the first node with the first element of the array
        head = new Node(arr[0]);
        Node* mover = head;  // Use 'mover' to traverse and build the list

        // Loop through the array to create and link the remaining nodes
        for (int i = 1; i < size; i++) {
            Node* temp = new Node(arr[i]);  // Create a new node
            mover->next = temp;  // Link the new node to the list
            mover = temp;       // Move 'mover' to the new node
        }
        return head;  // Return the head of the constructed list
    }

    // Function to insert a new node at the head of the list
    void insertHead(int x) {
        Node* newNode = new Node(x);  // Create a new node
        newNode->next = head;         // Point the new node to the current head
        head = newNode;               // Update head to the new node
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
        temp->next = newNode;        // Link the previous node to the new node
    }

    // Function to print all elements in the linked list
    void printElements() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";  // Print the data of the current node
            temp = temp->next;          // Move to the next node
        }
        cout << endl;
    }

    // Function to delete the head node of the list
    void deleteHead(){
        if (!head) return;  // If list is empty, do nothing
        Node* temp = head;
        head = temp->next;  // Update head to the next node
        delete temp;         // Delete the old head node
    }

    // Function to delete the tail node of the list
    void deleteTail(){
        if (!head) return;  // If list is empty, do nothing
        if (!head->next) {
            delete head;    // If only one node, delete it
            head = nullptr;
            return;
        }
        Node* temp = head;
        // Traverse to the second last node
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;  // Delete the last node
        temp->next = nullptr;  // Set the next of the second last node to nullptr
    }

    // Function to delete a node at a specific position (k) in the list
    void deleteK(int k){
        if (!head) return;  // If list is empty, do nothing
        if (k == 0) {
            deleteHead();  // If k is 0, delete the head
            return;
        }
        int c = 0;
        Node* temp = head;
        // Traverse to the (k-1)th position
        while (temp && c < k - 1) {
            temp = temp->next;
            c++;
        }
        if (!temp || !temp->next) { 
            cout << "Position out of bounds!" << endl;  // If k is out of bounds, print error
            return;
        }
        Node* n = temp->next;  // Node to be deleted
        temp->next = n->next;  // Link the previous node to the next node
        delete n;              // Delete the node
    }
};

int main() {
    LinkedList ll;
    int arr[] = {5, 7, 2, 4, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Construct the linked list from the array
    ll.head = ll.construct(arr, size); 

    // Insert 10 at the head of the list
    ll.insertHead(10);

    // Insert 20 at the tail of the list
    ll.insertTail(20);

    // Insert 15 at the 2nd index (0-based)
    ll.insertK(15, 2);

    // Delete the head of the list
    ll.deleteHead();

    // Delete the tail of the list
    ll.deleteTail();

    // Delete the node at the 4th index (0-based)
    ll.deleteK(4);

    // Print all elements in the list
    ll.printElements(); 

    return 0;
}