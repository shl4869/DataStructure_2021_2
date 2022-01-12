decrease_increase_key_Readme.txt

//Program Purpose
This program is written for implementing the decrease key and increase key function of min heap.

0. define

(1) SWAP(x.y.t): This definition executes swap operation between two data.
(2) HEAPSIZE: This definition represents the number of elements in the heap.


1. Functions

(1) void print_heap (int* A):
This function prints out the heap stored in array displayed in levels.
There is no return for this function.

(2) void Decrease_key_min_heap(int* A, int i, int key): 
This function is for decreasing the value of the key in given index i. Since the heap is min heap, when key is decreased, the key value may be smaller than its ancestors. So, the function compares the value with its parent and if the key value of the parent is larger, the two nodes of the heap is swapped. This iterates until the key changed is no more smaller than its parent. 
This function has no return. 

(3) void Increase_key_min_heap (int* A, int i, int key): 
This function is for increasing the value of the key in given index i. Since the heap is min heap, when key is increased, the key value may be bigger than its children. If the key value of the node is bigger than its child, the function swaps the two value's location. Unlike the decrease key, the swapped child can be bigger than its original sibling, which is child after swap. So, the function calls itself recursively for the swapped value. This sequence is executed iteratively until the heap qualifies the minheap property. 
This function has no return.

(4) void main():
In main function, the input heap is initialized. Then it prints the original heap and calls Decrease_key_min_heap() and Increase_key_min_heap() and prints its results. 
※ The heap starts from index 1, not 0. 