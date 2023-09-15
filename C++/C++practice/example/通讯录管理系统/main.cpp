#include <iostream>
using namespace std;

//Menu
void showMenu(){
    cout << "************************" << endl;
    cout << "**** 通讯录管理系统 ****" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "************************" << endl;
}


int main(){
    showMenu();

    return 0;
}