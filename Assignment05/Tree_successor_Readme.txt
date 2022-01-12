Tree_successor_Readme.txt

//Program Purpose
This program is written for finding the successor of the given node. 

1. typedef

(1) TreeNode:
This structure contains the key value(int key), the link address to the left(struct TreeNode *left) and right(struct TreeNode *left) node of the node, and the address to the parent node(struct TreeNode *parent). 


2. Functions

(1) TreeNode* tree_successor(TreeNode* p):
If the right subtree of the given node is not NULL, it returns the leftmost node of right subtree as the successor. When the right subtree of the given node is NULL, the it returns the ancestor of the given node which has the node as the left subtree. 

(6)void main():
In main function, the program assigns the parent nodes of the nodes in the tree. Then, it goes to the leftmost node. Then the program prints the data of the node and updates the next node(successor) of the current node to q using function ‘tree_successor()’ until the successor of q is null. Using do-while statement, the loop is executed at least once.