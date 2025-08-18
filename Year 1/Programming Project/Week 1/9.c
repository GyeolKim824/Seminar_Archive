#include<stdio.h>
#include<stdlib.h>

int main() {

	int A[3][4] = { 0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; i++) {
			A[i][j] = rand()%100;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%2d", A[i][j]);
		}
		printf("\n");
	}

	int rSum, cSum;
	
	for (int i = 0; i < 3; i++) {
		rSum = 0;
		for (int j = 0; j < 4; j++) {
			rSum += A[i][j];
		}
		printf("%dÇàÀÇ ÇÕ : %d", i, rSum);
	}
}