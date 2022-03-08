#include <iostream>

using namespace std;

/*
类模板可以有默认类型
    template <class T1, class T2>
    template <class T1, class T2 = string>
    template <class T1 = int, class T2 = string>
*/
template <class T1, class T2 = string>
class Test {
public:
    Test(T1 id, T2 name) : id(id), name(name) {}
    void show() {
        cout << id << '-' << name << endl;
    }
    T1 id;
    T2 name;
};

/*
函数模板 / 类模板
    template<class T>在函数上 - 函数模板
    template<class T>在类上 - 类模板
*/
int main() {

    // 1.类模板不支持自动类型推导
    // error: missing template arguments before ‘t’
    // Test t(1, "Java");

    // 2.显示指定类型
    Test<int, string> t(1, "Java");
    t.show();
    
    // 3.存在默认类型时，可以不指定存在默认类型的参数
    Test<int> t2(1, "Java");
    t2.show();

    return 0;
}
