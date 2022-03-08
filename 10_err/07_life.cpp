#include <iostream>

using namespace std;

class MyException {
public:
    MyException() {
        cout << "MyException(): " << this << endl;
    }
    MyException(const MyException &e) {
        cout << "---> Copy" << endl;
    }
    ~MyException() {
        cout << "~MyException(): " << this << endl;
    }
    void printError() {
        cout << "custom exception" << endl;
    }
};

void test() {
    // taking address of temporary
    //throw &MyException(); // 匿名对象，这是非法的栈地址了呀
    throw new MyException(); // 指针
}

/*
    异常的一般写法 - 引用

MyException(): 0x6b1ac0
custom exception
~MyException(): 0x6b1ac0
*/
int main() {

    try {
        test();
    // } catch (MyException e) { // 开辟了新的内存空间
    // } catch (MyException &e) { // 使用原来的匿名异常对象
    } catch (MyException *e) { // 指针
        e->printError();
        delete e;
    } catch (...) {
        cout << "main: other error" << endl;
    }

    return 0;
}