heapsort_Readme.txt

//Program Purpose
This program is written for building the heap according to the heap property.

1. typedef

(1) HeapType:
the structure contains the address of the root(element *heap) of the heap and the size of the heap(int heap_size).

(2) element:
the structure contains the key(int key) of the heap element.


2. Functions

(1) void build_max_heap(HeapType *h):
This function is made for building the max heap. When the heap was given(HeapType *h), the function checks if each nodes' decendants are smaller than itself from bottom to up. If it is, then it is swapped with its children. 