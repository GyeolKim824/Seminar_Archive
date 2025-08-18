#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 2주차 과제 4번 풀이
/*
int rMax(int A[], int idx) {
	if (idx == 0) {
		return A[0];
	}
	int max = rMax(A, idx - 1); // 문제 쌓는중~ idx가 0이 되어서 A[0](base case)가 나올 때까지
	if (max > A[idx]) {
		return max;
	}
	else {
		return A[idx];
	}
}


int main() {

	int n, A[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	printf("%d\n", rMax(A, n-1));
}
*/

// 동적배열할당 malloc

/*
int main() {
	int n, * arr;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	
	srand(time(NULL));
	
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", *(arr + i));
	}
	
	free(arr);

}
*/

// 다항식 표현1
/* #define N 20

typedef struct Poly {
	int degree;
	int coef[N];
}Poly;

void print(Poly p) {

	int i, j;
		for (i = 0, j = p.degree; i <= p.degree; i++, j--) {
			printf("%2dx^%d +", p.coef[i], j);
	}
		printf("\b\b  \n");
}

Poly add(Poly A, Poly B) {

	Poly C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degA = A.degree;
	int degB = B.degree;
	C.degree = (degA >= degB) ? degA : degB;

	while (Apos <= A.degree && Bpos <= B.degree) { 
		if (degA > degB) {
			C.coef[Cpos] = A.coef[Apos];
			Apos++;
			Cpos++;
			degA--;
		}
		else if (degA == degB) {
			C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
			Apos++; Bpos++; Cpos++;
			degA--; degB--;
		}
		else {
			C.coef[Cpos] = B.coef[Bpos];
			Bpos++;
			Cpos++;
			degB--;
		}
	}
	return C;
}

int main() {

	Poly a, b, c; // a,b는 다항식, c는 합 저장
	scanf("%d %d", &a.degree, &b.degree);
	
	for (int i = 0; i <= a.degree; i++) {
		scanf("%d", &a.coef[i]); // 계수입력받기
	}
	for (int i = 0; i <= b.degree; i++) {
		scanf("%d", &b.coef[i]); // 계수입력받기
	}

	printf("--------------------------\n");
	print(a);
	print(b);
	printf("--------------------------\n");

	c=add(a, b);
	print(c);
}
*/

/*
// 다항식 표현 2
#define N 20

typedef struct Poly {
	int coef;
	int expon;
}Poly;

Poly terms[N] = { {8, 3},{7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0} };
int avail = 6;

void print(int s, int e) {

	for (int i = s; i <= e; i++) {
		printf("%2dx^%d +", terms[i].coef, terms[i].expon);
	}
	printf("\b\b  \n");
}

char compare(int exponA, int exponB) {
	if (exponA > exponB) {
		return '>';
	}
	else if (exponA == exponB) {
		return '=';
	}
	else {
		return '<';
	}
}

void attach(int coef, int expon) {
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}


void add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	*Cs = avail;
	int temp;

	while (As <= Ae && Bs <= Be) {
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>':
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;

		case'=':
			temp = terms[As].coef + terms[Bs].coef;
			if (temp != 0) {
				attach(temp, terms[As].expon);
			}
			As++, Bs++;
			break;

		case'<':
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		}
	}
	for (; As <= Ae; As++) {
		attach(terms[As].coef, terms[As].expon);
	}
	for (; Bs <= Be; Bs++) {
		attach(terms[Bs].coef, terms[Bs].expon);
	}
	*Ce = avail - 1;
}

int main() {

	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	
	printf("---------------------------------\n");
	print(As, Ae);
	print(Bs, Be);
	printf("---------------------------------\n");
	
	add(As, Ae, Bs, Be, &Cs, &Ce);
	print(Cs, Ce);
}
*/

// 2차원배열(행렬) 사용
#define N 3

void makeMatrix(int A[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (rand() % 2 == 0) { // rand()%2는 50%의 확률을 뜻하게 됨
				A[i][j] = rand() % 10;
			}
			else {
				A[i][j] = -(rand() % 10);
			}
			// -> 반반의 확률로 음수양수 저장한다~
		}
	}
}

void printMatrix(int A[N][N]) {
	for (int i = 0; i < N; i++) {
		printf(" |");
		for (int j = 0; j < N; j++) {
			printf("%3d", A[i][j]);
		}
		printf("|\n");
	}
}

void transposeMatrix(int B[N][N]) {
	for (int i = 0; i < N; i++) {
		printf(" |");
		for (int j = 0; j < N; j++) {
			printf("%3d", B[j][i]);
		}
		printf("|\n");
	}
}

void mulMatrix(int A[N][N], int B[N][N], int C[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = 0; // 합이 누적되니까 0으로 초기화
			for (int k = 0; k < N; k++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
}

int main() {
	int A[N][N], B[N][N], C[N][N];
	srand(time(NULL));

	makeMatrix(A);
	makeMatrix(B);

	printMatrix(A);
	printf("\n");
	printMatrix(B);
	printf("\n");

	transposeMatrix(B);
	
	mulMatrix(A, B, C);
	printf("\n");
	printMatrix(C);
}
