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
    throw MyException(); // 匿名对象
}

/*
    异常的一般写法 - 引用

情况一
    MyException(): 0xdd5cb0
    ---> Copy
    custom exception
    ~MyException(): 0x61fe0f
    ~MyException(): 0xdd5cb0
情况二
    MyException(): 0xfd5cb0
    custom exception
    ~MyException(): 0xfd5cb0
*/
int main() {

    try {
        test();
    // } catch (MyException e) { // 开辟了新的内存空间
    } catch (MyException &e) { // 使用原来的匿名异常对象
        e.printError();
    } catch (...) {
        cout << "main: other error" << endl;
    }

    return 0;
}