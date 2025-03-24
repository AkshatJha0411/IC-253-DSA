#include <iostream>
#include <stack>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;
    
    for (char c : postfix) {
        // If the character is an operand, push it as a string
        if (!isOperator(c)) {
            s.push(string(1, c));
        } else {
            // Pop two operands from stack
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            
            // Determine if we need parentheses
            if (precedence(c) > precedence(op1[0])) {
                op1 = "(" + op1 + ")";
            }
            if (precedence(c) >= precedence(op2[0])) {
                op2 = "(" + op2 + ")";
            }
            
            // Form new expression and push back to stack
            string exp = op1 + c + op2;
            s.push(exp);
        }
    }
    
    // The final expression on stack is the result
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    
    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    
    return 0;
}
