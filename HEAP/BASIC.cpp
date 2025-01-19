Heapify is the process used to maintain the heap property in a binary heap data structure. In a min-heap, the parent node is always less than or equal to its children, while in a max-heap, the parent node is always greater than or equal to its children. Heapify helps to keep this structure intact by rearranging nodes in the heap.

There are two main types of heapify operations:

Heapify-up (or "Bubble-up")
Heapify-down (or "Bubble-down")
These operations are used for inserting and deleting elements to maintain the heap property.

1. Heapify-up (Bubble-up)
Heapify-up is used when a new element is added to the heap (usually at the end). It moves the new element up the tree until the heap property is restored.

Process:
Insert the new element at the end of the heap (maintaining the complete binary tree structure).
Compare the new element with its parent:
If it violates the heap property, swap it with its parent.
Continue this process until the element is in the correct position or reaches the root.
Time Complexity
The time complexity of heapify-up is 
O(logn) because, in the worst case, the element has to move up the height of the heap, which is 
O(logn) for a complete binary tree.
Example of Heapify-up in a Min-Heap
Given the min-heap:

         2
       /   \
      3     5
     / \
    4   7
Suppose we insert 1:

Insert 1 at the end:

      2
    /   \
   3     5
  / \   /
 4   7  1
Heapify-up: 1 is smaller than its parent 5, so swap 1 with 5.

      2
    /   \
   3     1
  / \   /
 4   7  5
1 is smaller than its new parent 2, so swap again.

      1
    /   \
   3     2
  / \   /
 4   7  5
2. Heapify-down (Bubble-down)
Heapify-down is used when removing the root element (the smallest in a min-heap or largest in a max-heap). It moves the new root element down the tree until the heap property is restored.

Process:
Replace the root with the last element in the heap and remove the last element.
Compare the new root with its children:
Swap it with the smaller child (in a min-heap) or larger child (in a max-heap) if it violates the heap property.
Repeat this process until the element is in the correct position or it has no children.
Time Complexity
The time complexity of heapify-down is 

O(logn), as the element may need to move down the height of the heap.
Example of Heapify-down in a Min-Heap
Given the min-heap:

         2
       /   \
      3     5
     / \
    4   7
Suppose we delete the root element (2):

Replace 2 with 7 (the last element) and remove 7 from the end.

      7
    /   \
   3     5
  /
 4
Heapify-down: 7 is greater than its smaller child 3, so swap 7 with 3.

      3
    /   \
   7     5
  /
 4
7 is greater than its child 4, so swap 7 with 4.
      3
    /   \
   4     5
  /
 7
Now the heap property is restored.
