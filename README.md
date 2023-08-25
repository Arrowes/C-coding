---
title: C, C++, Cmake
date: 2023-05-16 09:43:00
tags:
- C/C++
---
项目地址：[C-coding](https://github.com/Arrowes/C-coding)
# C
[C Primer Plus(第六版)中文版](https://img.anfulai.cn/bbs/94810/C%20Primer%20Plus(%E7%AC%AC%E5%85%AD%E7%89%88)%E4%B8%AD%E6%96%87%E7%89%88.pdf)

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







------------------------------------------------------------------

# Cmake
[CMake](www.cmake.org) 是一个跨平台的开源构建管理系统，用于自动化应用程序的构建、测试和打包过程。它使用类似于Makefile的文本文件来描述构建过程中所需的所有组件和依赖项，并将其转换为适合各种不同编译器和操作系统的本地构建系统的配置文件。总之，CMake就是一个将多个cpp,hpp文件组合构建为一个大工程的语言。
[CMake下载](https://cmake.org/download/) (Linux无需下载)
[Cmake 实践](https://github.com/gavinliu6/CMake-Practice-zh-CN) 在实践中上手的教程
[cmake-examples-Chinese](https://github.com/SFUMECJF/cmake-examples-Chinese) 例程

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
CMAKE_MODULE_PATH   #定义自己的 cmake 模块所在的路径
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