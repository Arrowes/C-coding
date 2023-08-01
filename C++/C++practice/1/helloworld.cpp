// # include <stdio.h>

// int main() {
//     printf("hello world!");
//     return 0;
// }

#include <iostream>  //标准头文件，引入std::cout
int main()
{
    std::cout << "Hello World!!" << std::endl; // <<：流插入运算符
    return 0;  //cout 是在名称空间 std 中定义的一个流, 用来显示
}
