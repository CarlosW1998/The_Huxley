#include<stdio.h>
#include<stdlib.h>

void read(int elements[], int size)
{
	int a, b, c;
	char aux[50];
	for(a = 1; a <= size; a++)
	{
		scanf("%s", aux);
		for(b = 0; aux[b] != '\0'; b++);
		if(aux[0] == aux[b-1] || b == 1) elements[a] = 1;
		else elements[a] = 0;

	}
}

int contruct_tree(int tree[], int elements[], int i, int f, int p)
{
	if(i == f)
	{
		tree[p] = elements[i];
		return tree[p];
	}
	int midle = (i+f)/2;
	tree[p] = contruct_tree(tree, elements, i, midle, p*2) + contruct_tree(tree, elements, midle+1, f, p*2+1);
	return tree[p];
}
int get_sum(int tree[], int i, int f, int ii, int fi, int p)
{
	if(i >= ii && f <= fi) return tree[p];
	if(f < ii || i > fi) return 0;

	int midle = (i+f)/2;
	return get_sum(tree, i, midle, ii, fi, p*2) + get_sum(tree, midle+1, f, ii, fi, p*2+1);
}
int get_value()
{
	char aux[50];
	int a;
	scanf("%c", aux);
	for(a = 0; aux[a] != '\0'; a++);
	if(aux[0] == aux[a-1] || a== 1) return 1;
	return 0;
}
void update(int tree[], int i, int f, int k, int dif, int p)
{
	if(f < k || i > k) return;
	tree[p] += dif;
	if(i != f)
	{
		int midle = (i+f)/2;
		update(tree, i, midle, k, dif, p*2);
		update(tree, midle+1, f, k, dif, p*2+1);
	}
}

void main()
{
	int size, comands;
	int a, b, c, dif;
	int o, x, y, newv;
	
	scanf("%d%d", &size, &comands);
	getchar();

	int elements[size+1], segment_Tree[500000];
	read(elements, size);
	contruct_tree(segment_Tree, elements, 1, size, 1);
	
	while(comands)
	{
		scanf("%d", &o);
		if(o == 1)
		{
			scanf("%d%d", &x, &y);
			 printf("%d\n", get_sum(segment_Tree, 1, size, x, y, 1));
		}
		if(o == 2)
		{
			scanf("%d", &x);
			getchar();
			newv = get_value();
			dif = newv - elements[x];
			elements[x] = newv;
			if(dif)update(segment_Tree, 1, size, x, dif, 1);
		}
		comands--;
	}
}