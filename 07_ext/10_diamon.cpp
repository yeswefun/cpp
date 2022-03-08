#include <iostream>

using namespace std;

class A {
public:
    int id;
};

class B: public A {
};

class C: public A {
};

/*
    菱形继承：基类A中的属性id在类B与类C中都保留了一份
*/
class D: public B, public C {
};

/*
    多继承的问题二：菱形继承

    $ cl /d1 reportSingleClassLayoutD test4.cpp
*/
int main() {
    D d;
    // error: request for member ‘id’ is ambiguous
    //cout << d.id << endl;
    d.B::id = 10;
    d.C::id = 20;
    cout << d.B::id << endl; // 10
    cout << d.C::id << endl; // 20
    return 0;
}
