#include<stdio.h>

int main() {

	float a, b, c;
	scanf_s("%f, %f, %f", &a, &b, &c);

	float sum = a + b + c;
	float avg = sum / 3.0;

	printf("sum=%f, avg=%f", sum, avg);
}