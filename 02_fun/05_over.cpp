#include <iostream>

using namespace std;

/*
    函数重载: 函数名相同，参数列表不同，必须在同一作用域
        与函数返回值类型无关
*/
void test() {
    cout << "no arg" << endl;
}
void test(int a) {
    cout << "int arg: " << a << endl;
}
void test(double a) {
    cout << "double arg: " << a << endl;
}

/*
    必须在同一作用域

    与函数返回值类型无关
*/
class Demo {
    void test() {}
};

/*
    函数返回值类型不可以作为函数重载的条件

    int demo();
    float demo();

    int max(int x, int y);
    float max(int x, int y);
*/

/*
    int add(int x, int y);
    double add(double x, double y);
*/
int main() {
    test();
    test(6);
    test(3.14);
    return 0;
}
