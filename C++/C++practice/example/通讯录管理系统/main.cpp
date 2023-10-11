//https://www.bilibili.com/video/BV1et411b73Z?p=72

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
using namespace std;
#include <string>
#define MAX 1000

//联系人结构体
struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

//通讯录结构体
struct Addressbooks
{
    //联系人数组
    struct Person personArray[MAX];
    //联系人个数
    int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks * abs)
{
    if(abs->m_Size==MAX)
    {
        cout << "通讯录已满，无法添加"<<endl;
        return;
    }
    else    //添加联系人
    {
        string name;
        cout<<"请输入姓名： ";
        cin >> name;
        abs->personArray[abs->m_Size].m_Name=name;

        cout<<"请输入性别：（1--男，2--女 ）： ";
        while(true)
        {        
           int sex=0;
            cin >> sex;
            if(sex==1||sex==2)
            {
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cin.clear();
            cin.ignore();
            cout << "错误，重新输入：";
        }

        cout << "请输入年龄：";
        int age=0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age=age;

        cout << "请输入电话：";
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone=phone;

        cout<<"请输入地址：";
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;

        abs->m_Size++;
        cout<<"添加成功!"<<endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
    }
}

//2.显示联系人
void showPerson(Addressbooks * abs)//用指针的方式传通讯录进来
{
    if (abs->m_Size==0)
    {
        cout<<"当前联系人为空"<<endl;
    }
    else
    {
        for (int i=0;i< abs->m_Size;i++)
        {
            cout << "姓名："<<abs->personArray[i].m_Name<<"\t";
            cout << "性别："<<(abs->personArray[i].m_Sex== 1?"男":"女")<<"\t"; 
            cout << "年龄："<<abs->personArray[i].m_Age<<"\t";
            cout << "电话："<<abs->personArray[i].m_Phone<<"\t";
            cout << "住址："<<abs->personArray[i].m_Addr<<endl;
        }
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

//3.删除联系人
int isExist(Addressbooks * abs, string name) //传入通讯录和姓名
{
    for (int i=0; i<abs->m_Size; i++)
    {
        if(abs->personArray[i].m_Name==name)
        {
            return i;
        }
    }
    return -1;
}

void deletePerson(Addressbooks * abs)   //把通讯录按地址的方式传递，用指针的形式接收
{
    cout << "请输入要删除的联系人姓名：";
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret!=-1)
    {
        for(int i=ret; i < abs->m_Size;i++)
        {
            abs->personArray[i]=abs->personArray[i+1];   //数据前移
        }
        abs->m_Size--;
        cout << "删除“ "<<name<<" ”成功"<< endl;
    } 
    else
    {
        cout << "查无此人"<<endl;
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

//4.查找联系人
void findPerson(Addressbooks * abs)
{
    cout<<"请输入要查找的联系人: ";
    string name;
    cin >> name;

    int ret = isExist(abs,name);
    if (ret !=-1)
    {
        cout << "姓名："<<abs->personArray[ret].m_Name<<"\t";
         cout << "性别："<<(abs->personArray[ret].m_Sex== 1?"男":"女")<<"\t"; 
        cout << "年龄："<<abs->personArray[ret].m_Age<<"\t";
        cout << "电话："<<abs->personArray[ret].m_Phone<<"\t";
        cout << "住址："<<abs->personArray[ret].m_Addr<<endl;
    }
    else
    {
        cout << "查无此人"<<endl;
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

//5.修改联系人
void modifyPerson(Addressbooks * abs)
{
    cout << "请输入要修改的联系人： "<< endl;
    string name;
    cin >> name;
    int ret = isExist(abs,name);
    if (ret !=-1)
    {
        cout<<"请输入姓名： ";
        cin >> name;
        abs->personArray[ret].m_Name=name;

        cout<<"请输入性别：（1--男，2--女 ）： ";
        while(true)
        {        
           int sex=0;
            cin >> sex;
            if(sex==1||sex==2)
            {
                abs->personArray[ret].m_Sex=sex;
                break;
            }
            cin.clear();
            cin.ignore();
            cout << "错误，重新输入：";
        }

        cout << "请输入年龄：";
        int age=0;
        cin>>age;
        abs->personArray[ret].m_Age=age;

        cout << "请输入电话：";
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone=phone;

        cout<<"请输入地址：";
        string address;
        cin>>address;
        abs->personArray[ret].m_Addr=address;

        cout<<"修改成功!"<<endl;
    }
    else 
    {
        cout << "查无此人"<<endl;
    }
        system("read -p 'Press Enter to continue...' var");
        system("clear");
}

//6.清空联系人
void cleanPerson(Addressbooks * abs)
{
    cout << "是否确认清空?(y/n)：";
    string ret;
    cin >> ret;
    if  (ret=="y")
    {
        abs->m_Size=0;
        cout << "已清空！" <<endl;
    }
    else
    {
    cout << "已取消" <<endl;
    }
    system("read -p 'Press Enter to continue...' var");
     system("clear");
}


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

void sayGoodbye() {
    srand(time(0)); // 设置随机数生成器的种子为当前时间的秒数
    int num = rand() % 3; // 生成一个在0到2之间的随机数
    switch (num) {
    case 0:
        cout << "Goodbye!" << endl;
        break;
    case 1:
        cout << "See you later!" << endl;
        break;
    case 2:
        cout << "Take care!" << endl;
        break;
    }
}

int main()
{
    //创建通讯录结构体变量
    Addressbooks abs;
    abs.m_Size=0;

    int select=0;//用户变量

    while (true)
    {
    showMenu();
    cin >> select;
    
    switch(select)
    {
        case 1:     // 1.添加联系人
            addPerson(&abs);//利用地址传递，可以修饰实参
            break;
            
        case 2:     //2.显示联系人
            showPerson(&abs);
            break;

         case 3:     //3.删除联系人
            deletePerson(&abs);
            break;

         case 4:     //4.查找联系人
            findPerson(&abs);
            break;

        case 5:     // 5.修改联系人
             modifyPerson(&abs);
            break;

        case 6:     //6.清空联系人
            cleanPerson(&abs);
            break;

        case 0:     //0.退出通讯录
            sayGoodbye();
            return 0;
            break;

        default:
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            break;
                  
    }
    }

   

    return 0;
}