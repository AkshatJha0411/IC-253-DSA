#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class LinkedList {
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
        return head;
    }

    void insertHead(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
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
    }

    void insertK(int x, int k) {
        if (k == 0) {  
            insertHead(x);
            return;
        }
        int c = 0;
        Node* temp = head;
        Node* newNode = new Node(x);
        while (temp && c < k - 1) { // Move to (k-1)th position
            temp = temp->next;
            c++;
        }
        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printElements() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteHead(){
        if (!head) return;
        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    void deleteTail(){
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteK(int k){
        if (!head) return;

        if (k == 0) {
            deleteHead();
            return;
        }

        int c = 0;
        Node* temp = head;

        while (temp && c < k - 1) { // Move to (k-1)th position
            temp = temp->next;
            c++;
        }

        if (!temp || !temp->next) { 
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* n = temp->next;
        temp->next = n->next;
        delete n;
    }
};

int main() {
    LinkedList ll;
    
    ll.head = ll.construct(ll.arr); 

    ll.insertHead(10);
    ll.insertTail(20);
    ll.insertK(15, 2); // 0-based index, so inserts at index 2
    ll.deleteHead();
    ll.deleteTail();
    ll.deleteK(4); // Delete at index 2
    ll.printElements(); 

    return 0;
}