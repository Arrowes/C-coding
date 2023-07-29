#include<stdio.h>
int main(void)
{
	char assets;
	char pet[30];
	printf("Enter:\n");
	scanf("%c",&assets);
	scanf("%s", pet);
	printf("%c %s \n",assets, pet);
	return 0;
}