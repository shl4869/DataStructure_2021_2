#include <stdio.h>

#define MAX_TERMS 36;
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct {
	element data[MAX_TERMS];
	int rows;	//row size
	int cols;	//column size
	int terms;	//the #of elements
} sparseMatrix;

sparseMatrix Sparse_matrix_transpose(sparseMatrix a) {
	//Define Matrix b with size transposed from a
	sparseMatrix b;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	//Perform the transpose operation 
	for (int i = 0; i < a.terms; i++) {
		b.data[i].row = a.data[i].col;
		b.data[i].col = a.data[i].row;
		b.data[i].value = a.data[i].value;
	}

	//sort the array b.data by b.data[i].row and b.data[i].col
	element tmp;
	for (int i = b.terms - 1; i > 0;i--) {
		for (int j = 0; j < i; j++) {
			if (b.data[j].row > b.data[j + 1].row)
				SWAP(b.data[j], b.data[j + 1], tmp);

			else if (b.data[j].row == b.data[j + 1].row && b.data[j].col > b.data[j + 1].col)
				SWAP(b.data[j], b.data[j + 1], tmp);
		}
		
	}

	return b;
}

void Show_matrix_dense(sparseMatrix a) {
	int cnt = 0;
	for (int i = 0; i < a.rows; i++) {
		for (int j = 0; j < a.cols; j++) {
			if (a.data[cnt].row == i && a.data[cnt].col == j)
				printf("%d ", a.data[cnt++].value);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

void main() {
	//Add B as an input. 
	sparseMatrix B = { {{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7 };
	

	//Perform the transpose operation
	sparseMatrix BT = Sparse_matrix_transpose(B);


	//Print out B and B^T in a dense matrix form
	printf("Original Matrix B\n");
	Show_matrix_dense(B);
	printf("\nTransposed Matrix B^T\n");
	Show_matrix_dense(BT);

}