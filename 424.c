#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a, b, c;
	int jogadores, jogos;
	int j = 0, k, p;

	scanf("%d%d", &jogadores, &jogos);

	for(a = 0; a < jogadores; a++)
	{
		p = 1;
		for(b = 0; b < jogos; b++)
		{
			scanf("%d", &k);
			if(k == 0) p = 0;
		}
		if(p) j++;
	}
	printf("%d\n", j);

	return 0;
}