#include <iostream>
using namespace std;

// Node class representing each element in the doubly linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* prev; // Pointer to the previous node
    Node* next; // Pointer to the next node

    // Constructor to initialize a new node with given data
    Node(int x) {
        data = x;
        next = nullptr; // Initially, the next pointer is null
        prev = nullptr; // Initially, the previous pointer is null
    }
};

// Class representing a doubly linked list
class DoublyLinkedList {
public:
    Node* head; // Pointer to the head (first node) of the linked list

    // Constructor to initialize an empty linked list
    DoublyLinkedList() : head(nullptr) {}

    // Function to append a new node at the end of the linked list
    void append(int data) {
        Node* new_node = new Node(data); // Create a new node with given data
        if (!head) { // If the list is empty, make the new node the head
            head = new_node;
            return;
        }
        
        Node* temp = head; // Temporary pointer to traverse the list
        while (temp->next) { // Move to the last node
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = new_node;
        new_node->prev = temp;
    }
    
    // Function to convert an array into a doubly linked list
    void array_to_list(int arr[], int size) {
        for (int i = 0; i < size; i++) { // Iterate through the array
            append(arr[i]); // Append each element to the linked list
        }
    }

    // Function to perform insertion sort on the doubly linked list
    void insertion_sort() {
        if (!head || !head->next) return; // If the list is empty or has one node, no sorting is needed
        
        Node* current = head->next; // Start sorting from the second node
        while (current) {
            Node* key = current; // Store the current node (key)
            
            // Move key to the correct position by swapping data values
            while (key->prev && key->data < key->prev->data) {
                swap(key->data, key->prev->data); // Swap values if they are out of order
                key = key->prev; // Move back to continue checking previous elements
            }
            current = current->next; // Move to the next node in the list
        }
    }

    // Function to print the linked list
    void print_list() {
        Node* temp = head; // Start from the head
        while (temp) {
            cout << temp->data << " <-> "; // Print the current node's data
            temp = temp->next; // Move to the next node
        }
        cout << "None" << endl; // Indicate the end of the list
    }
};

int main() {
    DoublyLinkedList dll; // Create a doubly linked list object
    int arr[] = {4, 3, 5, 1, 2}; // Array to be converted into a linked list
    int size = 5; // Size of the array
    dll.array_to_list(arr, size); // Convert the array into a doubly linked list

    cout << "Before sorting:" << endl;
    dll.print_list(); // Print the list before sorting

    dll.insertion_sort(); // Perform insertion sort on the linked list

    cout << "After sorting:" << endl;
    dll.print_list(); // Print the list after sorting
    
    return 0;
}
