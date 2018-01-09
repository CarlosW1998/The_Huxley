#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>



int main()
{
	int size, erease, atual;
	int a, b, head, max;
	char num[500000], aux;

	while(scanf("%d%d", &size, &erease) && size != 0 && erease != 0)
	{
		max = size-erease;
		getchar();
		for(a = 0, head = 0; a < size; a++)
		{
			scanf("%c", &aux);
			while(head >= 1 && erease &&  num[head-1] < aux)
			{
				head--;
				erease--;
			}
			if(head < max)
			{
				num[head] = aux;
				head++;
			}
		}

		num[head] = '\0';

		printf("%s\n", num);
		
	}

	return 0;
}