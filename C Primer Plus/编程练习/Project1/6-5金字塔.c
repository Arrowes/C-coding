#include<stdio.h>
int main(void)
{
	char ch=0;
	while (scanf("%c", &ch)==1)
	{
		int length = ch - 'A' + 1;//��������
		for (int i = 0; i < length; i++)//��
		{
			char temp = 'A' ;
			for (int j = 0; j < (length - i - 1); j++)//�ո���
			{
				printf(" ");
			}
			for (int j = 0; j <= i; j++)//�����ӡ��ĸ
			{
				printf("%c", temp++);
			}
			temp--;
			for (int j = 0; j < i; j++)//�����ӡ��ĸ
			{
				printf("%c",--temp);
			}

			printf("\n");
			
		}
		//scanf("%c", &ch);
		

     }
	return 0;
}