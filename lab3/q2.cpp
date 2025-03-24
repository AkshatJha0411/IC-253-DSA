#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;
};

// Stack class using linked list
class Stack {
public:
    Node* top;

    Stack() { top = nullptr; }

    void push(char x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    char pop() {
        if (top == nullptr) return '\0'; // Stack underflow (should not happen in a correct expression)
        char popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to check if two brackets match
bool isMatchingPair(char left, char right) {
    return (left == '(' && right == ')') || 
           (left == '{' && right == '}') || 
           (left == '[' && right == ']');
}

// Function to check if parentheses are balanced
bool isBalanced(string expr) {
    Stack s;
    
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false; // More closing brackets than opening
            char topChar = s.pop();
            if (!isMatchingPair(topChar, ch)) return false; // Mismatch
        }
    }
    
    return s.isEmpty(); // If stack is empty at the end, it's balanced
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr)) 
        cout << "Balanced\n";
    else 
        cout << "Not Balanced\n";

    return 0;
}
