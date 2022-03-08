#include <iostream>

using namespace std;

/*
    1.引用必须使用一块有效的内存空间初始化
*/
void test00() {
    // error: cannot bind non-const lvalue 
    // reference of type ‘int&’ to an rvalue of type ‘int’
    //int &a = 10;     // err, int &a; a是可变的
    const int &a = 10; // ok, const int &a; a是不可变的
}

/*
    2.不能返回局部变量的引用
*/
int& test01() {
    int a = 10;
    // warning: reference to local variable ‘a’ returned
    // return a;
    
    static int b = 20; // return b is ok
    return b;
}

/*
    静态局部变量只会初始化一次，随程序运行结束而结束生命周期
*/
int& test02() {
    static int a = 10;
    ++a;
    return a;
}

int main() {

    // 静态局部变量只会初始化一次，随程序运行结束而结束生命周期
    cout << test02() << endl;
    cout << test02() << endl;
    cout << test02() << endl;

    int &c = test02();
    cout << c << endl; // 14

    // 3.如果函数返回值是引用，那么这个函数可以作为左值
    test02() = 20;
    cout << c << endl; // 20
    
    return 0;
}
