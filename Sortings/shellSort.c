// implementation of 'shell sort' in c 

#include<stdio.h>

void printArray(int [], int);
void shellSort(int[], int); 

void printArray(int array[], int size) {
	for(int i=0; i<size; i++) {
		printf("%d ", array[i]); 
	}
	printf("\n"); 
}

void shellSort(int array[], int size) {
	for(int i=size/2; i>0; i/=2) {
		for(int j=i; j<size; i+=1) {
			int temp = array[j];
			int k;
		
			for(k=j; k>=i && array[k-i] > temp; k-=i) {
				array[k] = array[k-i];
			}	
			array[k] = temp; 
		}
	}
}


int main() {
	int size;
	printf("Enter size: ");
	scanf("%d", &size);
	
	int array[size];
	printf("Enter array elements: ");
	for(int i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}
	
	printf("Array before sortion: ");
	printArray(array, size);
	
	printf("Array after sortion: ");
	shellSort(array, size);
	printArray(array, size); 

	return 0;
}

/*
--------------------------------------
Analysis of shell sort algo: 
	Analysis of time complexity: 
		Best case: O(n*logn)
		Average case: O(n*logn)
		Worst case: O(n^2); 
	
	Analysis of space complexity: O(1) 
	
	Stability: No

---------------------------------------
*/
