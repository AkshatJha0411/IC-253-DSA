#include <iostream>
#include <vector>
using namespace std;

// Function to maintain max-heap property from bottom up
void heapifyUp(vector<int>& heap, int i) {
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Insert key into Max-Heap
void insertKey(vector<int>& heap, int key) {
    heap.push_back(key);
    heapifyUp(heap, heap.size() - 1);
}

// Increase key at index i to newKey (assumes newKey > old key)
void increaseKey(vector<int>& heap, int i, int newKey) {
    if (newKey < heap[i]) {
        cout << "New key is smaller than current key!\n";
        return;
    }
    heap[i] = newKey;
    heapifyUp(heap, i);
}

// Print the heap
void printHeap(const vector<int>& heap) {
    for (int val : heap)
        cout << val << " ";
    cout << "\n";
}

int main() {
    vector<int> heap;

    // Insert keys
    insertKey(heap, 10);
    insertKey(heap, 20);
    insertKey(heap, 5);
    insertKey(heap, 30);

    cout << "Heap after insertions: ";
    printHeap(heap);

    // Increase key at index 2 (5 → 25)
    increaseKey(heap, 2, 25);
    cout << "Heap after increasing key at index 2 to 25: ";
    printHeap(heap);

    return 0;
}
