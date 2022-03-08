#include <iostream>

using namespace std;

class User {
public:
    User() {
        // 为什么不在构造中初始化静态成员, 
        // 每次有新对象构造，原来的值都会被重新赋值
        // 静态成员是所有对象共享的
        // s_id = 10;
    }
    int m_x;
    // 静态成员变量在类内声明，在类外初始化
    //static int s_id = 10;
    // 本类对象共享, 全局静态区
    static int s_id;
private:
    // 可以在类外初始化，但不能直接访问
    static int s_code;
};

int User::s_id = 10;
int User::s_code = 20;

/*
    静态属性
        类内声明，类外初始化

    静态成员属于类，所有类的实例共享同一份数据
*/
int main() {
    // 通过类名访问静态成员
    cout << User::s_id << endl;
    // error: ‘int User::s_code’ is private within this context
    //cout << User::s_code << endl;
    return 0;
}
