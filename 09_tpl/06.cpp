#include <iostream>

using namespace std;

class A {
public:
    A(int id, string name) {
        this->id = id;
        this->name = name;
    }
    // fix-1: 重载==运算符
    bool operator==(const A &o) {
        return this->id == o.id && this->name == o.name;
    }
    int id;
    string name;
};

template <class T>
bool compare_t(T &a, T &b) {
    return a == b;
}

/*
    函数模板 - 局限性
        无法对任何类型进行比较之类的操作
*/
int main() {

    // 比较普通类型
    int a = 10;
    int b = 20;
    cout << compare_t(a, b) << endl;

	// 比较自定义类型
    A aa(6, "Jerry");
    A bb(6, "Jerry");
    cout << compare_t(aa, bb) << endl;

    return 0;
}
