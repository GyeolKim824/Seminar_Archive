#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

	int A[7] = { 0 };

	for (int i = 1; i <= 10000; i++) {
		A[rand() % 6 + 1]++;
	}
	for (int i = 1; i <= 6; i++) {
		printf("%d %d\n", i, A[i]);
	}

}