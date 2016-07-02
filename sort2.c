#include "sort2.h"

// https://gist.github.com/snadahalli/7087434

void sort2(int *a, int n) {
	int i, j, temp;

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}