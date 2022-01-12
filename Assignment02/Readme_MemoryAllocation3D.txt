Readme_MemoryAllocation3D.txt

//Program purpose
This program is written for dynamic memory allocation of the 3D array(matrix), and computing the sum of two arrays given. 


0. Define

(1) PAGE 3:
This definition is for input of the page size when doing sonething with the 3D array. 
This can be changed to value of page size you want the array to have. 

(2) ROW 3:
This definition is for input of the row size when doing sonething with the 3D array. 
This can be changed to value of row size you want the array to have. 

(3) COL 3:
This definition is for input of the column size when doing sonething with the 3D array. 
This can be changed to value of column size you want the array to have. 

1. Function

(1) double*** mem_alloc_3D_double(int page, int row, int col):
This function is for dynamic memory allocation of 3D array, using the triple pointer. 
the page size, row size, and the column size is given as integer input, and the function allocates the memory to page, row and column in sequence. 
When the memory allocation is finished, the function returns the triple pointer pointing to the address of the 3D array created. 

(2) void initialize_3D(double*** A, int page, int row, int col, int num):
This function is for initializing the 3D array allocated by 'mem_alloc_3D_double'.
The function gets the triple pointer of array A, the row, column, page size of the array, and the number that you want the array to be initialized. 
For the input variable num, when num is 1, the array initializes as 'page location+row location+col location' and for other numbers, all the elements in array is initialized as 'num'
There is no return for this function. 

(3) double*** addition_3D(double*** A, double*** B, int page, int row, int col):
The function is for adding the two 3D array A and B given as input. Also, the page size, row size, column size are given as integer input which represents the size of each array. 
This function returns NULL when the sizes of two array gicen are different, and the array of sum when sizes of two array are same. 

(3) void display_3D(double*** A, int page, int row, int col):
This function is for printing out the elements in 3D array in form of pages with ro and column. 
It gets the triple pointer of array A as an input and its page size, row size, and column size as well. 
There is no return for this function.

(4) deallocate_3D(double*** A):
This function is for deallocating memory from the existing 3D array. first it deallocates the column, then row, finally page. 
It gets triple pointer of 3D array A that is going to be deallocated. 
There is no return for this function. 

(5) void main():
When the main() is started, it executes the memory allocation of  3D array A and B, by the defined size. 
Then, it initializes the elements of array A by 1,2,3... and all the elements of array B by 2. 
Nextly, it sums up two array A and B, and saves it to the 3D array SumArray. 
Then it displays the original array of A and B, then the array of sum, SumArray. 
Finally, it deallocates A, B and SumArray using the function 'deallocate_3D'. 

