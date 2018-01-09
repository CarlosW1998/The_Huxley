#include <stdio.h>
#include <stdlib.h>

int get_next(int size, int p, int higt[])
{
	p++;
	return higt[p%size];
}
int get_previous(int size, int p, int higt[])
{
	p--;
	if(p < 0) p += size;
	return higt[p];
}

int main()
{
	int size;
	int a, points;
	int next, previous;
	int higt[100000];

	while(scanf("%d", &size), size)
	{
		points = 0;
		for(a = 0; a < size; a++) scanf("%d", &higt[a]);
		for(a = 0; a < size; a++)
		{
			next = get_next(size, a, higt);
			previous = get_previous(size, a, higt);
			if((higt[a] > next && higt[a] > previous)  || (higt[a] < next && higt[a] < previous)) points++;
		}
		printf("%d\n", points);
	}
	return 0;
}