#include <iostream>

int main()
{
    int x=8;
    int y=6;
    std::cout << std::endl; //输出一个换行符并刷新输出缓冲区
    std::cout << x-y << " "<< x*y<<" "<<x+y;
    std::cout << std::endl;
    return 0;
}