#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int m, nm, d, nd;
	int a, j, z;

	scanf("%d%d%d%d", &d, &nd, &m, &nm);
	if(m < 100000000) z = m/2;
	else z = sqrt(m)

	for(a = 1; a*d <= z;  a++)
	{
		j = a*d;
		if(j%nd != 0 && m%j == 0 && nm%j != 0) 
		{
			printf("%d\n", j);
			return 0;
		}
	}
	printf("-1\n");

	return 0;
}