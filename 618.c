#include<stdio.h>
#include<stdlib.h>

typedef struct _Segment Tree;
struct _Segment
{
	int *bla;
};
int get_sum(int tree[], int i, int f, int ii, int fi, int p)
{
	if(i >= ii && f <= fi) return tree[p];
	if(f < ii || i > fi) return 0;

	int midle = (i+f)/2;
	return get_sum(tree, i, midle, ii, fi, p*2) + get_sum(tree, midle+1, f, ii, fi, p*2+1);
}

int contruct_tree(char elements[], char e, int *tree, int i, int f, int p)
{
	if(i == f)
	{
		tree[p] = 0;
		if(elements[i-1] == e) tree[p] = 1;
		return tree[p];
	}
	int midle = (i+f)/2;
	tree[p] = contruct_tree(elements, e, tree, i, midle, p*2) + contruct_tree(elements, e, tree, midle+1, f, p*2+1);
	return tree[p];
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

int main()
{
	Tree elements[30];
	int size, comands;
	int a, b, c, impar;
	int o, x, y;
	char aux;
	char str[100020];

	scanf("%d%d", &size, &comands);
	getchar();
	scanf("%s", str);
	for(a = 1; a < 30; a++)
	{
		elements[a].bla = (int*)malloc(sizeof(int)*500000);
		contruct_tree(str, a+96, elements[a].bla, 1, size, 1);
	}
	while(comands)
	{
		scanf("%d", &o);
		if(o == 1)
		{
			scanf("%d %c", &x, &aux);
			if(aux != str[x-1])
			{
				update(elements[str[x-1]-96].bla, 1, size, x, -1, 1);
				update(elements[aux-96].bla, 1, size, x, 1, 1);
				str[x-1] = aux;
			}
		}
		if(o == 2)
		{
			impar = 0;
			scanf("%d%d", &x, &y);
			if(x == y-1)
			{
				if(str[x] == str[y]) printf("yes\n");
				else printf("no\n");
			}
			else
			{
				for(a = 1; a < 25; a++)
				{
					if(get_sum(elements[a].bla, 1, size, x, y, 1)%2) impar++;
					if(impar > 1) break;

				}
				if(impar > 1) printf("no\n");
				else  printf("yes\n");
			}
		}

		comands--;
	}


}