#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_DATA 1000
#define MAX_BIT 24
#define RADIX_BIT 6

int radix = int(pow(2, RADIX_BIT));
int digit = MAX_BIT / RADIX_BIT;


int random(int n)
{
	return (rand()*rand()) % n;
}

void CountingSort(int* A, int* B) {
	int result[MAX_DATA+1];
	int* hist = (int*)malloc(sizeof(int) * radix);

	//Initialize Histogram
	for (int i = 0; i < radix; i++)
	{
		hist[i] = 0;
	}

	//Build HIstogram , Result Initialization
	for (int j = 0; j < MAX_DATA; j++) {
		hist[B[j]] += 1;
		result[j] = 0;
	}

	//Cumulative Histogram
	for (int k = 1; k < radix; k++)
		hist[k] = hist[k] + hist[k - 1];

	//Sort Data based of the Histogram
	for (int s = MAX_DATA - 1; s > 0; s--) {
		result[hist[B[s]] -1] = s;
		hist[B[s]] -= 1;
	}

	//Save the data in A to result in sorted order
	for (int t = 0; t < MAX_DATA; t++) {
		result[t] = A[result[t]];
	}

	//Copy the result to A
	for (int t = 0; t < MAX_DATA; t++) {
		A[t] = result[t];
	}
		
}

void RadixSort(int* A, int d) {
	
	//for each digit
	for (int i = 1; i <= d; i++) {
		int B[MAX_DATA], C[MAX_DATA];

		//Get the number in digit and save to B
		for (int j = 0; j < MAX_DATA; j++) {
			C[j] = A[j] / int(pow(radix, i-1));
			B[j] = C[j] % radix;
		}
		
		//Do counting sort based on the i th digit
		CountingSort(A, B);
	}
}

void main() {
	srand((unsigned int)time(NULL));
	int input_data[MAX_DATA];

	printf("Number Generate Range: 0 - %d\nRadix: %d\n\n",int(pow(2, MAX_BIT))-1,radix);

	printf("Original Data:\n");
	for (int i = 0; i < MAX_DATA; i++) {
		input_data[i] = random(int(pow(2, MAX_BIT)));
		printf("%3d  %10d\n", i, input_data[i]);
	}

	RadixSort(input_data, digit);

	printf("Sorted Data:\n");
	for (int i = 0; i < MAX_DATA; i++) {
	
		printf("%3d  %10d\n",i, input_data[i]);
	}
}