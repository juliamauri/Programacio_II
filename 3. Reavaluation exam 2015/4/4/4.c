/* ​Create a function “encode”​that receives a string and returns a new string that is a
copy of the first one but with those characters replaced:a=4, e=3, i=1, o=0
The entered string won’t contain uppercase letters. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char aux[50]);
char encode(char(*​text)[50]);

int main(){


	char phrase[50];
	
	printf("Write the phrase for encoding>(max 49 characters): ");
	fgets(phrase, 50, stdin);
	fflush(stdin);
	change(phrase);

	printf("The value of phrase should be “%s”", encode(phrase));

	system("pause");
	return 0;
}

void change(char aux[50]){
	int i, temp = 0;

	for (i = 0; i < 100 && temp == 0; i++){
		if (aux[i] == '\n'){
			aux[i] = '\0';
			temp = 1;
		}
	}
}

char ​encode(char (*​text)[50]){
	char textencoded;
	textencoded = (char*)malloc((strlen(*​text) + 1)*sizeof(char));
	if (textencoded == NULL){
		printf("Could not allocate memory.\n");
		exit(1);
	}

	for (int i = 0; i <= strlen(*​text); i++){
		switch ((*​text)[i])
		{
		case 'e':
			textencoded[i] = '3';
			break;
		case 'a':
			textencoded[i] = '4';
			break;
		case 'i':
			textencoded[i] = '1';
			break;
		case 'o':
			textencoded[i] = '0';
			break;
		default:
			textencoded[i] = *​text[i];
			break;
		}
	}
	
	return textencoded;
}