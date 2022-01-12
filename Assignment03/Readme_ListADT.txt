Readme_ListADT.txt

//Program Purpose
This program was written to implement the 'List ADT' that perform the operation of adding, deleting node to various place in a linked list, search specific element, get element in certain location of list, and display the list. 


0. Define

(1) TRUE 1, FALSE 0:
This definition is for using boolean form when judging whether element is in the list or not. 


1. typedef

(1) element: 
This typedef defines the data type of the element in list that contains data and link.

(2) ListNode:
This structure is made to create a node and is in form of a node. It contains a data and link pointing to the address of the next node. 

(3) ListType:
This structure is for containing the principal information of each list. The pointers to the head and tail of the list and the length of the list are saved. 


2. Functions

(1) void error(const char* message):
This function is for printing out the error message and halting the program after error. 
This function has no return. 

(2) void init(ListType* list):
This function was made to initialize the list information when the list is first made. 
It creates blank list assigning the NULL to both head and tail of the list and sets the length to 0. 
There is no return for this function. 

(3) int is_empty(ListType* list):
This function returns 0 if list has at least one node, and returns 1 when the list is empty(when the head of list is NULL).

(4) int get_length(ListType* list):
This function returns the length of the given list. 

(5) ListNode* get_node_at(ListType* list, int pos):
This function follows the link of the list and returns the 'pos'th node's address. If the pos is negetive integer, the function returns NULL. 

(6) void insert_node(ListNode** phead, ListNode* p, ListNode* new_node):
This function is made to insert node after the node 'p'. 
When the list is empty(when the headpointer is pointing to NULL), the new node is added to the first place of the list and the '*phead' is updated to the address of new node. 
When the list has element and the preceding node is NULL, the new node is inserted to the beggining of the list and the headpointer is updated. Otherwise, the new node's link is updated to link of preceding node, then the preceding node's link is updated to the address of the new node. 
This function has no return. 

(7) void add(ListType* list, int position, element data):
This function is for adding the new node in the location given(int position). 
When the position is whithin the length of the list, the data is assigned to node->data. Then the function searches for the preceding node of the location that the new node should be inserted by 'get_node_at()'. When the preceding node was found, new node is inserted to the position through 'insert_node()' and the length of the list increses by 1. 
This function has no return.

(8) void add_first(ListType* list, element data):
This function is for adding the new node in the beginning of the list. 
When the memory is allocated to the new node, the data is assigned to the node->data. 
If the list is empty, the tail is updated to the new node.
The node is inserted to the beginning of the list by 'inset_node()' and the length of the list increses by 1. 
This function has no return. 

(9) void add_last(ListType* list, element data):
This function is for adding the new node in the end of the list. 
When the memory is allocated to the new node, the data is assigned to the node->data. 
Since the node is inserted to the end of the list, the tail is updated to the new node.
The node is inserted to the end of the list by 'inset_node()' and the length of the list increses by 1. 
This function has no return. 

(10) void remove_node(ListNode** phead, ListNode* p, ListNode* removed):
This function is made to remove the node after the node 'p'. 
When the list is empty(when the headpointer is pointing to NULL), there is nothing to remove, so it prints error. When the preceding node is NULL, the first node's link is saved to the headpointer and the first node is removed. Otherwise, the link of preceding node is updated to the link of removed node and the node is removed through 'free()'. 
This function has no return. 

(11) void delete_node(ListType* list, int pos):
This function is for deleting the node in the location given(int pos). 
When the list is not empty and position is whithin the length of the list, the function searches for the preceding node of the location that the node should be deleted by 'get_node_at()'. When the preceding node was found, node of the position is removed through 'remove_node()' and the length of the list decreses by 1. 
This function has no return.

(12) void delete_first(ListType* list):
This function is for deleting the node at the beginning of the list. 
If the list length is 1, the deletion would make it to blank list. So, the tail should be updated. 
The node at the beginning of the list is deleted by 'remove_node()' and the length of the list decreases by 1. 
This function has no return. 

(13) void delete_last(ListType* list):
This function is for deleting the node at the end of the list. 
The node is inserted to the end of the list by 'inset_node()' and the length of the list decreases by 1. 
Since the node deleted is tail, the tail is updated to the preceding node.
This function has no return. 

(14) element get_entry(ListType* list, int pos):
This function follows the list and returns the data at the given position(int pos).

(15) void display(ListType* list):
This function follows the given list and prints out the list in form of "( elements )".
This function has no return. 

(16) int is_in_list(ListType* list, element item):
This fucntion follows the given list and finds the given data(element item) in the list. When the data is in the list, the while loop ends and the p contains the address of the node that contains the data. Otherwise, the loop continues until it meets the end of the list. 
If it finds the data in list, the function returns 'TRUE' and if it cannot find the data in the list, it returns 'FALSE'. 

(3) void main():
In the main fuction, 'list1' is defined and the elements are added or deleted to the list1. Then it looks up the list for data 20, and gets the data from the 0th place of the list. 




