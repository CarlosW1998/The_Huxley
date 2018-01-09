#include<stdio.h>
#include<stdlib.h>
void push(char *k, int p)
{
	while(k[p+2] != '\0')
	{ 
		k[p] = k[p+2];
		p++;
	}
	k[p] = '\0';
}
int merge(char *k, int p)
{	

	if(k[p] == 'Z' || k[p] == '\0' || k[p+1] == '\0') return 0;

	if(k[p] == 'B' || k[p] == 'S')
	{
		if(k[p+1] != k[p] && (k[p+1] == 'B' ||  k[p+1] == 'S'))
		{
			push(k, p);
			return 1;
		}
		else if(p > 0 && k[p-1] != k[p] && (k[p-1] == 'B' || k[p-1] == 'S'))
		{
			push(k, p-1);
			return 1;
		}
	}
	else if(k[p] == 'C' || k[p] == 'F')
	{
		if(k[p+1] != k[p] && (k[p+1] == 'C' || k[p+1] == 'F'))
		{
			push(k, p);
			return 1;
		}
		else if(p > 0 && k[p-1] != k[p] && (k[p-1] == 'C' || k[p-1] == 'F'))
		{
			push(k, p-1);
			return 1;
		}
	}
	return 0;
}

int main()
{
	char rnaa[500000];
	int a, b, c;
	int cont, size, ncont;

	scanf("%s", rnaa);
	getchar();

	while(rnaa[0] != 'Z')
	{
		cont = 0;
		for(a = 0; rnaa[a] != '\0'; )
		{
			if(merge(rnaa, a))
			{
				cont++;
				if(a > 0) a--;
			}
			else a++;
			
		}
		printf("%s\n", rnaa);
		printf("%d\n", cont);
		scanf("%s", rnaa);
		getchar();
	}

	return 0;
}