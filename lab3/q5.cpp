#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (char ch : infix) {
        // If the character is an operand (A-Z, a-z, 0-9), add it to output
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        // If the character is '(', push it to stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '(' from stack
        }
        // If an operator is encountered
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    
    // Pop all remaining operators from stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
