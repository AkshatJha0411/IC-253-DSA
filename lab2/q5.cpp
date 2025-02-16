#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}

    void append(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }

    void insertion_sort() {
        if (!head || !head->next) return;
        
        Node* current = head->next;
        while (current) {
            Node* key = current;
            while (key->prev && key->data < key->prev->data) {
                swap(key->data, key->prev->data);
                key = key->prev;
            }
            current = current->next;
        }
    }

    void print_list() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(4);
    dll.append(3);
    dll.append(5);
    dll.append(1);
    dll.append(2);

    cout << "Before sorting:" << endl;
    dll.print_list();

    dll.insertion_sort();

    cout << "After sorting:" << endl;
    dll.print_list();
    
    return 0;
}
