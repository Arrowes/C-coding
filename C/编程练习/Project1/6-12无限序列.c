#include<stdio.h>
int main(void)
{
    long long item = 0;
    double result1 = 0.0;
    double result2 = 0.0;

    while (scanf("%lld", &item) == 1)
    {
        for 
            (int i = 1; i <= item; i++)
        {
            result1 += 1.0 / i;
            if (i % 2 == 1)
            {
                result2 += 1.0 / i;
            }
            else
            {
                result2 -= 1.0 / i;
            }
        }
        printf("first:%lf\n", result1);
        printf("second:%lf\nsum=%lf\n", result2,result1+result2);
    }

    return 0;
}