#include<stdio.h>
int main(void)
{
	char ch;
	int blank=0, line=0, words=0;
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case' ':
			blank++;
		case'\n':
			line++;
		default:
			words++;

		}
	}
	printf("blank:%d,line:%d,words:%d\n",blank,line,words);
	return 0;
}