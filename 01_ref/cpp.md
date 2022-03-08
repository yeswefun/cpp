

## 使用注意

```cpp
// 引用变量必须初始化
void test01() {
    // error: ‘a’ declared as reference but not initialized
    //int &a;
}

// 引用变量初始化后，不能再作为其它变量的引用
void test02() {
    int a = 10;
    int &b = a;
    cout << b << endl; // 10
    // 下面的意思并不是为变量c起别名为b
    int c = 20;
    b = c; // 将变量c中的值赋给变量b
    cout << b << endl; // 20
}
```



```cpp
// 1. 引用必须使用一块有效的内存空间初始化
void test00() {
    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    //int &a = 10;     // err
    const int &a = 10; // ok, 都是常量
}


// 2. 不能返回局部变量的引用
int& test01() {
    int a = 10; // warning: reference to local variable ‘a’ returned
    static int b = 20; // return b is ok
    return a;
}

int& test02() {
    // 静态局部变量只初始化一次，随程序运行结束而结束生命周期
    static int a = 10;
    return a;
}

void test() {
    int &c = test02();
    cout << c << endl; // 10
    // 如果函数返回值是引用，那么这个函数可以作为左值
    test02() = 20;
    cout << c << endl; // 20
}
```



## 引用的本质

```cpp
// int* const p = &a;
void test01(int &p) {
    // *p = 20;
    p = 20;
}

// 引用的本质是指针常量
int main() {
    int a = 10;

    // 指针常量必须初始化，且指向不能改变，但指向的值可以改变
    // int* const p = &a;
    int &p = a;

    // *p = 20
    p = 20;
    return 0;
}
```




## 指针引用

```cpp
struct User {
    int id;
};

// 二级指针
void test01(User **p) {
    // **p - User
    //  *p - User*
    //   p - User**
    *p = (User*) malloc(sizeof(User));
    (*p)->id = 666;
}

void test00() {
    User *p = NULL;
    test01(&p);
    cout << p->id << endl;
}

// 指针引用
void test03(User* &p) {
    p = (User*) malloc(sizeof(User));
    p->id = 888;
}

void test02() {
    User *p = NULL;
    test03(p);
    cout << p->id << endl;
}
```





## 常量引用

```cpp
void test00() {
    //可变变量=不可变变量;
    //int &r = 10; // error

    // 指向一块栈上的内存空间
    const int &r = 10;
    //int tmp = 10;
    //const int &r = tmp;
    cout << r << endl;	// 10

    // error: assignment of read-only reference ‘r’
    //r = 10;

    int *p = (int*) &r; // no warning
    *p = 20;
    cout << r << endl;	// 20
}
```



```cpp
#include <iostream>
using namespace std;

// 常量引用用来修饰形参
void show(const int &val) {
    cout << val << endl;
    //val = 888; //error: assignment of read-only reference ‘val’
}

int main() {
    int a = 666;
    show(a);
    cout << a << endl;
    return 0;
}
```

