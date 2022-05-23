//  Implementation of insertion sort in c 

#include<stdio.h>

void displayArray(int[], int); 
void insertionSort(int[], int); 

void displayArray(int array[], int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%d ", array[i]); 
	}
	printf("\n"); 
}

void insertionSort(int array[], int size) {
	
	int i, j, count = 0;

	for(i=1; i<size; i++) {
		int key = array[i];
		j = i-1; 
	
		while(key<array[j] && j>=0) {
			array[j+1] = array[j];
			j--;
			count++;   
		}
		array[j+1] = key; 
	}
	if(count==0)	{
		printf("\n(--------Array already sorted---------)\n"); 
	}
}

int main() {
	int size; 
	printf("Enter Array size: ");
	scanf("%d", &size); 

	int array[size]; 
	printf("Enter %d Array elements: ", size);
	for(int i=0; i<size; i++) {
		scanf("%d", &array[i]); 
	}

	printf("Array before sortion: ");
	displayArray(array, size); 

	printf("Array after sortion: ");
	insertionSort(array, size); 
	displayArray(array, size); 

	return 0;
}

/*
---------------------------------------------------
Analysis of Insertion Sort:

Time complexity: 
	Best case: O(n) 
	Average case: O(n^2) 
	Worst case: O(n^2) 

Space complexity: O(1) 

Stability: yes. 

---------------------------------------------------

*/
