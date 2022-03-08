#include <iostream>

using namespace std;


class User {
public:
    User() {}

    static void test() {
        cout << "test" << endl;
        User::test2();
        // a nonstatic member reference must be relative to a specific object
        // test3();
    }
    void test3() {
        cout << "test3" << endl;
    }
    int m_x;
    static int s_id;
private:
    static void test2() {
        cout << "private:test2" << endl;
    }
    static int s_code;
};

int User::s_id = 10;
int User::s_code = 20;

/*
    非静态函数可以访问所有成员
    静态函数只能访问静态成员

    静态成员函数
        不可以访问非静态属性，非静态方法 - 没有this

    静态成员函数可以访问其它静态属性，静态方法
*/
int main() {
    // 通过类名访问静态成员
    cout << User::s_id << endl;
    // error: ‘int User::s_code’ is private within this context
    //cout << User::s_code << endl;
    User::test();
    return 0;
}
