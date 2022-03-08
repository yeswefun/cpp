#include <iostream>
using namespace std;

class Safe {

/*
    单方向: User -> Safe
    不传递: A -> B; B -> C; but A x-> C
    友元函数 - 访问类中的私有成员
*/
friend class User;

public:
    Safe();
public:
    int a;
private:
    int b;
};

class User {
public:
    User();
    void test();
private:
    Safe *safe;
};

// Safe的无参构造实现
Safe::Safe() {
    this->a = 666;
    this->b = 888;
}

// User的无参构造实现
User::User() {
    this->safe = new Safe;
}
// User的test方法实现
void User::test() {
    cout << this->safe->a << endl;	// 666
    // error: ‘int Safe::b’ is private within this context
    cout << this->safe->b << endl;	// 888
}

/*
    另一个类作为友元成员
*/
int main() {
    User User;
    User.test();
    return 0;
}
