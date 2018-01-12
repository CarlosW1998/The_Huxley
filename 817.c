#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	if(a > b) return a;
	return b;
}

int main()
{
	int size;
	int a, b, c;

	scanf("%d", &size);

	int hight[size], sub = 0;
	int minleft[size], minright[size], mindef[size];

	for(a = 0; a < size; a++) scanf("%d", &hight[a]);
	minleft[0] = hight[0];
	for(a = 1; a < size; a++) minleft[a] = max(minleft[a-1], hight[a]);
	minright[size-1] = hight[size-1];
	for(a = size-2; a >= 0; a--) minright[a] = max(minright[a+1], hight[a]);
	for(a = 0; a < size; a++) mindef[a] = -max(-minright[a], -minleft[a]);
	for(a = 0; a < size; a++)
	{
		if(mindef[a] > hight[a]) sub++;
	}

	printf("%d\n", sub);

	return 0;
}