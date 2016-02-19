#include <stdio.h> 
#include <stdlib.h>
int main(){ int num1 = 0, num2 = 0, count = 0, result = 0;printf("Tell me two numbers to multiply:\n");printf("First number:");scanf_s("%i", &num1);printf("Second number:");scanf_s("%i", &num2);while (count != num2){ result += num1; count++; }printf("The result is %i.\n", result); system("pause");return 0;
}