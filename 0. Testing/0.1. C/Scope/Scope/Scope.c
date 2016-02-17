#include <stdio.h>
#include <stdlib.h>

int main(){

	int a = 5;
	int *p;
	p = &a;
	{
		int a = 10;
		printf("%i\n", (*p)); //Only with Pointers
		printf("%i\n", (a)); //Colision Name.
	}
	printf("%i\n", sizeof(a));

	getchar();
	return 0;
}