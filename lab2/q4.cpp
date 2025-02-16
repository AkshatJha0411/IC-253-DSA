#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[5] = {4, 3, 2, 6, 1};
    int swaps = 0;
    int comparisons = 0;

    // Insertion Sort
    for (int i = 1; i < n; i++) { // Start from the second element
        int key = arr[i];
        int j = i - 1;

        // Compare key with previous elements and shift them if necessary
        while (j >= 0) {
            comparisons++; // Count each comparison
            if (arr[j] > key) {
                arr[j + 1] = arr[j]; // Shift element
                j--;
                swaps++; // Count swaps
            } else {
                break; // If arr[j] is not greater, stop shifting, breaks out of the while loop if no shifting is needed
            }
        }

        arr[j + 1] = key; // Insert the key at the correct position
    }

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "Comparisons: " << comparisons;
    cout << endl << "Swaps: " << swaps;

    return 0;
}
