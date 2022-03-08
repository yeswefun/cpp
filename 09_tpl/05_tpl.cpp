#include <iostream>

using namespace std;

// 编译器依据函数模板生成不同的模板函数
template<class T>
void test(T a) {
    cout << "template: " << typeid(T).name() << endl;
}
/*
    模板为STL作铺垫
    
    声明时编译, 生成模板函数后再编译

    //test(6); 编译器生成以下函数 - 模板函数
    void test(int a) {
        cout << "template" << endl;
    }

    //test(3.14); 编译器生成以下函数 - 模板函数
    void test(float a) {
        cout << "template" << endl;
    }
*/
int main() {
    test(6);	// template: i
    test(3.14); // template: d
    return 0;
}
