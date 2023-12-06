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