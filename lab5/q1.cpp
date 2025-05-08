#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& heap, int i, int n) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;
    if (largest != i) {
        swap(heap[i], heap[largest]);
        maxHeapify(heap, largest, n);
    }
}

void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n/2 - 1; i >= 0; --i){
        maxHeapify(heap, i, n);
    }
}

int getMax(const vector<int>& heap) {
    return heap.empty() ? -1 : heap[0];
}

int extractMax(vector<int>& heap) {
    if (heap.empty()) return -1;
    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    maxHeapify(heap, 0, heap.size());
    return maxVal;
}

int main() {
    vector<int> heap = {4, 10, 3, 5, 1};
    buildMaxHeap(heap);

    cout << "Max: " << getMax(heap) << endl;

    cout << "Extracted Max: " << extractMax(heap) << endl;

    cout << "Heap after extraction: ";
    for (int x : heap) cout << x << " ";
    cout << endl;

    return 0;
}
