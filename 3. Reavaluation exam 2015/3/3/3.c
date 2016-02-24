/* ​Create a function “reach​” that given a 8x8 matrix​, x​and y​coordinates and a blast
radius​returns the amount of points gathered by the user.
Function header should be: int reach(int matrix[8][8], int x, int y, int radius) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int reach(int matrix[8][8], int x, int y, int radius);

int main(){

	int matrix[8][8], x, y, radius;

	srand(time(NULL));

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			matrix[i][j] = rand() % 3;
		}
	}

	do{
		printf("Enter row: ");
		scanf_s("%i", &x);
		printf("Enter column: ");
		scanf_s("%i", &y);
		printf("Enter radius: ");
		scanf_s("%i", &radius);
	} while (x <= 0 && x >= 8 && y <= 0 && y >= 8 && radius > 0);


	printf("The total amount of points gathered is %i.\n\n", reach(matrix, x, y, radius));

	system("pause");
	return 0;
}

int reach(int matrix[8][8], int x, int y, int radius){

	int score = 0;

	int right = (x + radius)>7 ? 7 : x + radius;

	int bottom = (y + radius)>7 ? 7 : y + radius;

	for (int left = (x - radius) < 0 ? 0 : x - radius; left <= right; left++)
	{
		for (int top = (y - radius)<0 ? 0 : y - radius; top <= bottom; top++)
		{
			int value = matrix[left][top];
			score += (value == 2) ? 5 : value;
		}
	}

	return score;
}