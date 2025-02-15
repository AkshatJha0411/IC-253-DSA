#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class CircularLinkedList {
    public:
    vector<int> arr = {5, 7, 2, 4, 8, 1};
    Node* head = nullptr;

    Node* construct(vector<int>& arr) {
        if (arr.empty()) return nullptr;
        head = new Node(arr[0]);
        Node* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        mover->next = head; // Making it circular
        return head;
    }

    void insertHead(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void insertTail(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insertK(int x, int k) {
        if (k == 0) {
            insertHead(x);
            return;
        }
        int c = 0;
        Node* temp = head;
        Node* newNode = new Node(x);
        while (temp->next != head && c < k - 1) {
            temp = temp->next;
            c++;
        }
        if (c < k - 1) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printElements() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void deleteHead(){
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteTail(){
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    void deleteK(int k){
        if (!head) return;
        if (k == 0) {
            deleteHead();
            return;
        }
        int c = 0;
        Node* temp = head;
        while (temp->next != head && c < k - 1) {
            temp = temp->next;
            c++;
        }
        if (temp->next == head || c < k - 1) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        Node* n = temp->next;
        temp->next = n->next;
        delete n;
    }
};

int main() {
    CircularLinkedList cll;
    cll.head = cll.construct(cll.arr);
    
    cll.insertHead(10);
    cll.insertTail(20);
    cll.insertK(15, 2);
    cll.deleteHead();
    cll.deleteTail();
    cll.deleteK(4);
    cll.printElements();
    
    return 0;
}
