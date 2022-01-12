Hashing_Readme.txt

//Program Purpose
This program is written for implementing the delete function at the hash chain. 

1. Functions

(1) void hash_chain_delete (element item, ListNode* ht[]):
This function is for deleting a node with the key given as the input. It first gets the hash value by calling 'hash_function()'. Then it searches the chain of the matching hash value for node with same value as 'element item'. When there is no such node, the function prints error message and returns. Otherwise, the link of the parent node is updated. Finally, the node is freed and funciton returns. 
There is no return for this function.

(2) void main():
In main function, it gets the operation number from keyboard. If the operation number is 3, the main function calls ‘hash_chain_delete()’ to delete the node with the given element and the hash table is printed out.  