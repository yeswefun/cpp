#include <iostream>

using namespace std;
//#pragma pack(1)

// 成员属性与成员函数分开存储
class Dog {
public:
    int m_a;                // 非静态成员变量，属于对象
    void test_a() {}        // 非静态成员函数，不属于对象
    static int m_b;         // 静态成员变量，不属于对象
    static void test_b() {} // 静态成员函数，不属于对象
    double m_c;             // 非静态成员变量，属于对象
};

class Cat {

};

/*
    非静态成员变量，属于对象
*/
int main() {
    // 空类的大小为1
    // 每一个实例对象都有一个独一无二的地址, char维护了这个地址
    cout << sizeof(Cat) << endl;    // 1

    cout << sizeof(Dog) << endl;    // 16

    Dog dog;
    cout << sizeof(dog) << endl;    // 16
    return 0;
}
