---
title: C, C++, Cmake
date: 2023-05-16 09:43:00
tags:
- C/C++
---
# C++

## 基于VScode用cmake搭建C++编译调试环境
1. 安装VScode插件：C/C++，cmake，cmake tools
2. 按F1，选择cmake:Quick Start,创建一个cmake工程
3. 点击左侧栏的CMake工具按钮,右键可执行文件，选择Debug,进入调试界面

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

## gcc/g++,MinGW/MSVC与make/CMake/qmake
**GNU**/Linux：简称Linux，包括Ubuntu，Debian，CentOS，自带gcc； 
**gcc/g++** ：GNU编译器套件（GNU Compiler Collection）,在*Linux*或MacOS上使用，gcc主要用于C语言,g++支持更多的C++特性。

**MinGW**(Minimalist GNUfor Windows)，是*Windows*下运行的GNU环境，包含gcc和一系列工具，让开发者在Windows下可以写GNU的c/c++代码, 编译的结果是windows的可执行文件exe；
**MSVC**:微软开发的C/C++编译器，在*Windows*下编译C/C++程序。它被集成在Visual Studio IDE中。

**Makefile**包含了描述如何编译和链接程序的规则和指令,指定哪些文件需要先编译，后编译以及重新编译，甚至更复杂的功能操作,通常被用于自动化构建C/C++项目;
**Make**是一个自动化构建工具，执行Make命令时，它会读取Makefile中的规则，并根据依赖项关系来判断哪些规则需要被执行，来实现编译、链接等操作。
**CMake**是一个跨平台的自动化构建工具，与Make类似，但是它不直接构建项目，而是生成适合不同构建系统的配置文件，如Makefile或Visual Studio的.sln文件，并调用相应的构建系统来进行项目构建。
**qmake**是Qt框架提供的自动化构建工具，用于构建Qt项目。