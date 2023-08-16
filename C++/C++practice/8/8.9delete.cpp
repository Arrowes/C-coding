#include <iostream>
using namespace std;

int main()
{
    cout << "Enter number: ";
    int num=0;
    cin >> num;

    int* point=new int [num];   //分配内存

    cout << num << " integers" << endl;
    for( int counter = 0; counter < num; ++counter)
    {
        cout << "Enter new number " << counter+1 << ": ";
        cin >> *(point + counter);  //使用偏移量变量 counter 将用户输入直接存储到内存单元中
    }
    cout << "Display : "<<endl;
    for( int counter = 0; counter < num; ++counter)
    {
        cout << *(point+counter) << " ";  //将指针包含的地址递增，让指针指向下一个元素
    }
    cout << endl;
    //point -= num;   //使用运算符-=让 pointsToInts重新指向原来的地址
    delete[] point; //调用 delete[]来释放内存时，必须指定分配内存时 new 返回的指针地址
    return 0;
}