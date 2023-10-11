---
title: C, C++, Cmake
date: 2023-05-16 09:43:00
tags:
- C/C++
---
项目地址：[C-coding](https://github.com/Arrowes/C-coding)
# C
[C Primer Plus(第六版)中文版](https://img.anfulai.cn/bbs/94810/C%20Primer%20Plus(%E7%AC%AC%E5%85%AD%E7%89%88)%E4%B8%AD%E6%96%87%E7%89%88.pdf)

```c
system("read -p 'Press Enter to continue...' var");//linux按任意键继续命令
system("clear");//linux清屏操作

system("pause"); //windows请按任意键继续
system("cls");//windows清屏操作
```




--------------------------------------------------------------
--------------------------------------------------------------

# C++
[21天学通C++第8版](https://github.com/Arrowes/C-coding/blob/main/C%2B%2B/21%E5%A4%A9%E5%AD%A6%E9%80%9AC%2B%2B%E7%AC%AC8%E7%89%88%20%E9%AB%98%E6%B8%85%E5%AE%8C%E6%95%B4PDF.pdf)
## 1.绪论
C++最初由 Bjarne Stroustroup 于 1979 年在贝尔实验室开发，旨在作为 C 语言的继任者。但不同于C 语言，C++是一种面向对象的语言，实现了继承、抽象、多态和封装等概念。
C++是一种中级编程语言，这意味着使用它既可以高级编程方式编写应用程序，又可以低级编程方式编写与硬件紧密协作的库。

构建可执行文件：编写代码(.cpp) > 编译器(.o / .obj) > 链接器(.exe)

```c++
#include <iostream>  //标准头文件，引入std::cout
int main()
{
    std::cout << "Hello World!!" << std::endl; // <<：流插入运算符
    return 0;  //cout 是在名称空间 std 中定义的一个流, 用来显示
}
```

**开发环境**：Visual studio code + GCC compiler/MinGW, 按F5 Choose `C/C++: g++.exe build and debug active file`, 将编译、链接并执行应用程序

## 2.C++程序的组成部分
+ 预处理器编译指令 `#include`
   `#include "...relative path to .\FileB"`包含自定义头文件，`<>`用来包含自定义头文件 
+ 程序主体 `main()`
程序的起点，前面的int是一种标准化约定，表示返回类型为整数
+ 返回值
在 C++中，除非明确声明了不返回值，否则函数必须返回一个值，根据约定，程序员在程序运行成功时返回 0，并在出现错误时返回−1

**namespace名称空间**：是给代码指定的名称，有助于降低命名冲突的风险，如`std::cout`:调用名称空间 std 中独一无二的 cout, 若要省略std::, 先加入`using namespace std`

**注释**：
```c
//单行注释
/* 跨行
   注释
*/
```
cin 可用于从用户那里获取文本输入和数字输入`std::cin >> Variable1 >> Variable2; `

## 3.使用变量和常量
### 变量
`VariableType VariableName = InitialValue;`
变量类型向编译器指出了变量可存储的数据的性质，编译器将为变量预留必要的空间。变量名由程序员选择，它替代了变量值在内存中的存储地址;
函数内部声明的为*局部变量*，作用域为局部，被限定在声明它的函数内，函数结束后，将销毁所有局部变量，并归还它们占用的内存；在函数外部声明的则为*全局变量*。

命名约定：对于变量名，采用*骆驼拼写法*(firstNumber, 第一个单词的首字母采用小写)，而对于诸如函数名等其他元素，采用 *Pascal 拼写法*(MultiplyNumbers(), 函数名每个首字母都大写)。

编译器支持的常见 C++变量类型:
| 类型               | 值                      |概念|
|-------------------|--------------------------|-----|
| bool              | true/false               |布尔变量
| char              | 256个字符值               |存储单字符,如'A'
| unsigned short int | 0～65535                 |占16位内存=$2^{16}$=65536
| short int         | –32768～32767             |最高有效位（MSB）做符号位
| unsigned long int | 0～4294967295             |$2^{32}$
| long int          | –2147483648～2147483647   |
| int (16位)         | –32768～32767            |
| int (32位)         | –2147483648～2147483647  |
| unsigned int（16位）| 0～65535                |
| unsigned int（32位） | 0～4294967295          |
| float             | 1.2e–38～3.4e38           |浮点数
| double            | 2.2e–308～1.8e308         |双精度浮点数

sizeof 确定变量长度（字节）：`sizeof (int)`
使用列表初始化避免缩窄转换错误：`int anotherNum{ largeNum };`
关键字 auto 自动推断类型：`auto coinFlippedHeads = true`
typedef 替换变量类型: `typedef unsigned int MYINT; `

### 常量
在 C++中，常量类似于变量，只是不能修改。
+ 字面常量：可以是任何类型：布尔型、整型、字符串等
+ 使用关键字 const 将变量声明为常量(最实用): `const double pi = 22.0 / 7;`
+ 使用 constexpr 定义常量表达式: `constexpr double GetPi() {return 22.0 / 7;} `
+ 使用关键字 enum 声明枚举: 指定一组特定的取值，枚举量起始值默认为0
+ ~~使用#define 定义常量：`#define pi 3.14286`, 已被摒弃~~

务必确保变量名阐述了变量的用途。
务必对变量进行初始化，确保变量包含非随机的确定值；并使用列表初始化来避免缩窄转换错误。
不要将保留的 C++关键字用作变量名，因为这将导致程序无法通过编译。

## 4.管理数组和字符串
### 数组
在 C++中，数组让您能够按顺序将一系列相同类型的数据存储到内存中。

**静态数组：**
```c
int myNumbers [5] = {}; //声明一个包含 5 个 int 元素的数组，并将每个元素都初始化为零
char myCharacters [5];  //定义一个包含 5 个字符的数组
Num = myNumbers [0];    //取出第一个元素 
myNumbers [3] = 2023;   //重新赋值
//Bytes consumed by an array = sizeof(element-type) * Number of Elements 
//务必初始化数组，否则其元素将包含未知值。使用数组时，务必确保在其边界内。

//在 C++中，可在内存中模拟多维数组(但存储数组的内存是一维的)
int array [2][3] = {{0, 1, 2}, {3, 4, 5}};  //or {0, 1, 2, 3, 4, 5}
Num1 = array [0][1]  //取出元素1
```
**动态数组** `std::vector`：
```c
#include <vector>
vector<int> dynArray (3); //这个矢量能动态地调整其长度，以存储更多数据，且无需初始化
```
### 字符串
C 风格字符串（危险）：
```c
std::cout << "Hello World"; 
//等同于：
char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};
std::cout << sayHello
//空字符‘\0’,也被称为字符串结束字符，告诉编译器字符串到此结束。不算长度
//如果没有在字符数组末尾添加空字符，可能跨越字符数组的边界,被称为缓冲区溢出
```
**C++字符串**：使用 `std::string`:
使用 C++标准字符串是更高效、更安全的方式。不同于字符数组（C 风格字符串实现），std::string 是动态的
```c
#include <string> 
string greetString ("Hello std::string!");
```

## 5.使用表达式、语句和运算符
从本质上说，程序是一组按顺序执行的命令。这些命令为表达式和语句，使用运算符执行特定的计算或操作。

+ 语句：分号界定了语句的边界; 要将一条语句放到两行中，可在第一行末尾添加反斜杠`\`; 可使用花括号（{}）将多条语句组合在一起，以创建复合语句（语句块）
+ 运算符：
   + `=` 赋值运算符，左值通常是内存单元，右值可以是内存单元的内容。
   + `+ - * / %` 求模运算符%返回除法运算的余数，只能用于整数
   + `++ --` 递增和递减运算符，分为前缀与后缀：
      ```c
      int num = ++num;  //前缀，先＋再赋值
      int num = num++;  //后缀，先赋值再+
      ```
   + `== !=`   相等性检查的结果为布尔值，即 true 或 false, 1 / 0
   + `< > <= >=`
   + 逻辑运算符(返回布尔值)：
      ```c
      !  //NOT 用于单个操作数，用于反转
      && //AND, 2true则true
      || //OR, 1true就true
      ^  //XOR异或，1true才true
      ```
   + 按位运算符（返回运算结果）：` ~  &  |  ^ `
   + 移位运算符,用途之一是将数据乘以或除以 $2^n$
      ```c
      int halfNum = inputNum >> 1;
      int quadrupleNum = inputNum << 2;
      ```
   + 复合赋值运算符,将运算结果赋给左边的操作数 `num1 += num2;`
   + 运算符 `sizeof`, 确定变量占用的内存量

运算符优先级,C++标准非常严格地指定了各种运算的执行顺序:
`int myNumber = 10 * 30 + 20 – 5 * 5 << 2;` 应写作 `int myNumber = ((10 * 30) – (5 * 5) + 20) << 2;`，使用括号让代码和表达式易于理解


## 6.控制程序流程
### 条件执行
`if...else`  条件不为0就被视为true
`if...else if...else`   
`switch-case`  条件处理,相比if-else-if结构化程度更高
```c
switch(expression)   
{ //计算 expression 的值，并将其与每个 case 标签进行比较
case LabelA:   //务必将枚举量用作 case 标签，以提高代码的可读性。
 DoSomething; 
 break;  //退出当前代码块
// And so on... 
default: 
 DoStuffWhenExpressionIsNotHandledAbove; 
 break; 
}
```
`?:` 条件运算符/三目运算符, 相当于紧凑的 if-else 结构
`(conditional expression evaluated to bool) ? expression1 if true : expression2 
if false; `

### 循环执行 
`goto`   (避免使用 goto，可防止代码不直观且难以维护。)
```c
SomeFunction() 
{  //不推荐使用 goto 语句来编写循环
Start: // Called a label 
 CodeThatRepeats; 
 goto Start; 
} 
```
`while` 只要条件为 true，就将反复执行该语句块
```c
while(expression) 
{ 
 // Expression evaluates to true 
 StatementBlock; 
}
```
`do...while` 循环逻辑至少执行一次时
```c
do 
{ 
 StatementBlock; // executed at least once 
} while(condition); // ends loop if condition evaluates to false 
```
`for`
```c
for (初始化语句 executed only once;  //迭代器
 条件表达式 executed at the beginning of every loop; 
 修改变量 executed at the end of every loop) 
{ //以上三项都是可选的
 DoSomething; 
}
```
C++11引入了*基于范围的 for 循环*，让对一系列值（如数组包含的值）进行操作的代码更容易编写和理解。
```c
char charArray[] = { 'h', 'e', 'l', 'l', 'o' }; 
for (auto aChar : charArray) 
   cout << aChar << ' '; 
cout << endl;  //h e l l o 
```
`continue` 能够跳转到循环开头，跳过循环块中后面的代码;
`break` 退出循环块，即结束当前循环。

控制无限循环
```c
for (;;) // no condition supplied = unending for 
{ 
 DoSomethingRepeatedly; 
 if(expression) 
 break; // 使用 break 退出无限 for 循环
} 
```

## 7.使用函数组织代码
函数让您能够划分和组织程序的执行逻辑。通过使用函数，可将应用程序的内容划分成依次调用的逻辑块。
+ 声明函数原型
`double Area(double radius)` = 返回值类型 函数名(函数接受的参数列表)
函数可接受用逗号分隔的多个参数，但只能有一种返回类型。可以给多个参数指定默认值，但这些参数*必须位于参数列表的末尾*。
+ 定义函数
函数定义由一个语句块组成。除非返回类型被声明为 void，否则函数必须包含一条 return 语句;
+ 调用函数
如果函数声明中包含形参（parameter），调用函数时必须提供实参（argument）

递归函数：调用自己，必须有明确的退出条件
多条 return 语句的函数：可使用 return 语句退出

### 函数数据处理
函数重载：名称和返回类型相同，但参数不同的函数被称为重载函数。
```c
double Area(double radius); // for circle 
double Area(double radius, double height); // for cylinder
//根据不同的输入使用不同的函数，实现不同的功能
```
数组传递给函数: `void DisplayIntegers(int[] numbers, int Length); `

`&` 按引用传递参数, 让函数修改的变量在其外部（如调用函数）中也可用(详见第八章引用)：
```c
void Area(double radius, double &result) 
//此时，result是指向调用函数中相应变量的引用，而不是其拷贝
int main()：...
   Area(radius, areaFetched); 
//Area( )中的变量 result，与 main( )中的 double areaFetched 指向同一个内存单元。
```
### 微处理器如何处理函数调用
*函数调用* 在微处理器中的过程：跳转到属于被调用函数的下一条指令处执行。执行完函数的指令后，返回到最初*离开的地方*;
因此，编译器将函数调用转换为一条供微处理器执行的 `CALL` 指令, 指出接下来要获取的指令所在的地址，该地址归函数所有。遇到 `CALL` 指令时，微处理器将调用函数后将要执行的指令的位置保存到 **栈** 中，再跳转到 `CALL` 指令包含的内存单元处。
> 栈是一种后进先出的内存结构，将数据加入栈被称为压入操作, 从栈中取出数据被称为弹出操作。栈增大时，栈指针将不断递增，始终指向栈顶; 
栈的性质使其非常适合用于处理函数调用。函数被调用时，所有局部变量都在栈中实例化，即被压入栈中。函数执行完毕时，这些局部变量都从栈中弹出，栈指针返回到原来的地方。
如：微处理器执行CALL指令指出的内存单元包含属于函数的指令，直到 RET 语句（return 语句对应的微处理器代码）导致微处理器从栈中弹出执行 CALL 指令时存储的地址。该地址包含调用函数中接下来要执行的语句的位置

**内联函数**
使用关键字 inline 发出请求，要求在函数被调用时就地展开它们：`inline double GetPi() ` 编译器通常将该关键字视为请求，请求将函数 GetPi()的内容直接放到调用它的地方，以提高代码的执行速度(因为执行函数调用的开销可能非常高)，仅当函数非常简单，需要降低其开销时，才应使用该关键字
(根据性能设置，大多数较新的编译器都能判断应内联哪些函数，进而为程序员这样做)

**自动推断返回类型**: ` auto Area(double radius)`

**lambda 函数**: `[optional parameters](parameter list){ statements; } `
lambda函数是 C++11 引入的，有助于使用 STL 算法对数据进行排序或处理，可以在需要函数对象的地方使用，用于简化代码和提高可读性。

## 8.阐述指针和引用
C++最大的优点之一是，既可使用它来编写不依赖于机器的高级应用程序，又可使用它来编写与硬件紧密协作的应用程序。能够在字节和比特级调整应用程序的性能。要编写高效地利用系统资源的程序，理解*指针和引用*是必不可少的一步。

### 指针 *
**指针是存储内存地址的变量**，是一种指向内存单元的特殊变量。
（内存单元地址通常使用十六进制表示法）
```c
int* pointsToInt = NULL;   //声明指针并初始化，务必初始化指针变量，否则它将包含垃圾值。
//例如int在内存中的地址为0x002EFB34，则占用 0x002EFB34～0x002EFB37
&pointsToInt      //引用运算符（&）, 也叫地址运算符，用来获取变量的地址。

int* pointsToInt = &age;   //使用指针存储地址(age是int变量)
int dogsAge = 9; 
pointsToInt = &dogsAge;    //同一个 int 指针可指向任何 int 变量

++pointsToInt     //将指向下一个int, Address + sizeof(int)

*pointsToInt              //解除引用运算符（*）,也叫间接运算符, 访问指向的数据
cin >> *pointsToInt;      //使用 * 操纵数据
```
**动态内存分配 new delete**
静态数组的长度是固定的，不能根据应用程序的需求增大或缩小, 因此使用 new 和 delete 动态地分配和释放内存
```c
int* pointToAnInt = new int;  //给整型分配内存（int* Pointer = new int[10]; 为一系列元素分配内存
delete pointToAnInt;          //释放内存（delete[] Pointer; 
//如果不释放，会造成内存泄露
```
运算符 new 和 delete 分配和释放自由存储区中的内存。自由存储区是一种内存抽象，表现为一个内存池，应用程序可分配（预留）和释放其中的内存。

**将关键字 const 用于指针**
```c
int Age=23;
int* const point = &Age;         //指针包含的地址是常量，不能修改，但可修改指针指向的数据
const int* point = &Age;         //指针指向的数据为常量，不能修改，但可以修改指针包含的地址，即指针可以指向其他地方
const int* const point = &Age;   //指针包含的地址以及它指向的值都是常量，不能修改（这种组合最严格）
//函数参数应声明为最严格的 const 指针
//**将指针传递给函数**: 指针是一种将内存空间传递给函数的有效方式，其中可包含函数完成其工作所需的数据，也可包含操作结果。
```
数组变量是指向第一个元素的指针, 类似于在固定内存范围内发挥作用的指针，因此也可将用于指针的解除引用运算符（*）用于数组

**使用指针相关错误**
+ 内存泄漏：new动态分配的内存没有用delete释放
+ 无效指针：务必确保指针指向了有效的内存单元, 否则使用 * 和 delete 时会崩溃
+ 悬浮指针：使用 delete 释放后，任何有效指针都将无效，很多程序员在初始化指针或释放指针后将其设置为 NULL，并在使用运算符 * 对指针解除引用前检查它是否有效（将其与 NULL 比较）
+ new内存分配失败：大块内存分配请求不一定能成功，失败会引发 `std::bad_alloc` 异常并中断执行
（`try-catch` 异常处理结构让程序能够向用户指出这一点，再正常退出；或可使用 new 变种 `new(nothrow)`，在内存分配失败时不引发异常，而返回 NULL，让您能够在使用指针前检查其有效性）

### 引用 &
引用运算符（&）, 也叫地址运算符，用来获取变量的地址。
引用是变量的别名，只是另一种访问相应变量存储的数据的方式。直接调用，避免将形参复制给形参，减少复制步骤的开销，极大地提高性能
```c
int original = 20;
int& ref = original; //指向相应变量所在的内存单元

//可避免复制步骤的函数
ReturnType DoSomething(Type& parameter);     //Parameter 不再是 argument 的拷贝，而是它的别名
ReturnType Result = DoSomething(argument);   //argument 是按引用传递的
//函数直接使用调用者栈中的数据

const int& constRef = original;  //使禁止通过引用修改它指向的变量的值
void GetSquare(const int& number, int& result)  //const 引用将参数标识为输入参数
void GetSquare(const int* const number, int* const result)  //效果同上，但指针不同于引用，可能为 NULL 或无效，因此使用前必须核实它们是有效的
```

## 9.类和对象
<u>现在开始面向对象</u>

### 类和对象 
将一系列数据和函数整合在一起的结构就是**类**,让您能够创建自己的数据类型，并在其中封装属性和使用它们的函数。
(*封装指的是将数据以及使用它们的函数进行逻辑编组，这是面向对象编程的重要特征*)

```c
//声明类, 使用关键字class
class Human
{
   string name;
   string age;
   void Talk()
   ...
}；         // ;结尾
```

在程序执行阶段，**对象**是类的化身。要使用类的功能，通常需要创建其实例—对象，并通过对象访问成员方法和属性。

```c
//创建 Human 的对象
Human Man;  //Man是Human类的对象，是运行阶段的化身

//可使用 new 为 Human 对象动态地分配内存
Human* Woman = new Human(); // dynamically allocated Human 
delete Woman; // de-allocating memory 
```

+ 句点运算符 (.) 用于访问对象的属性
   ```c
   Man.age= "23";
   Man.Talk();

   Human* Woman = new Human(); 
   (*Woman).Talk();
   ```

+ 指针运算符（->）访问成员
   ```c
   Human* Woman = new Human(); 
   Woman->age = "22";
   Woman->Talk();
   delete Woman;
   ```
例：
```c
#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
   string name;
   int age;
   void Talk()
   { cout << "I am " + name <<", " << age <<   " years old" << endl;
   }
};

int main()
{
   Human Man;
   Man.name = "wyj";
   Man.age = 23;

   Human Woman;
   Woman.name = "girl";
   Woman.age = 22;

   Man.Talk();
   Woman.Talk();
}

//output:
I am wyj, 23 years old
I am girl, 22 years old
```

### 关键字 public 和 private
在面向对象编程语言中，抽象是一个非常重要的概念, 作为类的设计者，使用 C++关键字 public 和 private 来指定哪些部分可从外部（如 main( )）访问，哪些部分不能。
private私有属性和方法，访问和修改的唯一的途径就是通过类的public公有方法，这个以编写类的程序员认为的合适方式暴露。
```c
class Human 
{ 
private:
   int age; 

public: 
   void SetAge(int humansAge) 
   { 
      if (humansAge > 0) 
      age = humansAge; 
   } 

   int GetAge()
   {
      if(age > 30)
         return(age - 2)   //隐藏实际数据
      else
         return age;
   }
}; 
```

### 构造函数
构造函数是一种特殊的函数，它与类同名且不返回任何值，在实例化对象时被调用。

**声明和实现**
```c
//在类声明中实现
class Human 
{ 
public: 
   Human()  
   { 
   // constructor code here 
   } 
}；

//在类声明外实现
class Human 
{ 
public: 
 Human(); // constructor declaration 
}; 
// constructor implementation (definition) 
Human::Human() //::被称为作用域解析运算符。例如，Human::dateOfBirth 指的是在 Human 类中声明的变量 dateOfBirth，而::dateOfBirth 表示全局作用域中的变量 dateOfBirth
{ 
 // constructor code here 
}
```

**构造函数总是在创建对象时被调用**，这让构造函数是将类成员变量（int、指针等）**初始化为选定值**的理想场所。
与函数一样，构造函数也可重载，创建对象时提供不同的参数会调用不同的构造函数，（*可在不提供参数的情况下调用的构造函数被称为**默认构造函数***）
```c
class Human 
{ 
private: 
 string name; 
 int age; 

public: 
 Human(string humansName, int humansAge = 25) 
 { 
 name = humansName; 
 age = humansAge; 
 cout << "Overloaded constructor creates " << name; 
 cout << " of age " << age << endl; 
 } 
 // ... other members 
}; 

//实例化这个类时，可使用下面的语法：
Human adam("Adam"); // adam.age is assigned a default value 25 
Human eve("Eve", 18); // eve.age is assigned 18 as specified
```
另一种初始化成员的方式是使用**初始化列表**, 冒号后面列出了各个成员变量及其初始值, 可以将上下代码对比着看：
```c
class Human 
{ 
private: 
 string name; 
 int age; 

public: 
 // two parameters to initialize members age and name 
 Human(string humansName, int humansAge) 
 :name(humansName), age(humansAge) 
 { 
 cout << "Constructed a human called " << name; 
 cout << ", " << age << " years old" << endl; 
 } 
// ... other class members 
};
```

### 析构函数
也是一种特殊的函数，与类同名，但前面有一个腭化符号（～）
构造函数在实例化对象时被调用，而析构函数在**对象销毁时**自动被调用。

**声明和实现**
```c
//在类声明中实现（定义）
class Human 
{ 
public: 
 ~Human() 
 { 
 // destructor code here 
 } 
}; 

//在类声明外定义
class Human 
{ 
public: 
 ~Human(); // destructor declaration 
}; 

Human::~Human() 
{ 
 // destructor code here 
} 
```
每当对象不再在作用域内或通过 delete 被删除进而被销毁时，都将调用析构函数。这使得析构函数成为*重置*变量以及*释放*动态分配的内存和其他资源的理想场所
如：某个类中，在构造函数中new, 在析构函数中delete, 使该类不仅对程序员隐藏了内存管理实现，还正确地释放了分配的内存。
（*析构函数不能重载*）

### 复制构造函数
浅复制的问题：*复制类的对象时*，将复制其指针成员，但不复制指针指向的缓冲区，其结果是两个对象指向同一块动态分配的内存。销毁其中一个对象时，delete[]释放这个内存块，导致另一个对象存储的指针拷贝无效。这种复制被称为浅复制，会威胁程序的稳定性

因此使用复制构造函数确保*深复制*，这是一个重载的构造函数，每当**对象被复制时**，编译器都将调用复制构造函数。
```c
class MyString 
{ 
   private:...
   public:
   MyString(const char* initString)
   ...
   MyString(const MyString& copySource) // copy constructor 
   {  //使用 const，可确保复制构造函数不会修改指向的源对象
   // Copy constructor implementation code 
   }
}; 

//以确保在main中函数调用时进行深复制
MyString sayHello("Hello world！");
UseMyString(sayHello);  //自动调用复制构造函数
```
(*类包含原始指针成员（char\* 等）时，务必编写复制构造函数和复制赋值运算符。
务必将类成员声明为 std::string 和智能指针类（而不是原始指针），因为它们实现了复制构造函数，可减少工作量。*)

移动构造函数 `MyString(MyString&& moveSource) `：编译器将自动使用它来“移动”临时资源，从而避免深复制
### 构造函数和析构函数的其他用途
禁止类对象被复制：声明一个私有的复制构造函数 `private: President(const President&);`

只能有一个实例的单例类：使用关键字 `static`
```c
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
```
禁止在栈中实例化的类(栈空间通常有限): 将析构函数声明为私有的
```c
class MonsterDB 
{ 
private: 
 ~MonsterDB(); // private destructor 
 //... members that consume a huge amount of data 
}; 
通过声明私有的析构函数，可禁止像下面这样创建实例：
int main() 
{ 
 MonsterDB myDatabase; // compile error 
 // … more code 
 return 0; 
} 
```
使用构造函数进行类型转换：
```c
class Human 
{ 
 int age;  // 私有成员变量 age，表示人的年龄
public: 
 Human(int humansAge): age(humansAge) {}  // 构造函数，接受人的年龄作为参数并初始化成员变量 age
}; 

// Function that takes a Human as a parameter 
void DoSomething(Human person) 
{ 
 cout << "Human sent did something" << endl;  // 输出信息
 return;  // 返回
}

int main()
{
 Human kid(10);  //利用构造函数显式转换：将整数 10 转换为 Human 类型对象
 //在这里，通过构造函数 Human(int humansAge) 创建了一个名为 kid 的 Human 类型对象，传递整数值 10 作为构造函数的参数。
 //这个构造函数被用来创建 Human 类型对象，并将整数 10 转换为 kid 的一个属性，即年龄
 DoSomething(kid);  // 调用 DoSomething 函数，将 kid 作为参数传递
 return 0;

 //隐式转换:
 Human anotherKid = 11; // int converted to Human 
 DoSomething(10); // 10 converted to Human! 
}
 //使用关键字 explicit 可禁止隐式转换，使上面两行编译失败:
 explicit Human(int humansAge): age(humansAge) {}
```

**this 指针** :  在类中，关键字 this 包含当前对象的地址,当您在类成员方法中调用其他成员方法时，编译器将隐式地传递 this 指针—函数调用中不可见的参数 
`Talk("Bla bla"); // same as Talk(this, "Bla Bla") `
*this表示当前对象的指针。它是一个特殊的指针，指向类的实例或对象自身

**sizeof( )** ： 指出类声明中所有数据属性占用的总内存量，单位为字节 （结果受字填充word padding和其他因素的影响）

**关键字 struct** 来自 C 语言，在 C++编译器看来，它与类及其相似，差别在于程序员未指定时，默认的访问限定符（public 和 private）不同，不同于结构，类的成员默认为私有
```c
//C++ Class
class Human
{
private:
   int age;
   bool gender;
   MyString name;

public:
   Human(const MyString& InputName, int InputAge, bool InputGender)
      : name(InputName), age (InputAge), gender(InputGender) {}

   int GetAge ()
   { return age; }
};

//C struct, 除非指定了，否则结构中的成员默认为公有的, 另外，除非指定了，否则结构以公有方式继承基结构
struct Human 
{ 
 Human(const MyString& humansName, int humansAge, bool humansGender) 
 : name(humansName), age (humansAge), Gender(humansGender) {} 

 int GetAge () 
 { 
 return age; 
 } 

private: 
 int age; 
 bool gender; 
 MyString name; 
};

//结构 Human 与类 Human 很像；结构的实例化与类的实例化也很像：
Human firstMan("Adam", 25, true); // an instance of struct Human
```

**声明友元**： 使用关键字 friend ，从外部访问类的私有数据成员和方法
```c
private: 
   friend void DisplayAge(const Human& person); //指出DisplayAge( )是 Human 类的友元，能够访问Human类的私有数据成员
   //friend class Utility; //指出 Utility 类是 Human 类的友元
   ...

void DisplayAge(const Human& person) 
   { 
   cout << person.age << endl; 
   } 
```

**共用体**：使用关键字 union声明，是一种特殊的类，每次只有一个非静态数据成员处于活动状态。在结构中，常使用共用体来模拟复杂的数据类型
```c
union UnionName 
{ 
 Type1 member1; 
 Type2 member2; 
…
};
//实例化并使用共用体：
UnionName unionObject; 
unionObject.member2 = value; // choose member2 as the active member

//在结构中，常使用共用体来模拟复杂的数据类型
struct  ComplexType
{
    enum DataType //使用枚举来存储信息类型
    {
        Int,
        Char
    }Type;

    union Value   //使用共用体来存储实际值
    {
        int num;
        char alphabet;

        Value() {}
        ~Value() {}
    }value;
};
```
**聚合初始化**：即满足如下条件的类或结构为聚合类型，可作为一个整体进行初始化：只包含公有和非静态数据成员，而不包含私有或受保护的数据成员；不包含任何虚成员函数；只涉及公有继承（不涉及私有、受保护和虚拟继承）；不包含用户定义的构造函数。
```c
struct Aggregate2 
{ 
 int num; 
 char hello[6]; 
 int impYears[5]; 
}; 

//对于这个结构，可像下面这样进行初始化：
Aggregate2 a2 {42, {'h', 'e', 'l', 'l', 'o'}, {1998, 2003, 2011, 2014, 2017}};
```
定义常量表达式的关键字 **constexpr** 也可用于类和结果为常量的对象
`constexpr Human(int humansAge) :age(humansAge) {}`

## 10.实现继承
面向对象编程基于 4 个重要方面：封装、抽象、继承和多态。继承是一种强大的属性重用方式，是通向多态的跳板.

### 继承和派生
继承: 从一个包含通用属性且实现了通用功能的基类（超类）派生出类似的类，并在派生类（子类）中覆盖基本功能，以实现让每个类都独一无二的行为。

**公有继承 public**：
```c
class Base 
{ 
 // ... base class members 
}; 
class Derived: public Base    //public：公有继承，is-a关系，可通过派生类的对象来访问基类的公有成员
{ 
 // ... derived class members 
}; 

```


**基类初始化** 向基类传递参数: 如果基类包含重载的构造函数，需要在实例化时给它提供实参,就使用初始化列表，并通过派生类的构造函数调用合适的基类构造函数
```c
class Base 
{ 
public: 
 Base(int someNumber) // overloaded constructor 
 { 
 // Use someNumber 
 } 
}; 

class Derived: public Base 
{
public: 
 Derived(): Base(25) // instantiate Base with argument 25 
 { 
 // derived class constructor code 
 } 
};    
```

**覆盖基类**: 派生类实现从基类继承的函数，且返回值和特征标相同的情况
```c
class Base 
{ 
public: 
 void DoSomething() 
 { 
 // implementation code… Does something 
 } 
}; 

class Derived:public Base 
{ 
public: 
 void DoSomething() 
 { 
 // implementation code… Does something else 
 //也可以用作用域解析运算符（::）在派生类中调用基类方法
   Base::DoSomething   
 } 
}; 

//调用基类中被覆盖的方法
int main()
{
   Derived test;
   test.DoSomething();     //被覆盖
   test.Base::DoSomething; //未覆盖，调用基类中的方法
}

//隐藏问题：覆盖可能导致派生类隐藏基类的所有重载版本，使调用重载产生编译错误（被隐藏）
//可使用关键字 using 避免隐藏基类方法
```
构造顺序：基类对象在派生类对象之前被实例化，实例化时，先实例化成员属性，再调用构造函数；析构顺序正好相反。

**私有继承 private**
私有继承使得只有子类才能使用基类的属性和方法，继承派生类的类不能访问基类的成员, 因此也被称为 *has-a* 关系, 指定派生类的基类时使用关键字 private：
```c
class Base 
{ 
 // ... base class members and methods 
}; 
class Derived: private Base // private inheritance  类的继承关系默认为私有
{ 
 // ... derived class members and methods 
}; 
```

**保护继承 protected**
继承派生类的类能够访问基类的公有和保护方法，但不能通过派生类的对象来访问基类的公有成员；
使用访问限定符 protected: 对需要继承的基类属性进行保护,让基类的某些属性能在派生类中访问，但不能在继承层次结构外部访问
```c
class Derived: protected Base
//...
//子类的子类能够访问 Base 类的公有和保护成员:
class Derived2: protected Derived 
{ 
 // can access public & protected members of Base 
}; 
```

切除（slicing）问题: 复制对象时不要按值传递参数，而应以指向基类的指针或 const 引用的方式传递

多继承: 
```c
class Derived: public Base1, publice Base2 
{ 
 // class members 
};
```
使用 final 禁止继承: `class Derived final: public Base1, publice Base2 `

> 要建立 is-a 关系，务必创建公有继承层次结构。
要建立 has-a 关系，务必创建私有或保护继承层次结构。(仅当必要时才使用私有或保护继承)
无论继承关系是什么，派生类都不能访问基类的私有成员。一个例外是类的友元函数和友元类

## 11.多态
面向对象编程的核心——多态
多态：将派生类对象视为基类对象，并执行派生类的实现

**虚函数 virtual**
使用虚函数实现多态行为
```c
class Base 
{ 
 virtual ReturnType FunctionName (Parameter List); 
}; 
class Derived 
{ 
 ReturnType FunctionName (Parameter List); 
}; 
```
使用关键字 virtual, Swim( )被声明为虚函数，确保编译器调用覆盖版本
对于将被派生类覆盖的基类方法，务必将其声明为虚函数。

作用：对于使用 new 在自由存储区中实例化的派生类对象，如果将其赋给基类指针，并通过该指针调用 delete，将不会调用派生类的析构函数。这可能导致资源未释放、内存泄露等问题，因此可将**析构函数声明为虚函数**
```c
class Base 
{ 
public: 
 virtual ~Base() {}; // virtual destructor 
}; 
```

**抽象基类和纯虚函数**
不能实例化的基类被称为抽象基类，这样的基类只有一个用途，那就是从它派生出其他类（充当接口）。在 C++中，要创建抽象基类，可声明纯虚函数。
```c
class AbstractBase 
{ 
public: 
 virtual void DoSomething() = 0; // pure virtual method 
}; 
//该声明告诉编译器，AbstractBase 的派生类必须实现方法 DoSomething()：
class Derived: public AbstractBase 
{ 
public: 
 void DoSomething() // pure virtual fn. must be implemented 
 { 
 cout << "Implemented virtual function" << endl; 
 } 
}; 
```
抽象基类提供了一种非常好的机制，能够声明所有派生类都必须实现的函数。如果 Trout 类从Fish 类派生而来，但没有实现 Trout::Swim( )，将无法通过编译

**虚继承 virtual**
使用**虚继承**解决菱形问题：在继承层次结构中，继承多个从同一个类派生而来的基类时，如果这些基类没有采用虚继承，将导致二义性，因此，如果派生类可能被用作基类，派生时最好使用*虚继承*：
```c
class Derived1: public virtual Base 
{ 
 // ... members and functions 
}; 
```
> 用于创建继承层次结构和声明基类函数时，关键字 virtual 的作用不同:
在函数声明中，virtual 意味着当基类指针指向派生对象时，通过它可调用派生类的相应函数。
从 Base 类派生出 Derived1 和 Derived2 类时，如果使用了关键字 virtual，则意味着再从Derived1 和 Derived2 派生出 Derived3 时，每个 Derived3 实例只包含一个 Base 实例。

表明覆盖意图的限定符 **override** , 来核实被覆盖的函数在基类中是否被声明为虚的
```c
class Tuna:public Fish 
{ 
public: 
 void Swim() const override // Error: no virtual fn with this sig in Fish 
 { 
 cout << "Tuna swims!" << endl; 
 } 
}; 
```
在派生类中声明要覆盖基类函数的函数时，务必使用关键字 override。

使用 **final** 来禁止覆盖函数, 被声明为 final 的虚函数，不能在派生类中进行覆盖
```c
class Tuna:public Fish 
{ 
public: 
 void Swim() override final  // override Fish::Swim and make this final 
 { 
 cout << "Tuna swims!" << endl; 
 } 
};//可继承这个版本的 Tuna 类，但不能进一步覆盖函数 Swim()
```

虚函数 Clone 模拟虚复制构造函数：
```c
#include <iostream>        //头文件
using namespace std;     //名称空间

class Fish     //定义Fish类作为基类
{
   public:
      virtual Fish* Clone()=0;   //声明一个纯虚函数Clone 用于克隆对象
      virtual void Swim()=0;     //声明一个纯虚函数Swim
      virtual ~Fish() {};     //声明虚析构函数
};

class Tuna: public Fish    //定义Tuna类，继承自Fish
{
   public:
      Fish* Clone() override  //实现Clone函数，返回一个克隆对象指针
      {
         return new Tuna (*this);   //*this表示当前对象的指针
      }

   void Swim() override final //final使它的派生类无法覆盖swim
   {
      cout << "Tuna swims fast in the sea" << endl;
   }
};

class BluefinTuna final:public Tuna // 定义BluefinTuna类，继承自Tuna
{
   public:
      Fish* Clone() override  //无法覆盖Tuna类中的Swim函数
      {//调用 Swim()时执行 Tuna::Swim()
         return new BluefinTuna(*this);
      }
};

class Carp final: public Fish // 定义Carp类，继承自Fish
{
   Fish* Clone() override{
      return new Carp(*this);
   }
   void Swim() override final  // 实现Carp的Swim函数
   {
      cout << "Carp swims slow in the lake" << endl;
   }
} ;

int main()
{
   const int ARRAY_SIZE =4;

   Fish* myFishes[ARRAY_SIZE]={NULL};  //声明静态基类指针（Fish *）数组，创建对象
   myFishes[0]=new Tuna();
   myFishes[1]=new Carp();
   myFishes[2]=new BluefinTuna();
   myFishes[3]=new Carp();

   Fish* myNewFishes[ARRAY_SIZE];
   for (int index=0; index < ARRAY_SIZE; ++index)
      myNewFishes[index]=myFishes[index]->Clone(); // 使用Clone函数克隆原对象到另一个数组

   for (int index=0; index<ARRAY_SIZE; ++index)
      myNewFishes[index]->Swim();   // 调用克隆对象的Swim函数，以验证 Clone( )复制了整个派生类对象

   for (int index=0; index<ARRAY_SIZE; ++index)
      {  // 释放内存
         delete myFishes[index];
         delete myNewFishes[index];
      }

      return 0;
}
```














------------------------------------------------------------------
------------------------------------------------------------------

# Cmake
[CMake](www.cmake.org) 是一个跨平台的开源构建管理系统，用于自动化应用程序的构建、测试和打包过程。它使用类似于Makefile的文本文件来描述构建过程中所需的所有组件和依赖项，并将其转换为适合各种不同编译器和操作系统的本地构建系统的配置文件。总之，CMake就是一个将多个cpp,hpp文件组合构建为一个大工程的语言。
[CMake下载](https://cmake.org/download/) (Linux无需下载)
[Cmake 实践](https://github.com/gavinliu6/CMake-Practice-zh-CN) 在实践中上手的教程
[cmake-examples-Chinese](https://github.com/SFUMECJF/cmake-examples-Chinese) 例程

[C-coding/Cmake at main · Arrowes/C-coding](https://github.com/Arrowes/C-coding/tree/main/Cmake)

## [Cmake 实践](https://gavinliu6.github.io/CMake-Practice-zh-CN/#/)

### t1 [创建Hello world](https://github.com/gavinliu6/CMake-Practice-zh-CN/blob/master/hello-world.md)
建立main.c与CMakeLists.txt并编译（需要为每一个子目录建立一个CMakeLists.txt）
```sh
PROJECT (HELLO)     #PROJECT(projectname [CXX] [C] [Java])
SET(SRC_LIST main.c)    #提供要编译的源代码文件列表，可定义多个源文件main.c 1.c
MESSAGE([SEND_ERROR|STATUS|FATAL_ERROR] "message to display")
ADD_EXECUTABLE(hello ${SRC_LIST})   #创建名为hello的可执行文件，IF不用${}引用变量

#内部编译(在文件夹中产生文件太多)
cmake . #构建工程，生成makefile
make    #构建目标文件hello二进制
./hello #运行目标文件
#外部编译(out of source build,推荐)
mkdir build && cd build #新建并进入build文件夹
cmake ..    #在父目录找到cmakelists构建工程
make    #在build编译目录中获得目标文件，不影响原有工程
```
目标文件:在linux下，是ELF格式（Executable Linkable Format，可执行可链接格式），而在windows下是PE（Portable Executable，可移植可执行）。通常有三种形式：
 + 可执行目标文件。即我们通常所认识的，可直接运行的二进制文件。
 + 可重定位目标文件。包含了二进制的代码和数据，可以与其他可重定位目标文件合并，并创建一个可执行目标文件。
 + 共享目标文件。它是一种在加载或者运行时进行链接的特殊可重定位目标文件。

### t2 [完善项目并安装](https://github.com/gavinliu6/CMake-Practice-zh-CN/blob/master/better-hello-world.md)
```sh
#在CMakeLists中加入
ADD_SUBDIRECTORY(src bin) #把src子目录加入工程，编译输出路径为bin
INSTALL(FILES COPYRIGHT README DESTINATION doc)
INSTALL(PROGRAMS runhello.sh DESTINATION bin)
INSTALL(DIRECTORY doc/ DESTINATION doc) #不同的安装类型
#在 src的 CMakeLists.txt中添加，以安装hello到bin中
INSTALL(TARGETS hello RUNTIME DESTINATION bin) 

#Install
cmake -DCMAKE_INSTALL_PREFIX=tmp ..
make
make install
```
### t3 [lib静态库和动态库构建](https://github.com/gavinliu6/CMake-Practice-zh-CN/blob/master/static-and-dynamic.md)

```sh
SET(LIBHELLO_SRC hello.c)
ADD_LIBRARY(hello SHARED ${LIBHELLO_SRC})   #SHARED动态库（.so）
ADD_LIBRARY(hello_static STATIC ${LIBHELLO_SRC})    #STATIC静态库(.a) 
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")  #设置静态库名称，以得到名字相同的.so .a
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1) #动态库版本号 
INSTALL(TARGETS hello hello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib) #关键字ARCHIVE 特指静态库，LIBRARY 特指动态库，RUNTIME 特指可执行目标二进制
INSTALL(FILES hello.h DESTINATION include/hello)
```
静态库.a（Static Library），所有函数和数据都在编译时被静态链接到可执行文件中。文件较大，但不容易受到环境变量和库版本变化的影响，能够提供更好的性能和稳定性。
动态库.so（Dynamic Library）（共享库），在程序运行时才被加载到内存中，而不是在程序编译时被静态链接到可执行文件中，每个动态库只需要一个副本，可以供多个程序使用，因此可以减小可执行文件的大小，减少内存占用，并且如果库文件更新，则只需要替换动态库文件即可，但由于需要在运行时加载库文件，因此可能会稍微降低程序的启动和运行速度。

### t4 [使用外部共享库和头文件](https://github.com/gavinliu6/CMake-Practice-zh-CN/blob/master/the-use-of-lib-and-header-file.md)
```sh
#在src/CMakeLists.txt中添加头文件.h搜索路径
INCLUDE_DIRECTORIES(XXX/include/hello)
TARGET_LINK_LIBRARIES(main XXX/lib/libhello.so) #添加共享库链接
#若要链接静态库：TARGET_LINK_LIBRARIES(main XXX/lib/libhello.a)

#运行ldd查看链接情况
ldd src/main

#修改环境变量，在bash中运行：
export CMAKE_INCLUDE_PATH=XXX/include/hello #然后利用FIND_PATH相关指令替换INCLUDE_DIRECTORIES
```
### [常用变量与环境变量](https://github.com/gavinliu6/CMake-Practice-zh-CN/blob/master/common-var.md)
```sh
#常用变量
CMAKE_BINARY_DIR    #如果是 in source 编译，指工程顶层目录，如果是 out-of-source 编译，指工程编译发生的目录,还有PROJECT_BINARY_DIR，<projectname>_BINARY_DIR
CMAKE_SOURCE_DIR    #工程顶层目录，PROJECT_SOURCE_DIR，<projectname>_SOURCE_DIR
CMAKE_CURRENT_SOURCE_DIR    #当前处理的 CMakeLists.txt 所在的路径
CMAKE_CURRRENT_BINARY_DIR   #若是 in-source 编译，同上一致，对out-ofsource 编译，他指的是 target 编译目录。
CMAKE_CURRENT_LIST_FILE #输出调用这个变量的 CMakeLists.txt 的完整路径
CMAKE_CURRENT_LIST_LINE #输出这个变量所在的行
CMAKE_MODULE_PATH       #定义自己的 cmake 模块所在的路径
EXECUTABLE_OUTPUT_PATH，LIBRARY_OUTPUT_PATH #分别用来重新定义最终结果的存放目录，如SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
PROJECT_NAME    #返回通过 PROJECT 指令定义的项目名称

#环境变量，使用$ENV{NAME} 调用系统环境变量
SET(ENV{变量名} 值) #设置环境变量
    CMAKE_INCLUDE_CURRENT_DIR
    CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE
    CMAKE_INCLUDE_PATH，CMAKE_LIBRARY_PATH
```

### [cmake常用指令](https://github.com/gavinliu6/CMake-Practice-zh-CN/blob/master/common-directives.md)
```sh
make VERBOSE=1  #查看make过程
make clean  #清理工程
```
### [t5,t6 模块](https://github.com/gavinliu6/CMake-Practice-zh-CN/blob/master/module.md)
```sh
#系统预定义的模块
FIND_PACKAGE(CURL)  #FindCURL模块
IF(CURL_FOUND)  #判断模块是否被找到
   INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
   TARGET_LINK_LIBRARIES(curltest ${CURL_LIBRARY})
ELSE(CURL_FOUND)
     MESSAGE(FATAL_ERROR ”CURL library not found”)
ENDIF(CURL_FOUND)

#自定义FindHELLO模块
FIND_PATH(HELLO_INCLUDE_DIR hello.h /usr/include/hello /usr/local/include/hello)    # 在指定目录中搜索hello.h文件
FIND_LIBRARY(HELLO_LIBRARY NAMES hello PATH /usr/lib /usr/local/lib)    # 在指定目录中搜索名为hello的库文件
IF(HELLO_INCLUDE_DIR AND HELLO_LIBRARY) # 如果找到了头文件和库，则标记为HELLO_FOUND
   SET(HELLO_FOUND TRUE)
ENDIF(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
IF(HELLO_FOUND) # 如果找到了头文件和库，则输出一个消息
   IF(NOT HELLO_FIND_QUIETLY)   #如果没有被标记为“安静模式”，则输出
       MESSAGE(STATUS "Found Hello: ${HELLO_LIBRARY}")
   ENDIF(NOT HELLO_FIND_QUIETLY)
ELSE(HELLO_FOUND)   # 如果没有找到，并且被标记为必需，则输出错误信息
   IF(HELLO_FIND_REQUIRED)  #如果被标记为“必需”，则输出致命错误消息
      MESSAGE(FATAL_ERROR "Could not find hello library")
   ENDIF(HELLO_FIND_REQUIRED)
ENDIF(HELLO_FOUND)
```
## Cmake Opencv Demo
**1.安装OpenCV**
```
git clone https://github.com/opencv/opencv.git
cd opencv
#cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..   #cmake把opencv的一些库和可执行文件安装到系统目录下 需要权限
cmake -DCMAKE_INSTALL_PREFIX=$HOME/opencv .. #本地安装无需权限
make -j8 #使用8个线程进行编译,否则很久
make install   #安装库文件

#配置OpenCV环境变量
export LD_LIBRARY_PATH=/home/ywang85/opencv/lib:$LD_LIBRARY_PATH  #链接库文件
export PKG_CONFIG_PATH=/home/ywang85/opencv/lib/cmake/opencv4/:$PKG_CONFIG_PATH  #链接配置文件
```
**2.写主程序**
<details>
  <summary>边缘提取程序</summary>

```c
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <iostream>
using namespace cv;
using namespace std;

int threshold_value = 100, threshold_max = 255;
int threshold_type = 0, threshold_type_max = 4;
string outwindow = "threshold img";
Mat src, dst;
int main(){
   Mat src1;
   src1 = imread("1.jpg");
   resize(src1, src, Size(src1.cols, src1.rows)); 
   //resize(src1, src, Size(src1.cols/2, src1.rows/2)); //缩小一半
   if (!src.data){
      printf("cannot load image ...");
      return -1;
   }
   Mat src_gray;
   cvtColor(src, src_gray, COLOR_BGR2GRAY);
   Canny(src_gray, dst, 100, 200);//canny边缘检测算子
   imwrite("canny.jpg", dst);
   imwrite("canny2.jpg", ~dst); //dst按照像素值取反
   return 0;
}
```
</details>

使用OpenCV的canny算子检测边缘

**3.写CMake**
```c
cmake_minimum_required(VERSION 2.8)
project(EDGE)
set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/opencv/lib/cmake/opencv4/") #设置 OpenCV 的 CMake 路径
find_package(OpenCV REQUIRED)
add_executable(EDGE main.cpp)
target_include_directories(EDGE PUBLIC ${OpenCV_INCLUDE_DIRS})  #头文件路径添加到编译器的include路径中
target_link_libraries(EDGE PUBLIC ${OpenCV_LIBS})   #链接OpenCV库
#需要注意opencv库的链接
```
**4.编译运行**
```c
mkdir build && cd build
cmake ..
make  #生成可执行文件
./EDGE   #运行边缘提取执行文件
```
<img src="https://raw.sevencdn.com/Arrowes/Arrowes-Blogbackup/main/images/Cedge.png" width="50%">


## 基于VScode用cmake搭建C++编译调试环境
1. 安装VScode插件：C/C++，cmake，cmake tools
2. 按F1，选择cmake:Quick Start,创建一个cmake工程
3. 点击左侧栏的CMake工具按钮,右键可执行文件，选择Debug,进入调试界面


## gcc/g++,MinGW/MSVC与make/CMake/qmake
**GNU**/Linux：简称Linux，包括Ubuntu，Debian，CentOS，自带gcc； 
**gcc/g++** ：GNU编译器套件（GNU Compiler Collection）,在*Linux*或MacOS上使用，gcc主要用于C语言,g++支持更多的C++特性。

**MinGW**(Minimalist GNUfor Windows)，是*Windows*下运行的GNU环境，包含gcc和一系列工具，让开发者在Windows下可以写GNU的c/c++代码, 编译的结果是windows的可执行文件exe；
**MSVC**:微软开发的C/C++编译器，在*Windows*下编译C/C++程序。它被集成在Visual Studio IDE中。

**Makefile**包含了描述如何编译和链接程序的规则和指令,指定哪些文件需要先编译，后编译以及重新编译，甚至更复杂的功能操作,通常被用于自动化构建C/C++项目;
**Make**是一个自动化构建工具，执行Make命令时，它会读取Makefile中的规则，并根据依赖项关系来判断哪些规则需要被执行，来实现编译、链接等操作。
**CMake**是一个跨平台的自动化构建工具，与Make类似，但是它不直接构建项目，而是生成适合不同构建系统的配置文件，如Makefile或Visual Studio的.sln文件，并调用相应的构建系统来进行项目构建。
**qmake**是Qt框架提供的自动化构建工具，用于构建Qt项目。