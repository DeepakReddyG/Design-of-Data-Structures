// implementation of merge sort in c

#include<stdio.h>

void printArray(int[], int); 
void merge(int[], int, int, int); 
void mergeSort(int[], int , int); 


void printArray(int array[], int size) {
	for(int i=0; i<size; i++) {
		printf("%d ", array[i]); 
	}
	printf("\n"); 
}


void merge(int array[], int low, int mid, int high) {
	
	int n1 = (mid-low)+1;
	int n2 = (high-mid); 
	
	int L[n1], M[n2]; 
	
	for(int i=0; i<n1; i++) 
		L[i] = array[low+i];
	for(int j=0; j<n2; j++) 
		M[j] = array[mid+1+j]; 

	int i, j, k;
	i = 0;
	j = 0;
	k =  low;
	
	while(i<n1 && j<n2) {
		if( L[i] <= M[j]) {
			array[k] = L[i]; 
			i++; 
		}
		else {
			array[k] = M[j];
			j++; 
		}
		k++; 
	}
	
	while(i<n1) {
		array[k] = L[i];
		i++; 
		k++; 
	}
		
	while(j<n2) {
		array[k] = M[j];
		j++; 
		k++; 
	}
}


void mergeSort(int array[], int low, int high) {
	if(low<high) {
		int mid = low + (high-low)/2;
		
		mergeSort(array, low, mid);
		mergeSort(array, mid+1, high);

		merge(array, low, mid, high);  
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
	mergeSort(array, 0, size-1);
	printArray(array, size); 

	return 0;
}
/*
-----------------------------------------
Analysis of merge sort: 
	
	Analysis of time complexity: 
		Best case: O(n*logn)
		Average case: O(n*logn)
		Worst case: O(n*logn) 

	Analysis of space complexity: O(n)

-----------------------------------------
*/
