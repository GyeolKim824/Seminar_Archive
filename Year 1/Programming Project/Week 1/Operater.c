#include<stdio.h>

int main() {

	int n;
	printf("���ڸ��� ���� �Է� : ");
	scanf_s("%d", &n);

	int i;

	while (n!= 0) {
		
		i = n % 10;
		n = n / 10;
		printf("%d\n", i);

	}

}