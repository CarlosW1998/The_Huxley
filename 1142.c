#include<stdio.h>
#include<stdlib.h>

int is_(char a)
{
	if(a == 97 || a == 101 || a == 105 || a == 111 || a == 117) return 1;
	return 0;
}

int magic(char *smile, int a, int b)
{
	if(a >= b) return 1;
	if(smile[a] != smile[b]) return 0;
	return magic(smile, a+1, b-1);
}


int main()
{
	char smile[100], leter;
	int a = 0, b, c;

	while(scanf("%c", &leter) != EOF)
	{
		if(is_(leter))
		{
			smile[a] = leter;
			a++;
		}
	}
	smile[a] = '\0';

	if(magic(smile, 0, a-1)) printf("S\n");
	else printf("N\n");

	return 0;
}