#include <iostream>
using namespace std;

/*
    提前声明，让编译器知道有这个类型的存在

    指针的大小是固定的 32位 4字节，64位 8字节
*/
class Safe;


class User {
public:
    User();
    void test();
private:
    // 此处应该只能使用指针，不能使用非指针，因为编译器无法知道Safe的大小???
    Safe *safe;
};


class Safe {
/*
    单方向: User -> Safe
    不传递: A -> B; B -> C; but A x-> C
    友元函数 - 访问类中的私有成员
*/
friend void User::test();

public:
    Safe() {
        this->a = 666;
        this->b = 888;
    }
public:
    int a;
private:
    int b;
};


User::User() {
    this->safe = new Safe;
}

void User::test() {
    cout << this->safe->a << endl;	// 666
    // error: ‘int Safe::b’ is private within this context
    cout << this->safe->b << endl;	// 888

    this->safe->a = 6;
    this->safe->b = 8;
    cout << this->safe->a << endl;	// 6
    cout << this->safe->b << endl;	// 8
}

/*
    另一个类的成员函数作为友元成员
*/
int main() {
    User User;
    User.test();
    return 0;
}
