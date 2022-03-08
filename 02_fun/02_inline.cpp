#include <iostream>

using namespace std;

/*
    类内部的成员函数默认是内联函数
    
    内联函数的声明与定义都要加inline
        inline void func();
        inline void func() {}
*/

inline int test00(int x, int y) {
    return x > y ? x : y;
}

int test01(int x, int y) {
    return x > y ? x : y;
}

/*
    macro: no scope
*/
int main() {

    int a = 20;
    int b = 10;
    cout << test01(++a, b) << endl;	// 21

    int x = 20;
    int y = 10;
    cout << test00(++x, y) << endl; // 21

    return 0;
}
