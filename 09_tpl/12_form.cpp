#include <iostream>

using namespace std;

// 类内形式
template <class T1, class T2>
class A {
public:
    A(T1 a, T2 b) : a(a), b(b) {}
    void show() {
        cout << a << "@" << b << endl;
    }
    T1 a;
    T2 b;
};

// 类外形式
template <class T1, class T2>
class B {
public:
    B(T1 a, T2 b);
    void show();
    T1 a;
    T2 b;
};

template <class T1, class T2>
B<T1, T2>::B(T1 a, T2 b) : a(a), b(b) {}

template <class T1, class T2>
void B<T1, T2>::show() {
    cout << a << "@" << b << endl;
}

/*
    类模板-类内/外成员函数的实现
*/
int main() {
    A<char, string> a('a', "hello");
    a.show();
    B<int, float> b(10, 3.14);
    b.show();
    return 0;
}
