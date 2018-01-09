#include<stdio.h>
#include<stdlib.h>

typedef struct  _arvore arvore;
struct _arvore
{
	int i, c, f;
};
void sort(arvore u[], int size)
{
	int a, b;
	int i, c, f;

	for(a = 1; a <= size-1; a++)
	{
		for(b = a; b <= size; b++)
		{
			if(u[a].i > u[b].i)
			{
				i = u[a].i;
				c = u[a].c;
				f = u[a].f;

				u[a].i = u[b].i;
				u[a].c = u[b].c;
				u[a].f = u[b].f;

				u[b].i = i;
				u[b].c = c;
				u[b].f = f;
			}
		}
	}
}
int caule_size(arvore i[], int p)
{
	int a = 1;

	while(i[p].c != 0)
	{
		a++;
		p = i[p].c;
	}
	return a;
}
int max(int a, int b)
{
	if(a > b) return a;
	return b;
}
int find_size(arvore i[], int p)
{
	if(p == 0) return 0;

	int size = caule_size(i, p);
	while(p != 0)
	{
		size = max(size, find_size(i, i[p].f));
		p = i[p].c;
	}
	return size;
}
int min(int a, int b)
{
	if(a > b) return b;
	return a;
}
int main()
{
	int a, b, c;
	int sizec, sized;
	int pc = 1, pd = 1, cc, cd;
	int def_pc, def_pd, buia;

	scanf("%d", &sizec);

	arvore arvore_canhota[sizec+1];

	for(a = 1; a <= sizec; a++)
	{
		scanf("%d%d%d", &arvore_canhota[a].i, &arvore_canhota[a].f, &arvore_canhota[a].c);
	}

	scanf("%d", &sized);
	arvore arvore_destra[sized+1];

	for(a = 1; a <= sized; a++)
	{
		scanf("%d%d%d", &arvore_destra[a].i, &arvore_destra[a].c, &arvore_destra[a].f);
	}
	sort(arvore_canhota, sizec);
	sort(arvore_destra, sized);

	cc = caule_size(arvore_canhota, 1);
	cd = caule_size(arvore_destra, 1);
	def_pc = min(cc, find_size(arvore_destra, 1));
	printf("\n");
	def_pd = min(cd, find_size(arvore_canhota, 1));	

	printf("%d\n", sizec+sized-max(def_pc, def_pd));
	

	return 0;
}
