#include "My_String.h"


int main(){


	My_String hello("hi");

	My_String bye(hello);

	int i = bye.lenght();

	My_String k("");

	if (hello == bye)
		printf("Hi");

	return 0;
}