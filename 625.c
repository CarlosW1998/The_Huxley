#include<stdio.h>
#include<stdlib.h>

void update(int tree[], int i, int f, int ie, int dif, int p)
{
	if(i > ie || f < ie) return;
	tree[p] += dif;

	if(i != f)
	{
		int midle = (i+f)/2;
		update(tree, i, midle, ie, dif, p*2);
		update(tree, midle+1, f, ie, dif, p*2+1);
	}

}
int get_sum(int elemntes[], int i, int f, int ie, int fe, int p)
{
	if(i <= ie && f >= fe) return elemntes[p];
	if(ie > f || fe < i) return 0;
	int midle = (ie+fe)/2;

	return get_sum(elemntes, i, f, ie, midle, p*2) + get_sum(elemntes, i, f, midle+1, fe, p*2+1);
}

int contruct_tree(int elemntes[], int tree[], int i, int f, int p)
{
	if(i == f)
	{
		tree[p] = elemntes[i]%2;
		return tree[p];
	}
	tree[p] = contruct_tree(elemntes, tree, i, (i+f)/2, p*2) + contruct_tree(elemntes, tree, 1+(i+f)/2, f, p*2+1);
	return tree[p];

}

void main()
{
	int size, comands;
	int o, x, y, dif;
	int a, b, c;
	int segment_tree[500000];

	scanf("%d", &size);

	int elemntes[size+1];
	for(a = 1; a <= size; a++) scanf("%d", &elemntes[a]);
	contruct_tree(elemntes, segment_tree, 1, size, 1);
	scanf("%d", &comands);

	for(a = 0; a < comands; a++)
	{
		scanf("%d%d%d", &o, &x, &y);
		if(o == 1) printf("%d\n", y - x + 1 - get_sum(segment_tree, x, y, 1, size, 1));
		else if(o == 2) printf("%d\n", get_sum(segment_tree, x, y, 1, size, 1));
		else
		{
			dif = y%2 - elemntes[x]%2;
			elemntes[x] = y;
			if(dif)update(segment_tree, 1, size, x, dif, 1);
		}
	}
	
}