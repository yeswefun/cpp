#include <iostream>

using namespace std;

void test(int a = 6) {
    cout << "test - with default arg" << endl;
}

void test() {
    cout << "test - with no arg" << endl;
}

/*
    函数重载与函数默认参数

    无法解决，应该感避免这样使用
*/
int main() {
    // error: call of overloaded ‘test()’ is ambiguous
    // test();
    return 0;
}
