PROJECT (HELLO)
SET(SRC_LIST main.c) #提供要编译的源代码文件列表。
MESSAGE(STATUS "This is BINARY dir" ${HELLO_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir" ${HELLO_SOURCE_DIR})
ADD_EXECUTABLE(hello ${SRC_LIST}) #创建名为hello的可执行文件