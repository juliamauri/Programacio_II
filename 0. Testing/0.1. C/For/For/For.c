#include <stdio.h>
#include <stdlib.h>

int main(){

	int i = 5, n = 0;
	
	for (int i = 10, m = 1; i > 0; --i, --n) printf("%i, %i, %i\n", i, n, m);
	
	printf("BOOM!\n");
	

	getchar();
	return 0;
}

// The international Obfuscated C Contest