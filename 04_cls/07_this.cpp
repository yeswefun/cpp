#include <iostream>

using namespace std;

class Dog {
public:
    // this可以解决命名冲突
    Dog(int id) {
        //id = id;
        this->id = id;
    }
    // 链式调用
    Dog& test0(int id) {
        this->id += id;
        cout << "test01: " << this->id << endl;
        return *this;
    }
    Dog& test1(int id) {
        this->id += id;
        cout << "test02: " << this->id << endl;
        return *this;
    }
    int id;
};

/*
    应该返回引用类型
*/
int main() {
    Dog dog(10);
    cout << "main: " << dog.id << endl;
    dog.test0(10).test1(20);
    cout << "main: " << dog.id << endl;	// fix: 40
    return 0;
}
