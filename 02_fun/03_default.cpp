#include <iostream>

using namespace std;

// 函数的默认参数
void test00(int a = 0, int b = 0) {
    cout << "a: " << a << ", b: " << b << endl;
}

// 默认参数必须统一从右边开始
void test01(int a, int b = 0, int c = 0) {
    cout << "a: " << a << ", b: " << b <<  ", c: " << c << endl;
}

// 默认参数只能写在函数声明或定义
void test04(int a, int b, int c=666);
void test04(int a, int b, int c) {}

/*
    会优先向没有默认值的参数进行赋值
*/
int main() {

    test00();		// 0	0
    test00(10);		// 10	0
    test00(10, 20); // 10	20
    cout << "***************************" << endl;

    test01(10);			// 10	0	0
    test01(10, 20);		// 10	20	0
    test01(10, 20, 30);	// 10	20	30

    return 0;
}
