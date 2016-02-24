/* ​Write a program in C that uses a function “sequence” ​outputs the following
sequence:
5, 15, 30, 50, 75, 105, 140, 180, 225, 275 */

#include <stdio.h>
#include <stdlib.h>

void sequence();

int main(){

	sequence();

	printf("\n");
	system("pause");
	return 0;
}

void sequence(){

	for (int i = 1, result = 0; i < 11; i++){
		
		result += 5 * i;
		
		printf("%i", result);
		
		if (i != 10)
			printf(",");

	}

}