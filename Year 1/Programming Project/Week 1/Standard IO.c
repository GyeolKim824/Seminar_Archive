#include<stdio.h>

int main() {

	int i;
	float f;
	double d;

	// scanf_s("%d", &i);
	// printf("%d", i);

	// scanf_s("%f", &f);
	// printf("%f", f);

	// scanf_s("%lf", &d);
	// printf("%lf", d);

	scanf_s("%d %f %lf", &i, &f, &d);
	printf("i=%d, f= %f, d= %f", i, f, d); // <-- 간단하고 예쁨

}