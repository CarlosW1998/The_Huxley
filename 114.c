#include<stdio.h>
#include<stdlib.h>

int main()
{
	int l, h;
	int l1, h1;
	int l2, h2;

	scanf("%d%d%d%d%d%d", &l, &h, &l1, &h1, &l2, &h2);

	if(l1+l2 <= l && h1 <= h && h2 <= h) printf("S\n");
	else if(l1+l2 <= h && h1 <= l && h2 <= l) printf("S\n");
	else if(l1+h2 <= h && h1 <= l && l2 <= l) printf("S\n");
	else if(l1+h2 <= l && h1 <= h && l2 <= h) printf("S\n");
	else if(h1+h2 <= l && l1 <= h && l2 <= h) printf("S\n");
	else if(h1+h2 <= h && l1 <= l && l2 <= l) printf("S\n");
	else if(h1+l2 <= h && l1 <= l && h2 <= l) printf("S\n");
	else if(h1+l2 <= l && l1 <= h && h2 <= h) printf("S\n");


	else printf("N\n");
}