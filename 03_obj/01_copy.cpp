#include <iostream>

using namespace std;

//按照参数分类: 无参构造(默认构造)，有参数构造
//按照类型分类: 普通构造，拷贝构造
class User {
public:
    // 构造与析构必须是public才能被自动调用
    User() {
        this->id = 0;
        cout << "+++: " << this << " # " << id << endl;     // this->id
    }
    User(int id) {
        this->id = id;
        cout << "+++: " << this << " # " << id << endl;     // id, 参数
    }
    // 析构
    ~User() {
        cout << "---: " << this << " # " << id << endl;     // this->id
    }
    //拷贝构造
    User(const User &u) {
        id = u.id;
        cout << "copy+++: " << this << " # " << id << endl; // this->id
    }

    int id;
};


void test00() {
    User u;
    u.id = 10;
    User u2(1);
    User u3(u);
    cout << u.id << endl;   // 10
    cout << u3.id << endl;  // 10
}

void test01() {
    User u4; // 默认构造不要加()
    // User u4(); // 编译器认为下面为函数声明
}

void test02() {
    // 将匿名对象User()赋给u4
    User u4 = User(); // 默认
    User u5 = User(u4); // 拷贝

    User();	// 若没有将匿名对象赋给变量，则执行完该行就会被释放
    
    // 不能使用拷贝构造函数初始化匿名对象
    // error: redeclaration of ‘User u5’
    //User(u5); // 编译器认为该行是User u5，对象声明
    
    // 但是User(u5)可以写成右值
    User u6 = User(u5);
}

void test03() {
    // 相当于User u7 = User(100);
    User u7 = 100;
    // 相当于User u8 = User(u7);
    User u8 = u7;
}

/*
    拷贝构造函数
    $ g++ x.cpp -fno-elide-constructors -o x.out && ./x.out

    构造函数
    User();     // 若没有将匿名对象赋给变量，则执行完该行就会被释放
    User u = User();
    User u = User(10);
    User u = User(u2);

    User u(10);
    User u(u2);

    User u = 10; // User u = User(10);
    User u = u2; // User u = User(u2);

    User u;     //变量定义，默认构造
    User(u);    //变量定义，默认构造
    User u();   //函数声明
*/
int main() {
    test00();
    cout << "************************************" << endl;

    test01();
    cout << "************************************" << endl;
    
    test02();
    cout << "************************************" << endl;
    
    test03();
    return 0;
}
