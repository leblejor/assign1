#include "sort1.h"
#include <stdlib.h>

// https://gist.github.com/mycodeschool/9678029

void sort1(int *A, int n) {
	int mid, i, *L, *R;
	// Bae condition. Array has less than 2 elements, do nothing
	if (n < 2) {
		return;
	}
	// Find middle of array
	mid = n / 2;

	// Left subarray
	L = (int*) malloc(mid * sizeof(int));
	// Right subarray
	R = (int*) malloc((n - mid) * sizeof(int));

	// Create left subarray
	for(i = 0; i < mid; i++) {
		L[i] = A[i];
	}
	// Create right subarray
	for(i = mid; i < n; i++) {
		R[i - mid] = A[i];
	}

	sort1(L, mid); // Sort left
	sort1(R, n - mid); // Sort right
	merge(A, L, mid, R, n - mid); // Merge left and right into sorted array
	free(L);
	free(R);
}

void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
	int i, j, k;
	// Mark index of left subarray
	i = 0;
	// Mark index of right subarray
	j = 0; 
	//  Mark index of merged subarray
	k = 0;

	while (i < leftCount && j < rightCount) {
		if (L[i] < R[j]) {
			A[k++] = L[i++];
		} else {
			A[k++] = R[j++];
		}
	}

	while (i < leftCount) {
		A[k++] = L[i++];
	}

	while (j < rightCount) {
		A[k++] = R[j++];
	}
}