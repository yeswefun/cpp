#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A#construct" << endl;
    }
    ~A() {
        cout << "A#destruct" << endl;
    }
};

// 常用继承模式: public
class B : public A {
public:
    B() {
        cout << "B#construct" << endl;
    }
    ~B() {
        cout << "B#destruct" << endl;
    }
};

/*
    子类会继承父类的成员属性，成员函数
    但不会继承父类的构造，析构，operator=, 只有父类知道如何构造它自己
*/
int main() {
    B b;
    return 0;
}
