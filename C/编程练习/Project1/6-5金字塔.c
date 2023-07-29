#include<stdio.h>
int main(void)
{
	char ch=0;
	while (scanf("%c", &ch)==1)
	{
		int length = ch - 'A' + 1;//定义行数
		for (int i = 0; i < length; i++)//行
		{
			char temp = 'A' ;
			for (int j = 0; j < (length - i - 1); j++)//空格数
			{
				printf(" ");
			}
			for (int j = 0; j <= i; j++)//升序打印字母
			{
				printf("%c", temp++);
			}
			temp--;
			for (int j = 0; j < i; j++)//降序打印字母
			{
				printf("%c",--temp);
			}

			printf("\n");
			
		}
		//scanf("%c", &ch);
		

     }
	return 0;
}