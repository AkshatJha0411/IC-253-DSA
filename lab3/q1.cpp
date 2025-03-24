#include <bits/stdc++.h>
#include <climits>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Stack implementation using linked list
class Stack {
public:
Node* top;
    Stack() : top(nullptr) {}

    // Push operation
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        Node* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek operation (get top element)
    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display the stack
    void display() {
        Node* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Move disks between source, destination, and auxiliary
void moveDisks(Stack& src, Stack& dest, char s, char d) {
    int disk1 = src.isEmpty() ? INT_MIN : src.pop();
    int disk2 = dest.isEmpty() ? INT_MIN : dest.pop();

    // Legal move from source to destination
    if (disk1 == INT_MIN) {
        src.push(disk2);
        cout << "Move disk " << disk2 << " from " << d << " to " << s << endl;
    } else if (disk2 == INT_MIN) {
        dest.push(disk1);
        cout << "Move disk " << disk1 << " from " << s << " to " << d << endl;
    } else if (disk1 > disk2) {
        src.push(disk1);
        src.push(disk2);
        cout << "Move disk " << disk2 << " from " << d << " to " << s << endl;
    } else {
        dest.push(disk2);
        dest.push(disk1);
        cout << "Move disk " << disk1 << " from " << s << " to " << d << endl;
    }
}

// Solve Tower of Hanoi iteratively
void towerOfHanoi(int n) {
    Stack src, aux, dest ;
    char s = 'A',  a = 'B',d = 'C';

    // If number of disks is even, swap destination and auxiliary
    if (n % 2 == 0) swap(d, a);

    // Push initial disks onto source stack
    for (int i = n; i >= 1; i--) {
        src.push(i);
    }

    int totalMoves = pow(2,n) - 1; // 2^n - 1 moves

    // Perform the moves
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) moveDisks(src, dest, s, d);
        else if (i % 3 == 2) moveDisks(src, aux, s, a);
        else if (i % 3 == 0) moveDisks(aux, dest, a, d);
    }
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    towerOfHanoi(n);

    return 0;
}
