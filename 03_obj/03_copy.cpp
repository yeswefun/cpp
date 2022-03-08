#include <iostream>

using namespace std;

// 系统默认给一个类提供3个函数: 默认构造，拷贝构造，析构函数
// 系统提供的拷贝构造，只做简单的值拷贝
class Dog {
public:
/*
    Dog() {
        cout << "Dog" << endl;
    }
*/
    // 1.当提供了有参构造函数后，系统不再提供默认构造
    // 但系统还会提供默认拷贝构造函数
    Dog(int id) {
        this->id = id;
        cout << "Dog: " << id << endl;  // id, args
    }
    // 系统一定会提供析构函数
    int id;
};


class Cat {
    // 2.当提供了拷贝构造函数后，系统不再提供其它构造，但会提供析构
    Cat(const Cat &c) {
        cout << "copy" << endl;
    }
};

/*
    但提供有参数构造或拷贝构造时，系统就不会再提供默认构造

    $ g++ x.cpp -fno-elide-constructors -o x.out && ./x.out
*/
int main() {
    Dog g1(6);
    Dog g2(g1); // 拷贝构造
    cout << g2.id << endl;

    //no default constructor exists for class "Cat"
    // Cat cat;
    return 0;
}
