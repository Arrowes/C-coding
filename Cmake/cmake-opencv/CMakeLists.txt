cmake_minimum_required(VERSION 2.8)
project(EDGE)
set(OpenCV_DIR "/home/ywang85/opencv/lib/cmake/opencv4") #设置 OpenCV 的 CMake 路径
find_package(OpenCV REQUIRED)
add_executable(EDGE main.cpp)
target_include_directories(EDGE PUBLIC ${OpenCV_INCLUDE_DIRS})  #头文件路径添加到编译器的include路径中
target_link_libraries(EDGE PUBLIC ${OpenCV_LIBS})   #链接OpenCV库
