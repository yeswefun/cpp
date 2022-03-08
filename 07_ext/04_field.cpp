#include <iostream>

using namespace std;

class A {
public:
    A() {
        a = 100;
    }
    void show() {
        cout << "A::show()" << endl;
    }
    void test() {
        cout << "A::test()" << endl;
    }
    int a;
};

/*
    子类中存在与父类同名的成员，不会发生覆盖
*/
class B : public A {
public:
    B() {
        a = 200;
    }
    void show() {
        cout << "B::show()" << endl;
    }
    int a;
};

/*
    子类非静态成员与父类非静态成员同名
        就近原则
        $ cl /d1 reportSingleClassLayoutB test2.cpp
*/
int main() {
    B b;
    cout << b.a << endl;
    cout << b.A::a << endl;
    
    // 存在与子类同名的方法，则直接调用
    b.show();
    b.A::show();

    // 不存在与子类同名的方法，则调用子类的
    b.test();
    b.A::test();
    
    return 0;
}
