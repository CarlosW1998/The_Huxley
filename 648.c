#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	if(a < b) return a;
	return b;
}

int main()
{
	int box, stack, cust_esq = 0, cust_dir = 0;
	int a, b, c, aux;
	int p_stack, p_higt;	

	

	while(scanf("%d%d", &box, &stack))
	{
		if(!(box+stack)) break;

		int higt[stack];

		for(a = 0; a < stack; a++)
		{
			scanf("%d", &higt[a]);
			for(b = 0; b < higt[a]; b++)
			{
				scanf("%d", &aux);
				if(aux == 1)
				{
					p_stack = a;
					p_higt = b+1;

				}
			}
		}
		a = p_stack;
		cust_esq = 0;
		while(a >= 0)
		{
			if(p_higt > higt[a]) break;
			cust_esq += higt[a]-p_higt+1;
			a--;
		}
		a = p_stack;
		cust_dir = 0;
		while(a < stack)
		{
			if(p_higt > higt[a]) break;			
			cust_dir += higt[a]-p_higt+1;
			a++;
		}
		printf("%d\n", max(cust_dir, cust_esq)-1);
	}	


	return 0;
}