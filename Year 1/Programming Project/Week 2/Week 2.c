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
	printf("In Main : a = %d, b = %d\n", a, b); // 값 직접 전달시 함수를 지났음에도 메인함수 내에는 영향이 없음

	swap2(&a, &b); // 주소는 무조건 4바이트임
	printf("In Main : a = %d, b = %d\n", a, b); // 함수에게 메인함수 내 변수의 주소를 전달했으므로 메인함수 내의 변수도 변화시킬 수 있음

} */ // 11-12번 내용

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


