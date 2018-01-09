#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main()
{
	int d, vf, vg;
	double ds, tf, tg;

	scanf("%d%d%d", &d, &vf, &vg);

	while(d != -1 && vf != -1 && vg != -1)
	{
		ds = sqrt(144 + pow(d, 2));
		tf = 12.0/(double)vf;
		tg = ds/(double)vg;
		printf("%f %f\n", tf, tg);
		if(tf >= tg) printf("Y\n");
		else printf("N\n");

		scanf("%d%d%d", &d, &vf, &vg);
	}



	return 0;
}