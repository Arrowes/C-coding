#include <iostream>
#include <string>
using namespace std;

class President
{
    private:
        President() {};  // 私有的默认构造函数，防止外部创建实例
        President(const President&);  // 私有的拷贝构造函数，防止对象拷贝
        const President& operator=(const President);  // 私有的赋值运算符重载，防止对象赋值

        string name;  // 私有成员变量，用于存储总统的名字

    public:
        static President& GetInstance()  // 静态方法，用于获取唯一的实例
        {
            static President onlyInstance;  // 在首次调用时创建唯一实例
            return onlyInstance;
        }

        string GetName()  // 公有方法，用于获取总统的名字
        { return name; }

        void SetName(string InputName)  // 公有方法，用于设置总统的名字
        { name = InputName; }
};

int main()
{
    President& onlyPresident = President::GetInstance();  // 获取 President 实例的引用
    onlyPresident.SetName("Abraham Lincoln");  // 设置总统名字
    cout << "President is: " << President::GetInstance().GetName() << endl;  // 输出总统名字
    return 0;
}
