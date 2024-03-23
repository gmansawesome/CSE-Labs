
#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. 
	// You will need to create a new matrix to store the product.
	int i = 0;
	int j = 0;
	int k = 0;

	int** temp = (int**)malloc(size*sizeof(int*));

	for (int i = 0; i < size; i++) {
		*(temp+i) = (int*)malloc(size*sizeof(int));
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int sum = 0;
			for (int k = 0; k < size; k++) {
				sum += (*(*(a+i)+k)) * (*(*(b+k)+j));
				printf("%d,%d ", *(*(a+i)+k), *(*(b+k)+j));
			}
			*(*(temp+i)+j) = sum;
			printf("\n");
		}
	}

	return temp;
}

void printArray(int **arr, int n) {
	// (2) Implement your printArray function here
	int i;
	int j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			// printf("%d", *(*(arr+i)+j));
			if (j != n-1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main() {
	int n = 3;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 
	int i = 0;
	int j = 0;

	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));

	for (i = 0; i < n; i++) {
		*(matA+i) = (int*)malloc(n*sizeof(int));
	}

	for (i = 0; i < n; i++) {
		*(matB+i) = (int*)malloc(n*sizeof(int));
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			*(*(matA+i)+j) = 1;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			*(*(matB+i)+j) = 1;
		}
	}

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printf("\n");
	printArray(matB, n);
	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	// (6) Call printArray to print out resulting array here.
	printf("\n");
	printArray(matC, n);

    return 0;
}