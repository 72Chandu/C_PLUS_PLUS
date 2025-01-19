/*
Steps to Delete an Arbitrary Element in a Binary Heap
Locate the Element: Identify the index of the element you want to delete. In an array, this can be an 
O(n) operation since you might have to search the entire array to find the element.

Replace the Element with the Last Element:

Swap the element to be deleted with the last element in the heap array.
Remove the last element from the array (which is now the element you wanted to delete).
Restore the Heap Property:

         2
       /   \
      3     5
     / \   / \
    4   7  9  10
   /
  6
[2, 3, 5, 4, 7, 9, 10, 6]
Suppose we want to delete the element 4.

Locate the Element: 4 is at index 3.

Replace with the Last Element: Swap 4 with 6 (last element) and remove 4 from the array.
[2, 3, 5, 6, 7, 9, 10]

      2
    /   \
   3     5
  / \   / \
 6   7  9  10
Restore the Heap Property:

Heapify-down at index 3 (where 6 is now located).
6 is larger than its child 7, so no further heapify is needed.
The final heap array after deleting 4:
[2, 3, 5, 6, 7, 9, 10]
*/
#include <iostream>
#include <vector>
using namespace std;
void heapifyDown(vector<int>& heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;
    if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}
void heapifyUp(vector<int>& heap, int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heap[index] < heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}
void insert(vector<int>& heap, int value) {
    heap.push_back(value);
    heapifyUp(heap, heap.size() - 1);
}
void deleteElement(vector<int>& heap, int value) {
    // Find the index of the element to delete
    int index = -1;
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }
    // If the element is not found, return
    if (index == -1) {
        cout << "Element not found in the heap." << endl;
        return;
    }
    // Replace the element with the last element in the heap
    heap[index] = heap.back();
    heap.pop_back(); // Remove the last element
    // Restore the heap property by heapifying down or up as necessary
    if (index < heap.size()) {
        heapifyDown(heap, index);
        heapifyUp(heap, index); // To account for both directions
    }
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
    deleteElement(heap, 4); // Delete an arbitrary element (e.g., 4)
    cout << "Heap after deleting 4: ";
    printHeap(heap);
    return 0;
}
