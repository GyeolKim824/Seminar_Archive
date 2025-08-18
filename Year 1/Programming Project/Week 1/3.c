#include<stdio.h>

int main() {
	
	int a;
	scanf_s("%d", &a);
	int b=1;

	while (a != 0) {

		b = a % 10;
		printf("%d\n", b);
		a = a / 10;
	}

}