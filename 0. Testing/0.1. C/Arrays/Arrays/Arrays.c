#include <stdio.h>
#include <stdlib.h>

int main(){

	int v[3] = { 2, 1, 0 };

	printf("%i\n", v[3]); //Undefined
	printf("%i\n\n", sizeof(v));
	

	system("pause");
	return 0;
}