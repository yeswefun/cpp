#include <iostream>

using namespace std;

class A {
public:
    // 父类的virtual必须写上，子类的virtual可写可不写 
    virtual void test() {
        cout << "A::test()" << endl;
    }
    void demo() {
        cout << "A::demo()" << endl;
    }
};

class B : public A {
public:
    // void test() {}
    virtual void test() {
        cout << "B::test()" << endl;
    }
    void demo() {
        cout << "B::demo()" << endl;
    }
};

// 静态联编 - 编译阶段绑定
//    静态多态：函数重载
// 动态联编 - 运行阶段绑定
//    在继承结构中，基类A中将函数声明为虚函数
void test00(A &a) {
    // 父类的指针或引用指向子类对象
    a.test();
    a.demo();
}

/*
    静态多态：函数重载
*/
int main() {
    
    B b;
    test00(b);
    cout << "***************************" << endl;

    A a;
    test00(a);
    
    return 0;
}
