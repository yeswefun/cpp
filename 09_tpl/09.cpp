#include <iostream>

using namespace std;

class Test1 {
public:
    void show1() {
        cout << "test1" << endl;
    }
};

class Test2 {
public:
    void show2() {
        cout << "test2" << endl;
    }
};

template <class T>
class Demo {
public:
    void test1() {
        obj.show1();
    }
    void test2() {
        obj.show2();
    }
    T obj;
};

/*
    成员函数的创建时机

    成员函数：一开始不会创建出来，而是在运行时才去创建
*/
int main() {
    Demo<Test1> d1;
    d1.test1(); //ok
    // d1.test2(); //err

    Demo<Test2> d2;
    d2.test2(); //ok
}
