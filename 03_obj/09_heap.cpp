#include <iostream>

using namespace std;

class User {
public:
    User() {
        cout << "User()" << endl;
    }
    ~User() {
        cout << "~User()" << endl;
    }
};

void test00() {
    // warning: deleting ‘void*’ is undefined
    //void *p = new User;
    // 当void*接受new返回的堆内存时，会出现无法调用析构的问题
    //delete p;
}

int main() {

    // stack
    User u;

    // heap
/*
    new X
    会返回指向X的指针
    会自动调用构造函数, malloc不会自动调用构造函数
    new是一个运算符
*/
    User *pu = new User;
/*
    delete X
    会释放堆内存空间
    会自动调用析构函数, free不会自动调用析构函数
    delete是一个运算符
*/
    delete pu;

    return 0;
}
