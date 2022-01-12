Readme_MergeList.txt

//Program Purpose
This program is written for performing the merge operation for two given simple linked list A and B. 
When sorted linked list A and B is given, it merges the two lists with elements in ascending order. 


1. typedef

(1) element: 
This typedef defines the data type of the data list that contains data and link.

(2) ListNode:
This structure is made to create a node and is in form of a node. It contains a data and link pointing to the address of the next node. 

(3) ListInfo:
This structure is for containing the principal information of each list. The double pointer to the head of the list and to the last node of the list is saved. 


2. Functions

(1) void init(ListInfo* list):
This function was made to initialize the list information when the list is first made. 
When it allocates the memory to each pointer, it creates blank list assigning the NULL to both phead and plast. 
There is no return for this function. 

(2) void insert_last(ListInfo list, element new_data):
This function is for inserting a new node to the existing list. 
It allocates memory to the new node and puts the input data 'new_data' as the data of the node. 
Then, it sets the link of 'new_node' as NULL since it is inserted to the last of the list. 
There is no return for this function. 

(3) void display_list(ListInfo list):
This function is for displaying the given list following the links of the list. When the list ends(when the link of current node is NULL), the function ends. 
There is no return for this function. 

(4) ListInfo merge_list(ListInfo listA, Listinfo listB):
This function is made to perform the merge operation with given two list 'listA' and 'listB'.
It creates a new list, 'listMerged' and initializes. The 'cntA' and 'cntB' points to the address of the current node of 'listA' and 'listB' that should be added to the list nextly. 
The while sentence loops untill 'cntA' and 'cntB' both points to the NULL. Inside the loop, the node with smaller data is added to the last of the 'listMerged' between 'cntA' and 'cntB'. When all elements of one of the two lists are added to the 'listMerged', all the nodes left in the other list are all inserted to the end of 'listMerged' in ascending order. 
When all the operation is done, the merged list with elements in ascending order 'listMerged' is created and function returns the 'listMerged'. 

(5) void main():
In the main fuction, the list that has to be merged are declared, and initialized with 'init()'. Then, the elements of 'listA' and 'listB' are put in ascending order through the for loop.
The two lists are merged by 'merge_list()'. Finally, the original list 'listA' and 'listB' and the merged list 'mergedList' are printed out through 'display_list()'.