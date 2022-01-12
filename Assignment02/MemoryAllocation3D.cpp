#include <stdio.h>
#include <stdlib.h>

#define PAGE 3
#define ROW 3
#define COL 3


double*** mem_alloc_3D_double(int page, int row, int col){
	int i, j;

	//Allocate the memory of 3D matrix
	double*** A = (double***)malloc(sizeof(double**) * page);
	for ( i = 0; i < page; i++) {
		A[i] = (double**)malloc(sizeof(double*) * row);
		for ( j = 0; j < row; j++) {
			A[i][j] = (double*)malloc(sizeof(double) * col);
		}
	}

	return A;
}

void initialize_3D(double*** A, int page, int row, int col, int num) {
	//If the variable 'num' is 1, initialize the elememt as sum of its location.
	int i, j, k;
	if (num == 1) {
		int count = 0;
		for (i = 0; i < page; i++)
		{
			for (j = 0; j < row; j++)
			{
				for (k = 0; k < col; k++)
				{
					A[i][j][k] = ++count;
				}
			}
		}
	}

	//If the variable 'num' is not 1, initialize all the elements of matrix as num.
	else {
		for (i = 0; i < page; i++)
		{
			for (j = 0; j < row; j++)
			{
				for (k = 0; k < col; k++)
				{
					A[i][j][k] = num;
				}
			}
		}
	}

}

double*** addition_3D(double*** A, double*** B, int page, int row, int col) {
	
	//If the size of two matrices are different, return NULL and halt
	if (sizeof(A) != sizeof(B)) {
		printf("Size Error: cannot add A and B");
		return NULL;
	}

	//Perform the addition of two matrices and save to matrix C
	else {

		int i, j, k;

		double*** C = mem_alloc_3D_double(page, row, col);
		initialize_3D(C, page, row, col, 0);

		for (i = 0; i < page; i++)
		{
			for (j = 0; j < row; j++)
			{
				for (k = 0; k < col; k++)
				{
					C[i][j][k] = A[i][j][k] + B[i][j][k];
				}
			}
		}
		return C;
	}


}


void display_3D(double*** A, int page, int row, int col) {
	//Print out 3D Array
	for (int i = 0; i < page; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				printf("%10f ", A[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
}

void deallocate_3D(double*** A) {
	free(A[0][0]);
	free(A[0]);
	free(A);
}


void main() {

	//Define and initialize two matrices A and B using 'mem_alloc_3D_double'
	double*** A = mem_alloc_3D_double(PAGE, ROW, COL);
	double*** B = mem_alloc_3D_double(PAGE, ROW, COL);
	initialize_3D(A, PAGE, ROW, COL, 1);
	initialize_3D(B, PAGE, ROW, COL, 2);

	//Perform addition of two matrices using 'addition_3D()'
	double*** SumArray = addition_3D(A, B, PAGE, ROW, COL);


	//Print out array A,B and the sum of two array
	printf("Array A:\n");
	display_3D(A, PAGE, ROW, COL);
	printf("\n\nArray B:\n");
	display_3D(B, PAGE, ROW, COL);
	printf("\n\nArray Sum:\n");
	display_3D(SumArray, PAGE, ROW, COL);

	//Deallocate A, B, and SumArray
	deallocate_3D(A);
	deallocate_3D(B);
	deallocate_3D(SumArray);


}