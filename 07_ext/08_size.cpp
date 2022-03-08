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
        b = 20;
    }
    ~B() {
        cout << "B#destruct" << endl;
    }
    int b;
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
    多继承
*/
int main() {
    cout << sizeof(C) << endl; // 12
    C c;
    return 0;
}
