#include<stdio.h>

int main() {

	int N;
	scanf_s("%d", &N);
	int SumEven = 0;
	int SumOdd = 0;

	for (int i = 1; i <= N; i++) {
		if (i % 2 == 0) {
			SumEven += i;
		}
		else {
			SumOdd += i;
		}
	}

	printf("EvenSum : %d, OddSum : %d", SumEven, SumOdd);

}