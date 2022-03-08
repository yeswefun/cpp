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
    Dog test0(int id) {
        this->id += id;
        cout << "test01: " << this->id << endl; // 20
        // 发生了拷贝构造
        return *this;
    }
    Dog test1(int id) {
        this->id += id;
        cout << "test02: " << this->id << endl; // 40
        // 发生了拷贝构造
        return *this;
    }
    int id;
};

/*
    this的基本使用
*/
int main() {
    Dog dog(10);
    cout << "main: " << dog.id << endl; // 10

    dog.test0(10).test1(20);            // 返回的是一个临时创建的对象
    cout << "main: " << dog.id << endl;	// 20 == 10 + 10，问题出现在上面的第二次调用(作用在临时对象上)
    return 0;
}
