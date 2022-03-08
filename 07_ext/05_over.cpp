#include <iostream>
using namespace std;

class A {
public:
    /*
        重载函数需要在同一作用域
    */
    void test() {
        cout << "A::test()" << endl;
    }
    void test(int a) {
        cout << "A::test()@" << a << endl;
    }
};

class B : public A {
public:
    //  error: no matching function for call to ‘B::test(int)’
    void test() {
        cout << "B::test()" << endl;
    }
};

/*
    子类同名成员函数会让父类的所有同名成员函数隐藏conceal掉
*/
int main() {
    B b;
    // error: no matching function for call to ‘B::test(int)’
    //b.test(6);
    b.A::test(6);
    return 0;
}
