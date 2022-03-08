#include <iostream>

using namespace std;

class A {
public:
    virtual int test() = 0; // 纯虚函数
};

class B : public A {
public:
    int test() {return 0;}
};

/*
    存在纯虚函数的基类，称为"抽象类"
    抽象类不能实例化
    抽象类的子类只重写部分纯虚函数，那么子类也是抽象类
    抽象类的子类重写所有纯虚函数，那么子类不再是抽象类，而是一个普通类
*/
int main() {
    //A a;
    // error: cannot declare variable ‘b’ to be of abstract type ‘B’
    B b;
    return 0;
}
