/*ตฺศýีย 2
#include <stdio.h>
int main(void)
{
	char wyj;
	printf("please enter a ASCII.\n");
	scanf("%d",&wyj);
	printf("output is %
	c\n",wyj);
	return 0;
}

#include <stdio.h> 
int main(void) 
{
int ascii;          
printf("Enter an ASCII code: ");     
scanf("%d", &ascii);     
printf("%d is the ASCII code for %c.\n", ascii, ascii);     
return 0; 
} */

/* 2
#include <stdio.h>
int main(void)
{
	float wyj;
	printf("please enter float code.\n");
	scanf("%f",&wyj);
	printf("output is \n%f\n%e\n%d\n",wyj,wyj,wyj);
	return 0;
}

#include <stdio.h> 
int main(void) 
{     float num;     
printf("Enter a floating-point value: ");     
scanf("%f", &num);     
printf("fixed-point notation: %f\n", num);     
printf("exponential notation: %e\n", num);     
printf("p notation: %a\n", num);     return 0; } 
*/
#include <stdio.h>
int main(void)
{
	float year;
	printf("\"HOW OLD ARE YOU?.\n");
	scanf("%f",&year);
	float second=365*year*24*60*60;
	printf("you have live for %fs\n",second);
	return 0;
}