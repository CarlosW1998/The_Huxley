#include <stdio.h>
#include<stdlib.h>
int maximo;
int banda[999][999];
int bla[3];

void best(int k, int size, int *i, int *visited, int z)
{
	if(k == 3)
	{
		int sum = banda[i[0]][i[1]] + banda[i[0]][i[2]] + banda[i[1]][i[2]];
		if(sum > maximo)
		{
			bla[0] = i[0];
			bla[1] = i[1];
			bla[2] = i[2];
			maximo = sum;
			return;
		}
		return;
	}
	int a;
	for(a = 1; a <= size; a++)
	{
		if(!visited[a]) 
		{
			i[k] = a;
			visited[a] = 1;
			best(k+1, size, i, visited, a);
			visited[a] = 0;
			i[k] = 0;
		}
	}
}

int main()
{
	int musicos, edges;
	int a, b, c;
	int acutal[3];
	int visited[200];

	while(scanf("%d%d", &musicos, &edges), musicos+edges)
	{
		maximo = -1;
		acutal[0] = 0;
		acutal[1] = 0;
		acutal[2] = 0;

		for(a = 1; a <= musicos; a++)
		{
			visited[a] = 0;
			for(b = 1; b <= musicos; b++)banda[a][b] = 0;
		}
		while(edges)
		{
			scanf("%d%d%d", &a, &b, &c);
			banda[a][b] = c;
			banda[b][a] = c;
			edges--;
		}
		 for(a = 1; a <= musicos; a++)
		{
			acutal[0] = a;
			visited[a] = 1;
		 	 best(1, musicos, acutal, visited, a);
		 	 visited[a] = 0;
		 	 acutal[0] = 0;
		}

		printf("%d %d %d\n", bla[0], bla[1], bla[2]);
	}

	return 0;
}