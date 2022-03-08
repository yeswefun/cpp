#include <iostream>

using namespace std;

class Safe {

// 友元函数 - 访问类中的私有成员
friend void testFriend(Safe *s);

public:
    Safe() {
        this->a = 0;
        this->b = 0;
    }
public:
    int a;
private:
    int b;
};

// 全局友元函数
void testFriend(Safe *s) {
    cout << "testFriend start" << endl;
    cout << s->a << endl;
    cout << s->b << endl;
    cout << "testFriend end" << endl;
}

/*
    全局函数作友元函数
*/
int main() {
    Safe s;
    testFriend(&s);
    return 0;
}
