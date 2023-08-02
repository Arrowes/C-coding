 #include <iostream> 
using namespace std; 

int main() 
 { 
    int startValue = 101; 
    cout << "原数据： " << startValue << endl; 
    
    int postfixIncrement = startValue++; 
    cout << "后缀左值： " << postfixIncrement << endl; 
    cout << "后缀右值： " << startValue << endl; 

    startValue = 101; // Reset 
    int postfixIncrement2 = ++startValue; 
    cout << "前缀左值：" << postfixIncrement2 << endl; 
    cout << "前缀右值： " << startValue << endl; 

    return 0;
 }