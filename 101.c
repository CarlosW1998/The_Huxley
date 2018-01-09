#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size, a, k;
	int matriz[3][3];
	matriz[0][2] = 1;
	matriz[1][2] = 1;
	matriz[2][2] = 1;
	while(scanf("%d", &size), size)
	{
		k = 1;
		scanf("%d%d", &matriz[0][0], &matriz[0][1]);
		scanf("%d%d", &matriz[1][0], &matriz[1][1]);
		for(a = 0; a < size-2; a++)
		{
			scanf("%d%d", &matriz[2][0], &matriz[2][1]);
			if((matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1] - matriz[2][0]*matriz[1][1]*matriz[0][2] - matriz[2][1]*matriz[1][2]*matriz[0][0] - matriz[2][2]*matriz[1][0]*matriz[0][1]))
			{
				k = 0;
			}
		}
		if(k) printf("ALINHADOS\n");
		else printf("NAO_ALINHADOS\n");

	}

	return 0;
}