#include <iostream>

using namespace std;

class BaseException {
public:
    // virtual void printError();   // 虚函数不可省略函数体，但纯虚函数可以
    virtual void printError() {     // 虚函数
    }
    virtual void printError() = 0;  // 纯虚函数
};

class NullPointerException : public BaseException {
public:
    virtual void printError() {
        cout << "NullPointerException" << endl;
    }
};

class OutOfRangeException : public BaseException {
public:
    virtual void printError() {
        cout << "OutOfRangeException" << endl;
    }
};

void test() {
    // throw NullPointerException();
    throw OutOfRangeException();
}

/*
    异常 + 多态
*/
int main() {

    try {
        test();
    } catch (BaseException &e) {
        e.printError();
    } catch (...) {
        cout << "main: other error" << endl;
    }

    return 0;
}