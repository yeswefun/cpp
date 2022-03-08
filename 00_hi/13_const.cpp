#include <iostream>

using namespace std;

/*
    cpp中的const全局变量默认是内部链接（只能在声明的文件内使用）
*/
int main() {
    // undefined reference to `a'
    //extern const int a;
    extern const int b;
    cout << "b = " << b << endl;	// 888
    extern int c;
    cout << "c = " << c << endl;	// 999
    return 0;
}
