#include <iostream>
using namespace std;

int main() {
    int n = 5; // Number of elements in the array
    int arr[5] = {4, 3, 2, 6, 1}; // Unsorted array
    int swaps = 0; // Counter for swap operations
    int comparisons = 0; // Counter for comparison operations

    // Insertion Sort Algorithm
    for (int i = 1; i < n; i++) { // Start from the second element (index 1)
        int key = arr[i]; // Store the current element to be placed in the correct position
        int j = i - 1; // Start comparing with the previous elements

        // Shift elements of the sorted portion to make space for key
        while (j >= 0) { // Continue shifting until the correct position is found
            comparisons++; // Count each comparison
            if (arr[j] > key) { // If the current element is greater than key
                arr[j + 1] = arr[j]; // Move the larger element one position to the right
                j--; // Move to the previous element
                swaps++; // Count swap (shifting operation)
            } else {
                break; // Stop shifting if no more elements need to be moved
            }
        }

        arr[j + 1] = key; // Place key in the correct position in the sorted portion
    }

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output each element
    }

    cout << endl << "Comparisons: " << comparisons; // Print total number of comparisons
    cout << endl << "Swaps: " << swaps; // Print total number of swaps

    return 0;
}
