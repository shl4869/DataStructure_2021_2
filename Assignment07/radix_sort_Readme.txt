radix_sort_Readme.txt

//Program Purpose
This program is written for implementing the radix sort using counting sort iteratively.

0. define

(1) MAX_DATA: This definition represents the max number of data to be generated.
(2) MAX_BIT: This definition represents the number of bits used to save a number.
(3) RADIX_BIT: This definition represents the number of bits used for each digit. 

1. global variables

(1) int raidx: The variable is initialized as the 2^(RADIX_BIT) and it stands for the base number of radix sort.
(2) int digit: The variable is initialized as MAX_BIT/RADIX_BIT and it stands for the max number of digits a number can contain. 

2. Functions

(1) int random (int n):
This function returns the randomly selected number from 0 to n.

(2) void CountingSort (int* A, int* B): 
This function is for operating the counting sort on array A based on array B which is the array of number in a particular digit. The function first initializes the histogram and the array of result which will contain index number in sorted order. Then it builds histogram and makes it as cumulative. The function sorts data based on the histogram and saves the index to the result array and . Finally, it copies the data at index in result to the result and recopies it to A.
This function has no return.

(3) void RaidxSort (int* A, int d): 
This function is for executing the Radix Sort to the given data array A with numbers of d digit. For each digit, the function calculates the number at digit and calls 'CountingSort()' to sort the data based on the digit. The function iteratively operates until the last digit. 
This function has no return.

(4) void main():
In main function, the random numbers are assigned to the each index of the array, 'input_data' and the array is printed. Then, it calles the function 'RadixSort()' to sort the generated data. Finally, it prints out the sorted data. 