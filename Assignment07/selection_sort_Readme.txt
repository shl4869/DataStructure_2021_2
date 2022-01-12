selection_sort_Readme.txt

//Program Purpose
This program is written for implementing the selection sorting in stable manner.

1. typedef

(1) data: 
This typedef contains the array of id (initial position of the data), and score of the data.

2. Functions

(1) void selection_sort_stable(data *list, int n):
This function sorts the given data in stable manner. It executes the selection sort when the score of current element is smaller than the least score. When the score of the current element is equal to the least score, it compares weather its id is smaller than the least element's id, and if it is, it executes SWAP operation.
There is no return for this function. 

(2) int main():
In main function, the id and the score array is initialized. Memory is allocated to the 'data *input' and the elements are set to the address of the initialized id and score. It prints out the original data, and executes the stable slection sort by calling 'slsection_sort_stable()'. Then, it prints out the sorted data. 