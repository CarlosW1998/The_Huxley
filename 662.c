#include<stdio.h>
#include<stdlib.h>

int main()
{

	int k, n, aux, t;
	int a, b, c, max;
	int alice[100001];
	int beatriz[100001];
	int previous;

	while(scanf("%d%d", &k, &n), k+n)
	{
		max = 0;
		t = 0;
		previous = -1;
		for(a = 0; a <= k; a++) alice[a] = 0;
		for(a = 0; a <= n; a++) beatriz[a] = 0;

		for(a = 0; a < k; a++)
		{
			scanf("%d", &aux);
			alice[aux] = 1;
			if(aux > max) max = aux;
		}
		
		for(a = 0; a < n; a++)
		{
			scanf("%d", &aux);
			if(previous != aux)
			{				
				if(aux > max) max = aux;
				if(alice[aux]) alice[aux] = 0;
				else beatriz[aux] = 1;
			}
			previous = aux;
		}
		a = 1;
		b = 1;
		while(a <= max && b <= max)
		{
			if(alice[a])
			{
				while(!beatriz[b] && b <= max) b++;
				if(b <= max) 
				{
					t++;
					beatriz[b] = 0;
				}

			}
			a++;
		}
		printf("%d\n", t);

	}

	return 0;
}