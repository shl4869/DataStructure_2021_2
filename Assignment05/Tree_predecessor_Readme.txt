Tree_predecessor_Readme.txt

//Program Purpose
This program is written for finding the predecessor of the given node. 

1. typedef

(1) TreeNode:
This structure contains the key value(int key), the link address to the left(struct TreeNode *left) and right(struct TreeNode *left) node of the node, and the address to the parent node(struct TreeNode *parent). 


2. Functions

(1) TreeNode* tree_predecessor(TreeNode* p):
If the left subtree of the given node is not NULL, it returns the rightmost node of left subtree as the predecessor. When the left subtree of the given node is NULL, the it returns the ancestor of the given node which has the node as the right subtree. 

(6)void main():
In main function, the program assigns the parent nodes of the nodes in the tree. Then, it goes to the rightmost node. Then the program prints the data of the node and updates the preceding node(predecessor) of the current node to q using function ‘tree_predecessor()’ until the predecessor of q is null. Using do-while statement, the loop is executed at least once.