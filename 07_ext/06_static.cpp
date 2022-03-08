#include <iostream>

using namespace std;

class A {
public:
    static int a;
};
// 静态成员属性:类内声明，类外初始化
int A::a = 6;


class B : public A {
public:
    static int a;
};
// 静态成员属性:类内声明，类外初始化
int B::a = 8;


/*
    子类静态成员与父类静态成员同名
    
    静态成员属性可以被子类继承下来
        就近原则
*/
int main() {
    // 就近原则
    cout << B::a << endl;
    cout << A::a << endl;
    cout << B::A::a << endl;
    return 0;
}
