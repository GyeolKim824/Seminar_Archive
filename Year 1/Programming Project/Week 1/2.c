#include<stdio.h>

int main() {

	int i;
	scanf_s("%d", &i);

	if (i > 100 || i < 0) {
		printf("Wrong Input");
	}
	else
		if (i >= 90 && i < 100) {
			printf("A\n");
		}
		else if (i >= 80) {
			printf("B\n");
		}
		else if (i >= 70) {
			printf("C\n");
		}
		else
			printf("D of F\n");

	

	/* switch (i / 10) {
		case 10: 
		case 9: puts("A\n");
			break;
		case 8: puts("B\n");
			break;
		case 7: puts("C\n");
			break;
		default: puts("D or F\n");
			break;

	}  */

}