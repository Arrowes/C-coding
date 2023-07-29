#include<stdio.h>
void findmax(int a[3][3]);
void findmin(int a[3][3]);
void main()
{
	int a[3][3];
	int i,j,max,min,sum;
	float avg;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
	     scanf("%d",&a[i][j]);
			sum=0;
			sum=a[i][j]+sum;
			printf("sum=%d\n",sum);
			avg=sum/9.0;
			printf("avg=%f\n",avg);
}
void findmin(int a[3][3])
{
	int i,j,min;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
	    	min=a[0][0];
			if(min<=a[i][j])
				printf("min=%d",min);
			else
				printf("min=%d",a[i][j]);
			i=i-1,j=j-1;
			printf("i=%dj=%d\n",i,j);
}
void findmax(int a[3][3])
{
	int i,j,max;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			max=a[0][0];
			if(max>=a[i][j])
				printf("max=%d",max);
			else
				printf("max=%d",a[i][j]);
			i=i-1,j=j-1;
			printf("i=%dj=%d\n",i,j);
}
