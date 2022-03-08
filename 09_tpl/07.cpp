#include <iostream>

using namespace std;

class A {
public:
    A(int id, string name) {
        this->id = id;
        this->name = name;
    }
    int id;
    string name;
};

template <class T>
bool compare_t(T &a, T &b) {
    return a == b;
}

/*
fix-2:
    具体化自定义数据类型
    若具体化能够匹配，则选择具体化
    语法: template<> 返回值 函数名<参数类型>(参数列表)
*/
template<> bool compare_t<A>(A &a, A &b) {
    return a.id == b.id && a.name == b.name;
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
