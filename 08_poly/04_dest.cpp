#include <iostream>
#include <cstring>

using namespace std;

class A {
public:
    virtual void test() { // 虚函数
        cout << "A::test()" << endl;
    }
    ~A() {
        cout << "~A()" << endl;
    }
};

class B : public A {
public:
    B(const char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    virtual void test() { // 子类的virtual可写可不写
        cout << "B::test()" << endl;
    }
    ~B() {
        if (this->name != NULL) {
            delete [] this->name;
            this->name = NULL;
        }
    }
    char *name;
};

/*
多态析构问题引出
    B::test()
    ~A()

在父类指针指向子类对象时，对父类指针进行delete并不会调用子类对象的析构
*/
int main() {
    A *a = new B("Jerry");
    a->test();
    // 在父类指针指向子类对象时，对父类指针进行delete并不会调用子类对象的析构
    delete a;
    return 0;
}
