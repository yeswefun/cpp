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

/*
    malloc, free 与 new, delete 的区别

    new X
    会返回指向X的指针
    会自动调用构造函数, malloc不会自动调用构造函数
    会自动进行类型转换， malloc必须强制类型转换
    new是一个运算符

    delete X
    会释放堆内存空间
    会自动调用析构函数, free不会自动调用析构函数
    delete是一个运算符
*/
int main() {
    
    User *pu = (User*)malloc(sizeof(User));
    free(pu);

    cout << "*********************" << endl;

    User *p = new User;
    delete p;

    return 0;
}
