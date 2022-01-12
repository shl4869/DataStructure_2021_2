bst_insertion_deletion_Readme.txt

//Program Purpose
This program is written for implementing insertion and deletion of the node of binary tree. 
in delete_node(), the program deletes the node that has given key value.

1. typedef

(1) TreeNode:
This structure contains the key value(int key) and the link address to the left(struct TreeNode *left) and right(struct TreeNode *left) node of the node. 


2. Functions

(1) void delete_node(TreeNode **root, int key):
This function is to delete the node that has the value of 'int key'. At the beginning of the function, the target node 'TreeNode *t' and its parent 'TreeNode *p' is initialized as NULL and *root. Then in the first while loop, t is updated to the target node and p is updated to the parent of t using the binary search algorithm. If there is no node with the value 'int key' the function prints error message and returns. The case3 which the target node has both left and right subtree starts at line 106, else statement. This initializes the 'TreeNode *pred_p' as parent of 'TreeNode *pred' which is 't' and 'TreeNode *pred' as  't->left' to search the predecessor at left subtree. the while loop finds the rightmost node of the left subtree. When the loop ends, 'pred_p->right' is updated to the left child of 'pred' and the value of the target node is updated to the value of its predecessor. 
This function has no return. 

(6)void main():
In main, the tree's root node is set to n1. Then, it first prints the tree in inorder process, and it deletes the node of given key value. Finally it prints the tree after node deletion in inorder process. 