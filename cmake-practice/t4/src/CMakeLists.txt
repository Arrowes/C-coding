ADD_EXECUTABLE(main main.c)
#在src/CMakeLists.txt中添加头文件搜索路径
INCLUDE_DIRECTORIES(/home/ywang85/c/cmake/t3/build/t3/include/hello)
TARGET_LINK_LIBRARIES(main /home/ywang85/c/cmake/t3/build/t3/lib/libhello.so)