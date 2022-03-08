


头文件的包含名称

```
    //#include <stdlib.h>
    #inlucde <cstdlib>

    //#include <string.h>
    #include <cstring>

    //#include <time.h>
    #include <ctime>

    //#include <math.h>
    #include <cmath>
```


命名空间的总结

```
    命名空间可以防止命名冲突
    命名空间必须定义在全局作用域下
    命名空间可以嵌套命名空间
    同文件中同名命名空间可以合并
    可以存在匿名命名空间 - 相当于静态全局
    命名空间可以起别名
```



## 全局变量检测增强

```c
// 全局作用域下 - c
int a;
int a = 100;
```



```cpp
// 全局作用域下 - cpp
int a;
//int a = 100; // redefinition
```



## 函数检测增强

```c
// c可以省略参数类型与返回值类型
test00(x, y) {
}
// c语言不检测被调用函数的个数
test00(10, 20, 30);
```



```cpp
// c++必须明确参数类型与返回值类型
int test00(int x, int y) {
    return 0;
}
// c++检测被调用函数的个数
//test00(10, 20, 30);
```



## 类型转换增强

```c
void test02() {
    // malloc -> void*
    char *p = malloc(sizeof(int) * 3);
}
```



```cpp
void test02() {
    // malloc -> void*
    char *p = (char*) malloc(sizeof(int) * 3);
}
```



## 结构体增强

```c
struct User {
    int id;
    //void id_incr();
};

void test03() {
    // c语言必须写struct
    //User u; 	   // err
    struct User u; // ok 
}
```



```cpp
struct User {
    int id;
    void id_incr() {++id;}
};

void test03() {
    // c++可以不写struct
    User u;
    u.id = 666;
    u.id_incr();
    cout << u.id << endl;
}
```


## const修饰局部变量

```
const修饰局部变量:
	c语言: 伪常量，编译器会分配内存
	c++: 不分配内存
```



```c
void test01() {
    // const修饰局部变量 - 栈区
    const int a = 123;
    printf("a = %d\n", a);	// 123
    int *p = (int*) &a;
    *p = 321;
    printf("a = %d\n", a);	// 321
}
```



```cpp
// cpp中const修饰的局部变量无法改变 - 符号表?
void test01() {
    const int a = 123;
    cout << "a = " << a << endl; // 123
    // 编译器会临时分配内存空间
    // int tmp = a;
    // int *p = (int*) &tmp;
    // p指向的是临时开辟的内存空间，相当于以上两步
    int *p = (int*) &a; 
    // tmp = 321
    *p = 321;
    cout << "a = " << a << endl; // 123
}
```



```c
// c
void test02() {
    // error: variable-sized object may not be initialized
    const int size = 2;
    //int arr[size] = {0, 1};
    int arr[2] = {0, 1};
    printf("%d\n", arr[0]);
}
```



```cpp
// cpp
void test02() {
    const int size = 2;
    int arr[size] = {0, 1}; 
    cout << arr[0] << endl;
}
```



## const修饰全局变量

```
const修饰全局变量（存放在常量区），无论是在c或c++中都无法改变
```



```c
// test.h
const int a = 666;// c语言中默认是 extern const int a = 666;
```



```c
#include <stdio.h>
#include "test.h"

int main() {
    extern const int a;
    printf("a = %d\n", a);	// 666
    return 0;
}
```



```cpp
// test.h
// cpp中的const全局变量默认是内部链接（只能在声明的文件内使用）
const int a = 666;// c++中默认还是 const int a = 666;
extern const int b = 888;
int c = 999;
```



```cpp
#include <iostream>
#include "test.h"
using namespace std;

// cpp中的const全局变量默认是内部链接（只能在声明的文件内使用）
int main() {
    // undefined reference to `a'
    //extern const int a;
    extern const int b;
    cout << "b = " << b << endl;	// 888
    extern int c;
    cout << "c = " << c << endl;	// 999
    return 0;
}
```



## const分配内存情况

```cpp
// 对const变量&取地址
// 对const变量extern外部声明
void test00() {
    const int a = 666;
    int *p = (int*) &a; // 1) int tmp = a; 2) int *p = (int*) &tmp;
    *p = 888;		   // tmp = 888;	
    cout << a << endl;	// 666
}
```



```cpp
// 用普通变量初始化const变量
void test01() {
    int a = 10;
    const int b = a;
    cout << b << endl;	// 10
    // modified
    int *p = (int*) &b;	// 20
    *p = 20;
    cout << b << endl;
}
```



```cpp
// const修饰自定义数据类型会分配内存
struct User {
    //User() {}
    int id;
    string name;
};

void test02() {
    //const User u;//此时必须提供默认构造
    const User u = {6, "Jerry"};
    cout << u.id << "#" << u.name << endl;
    //u.id = 66;
    //u.name = "jerry";
    User *p = (User*) &u;
    p->id = 8;
    p->name = "Steven";
    cout << u.id << "#" << u.name << endl;
}
```



## const代替define

```
类型 / 作用域
在c++中const修饰的变量一般是无法改变的
```


