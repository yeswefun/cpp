#include <iostream>

using namespace std;

template <class T>
class A {
public:
    T a;
};

// 若B不是类模板，则必须指定T的具体类型，否则编译器无法分配内存
class B : public A<int> {};

// 若C是类模板，则可以不指定T的具体类型，而是用模板参数占位
template <class T1, class T2>
class C : public A<T2> {
public:
    C() {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
    T1 c;
};

/*
    类模板与继承
*/
int main() {
    C<float, int> c;
    return 0;
}
