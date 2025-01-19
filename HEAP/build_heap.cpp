/*
Identify the Last Non-Leaf Node:
The last non-leaf node in a binary heap (in an array) is at index (n / 2) - 1, where n is the number of elements.
Heapify Down for Each Node:

Starting from the last non-leaf node, perform a heapify-down operation on each node up to the root (index 0).
This will ensure that each subtree satisfies the heap property, resulting in a complete min-heap or max-heap.
Example: Building a Min-Heap

[10, 5, 6, 2, 3, 7, 1]
Starting with the last non-leaf node and applying heapify-down will result in a min-heap.
*/
#include <iostream>
#include <vector>
using namespace std;
void heapifyDown(vector<int>& heap, int index) {
    int size = heap.size();
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    // Check if the left child is smaller
    if (leftChild < size && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }

    // Check if the right child is smaller
    if (rightChild < size && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    // If the smallest is not the current node, swap and continue heapifying down
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}
void buildMinHeap(vector<int>& array) {
    // Build the heap by heapifying down from the last non-leaf node to the root
    for (int i = (array.size() / 2) - 1; i >= 0; i--) {
        heapifyDown(array, i);
    }
}
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    vector<int> array = {10, 5, 6, 2, 3, 7, 1};
    buildMinHeap(array);
    cout << "Min-Heap: ";
    printHeap(array);
    return 0;
}
/*
Constructor: MinHeap(vector<int>& array) takes an unsorted array and initializes the heap.
Heapify Down: Starting from the last non-leaf node (n / 2) - 1 to 0, it calls heapifyDown on each node, ensuring the entire array follows the min-heap property.

For the input array [10, 5, 6, 2, 3, 7, 1], the output will be:
Min-Heap: 1 2 6 5 3 7 10
*/



