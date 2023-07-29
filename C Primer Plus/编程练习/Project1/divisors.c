#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	unsigned long num, div;
	bool flag;

	printf("请输入一个数\n");
		while (scanf("%lu", &num) == 1)
		{
			for (div = 2, flag = true; (div * div) <= num; div++)
			{
				if (num % div == 0)
				{

					if ((div * div) != num)
						printf("%lu可被拆分为%lu和%lu。\n", num, div, num / div);
					else
						printf("%lu可被%lu整除。\n", num, div);
					flag = false;
				}
			}

			if (flag)
				printf("%lu是素数。\n", num);
			printf("输入另一个数继续，或输入任意字母退出。\n");
		}
		printf("再见~\n");
		return 0;
}