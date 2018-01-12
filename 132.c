#include<stdio.h>
#include<stdlib.h>

char matriz[999][999];

typedef struct _robot robot;
struct _robot
{
	int x, y;
	int points;
	int direction;
};
void find(robot *nyan, int h, int l)
{
	int a, b;
	for(a = 1; a <= h; a++)
	{
		for(b = 0; b <= l; b++)
		{
			if(matriz[a][b] == 'N' || matriz[a][b] == 'S' || matriz[a][b] == 'L' || matriz[a][b] == 'O')
			{
				if(matriz[a][b] == 'N') nyan->direction = 1;
				else if(matriz[a][b] == 'L') nyan->direction = 2;
				else if(matriz[a][b] == 'S') nyan->direction = 3;
				else nyan->direction = 4;
				matriz[a][b] = '.';
				nyan->x = b;
				nyan->y = a;
				return;
			}
		}
	}
}
void spin(robot *nyan, char direction)
{
	if(direction == 'E') nyan->direction--;
	else if(direction == 'D') nyan->direction++;
	if(nyan->direction > 4) nyan->direction -= 4;
	if(nyan->direction < 1) nyan->direction += 4;
	return;
}
void move(robot *nyan)
{
	if(nyan->direction == 1 && matriz[nyan->y-1][nyan->x] != '#') nyan->y--;
	else if(nyan->direction == 2 && matriz[nyan->y][nyan->x+1] != '#') nyan->x++;
	else if(nyan->direction == 3 && matriz[nyan->y+1][nyan->x] != '#') nyan->y++;
	else if(nyan->direction == 4 && matriz[nyan->y][nyan->x-1] != '#' && nyan->x-1 >= 0) nyan->x--;
	if(matriz[nyan->y][nyan->x] == '*')
	{
		nyan->points++;
		matriz[nyan->y][nyan->x] = '.';
	}
}

int main()
{
	int a, b, c;
	int h, l, moves;
	char aux[50000];
	robot *nyan = (robot*)malloc(sizeof(robot));

	while(scanf("%d%d%d", &h, &l, &moves), l+h+moves)
	{
		nyan->points = 0;
		getchar();	
		for(a = 0; a <= h+1; a++)
		{
			for(b = 0; b <= l+1; b++) matriz[a][b] = '#';
		}
		for(a = 1; a <= h; a++)
		{
			scanf("%s", matriz[a]);
			matriz[a][l] = '#';
		}
		find(nyan, h, l);
		scanf("%s", aux);
		for(a = 0; a < moves; a++)
		{
			if(aux[a] == 'D' || aux[a] == 'E') spin(nyan, aux[a]);
			else if(aux[a] == 'F') move(nyan);

		}
		printf("%d\n", nyan->points);

	}

	return 0;
}