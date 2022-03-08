#include <iostream>

using namespace std;

class A {
public:
    /*
        提供了有参构造，就不再提供默认构造
    */
    A(int a) {
        cout << "A::" << a << endl;
    }
};

/*
    子类实例化时，会先调用父类的无参构造，再调用本类构造
*/
class B : public A {
public:
    // error: no matching function for call to ‘A::A()’
    /*B() {
        cout << "B" << endl;
    }*/
    B() : A(6) {
        cout << "B" << endl;
    }
    /*
        初始化列表显示调用父类有参构造
    */
    B(int b) : A(b) {
        cout << "B" << endl;
    }
};

/*
    子类对象实例化时自动调用父类无参构造
*/
int main() {
    B b;
    B b2(8);
    return 0;
}
