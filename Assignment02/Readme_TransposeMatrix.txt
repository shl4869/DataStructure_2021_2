Readme_TransposeMatrix.txt

//Program Purpose
This program is written for performing the transpose operation for given matrix.
When the Matrix is assigned to B, it performs transpose operation and prints out B and B^T in dense form of matrix.

0. Define

(1) MAX_TERMS 36:
This definition is for assigning the size of "element data[]".
The value should be 'rows*cols' of matrix B you are going to use, because the matrix can have 'rows*cols' nonzero elements.

(2) SWAP(x,y,t):
This definition is for performing swap operation after transposing the matrix, when the data should be sorted from data that has lowest row number to highest row number. 


1. Structures

(1)element: 
This structure contains the actual element value of the sparse matrix. 
It contains the nonzero element's information of row (int row), column (int col), and value(int value). 

(2)sparseMatrix:
This structure contains array of data as form of element array (element data[MAX_TERMS]), the size of the actual dense matrix, and the number of nonzero elements which the matrix contains.
It contains the row size (int rows), column size (int cols), and the number of nonzero terms (int terms). 


2. Functions

(1) sparseMatrix Sparse_matrix_transpose(sparseMatrix a):
This function was made to perform the transpose operation to given sparseMatrix a for input. 
When the transpose is done, it sorts the transposed matrix by the value of row and col, from low to high. 
If all the operation is done, the function returns the transposed, sorted sparseMatrix b. 

(2) void Show_matrix_dense(sparseMatrix a):
This function was made to display the given input sparseMatrix a in a dense form. 
The input sparseMatrix a SHOULD be in acsending order based on the value of row, then column. 
This function has no return, and just poerates for printing out the matrix. 

(3) void main():
In the main fuction, the original sparseMatrix B is defined. You can change the matrix by {{array of elements}, rowsize, columnsize, number of terms}. 
Then, the BT is assigned and initialized as transpose matrix of B by Sparse_matrix_transpose(B).
The program ends after printing out the original and transposed matrix in a dense form.  




