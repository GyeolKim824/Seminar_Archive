#include<stdio.h>

int main() {

	int x;
	scanf_s("%d", &x);
	int fx = 3 * x * x - 2 * x + 3; // ���� ������ ��������� math.h ���̺귯���� �߰��ϸ� �ȴܴ�~~~

	printf("f(%d)=%d", x, fx);
}