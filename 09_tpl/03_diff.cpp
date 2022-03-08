#include <iostream>

using namespace std;

template<class T>
T add_t(T x, T y) {
    return x + y;
}

int add_int(int x, int y) {
    return x + y;
}

/*
    普通函数与函数模板的区别

        1.普通函数可以进行隐式类型转换

        2.模板函数不可以进行隐式类型转换
*/
int main() {
    int a = 10;
    int b = 10;
    char c = 'a';

    cout << add_t(a, b) << endl;
    cout << add_int(a, b) << endl;

    // 1.普通函数可以进行隐式类型转换
    cout << add_int(a, c) << endl;  // 107

    // 2.模板函数不可以进行隐式类型转换
    // error: no matching function for call to ‘add_t(int&, char&)’
    //add_t(a, c);

    return 0;
}
