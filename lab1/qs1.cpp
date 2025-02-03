
#include <iostream>
#include <limits> // For input validation

using namespace std;

// Function to validate input and ensure a positive integer is entered
int getPositiveInteger() {
    int num;
    while (true) {
        cout<< "Enter positive integer: ";
        cin >> num;
        if (cin.fail() || num <= 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a positive integer.\n";
        } else {
            return num;
        }
    }
}

int main() {
    int a, b;

    // Get two positive integers with validation
    a = getPositiveInteger();
    b = getPositiveInteger();

    // Calculate GCD with Euclidean algorithm
    while (b != 0) {
        // cout << "a % b = " << (a % b) << endl; // Display the remainder
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "The GCD is: " << a << endl;

    return 0;
}
