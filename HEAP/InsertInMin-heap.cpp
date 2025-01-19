/*Each node has either zero or two children, with nodes being added from left to right. The last level may not be fully filled, but all the nodes must be as far left as possible.        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  / \ / \
 8  9 10 11
if parent at i 
then left childe at=2*i
then right childe at=2*i+1

The root node is at index 0.
For any node at index i:
The left child is at index 2 * i + 1.
The right child is at index 2 * i + 2.
The parent is at index (i - 1) // 2.

-> if child at i then parent at i/2 
insert the new node in heap->
=add the node at end of the array 
=then put this node at correct position by comparing the node with it parent (i/2) that parent > child => tc O(logn)

ex:
         2
       /   \
      4     5
     / \   / \
    6   7  9  10
    [2, 4, 5, 6, 7, 9, 10]
 insert the value 3 
 Add the Element at the End  [2, 4, 5, 6, 7, 9, 10, 3]
         2
      /   \
     4     5
    / \   / \
   6   7  9  10
  /
 3
Compare 3 with its parent 6. Since 3 is smaller, swap them
        2
      /   \
     4     5
    / \   / \
   3   7  9  10
  /
 6
[2, 4, 5, 3, 7, 9, 10, 6]

Compare 3 with 4. Since 3 is smaller, swap them.
        2
      /   \
     3     5
    / \   / \
   4   7  9  10
  /
 6
 [2, 3, 5, 4, 7, 9, 10, 6]
Now, 3 is in the correct position as it is greater than 2,
*/
//########################################################
#include <iostream>
#include <vector>
using namespace std;
void heapifyUp(vector<int>& heap, int index) {
    if (index == 0) return;  // Stop if we reach the root
    int parentIndex = (index - 1) / 2;
    // If the current element is smaller than its parent, swap them
    if (heap[index] < heap[parentIndex]) {  // For max heap, use heap[index] > heap[parentIndex]
        swap(heap[index], heap[parentIndex]);
        heapifyUp(heap, parentIndex);// Recursively heapify up the parent
    }
}
void insert(vector<int>& heap, int value) {
    // Add the new element at the end of the heap
    heap.push_back(value);
    // Restore the heap property by bubbling up
    heapifyUp(heap, heap.size() - 1);
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
    insert(heap, 4);
    insert(heap, 5);
    insert(heap, 6);
    insert(heap, 7);
    insert(heap, 9);
    insert(heap, 10);

    cout << "Heap before inserting 3: ";
    printHeap(heap);
    // Insert a new element, 3, into the min-heap
    insert(heap, 3);
    cout << "Heap after inserting 3: ";
    printHeap(heap);
    return 0;
}
/*
hepify using loop 

void heapifyUp(int index) {
    while (index > 0) { // Continue until we reach the root
        int parentIndex = (index - 1) / 2;

        // If the current element is smaller than its parent in a min-heap
        // (or larger if it's a max-heap), swap them
        if (heap[index] < heap[parentIndex]) { // For max-heap, use `heap[index] > heap[parentIndex]`
            swap(heap[index], heap[parentIndex]);
            
            // Move to the parent index to continue heapifying up
            index = parentIndex;
        } else {
            break; // Exit the loop if the heap property is satisfied
        }
    }
}

*/
