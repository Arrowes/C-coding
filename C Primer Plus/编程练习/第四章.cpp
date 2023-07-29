/*#include <stdio.h>
int main(void)
{   
	char name[40];
	printf("ÇëÊäÈëÄãµÄĞÕÃû¡£\n");
    scanf("%s",name);
	printf("\"%s\"\n",name);
	printf("%20s\n",name);
    printf("%-20s\n",name);
	printf("%3.0s\n",name);
	getchar();
	getchar();
	return 0;
}*/

/* Programming Exercise 4-4 */
 #include <stdio.h> 
int main(void) 
{    
	float height;     
	char name[40];          
	printf("Enter your height in inches: ");     
	scanf("%f", &height);     
	printf("Enter your name: ");     
	scanf("%s", name);     
	printf("%s, you are %10.3f feet tall\n", name, height / 12.0);
	getchar();
	getchar();
	return 0; 
} 
 
 
