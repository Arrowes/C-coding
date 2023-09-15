#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr(10);
    string temp;
    cout << "输入任意数，按q退出" << endl;
    for (int i = 0; i <arr.size(); i++) {
        cout << "输入第" << i + 1 << "个数：";
        cin >> temp;
        if (temp == "q")
            break;
        arr[i] = stoi(temp);
    }

    int start = 0;
    int end = arr.size() - 1;
    cout << "原数组: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    cout << "逆置数组: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
