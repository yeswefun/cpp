#include <iostream>

using namespace std;

class User {
public:
    User() {
        cout << "+++" << endl;
    }
    // 若没有&，则外面的User对象赋值给参数User对象, 此时发生了拷贝构造的调用
    // User u1 = u2;相当于 User u1(u2);
    // User u = u2;相当于 User u(u2);
    // ...
    User(const User &u) {
        /*
            触发拷贝构造的方式
                User u = u2;
                User u = User(u2); // 此时传到构造里是 u = u2; 此时又触发构造(如果没有&)
        */
        id = u.id;
        cout << "copy+++" << endl;
    }
    ~User() {
        cout << "---" << endl;
    }
    int id;
};


// 1.用已创建的对象来初始化新的对象
void test00() {
    User u1;
    u1.id = 666;
    User u2(u1); // User u2 = u1;
}


// 2.以值传递的方式给函数参数传值,相当于 User u = u1;
void test01(User u) {}	// 此处会触发拷贝构造

void test02(User &u) {} // 此处不会触发拷贝构造


// 3.以值的方式返回局部对象 - 这里没有调用拷贝构造（debug / release）
// g++ x.cpp -fno-elide-constructors -o x && ./x
User test03() {
    User u1; // 调用默认构造
    cout << "test03" << endl;
    return u1; // 返回时，因为值拷贝，所以会调用拷贝构造
}

/*
    拷贝[构造]调用时机, 定义并赋值
        1.作为函数参数 - 值拷贝
        2.作为函数返回值 - 值拷贝
        3.定义新的对象并使用一个已经存在的对象赋值 - 值拷贝

    $ g++ x.cpp -fno-elide-constructors -o x.out && ./x.out
*/
int main() {
    // User u3;      //不调用默认构造
    // test03(u3);
    // void test03(User &u) {
    //      User u1; //调用默认构造
    // }
    User u3 = test03(); // 调用拷贝构造
    cout << "main" << endl;

    // 只有在初始化时才会调用构造
    // 先声明，后赋值不会调用拷贝构造
    User u;
    u = u3; // operator=

    // 下面也不会调用拷贝构造
    User *u5 = new User();
    User *u6 = u5;

    return 0;
}
