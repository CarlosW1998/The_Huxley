#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size, A[100001];
	int a, b, c, par = 0;
	
	scanf("%d", &size);
	int elements[size+1];

	for(a = 1; a <= 100000; a++) A[a] = 0;

	for(a = 1; a <= size; a++) scanf("%d", &elements[a]);

	for(a = size; a > 0; a--)
	{
		for(b = 0; b < elements[a]; b++) par += A[b];
		A[elements[a]]++;
	}
	printf("%d\n", par);

	return 0;
}