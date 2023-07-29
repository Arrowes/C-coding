#include<stdio.h>
#include<math.h>
int main(void)
{
	int B,C;
	const double A = 3.14159265;
	double R;
	printf("pai?\n");
	B=(scanf("%lf", &R)==1);
	C = (fabs(R - A) > 0.0001);
	while (C&&B)
	{
		printf("NO!\n");
		scanf("%lf", &R);
	}
	printf("Nice!");
	return 0;
}