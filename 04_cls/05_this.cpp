#include <iostream>

using namespace std;

class Dog {
public:
    // this指针指向被调用的成员函数的所属对象
    // 编译器会为非静态成员函数自动添加相应类类型的this
    void show() {
        cout << this << endl;
    }
};

/*
    this - 指向当前对象的指针

    因为类的方法是所有对象共享的，所以必须有东西能区分到底是谁正在调用当前方法
*/
int main() {
    Dog d1;
    Dog d2;
    d1.show();
    d2.show();
    return 0;
}
