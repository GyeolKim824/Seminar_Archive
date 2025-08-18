#include<stdio.h>

int main() {

	int A[3][4] = {{0,1,2,3}, {10,11,12,13}, {20,21,22,23}};

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 4; j++) {
			printf("%2d", A[i][j]);
		}
		printf("\n");
	}

}