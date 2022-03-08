#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A#construct" << endl;
        a = 10;
    }
    ~A() {
        cout << "A#destruct" << endl;
    }
    int a;
};

class B {
public:
    B() {
        cout << "B#construct" << endl;
        a = 20;
    }
    ~B() {
        cout << "B#destruct" << endl;
    }
    int a;
};

class C : public A, public B {
public:
    C() {
        cout << "C#construct" << endl;
        c = 30;
    }
    ~C() {
        cout << "C#destruct" << endl;
    }
    int c;
};

/*
    多继承的问题一：属性同名
*/
int main() {
    cout << sizeof(C) << endl; // 12
    C c;
    // error: request for member ‘a’ is ambiguous
    //cout << c.a << endl;
    cout << c.A::a << endl;
    cout << c.B::a << endl;
    return 0;
}
