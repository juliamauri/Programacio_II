#include <stdio.h>
#include <stdlib.h>

int main(){

	int b;

	scanf_s("%i", &b);

	switch (b)
	{
	case 1:
		int a;
		a = 5;
		break;
	case 2:
		printf("%i", a);
		break;
	default:
		break;
	}
	

	return 0;
}