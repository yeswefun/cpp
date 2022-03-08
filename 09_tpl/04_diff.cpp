#include <iostream>

using namespace std;

// 模板函数
template<class T>
void test(T a) {
    cout << "void test(T a)" << endl;
}

template<class T>
void test(T a, T b) {
    cout << "void test(T a, T b)" << endl;
}

// 普通函数
void test(int a) {
    cout << "void test(int a)" << endl;
}

/*
    普通函数与模板函数
        若只有声明，没有定义，则报链接错误

    普通函数与函数模板的区别

        1.若普通函数与模板函数同时存在，则优先使用普通函数

        2.若需要强制使用模板函数，则使用空参列表<>

        3.函数模板可以重载

        4.若函数模板的匹配度高，则优先使用函数模板
*/
int main() {
    // 1.若普通函数与模板函数同时存在，则优先使用普通函数
    int a = 10;
    test(a);    // non-template
    test(10);   // non-template
    
    // 2.若需要强制使用模板函数，则使用空参列表<>
    test<>(10); // template

    // 3.函数模板可以重载
    test(6, 8); // template overload

    // 4.若函数模板的匹配度高，则优先使用函数模板
    char c = 'a';
    test(c);	// template，普通函数还需要隐式类型转换
    return 0;
}
