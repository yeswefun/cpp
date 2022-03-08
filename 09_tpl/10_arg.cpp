#include <iostream>

using namespace std;

template <class T1, class T2>
class Test {
public:
    Test(T1 id, T2 name) : id(id), name(name) {}
    void show() {
        cout << id << " - " << name << endl;
    }
    T1 id;
    T2 name;
};

// 1.指定传入参数的类型
void test00(Test<int, string> &p) {
    p.show();
}

// 2.参数模板化
template <class T1, class T2>
void test01(Test<T1, T2> &p) {
    // 如何查看类型
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    p.show();
}

// 3.整体模板化
template <class T>
void test02(T &p) {
    cout << typeid(T).name() << endl;
    p.show();
}

/*
    类模板作为函数参数
*/
int main() {
    Test<int, string> t(6, "Java");
    test00(t);
    test01(t);
    test02(t);
    return 0;
}
