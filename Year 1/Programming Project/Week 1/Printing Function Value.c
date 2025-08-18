#include<stdio.h>

int main() {

	int x;
	scanf_s("%d", &x);
	int fx = 3 * x * x - 2 * x + 3; // 제곱 같은거 쓰고싶으면 math.h 라이브러리를 추가하면 된단다~~~

	printf("f(%d)=%d", x, fx);
}