#include<stdio.h>
#include<stdlib.h>

int ladrilho[999][999];
int total = 999999;

void maximo(int atual, int x, int y)
{
	if(ladrilho[x][y] == -1 || ladrilho[x][y] != atual) return ;
	ladrilho[x][y] = -1;
	total++;
	maximo(atual, x+1, y);
	maximo(atual, x-1, y);
	maximo(atual, x, y+1);
	maximo(atual, x, y-1);
}

int main()
{
	int l, c, def;
	int a, b;

	scanf("%d%d", &l, &c);

	for(a = 0; a < 999; a++)
	{
		for(b = 0; b < 999; b++) ladrilho[a][b] = -1;
	}

	for(a = 1; a <= l; a++)
	{
		for(b = 1; b <= c; b++) scanf("%d", &ladrilho[a][b]);
	}
	def =total;
	
	for(a = 1; a <= l; a++)
	{
		for(b = 1; b <= c; b++) 
		{
			total =  0;
			if(ladrilho[a][b] != -1)
			{

			 	maximo(ladrilho[a][b], a, b);
			 	if(total < def) def = total;
			}
		}
	}
	printf("%d\n", def);


	return 0;
}