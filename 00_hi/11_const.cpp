#include <iostream>

using namespace std;

/*
    cpp中const修饰的局部变量无法改变 - 符号表?

    const修饰全局变量（存放在常量区），无论是在c或c++中都无法改变
*/
int main() {
    const int a = 123;
    cout << "a = " << a << endl; // 123
    // 编译器会临时分配内存空间
    // int tmp = a;
    // int *p = (int*) &tmp;
    // p指向的是临时开辟的内存空间，相当于以上两步
    int *p = (int*) &a; 
    // tmp = 321
    *p = 321;
    cout << "a = " << a << endl; // 123
    return 0;
}
