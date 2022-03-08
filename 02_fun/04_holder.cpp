#include <iostream>

using namespace std;

// 占位参数必须提供，若有默认值，则可以不传，但是无法使用
void test00(int a, int) {
    cout << "@a: " << a << endl;
}

// 占位参数必须提供，若有默认值，则可以不传，但是无法使用
void test01(int a, int=-1) {
    cout << "#a: " << a << endl;
}

/*
    函数的占位参数
    最主要的作用是在于区分符号重载时，到底是前缀还是后缀
*/
int main() {
    test00(888, -1);
    test01(666);
    test01(666, -2);
    return 0;
}
