#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int l = 2*i + 1, r = 2*i + 2, largest = i;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; --i) heapify(a, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    vector<int> a = {10, 3, 76, 34, 23, 32};
    heapSort(a);
    for (int x : a) cout << x << " ";
}
// #include <iostream>
// #include <vector>
// using namespace std;

// // Heapify a subtree rooted with node i which is an index in arr[].
// // n is the size of the heap.
// void heapify(vector<int>& arr, int n, int i) {
//     int largest = i;         // Initialize largest as root
//     int left = 2 * i + 1;    // left child index
//     int right = 2 * i + 2;   // right child index

//     // If left child is larger than root
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // If right child is larger than largest so far
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If largest is not root
//     if (largest != i) {
//         swap(arr[i], arr[largest]);

//         // Recursively heapify the affected sub-tree
//         heapify(arr, n, largest);
//     }
// }

// // Main function to perform heap sort
// void heapSort(vector<int>& arr) {
//     int n = arr.size();

//     // Step 1: Build max heap
//     for (int i = n / 2 - 1; i >= 0; i--){
//         heapify(arr, n, i);
//     }

//     // Step 2: Extract elements one by one from heap
//     for (int i = n - 1; i > 0; i--) {
//         // Move current root to end
//         swap(arr[0], arr[i]);

//         // Call max heapify on the reduced heap
//         heapify(arr, i, 0);
//     }
// }

// // Helper function to print the array
// void printArray(const vector<int>& arr) {
//     for (int val : arr)
//         cout << val << " ";
//     cout << endl;
// }

// // Driver code
// int main() {
//     vector<int> arr = {12, 11, 13, 5, 6, 7};

//     cout << "Original array:\n";
//     printArray(arr);

//     heapSort(arr);

//     cout << "Sorted array:\n";
//     printArray(arr);

//     return 0;
// }
