#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int findMax(int A[], int n) {

	int M = A[0];

	for (int i = 0; i < n; i++) {
		if (M < A[i]) {
			M = A[i];
		}
	}
	return M;
}


int main() {

	int A[50], n;
	scanf_s("%d", &n);
	srand(time(NULL)); // 난수생성

	for (int i = 0; i < n; i++) {
		A[i] = rand() % 100; // rand() -> 임의의 양의 정수
	} 
	
	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
	}
	printf("\n");
	

	printf("Max : %d", findMax(A, n));

}