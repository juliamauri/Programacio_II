#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned short x;
	unsigned short y;
	char player;
}Player;

Player hero;

void position(char *, char *, char *(map)[5]);
void yourplace(char *, char *, char *(map)[5]);

int main(){


	char map[5][5] = {
		{ '\0', '\0', '\0', '\0', '\0' },
		{ '\0', 'a', 'k', '\0', '\0' },
		{ '\0', '\0', 'd', 'b', '\0' },
		{ '\0', '\0', 'e', '\0', '\0' },
		{ '\0', '\0', '\0', '\0', '\0' },
	};

	char temp, pos = 'n';

	hero.player = 'p';
	hero.x = 2;
	hero.y = 2;

	temp = map[hero.y][hero.x];
	map[hero.y][hero.x] = hero.player;


	while (pos != 'q'){

		position(&temp, &pos, map);
		yourplace(&temp, &pos, map);

	}

	printf("\n");
	system("pause");
	return 0;


}

void position(char *temp, char *pos, char(*map)[5]){

	printf("Which direction you want to go (n/s/e/w/q)? ");
	scanf_s("%c", pos);
	fflush(stdin);
	

	*(map[hero.y] + hero.x) = *temp;

	switch (*pos) {
	case 'n':
		--hero.y;
		*temp = *(map[hero.y] + hero.x);
		*(map[hero.y] + hero.x) = hero.player;
		break;
	case 's':
		++hero.y;
		*temp = *(map[hero.y] + hero.x);
		*(map[hero.y] + hero.x) = hero.player;
		break;
	case 'e':
		++hero.x;
		*temp = *(map[hero.y] + hero.x);
		*(map[hero.y] + hero.x) = hero.player;
		break;
	case 'w':
		--hero.x;
		*temp = *(map[hero.y] + hero.x);
		*(map[hero.y] + hero.x) = hero.player;
		break;
	case 'q':
		printf("\n");
		break;
	default:
		printf("Are you kidding me?\n");
		break;
	}

}

void yourplace(char *temp, char *pos, char(*map)[5]){

	switch (*temp) {
	case 'k':
		printf("Now you're at kitchen. North of dinning room.");
		break;
	case 'e':
		printf("Now you're at bedroom. South of dinning room.");
		break;
	case 'd':
		printf("Now you're at dinning room. In the Center of the map.");
		break;
	case 'a':
		printf("Now you're at pantry. East of kitchen.");
		break;
	case 'b':
		printf("Now you're at bathroom. East of dinning room.");
		break;
	case '\0':
		printf("Are you kidding me?");

		switch (*pos) {
		case 'n':
			*(map[hero.y] + hero.x) = *temp;
			++hero.y;
			*temp = *(map[hero.y] + hero.x);
			*(map[hero.y] + hero.x) = hero.player;
			break;
		case 's':
			*(map[hero.y] + hero.x) = *temp;
			--hero.y;
			*temp = *(map[hero.y] + hero.x);
			*(map[hero.y] + hero.x) = hero.player;
			break;
		case 'e':
			*(map[hero.y] + hero.x) = *temp;
			--hero.x;
			*temp = *(map[hero.y] + hero.x);
			*(map[hero.y] + hero.x) = hero.player;
			break;
		case 'w':
			*(map[hero.y] + hero.x) = *temp;
			++hero.x;
			*temp = *(map[hero.y] + hero.x);
			*(map[hero.y] + hero.x) = hero.player;
			break;
		}
		break;
	}
	printf("\n\n");
}