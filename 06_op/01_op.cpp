#include <iostream>

using namespace std;

class Test {
public:
    void operator()() {
        cout << "()" << endl;
    }
    void operator()(int a) {
        cout << "(): " << a << endl;
    }
    void operator()(string s) {
        cout << "(): " << s << endl;
    }
};

class Add {
public:
    int operator()(int x, int y) {
        return x + y;
    }
};

/*
    函数调用运算符()重载
*/
int main() {
    
    Test t;
    t();        // 仿函数
    t(6);       // 仿函数
    t("Jerry"); // 仿函数
    cout << "************************" << endl;

    Add add;
    cout << add(1, 2) << endl;
    cout << Add()(2, 3) << endl; // 匿名对象

    return 0;
}
