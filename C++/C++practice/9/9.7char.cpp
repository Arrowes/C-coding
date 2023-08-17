#include <iostream>
#include <string.h>
using namespace std;
class MyString
{
    private:
        char* buffer;

    public:
        MyString(const char* initString)
        {
            if(initString != NULL)
            {
                buffer=new char [strlen(initString)+1]; //使用 new 为字符缓冲区 buffer 分配内存
                strcpy(buffer, initString); //initString 复制到 buffer 指向的新分配的内存中
            }
            else
                buffer = NULL;  //以防该指针包含随机值
        }

        ~MyString()
        {
            cout << "Clear" << endl;
            if(buffer != NULL)
                delete [] buffer;
        }

        int GetLength()
        {
            return strlen(buffer);
        }

        const char* GetString()
        {
            return buffer;
        }

};

int main()
{
    MyString sayHello("Hello");     //实例化类时，构造函数被调用 "Hello" 字符串的地址被传递给构造函数
    cout << "syaHello length is "<<sayHello.GetLength() << " long" << endl;

    cout << "Buffer contains: " << sayHello.GetString() <<endl;
}