#include<stdio.h>

int main() {

	int K, N, M;

	scanf_s("%d %d %d", &K, &N, &M);

	if (K*N > M) {
		printf("%d", K*N - M);
	}
	else {
		printf("0");
	}

}