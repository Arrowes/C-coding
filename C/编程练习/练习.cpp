#include <stdio.h>
int main(void)
{
	char str[15],f[15];
	float i;
	printf("请输入姓名：");
	scanf("%s",str);
	printf("请输入课程名：");
	scanf("%s",f);
	printf("请输入成绩：");
	scanf("%f",&i);
	printf("输入的姓名、课程名和成绩为：%s %s %.1f\n",str,f,i);
}

