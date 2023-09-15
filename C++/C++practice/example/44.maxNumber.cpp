#include <iostream>
using namespace std;

int main() {
    int arr[5]={0,1,2,3,4};
    cout<<"输入五个数"<<endl;
    for(int i=0; i<5;i++){
        cout << "输入第" << i+1 <<"个数：";
        cin >> arr[i];
    }
    int max=0;

    for(int i=0;i<5;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<"最大值是：" << max << endl;
}