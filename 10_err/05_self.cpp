#include <iostream>

using namespace std;

class MyException {
public:
    void printError() {
        cout << "custom exception" << endl;
    }
};

class Test {
public:
    Test() {
        cout << "Test(): " << this << endl;
    }
    ~Test() {
        cout << "~Test(): " << this << endl;
    }
};

void test() {

    /*
        从try开始到throw之前的栈上对象都会被释放 这个过程称为 栈解旋
    */
    Test t1;
    Test t2;

    throw MyException(); // 匿名对象
}

/*
    栈解旋 - unwinding
*/
int main() {

    try {
        test();
    } catch (MyException e) {
        e.printError();
    } catch (...) {
        cout << "main: other error" << endl;
    }

    return 0;
}