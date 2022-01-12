prim_algorithm_Readme.txt

//Program Purpose
This program is written for implementing prim algorithm using min heap. 

0. define

(1) SWAP(x.y.t): This definition executes swap operation between two data.
(2) TRUE: This definition represents true value, which is 1.
(3) FALSE: This definition represents false value, which is 0.
(4) MAX_VERTICES: This definition represents the max number of vertices.
(2) INF: This definition represents infinite, for meaning no connection between vetices and the initialization of dist value for each vertex.


1. typedef

(1) struct vertex:
This structure contains the information about a vertex, including 'selected', 'dist', 'parent', 'child[]', 'child_num' and 'heap_id'.


2. global variable

(1) int weight[][]:
This 2D array contains the edge information between vertices. 

(2) vertex vertices[]:
This array contains each vertex of the graph. 

(3) int minheap[]:
This array is for minheap based on the value of 'dist' for each vertex, and the array contains the id of each vertex. 
※ The heap starts from index 1, not 0. 

(4) int heap_size:
This variable indicates the changed heap size due to the delete_min_heap() function.


1. Functions

(1) void build_min_heap (int* A):
This function initializes the heap and executes the line 'inserts all vertices into the priority queue Q' in the pseudo code. Since all vertices have INF for 'dist' at initial stage, this function just adds all vertices in to the heap in order of vertex id.  
There is no return for this function.

(2) void Decrease_key_min_heap(int* A, int i, int key): 
This function is for decreasing the value of the 'vertices[A[i]].dist' to given input 'int key'. Since the heap is min heap, when key is decreased, the key value may be smaller than its ancestors. So, the function compares the value with its parent and if the key value of the parent is larger, the two nodes of the heap is swapped. This iterates until the key changed is no more smaller than its parent. 
This function has no return. 

(3) void Increase_key_min_heap (int* A, int i, int key): 
This function is for decreasing the value of the 'vertices[A[i]].dist' to given input 'int key'.  Since the heap is min heap, when key is increased, the key value may be bigger than its children. If the key value of the node is bigger than its child, the function swaps the two value's location. Unlike the decrease key, the swapped child can be bigger than its original sibling, which is child after swap. So, the function calls itself recursively for the swapped value. This sequence is executed iteratively until the heap qualifies the minheap property. 
This function has no return.

(4) int delete_min_heap(int* A):
This function is for deleting the top element in the heap. It sets return value(int return_id) as the first node in heap. Then it swaps the first node of heap with the last node of the heap, then calls Increase_key_min_heap to organize the nodes to qualify the heap property. Lastly, it returns the return value, which is the vertex id of the original first node. 

(5) void prim(int s, int n):
This function executes the prim algorithm. First, it initializes distance and selected of all vertices to INF and FALSE. Then, the start vertex vertices[s]'s distance is set to 0 and the min heap is built. Inside the 'for' loop, the vertex with smallest dist value is selected by calling 'delete_min_heap()'. If the dist value of the selected vertex is INF, it means that it has no connection with other nodes, so the function returns. Otherwise, the inner for loop is started, and it updates the weight of the nonselected neighboring vertex's dist value to the smallest by calling 'Decrease_key_min_heap()' and updates the parent of the vertex. When every vertex is selected, the function updates the child relationship of vertices by saving the child vertex id to the 'child[]' array. 
This function has no return. 

(6) void print_prim(int s):
This function prints the prim algorithm tree starting from vertices[s] in preorder. For every child of the vertex, it calls 'print_prim()' recursively. If the vertex is not starting vertex, the function prints out the information about the vertex. 

(4) void main():
In main function, prim algorithm is executed by calling 'prim()', then the result is printed by 'print_prim()'.
