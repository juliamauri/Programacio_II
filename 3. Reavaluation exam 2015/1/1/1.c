/* Write a program that request a number between 1 to 6, representing a side of a
dice. The program must show the opposite side number. The opposite sides of a dice are 1-6​, 2-5​and
3-4​ */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	
	printf("Please enter a dice side: ");
	scanf_s("%i", &num);

	switch (num)
	{
	case 1:
		printf("In the opposite side there is a six.\n");
		break;

	case 2:
		printf("In the opposite side there is a five.\n");
		break;

	case 3:
		printf("In the opposite side there is a four.\n");
		break;

	case 4:
		printf("In the opposite side there is a three.\n");
		break;

	case 5:
		printf("In the opposite side there is a two.\n");
		break;

	case 6:
		printf("In the opposite side there is a one.\n");
		break;

	default:
		printf("ERROR: Incorrect input.\n");
		break;
	}
	
	printf("\n");
	system("pause");
	return 0;
}