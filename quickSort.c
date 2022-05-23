// implementation of quick sort in c 

#include<stdio.h>


void swap(int *, int *);
void printArray(int[], int); 
void partition(int [], int, int); 
void quickSort(int[], int, int); 

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp; 
}

void printArray(int array[],int size) {
	for(int i=0; i<size; i++) {
		printf("%d ", array[i]); 
	}
	printf("\n"); 
}

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = low-1;
	
	for(int j=low; j<high; j++) {
		if(array[j]<=pivot) {
			i++;
			swap(&array[i], &array[j]); 
		}
	}
	swap(&array[i+1], &array[high]); 
	
	return (i+1); 
}

void quickSort(int array[], int low, int high) {
	if(low<high) {
		int p = partition(array, low, high);

		quickSort(array, low, p-1);
		quickSort(array, pi+1, high); 
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
	quickSort(array, 0, size-1); 
	printArray(array, size); 

	return 0;
}


/*
------------------------------------
Analysis of quick sort: 

analysis of time complexity: 
	Best case: O(n*logn) 
	Average case: O(n*logn)
	Worst case: O(n^2)

space complexity:  O(log n) 

stability: NO 

-------------------------------------
*/
