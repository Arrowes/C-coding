#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define STOP '|'
int main(void)
{
	char c;
	char prev='\n';
	long chars = 0L;
	int lines = 0;
	int	words = 0;
	int line = 0;
	bool inword = false;
	printf("���루��|��β��\n");

	while ((c = getchar()) != STOP)  //�޽�βʱ
	{
		chars++;
		if (c == '\n')
			lines++;
		if (isspace(c)) //���ʿ�ͷ
		{
		
			words++;
		}
	
		prev = c;
	}
	if (prev != '\n')
		line = 1;
	printf("%ld����ĸ��%ld�����ʣ�%ld�У�%d�в�������\n", chars-words, words+1, lines+line,line);
	return 0;
}