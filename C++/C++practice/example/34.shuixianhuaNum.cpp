#include <iostream>
using namespace std;

int main(){
    int num=100;
    do{
        int a=0, b=0, c=0;
        a=num%10;
        b=num/10%10;
        c=num/100;
        if(num==a*a*a+b*b*b+c*c*c)    //如果是水仙花数
            cout << num <<endl;
    num++;
    }while (num<1000);
    return 0;
}
