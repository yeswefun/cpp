#include <iostream>

using namespace std;

class A {
public:
    static void test() {
        cout << "A::test" << endl;
    }
    static void test(int a) {
        cout << "A::test@" << a << endl;
    }
};

class B : public A {
public:
    // error: no matching function for call to ‘B::test(int)’
    static void test() {
        cout << "B::test" << endl;
    }
};

/*
    子类静态成员与父类静态成员同名

    子类同名静态成员函数会让父类的所有同名静态成员函数隐藏conceal掉
        就近原则
*/
int main() {
    // 就近原则
    B::test();
    // error: no matching function for call to ‘B::test(int)’
    //B::test(6);
    A::test();
    A::test(6);
    B::A::test();
    B::A::test(6);
    return 0;
}
