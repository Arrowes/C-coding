#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	unsigned long num, div;
	bool flag;

	printf("������һ����\n");
		while (scanf("%lu", &num) == 1)
		{
			for (div = 2, flag = true; (div * div) <= num; div++)
			{
				if (num % div == 0)
				{

					if ((div * div) != num)
						printf("%lu�ɱ����Ϊ%lu��%lu��\n", num, div, num / div);
					else
						printf("%lu�ɱ�%lu������\n", num, div);
					flag = false;
				}
			}

			if (flag)
				printf("%lu��������\n", num);
			printf("������һ����������������������ĸ�˳���\n");
		}
		printf("�ټ�~\n");
		return 0;
}