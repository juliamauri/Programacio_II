#include <stdio.h>
#include <stdlib.h>
int main(){int result = 0; 
printf("Tell me 10 numbers, then I tell you which number is the smallest:\n");for (int i = 0, num=0; i < 10; i++){
printf("Tell me de %i number: ", i + 1);scanf_s("%i", &num);
if (i == 0){result = num;}else if (result > num){result = num;}}
printf("The smallest number is: %i\n", result);system("pause");return 0;
}