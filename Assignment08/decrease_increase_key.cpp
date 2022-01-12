#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define HEAPSIZE 10

void print_heap(int* A) {
	int a = 2;
	for (int i = 1; i <= HEAPSIZE; i++) {
		printf("%3d", A[i]);
		if (i == a - 1) {
			printf("\n");
			a *= 2;
		}
	}
}

//decrease the element i¡¯s value to ¡®key¡¯
void Decrease_key_min_heap(int* A, int i, int key)
{
	if (key >= A[i]) {
		fprintf(stderr, "new key is not smaller than current key");
	}
	int tmp;
	A[i] = key;
	while (0 < i / 2 && A[i] < A[i / 2])
	{
		SWAP(A[i], A[i / 2], tmp);
		i /= 2;
	}

}

//Increase the element i¡¯s value to ¡®key¡¯
void Increase_key_min_heap(int* A, int i, int key)
{
	if (key <= A[i]) {
		fprintf(stderr, "new key is not larger than current key");
	}
	int tmp;
	A[i] = key;
	while (i * 2 <= HEAPSIZE && (A[i] > A[i * 2] || A[i] > A[i * 2 + 1])) {

		if (A[i] > A[i * 2]) {
			//printf("swap [%d]:%d with [%d]:%d\n", i, A[i], i * 2, A[i * 2]);
			SWAP(A[i], A[i * 2], tmp);
			Increase_key_min_heap(A, i, A[i]--);
			i *= 2;
		}

		else if (i * 2 + 1 <= HEAPSIZE && A[i] > A[i * 2 + 1]) {
			//printf("swap [%d]:%d with [%d]:%d\n", i, A[i], i * 2+1, A[i * 2+1]);
			SWAP(A[i], A[i * 2 + 1], tmp);
			Increase_key_min_heap(A, i, A[i]--);
			i = i * 2 +1;
		}

		else
			break;
	}
}


void main() {
	//heap starts at heap[1]
	int heap_increase[HEAPSIZE+1] = { -1,1,4,2,7,5,3,3,7,8,9 };
	int heap_decrease[HEAPSIZE + 1] = { -1,1,4,2,7,5,3,3,7,8,9 };

	printf("Original Heap:\n");
	print_heap(heap_increase);
	
	Decrease_key_min_heap(heap_decrease, 4, 3);
	printf("\n\nDecrease Key:\n");
	print_heap(heap_decrease);

	Increase_key_min_heap(heap_increase, 3, 10);
	printf("\n\nIncrease Key:\n");
	print_heap(heap_increase);
}