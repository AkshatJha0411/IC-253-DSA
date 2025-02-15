#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    vector<int> arr = {5, 7, 2, 4, 8, 1};

    DoublyLinkedList() {
        head = nullptr;
    }

    Node* construct(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        head = new Node(arr[0]);
        Node* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            temp->prev = mover;
            mover = temp;
        }
        return head;
    }

    void insertHead(int x) {
        Node* newNode = new Node(x);
        if (head) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertTail(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertK(int x, int k) {
        if (k == 0) {
            insertHead(x);
            return;
        }
        int c = 0;
        Node* temp = head;
        Node* newNode = new Node(x);
        while (temp && c < k - 1) {
            temp = temp->next;
            c++;
        }
        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next = temp->next;
        if (temp->next) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteK(int k) {
        if (!head) return;
        if (k == 0) {
            deleteHead();
            return;
        }
        int c = 0;
        Node* temp = head;
        while (temp && c < k) {
            temp = temp->next;
            c++;
        }
        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void printElements() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.head = dll.construct(dll.arr);
    
    dll.insertHead(10);
    dll.insertTail(20);
    dll.insertK(15, 2);
    dll.deleteHead();
    dll.deleteTail();
    dll.deleteK(4);
    dll.printElements();
    
    return 0;
}
