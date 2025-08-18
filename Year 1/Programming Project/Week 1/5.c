#include<stdio.h>

void sumOfWeight(int g);

int main() {

	int G;
	scanf_s("%d", &G);
	sumOfWeight(G);

}

void sumOfWeight(int g) {

	int count = 0;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				if (2 * i + 3 * j + 5 * k == g) {
					printf("%d %d %d\n", i, j, k);
					count++;
				}
			}
		}
	}
	
	printf("%d\n", count);
}