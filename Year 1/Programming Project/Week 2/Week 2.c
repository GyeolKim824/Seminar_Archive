#include<stdio.h>
#include<stdlib.h>

/*void swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	printf("In swap1 : a = %d, b = %d\n", a, b);
}

void swap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("In swap2 : a = %d, b = %d\n", *a, *b);
}

   int main() {

	int a = 10;
	int b = 20;

	printf("In Main : a = %d, b = %d\n", a, b);

	swap1(a, b);
	printf("In Main : a = %d, b = %d\n", a, b); // �� ���� ���޽� �Լ��� ���������� �����Լ� ������ ������ ����

	swap2(&a, &b); // �ּҴ� ������ 4����Ʈ��
	printf("In Main : a = %d, b = %d\n", a, b); // �Լ����� �����Լ� �� ������ �ּҸ� ���������Ƿ� �����Լ� ���� ������ ��ȭ��ų �� ����

} */ // 11-12�� ����

typedef struct student {
	int num;
	char name[20];
	int year;
}Student;

void up1(Student* S) {
	S->year++;
	printf("%d : %s(%d)\n", S->num, S->name, S->year);
}
void up2(Student S) {
	S.year++;
	printf("%d : %s(%d)\n", S.num, S.name, S.year);
}

int main() {

	Student s1;

	scanf_s("%d %s %d", &s1.num, s1.name, &s1.year);
	printf("%d : %s(%d)\n", s1.num, s1.name, s1.year);

	up1(&s1);
	printf("%d : %s(%d)\n", s1.num, s1.name, s1.year);

	up2(s1);
	printf("%d : %s(%d)\n", s1.num, s1.name, s1.year);

}


