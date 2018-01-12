#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size, A[100001], k;
	int a, b, c, par = 0;
	
	scanf("%d", &size);
	int elements[size+1];

	for(a = 1; a <= 100000; a++) A[a] = 0;

	for(a = 1; a <= size; a++) scanf("%d", &elements[a]);

	k = 0;
	for(a = size-1; a > 0; a--)
	{
		A[elements[a+1]]++;

		if(elements[a] > elements[a+1])
		{
			for(b = elements[a+1]; b < elements[a]; b++)
			{
				k += A[b];
			}
			par += k;
		}
		else if(elements[a] < elements[a+1])
		{
			for(b = elements[a+1]-1; b > elements[a]; b--)
			{
				k -= A[b];
			}
			par += k;
		}
		else if(elements[a] == elements[a+1]) par *= 2;
	}
	printf("%d\n", par);

	return 0;
}