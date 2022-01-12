Readme_linked_stack.txt

//Program Purpose
This program is written for implementing the linked stack's push and pop operation with a circular doubly linked list.

1. typedef

(1) element: 
This typedef represents the integer element of the list's node. 

(2) DlistNode:
This structure is made to set a form of doubly linked list's node that contains the element, left and right link. 

(3) LinkedStackType:
This structure is to save the address of the headnode of the doubly linked stack to distinguish a stack from other stack. 


2. Functions

(1) void init(DlistNode *s):
This function initializes the circular doubly linked list stack by setting the headnode of the list and initializing its two link to the headnode s. 
There is no return for this function. 

(2) int is_empty(DlistNode *s):
This function is for determining if the stack is empty. 
The function returns 1 when the queue is empty and 0 when the queue is not empty. 

(3) void push(DlistNode *s, element item):
This function is to add a new element to the top of the stack. It allocates the memory for new node and initializes as the given element. Then, it links the left link to the last node and the right link to the headnode. 
When the memory is not allocated properly, it prints message "Memory allocation error".
This function has no return. 

(4) element pop(DlistNode *s):
This function is to pop the last element added from the stack. It checks if the stack is empty, and if the stack is empty, it prints the message "Stack is empty" and stops. If it is not empty, it sets the temporary node as the last node of the stack. Then, it gets the data in the node and removes the last node from the stack. 
The function returns the element of the node poped. 

(5) element peek(DlistNode *s):
This function is to present the last element in the stack. Unlikely to 'pop()', it doesn't delete the node. 
If the stack is empry, it prints error message "Stack is empty"and stops the program. Otherwise, it returns the last element of the stack. 

(6)void main():
In main, it sets the circular doubly linked stack s and initializes by calling the function 'init()'. Then, it pushes 1,2,3 in order. Finally, it pops the element of stack from top. 