#include <iostream>

using namespace std;

/*
    用普通变量初始化const变量
*/
int main() {
    int a = 10;
    const int b = a;
    cout << a << endl;  // 10
    cout << b << endl;	// 10
    int *p = (int*) &b;
    *p = 20;
    cout << a << endl;  // 10
    cout << b << endl;  // 20
    return 0;
}
