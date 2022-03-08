#include <iostream>

using namespace std;

class A {
public:
    // 菱形继承：虚基类使属性id只在基类A中保存一份数据
    int id = -1;
};

class B: virtual public A {
};

class C: virtual public A {
};

class D: public B, public C {
};

/*
    菱形继承问题的解决：虚继承
        操作同一份共享数据

    $ cl /d1 reportSingleClassLayoutD test4.cpp
    vbptr: virtual base pointer
*/
int main() {
    D d;
    // 操作同一份共享数据
    cout << d.id << endl;   // -1
    d.B::id = 10;
    cout << d.B::id << endl; // 10
    cout << d.C::id << endl; // 10
    d.C::id = 20;
    cout << d.B::id << endl; // 20
    cout << d.C::id << endl; // 20
    // vbtable
    return 0;
}
