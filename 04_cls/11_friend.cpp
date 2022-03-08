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
    Safe() {
        this->a = 666;
        this->b = 888;
    }
public:
    int a;
private:
    int b;
};

class User {
public:
    User() {
        this->safe = new Safe;
    }
    void test() {
        cout << this->safe->a << endl;	// 666
        // error: ‘int Safe::b’ is private within this context
        cout << this->safe->b << endl;	// 888
    }
private:
    Safe *safe;
};

/*
    另一个类作为友元成员
*/
int main() {
    User User;
    User.test();
    return 0;
}
