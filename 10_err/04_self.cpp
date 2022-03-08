#include <iostream>

using namespace std;

class MyException {
public:
    void printError() {
        cout << "custom exception" << endl;
    }
};

void test() {
    throw MyException(); // 匿名对象
}

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