#include <iostream>

using namespace std;

/*
    一个类默认创建: 无参构造，析构，拷贝构造，赋值运算符（简单值传递）
*/
class Test {
public:
    Test() {
        this->id = -1;
        cout << "construct: " << id << endl;
    }
    Test(const Test &t) {
        cout << "copy: " << t.id << endl;
        this->id = t.id;
    }
    Test(int id) {
        this->id = id;
        cout << "construct@id: " << id << endl;
    }
    ~Test() {
        cout << "destruct: " << id << endl;
    }
    int id;
};

/*
    一个类默认创建: 默认构造，析构，拷贝构造，赋值运算符（简单值传递）
*/
int main() {
    Test t1(10);
    Test t2(0);
    t2 = t1;
    cout << t2.id << endl; // 10
    Test tt[3]; // 中括号
    cout << "***************************" << endl;
    int a = 10;
    int b = 20;
    int c = 30;
    c = b = a;
    cout << c << endl; // 10
    cout << "***************************" << endl;
    return 0;
}
