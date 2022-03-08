#include <iostream>
#include <cstring>

using namespace std;

/*
    虚析构 - 类可以实例化
    纯虚析构 - 类不可以实例化
*/
class A {
public:
    virtual void test() {
        cout << "A::test()" << endl;
    }
    // 虚析构
    /*virtual ~A() {
        cout << "~A()" << endl;
    }*/

    // 纯虚析构, 类内声明，类外实现
    // 类中存在纯虚析构函数时，该类也是抽象类
    // 抽象类不可以实例化
    virtual ~A() = 0;
};
A::~A() {
    cout << "virtual ~A()" << endl;
}

class B : public A {
public:
    B(const char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    virtual void test() {
        cout << "B::test()" << endl;
    }
    ~B() {
        if (this->name != NULL) {
            delete [] this->name;
            this->name = NULL;
        }
        cout << "~B()" << endl;
    }
    char *name;
};

/*
    纯虚析构
*/
int main() {
    A *a = new B("Jerry");
    a->test();
    // 在父类指针指向子类对象时，对父类指针进行delete并不会调用子类对象的析构
    // 解决 - 虚析构
    delete a;

    //抽象类不可以实例化
    //A a;
    return 0;
}
