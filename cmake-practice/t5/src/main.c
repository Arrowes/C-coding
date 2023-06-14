#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *fp; // 文件指针，用于存储下载的内容

// 回调函数，将下载的数据写入文件
int write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int written = fwrite(ptr, size, nmemb, (FILE *)fp); // 将数据写入文件中
    return written;
}

int main()
{
    const char * path = "/tmp/curl-test"; // 保存文件的路径
    const char * mode = "w"; // 打开文件的模式（写入）
    fp = fopen(path, mode); // 打开文件
    curl_global_init(CURL_GLOBAL_ALL); // 初始化curl库
    CURLcode res; // curl操作结果
    CURL *curl = curl_easy_init(); // 创建一个curl句柄
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com"); // 设置下载地址
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // 设置回调函数，将下载内容写入文件
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1); // 设置curl输出详细信息
    res = curl_easy_perform(curl); // 执行curl操作
    curl_easy_cleanup(curl); // 清理curl句柄
}
