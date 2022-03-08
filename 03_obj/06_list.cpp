#include <iostream>
using namespace std;

class Dog {
public:
/*
    Dog(int a, int b, int c) {
        m_a = a;
        m_b = b;
        m_c = c;
    }
*/
    // 参数初始化列表
    Dog(): Dog(0, 0) {}
    Dog(int a, int b): Dog(a, b, 0) {}
    Dog(int a, int b, int c): m_a(a), m_b(b), m_c(c) {}

    void show() {
        cout << m_a << "@" << m_b << "@" << m_c << endl;
    }
    int m_a;
    int m_b;
    int m_c;
};

/*
    使用 构造函数的参数列表 对 对象进行初始化
*/
int main() {
    Dog dog;
    dog.show();

    Dog dog2(10, 20);
    dog2.show();

    Dog dog3(10, 20, 30);
    dog3.show();
    return 0;
}
