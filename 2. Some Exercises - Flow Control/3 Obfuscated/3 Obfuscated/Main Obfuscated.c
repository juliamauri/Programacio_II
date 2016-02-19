#include <stdio.h>
#include <stdlib.h>

int main(){									int num;							char menu = '\0';

	




														printf("Tell me a number: ");
															scanf_s("%i", &num);
																fflush(stdin);

	
																
																
						while (menu != 'd'){															printf("\nWhat do you want to do?\n");
								printf("a. Increment (use ++)\n");							printf("b. Decrement (use --)\n");
												printf("c. Power of two\n");		printf("d. Quit.\n");
																	scanf_s("%c", menu);
																								
	fflush(stdin);																																	switch (menu){
			case 'a':++num;break;case 'b':																										--num;
								break;case 'c':num *= num;break;case 'd':system("pause");return 0;break;}printf("Your actual number is %i.\n", num);}}