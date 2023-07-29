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
	printf("输入（以|结尾）\n");

	while ((c = getchar()) != STOP)  //无结尾时
	{
		chars++;
		if (c == '\n')
			lines++;
		if (isspace(c)) //单词开头
		{
		
			words++;
		}
	
		prev = c;
	}
	if (prev != '\n')
		line = 1;
	printf("%ld个字母，%ld个单词，%ld行，%d行不完整。\n", chars-words, words+1, lines+line,line);
	return 0;
}