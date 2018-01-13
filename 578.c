#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _Heap Heap;

Heap *creat_heap(int max_size);

void Bild_Max_heap(Heap *heap);

void read(Heap *heap);

void print_heap(Heap *heap);

int main()
{
	Heap *heap = creat_heap(10000);
	read(heap);
	Bild_Max_heap(heap);
	return 0;
}
struct _Heap
{
	int size, max_size;
	int *elements;
};
void print_heap(Heap *heap)
{
    int a;
	for(a = 1; a < heap->size; a++) printf(" %d |", heap->elements[a]);
	printf(" %d\n", heap->elements[a]);
}
Heap *creat_heap(int max_size)
{
	Heap *new = (Heap*)malloc(sizeof(Heap));
	new->max_size = max_size;
	new->size = 0;
	new->elements = (int*)malloc(sizeof(int)*max_size);
	return new;
}
void read(Heap *heap)
{
	int aux;
	while(scanf("%d", &aux) != EOF) heap->elements[++heap->size] = aux;
}
int parent_index(int i)
{
	return i / 2;
}
int left_index(int i)
{
	return i * 2;
}
int right_index(int i)
{
	return i *2 +1;
}
bool is_empyt(Heap *heap)
{
	if(heap->size == 0) return true;
	return false;
}
void swap(int *i, int *j)
{
	int aux;
	aux = *i;
	*i = *j;
	*j = aux;
	return;
}
void max_heapfy(Heap *heap, int i)
{
	int largest;
	int left = left_index(i), right = right_index(i);
	if(left <= heap->size && heap->elements[left] > heap->elements[i]) largest = left;
	else largest = i;
	if(right <= heap->size && heap->elements[right] > heap->elements[largest]) largest = right;

	if(heap->elements[i] != heap->elements[largest])
	{
		swap(&heap->elements[i], &heap->elements[largest]);
		max_heapfy(heap, largest);
	}
}
void Bild_Max_heap(Heap *heap)
{
	int i;
	printf("Estado inicial:");
	print_heap(heap);
	for(i = heap->size/2; i >= 1; i--)
	{
		max_heapfy(heap, i);
		printf("Estado Atual:");
		print_heap(heap);
	}
	printf("Resultado Final:");
	print_heap(heap);
}