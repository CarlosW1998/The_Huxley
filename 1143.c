#include<stdio.h>
#include<stdlib.h>

int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

int max(int *i, int size)
{
	int a, biger = -999999;
	for(a = 0; a < size; a++) if(i[a] > biger) biger = i[a];
	return biger;
}

int main()
{
	int size;
	int a, b, c;

	scanf("%d", &size);

	int t[size], tesq[size], tdir[size], defsize[size];


	for(a = 0; a < size; a++) scanf("%d", &t[a]);

	tesq[0] = 1;
	for(a = 1; a < size; a++) tesq[a] = min(tesq[a-1]+1, t[a]);

	tdir[size-1] = 1;
	for(a = size-2; a >= 0; a--) tdir[a] = min(tdir[a+1]+1, t[a]);

	for(a = 0; a < size; a++) defsize[a] = min(tdir[a], tesq[a]);

	printf("%d\n", max(defsize, size));

	return 0;
}