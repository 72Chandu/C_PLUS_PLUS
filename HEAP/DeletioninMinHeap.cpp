/*
Steps for Deletion in a Min-Heap

         2
       /   \
      3     5
     / \   / \
    4   7  9  10
   /
  6
[2, 3, 5, 4, 7, 9, 10, 6]
Let's delete the root element (2).

Step-by-Step Process
Replace the Root with the Last Element:

[6, 3, 5, 4, 7, 9, 10]
        6
      /   \
     3     5
    / \   / \
   4   7  9  10
Heapify Down (Bubble Down):

Current Index: 0, Value: 6

Left Child Index: 2 * 0 + 1 = 1, Value: 3

Right Child Index: 2 * 0 + 2 = 2, Value: 5

Compare 6 with 3 (left child) and 5 (right child). Since 3 is the smallest, swap 6 with 3.
[3, 6, 5, 4, 7, 9, 10]
        3
      /   \
     6     5
    / \   / \
   4   7  9  10
Compare 6 with 4 and 7. Since 4 is the smallest, swap 6 with 4.

[3, 4, 5, 6, 7, 9, 10]

        3
      /   \
     4     5
    / \   / \
   6   7  9  10
Stop When Heap Property is Restored:

The heap property is now restored, and 3 is the new root.
Final Array Representation
After deleting 2, the final min-heap in array form is:

[3, 4, 5, 6, 7, 9, 10]
*/
#include <iostream>
#include <vector>
using namespace std;
void heapifyDown(vector<int>& heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;
    // Find the smallest among the node and its children
    if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }
    // If the smallest isn't the current node, swap and continue heapifying down
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}
void insert(vector<int>& heap, int value) {
    heap.push_back(value);
    int index = heap.size() - 1;
    while (index != 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
void deleteRoot(vector<int>& heap) {
    if (heap.size() == 0) {
        cout << "Heap is empty." << endl;
        return;
    }
    heap[0] = heap.back();// Replace the root with the last element
    heap.pop_back();
    heapifyDown(heap, 0);// Restore the heap property by bubbling down
}
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    vector<int> heap;
    insert(heap, 2);
    insert(heap, 3);
    insert(heap, 5);
    insert(heap, 4);
    insert(heap, 7);
    insert(heap, 9);
    insert(heap, 10);
    insert(heap, 6);
    cout << "Heap before deletion: ";
    printHeap(heap);
    deleteRoot(heap); // Delete the root element
    cout << "Heap after deletion: ";
    printHeap(heap);

    return 0;
}
//O(logn)
