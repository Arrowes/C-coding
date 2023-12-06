# 在指定目录中搜索hello.h文件
FIND_PATH(HELLO_INCLUDE_DIR hello.h /usr/include/hello /usr/local/include/hello)

# 在指定目录中搜索名为hello的库文件
FIND_LIBRARY(HELLO_LIBRARY NAMES hello PATH /usr/lib /usr/local/lib)

# 如果找到了头文件和库，则标记为HELLO_FOUND
IF(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
   SET(HELLO_FOUND TRUE)
ENDIF(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)

# 如果找到了头文件和库，则输出一个消息
IF(HELLO_FOUND)
   IF(NOT HELLO_FIND_QUIETLY)   #如果没有被标记为“安静模式”，则输出
       MESSAGE(STATUS "Found Hello: ${HELLO_LIBRARY}")
   ENDIF(NOT HELLO_FIND_QUIETLY)
# 如果没有找到，并且被标记为必需，则输出错误信息
ELSE(HELLO_FOUND)
   IF(HELLO_FIND_REQUIRED)  #如果被标记为“必需”，则输出致命错误消息
      MESSAGE(FATAL_ERROR "Could not find hello library")
   ENDIF(HELLO_FIND_REQUIRED)
ENDIF(HELLO_FOUND)
