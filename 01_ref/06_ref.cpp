#include <iostream>

using namespace std;

void test01(int &p) { // int* const p = &a;
    p = 30; // *p = 30;
}

/*
    1.引用的本质是指针常量

    指针常量，不可变的指针变量
        int* const p = &a;
    常量指针，指向常量的指针
        int  const *p = &a;
    只读指针
        int const * const p = &a;
*/
int main() {

    int a = 10;
    cout << a << endl;

    // 2.指针常量必须初始化，且指向不能改变，但指向的值可以改变
    int &p = a; // int* const p = &a;
    cout << p << endl;

    p = 20; // *p = 20
    cout << a << endl;

    test01(a);
    cout << a << endl;

    return 0;
}
