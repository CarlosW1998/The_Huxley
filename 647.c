#include<stdio.h>
#include<stdlib.h>

typedef struct  _comand comand;
struct _comand
{
	int i, position;
};

int find(comand k[], int size, int num)
{
	int a;
	for(a = 1; a < size; a++) if(k[a].i == num) return a;
	return 0;
}

int main()
{
	int a, b, c;
	int pi, size, aux, maximo;
	comand comandos[5000];

	scanf("%d", &pi);
	while(pi)
	{
		size = 1;
		maximo = 0;

		for(a = 0; a < pi; a++)
		{
			scanf("%d", &aux);
			b = find(comandos, size, aux);
			if(!b)
			{
				maximo += a+aux;
				comandos[size].i = aux;
				comandos[size].position = a;
				size++;
			}
			else 
			{
				maximo += a - comandos[b].position;
				comandos[b].position = a;
			}
		}
		printf("%d\n", maximo);
		scanf("%d", &pi);
	}



	return 0;
}