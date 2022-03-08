

模板



类型参数化 - 泛型编程 - 模板技术


```c++
/*
    template<class T> 等价于 template<typename T>
 */
template<typename T>
void xswap(T &x, T &y) {
    T tmp = x;
    x = y;
    y = tmp;
}

int main() {
    
    int x = 10, y = 20;
    cout << x << " @ " << y << endl;
    
    // xswap(x, y);        // 隐式推导
    xswap<int>(x, y);      // 显式指定类型
    cout << x << " @ " << y << endl;

    // 自动类型推导，必须是编译器能找到匹配的调用类型
    // error: no matching function for call to ‘xswap(int, char)’
    // xswap(10, 'c'); // 'c'不会作类型转换

    return 0;
}
```



普通函数与函数模板的区别

    1.普通函数可以进行隐式类型转换

    2.模板函数不可以进行隐式类型转换




普通函数与模板函数
    若只有声明，没有定义，则报链接错误


普通函数与函数模板的区别

    1.若普通函数与模板函数同时存在，则优先使用普通函数

    2.若需要强制使用模板函数，则使用空参列表<>
        test<>(10);

    3.函数模板可以重载

    4.若函数模板的匹配度高，则优先使用函数模板

        template<class A, class B>
        void test(A &a, B &b) {

        }

        void test(int a, int b) {

        }

        test(10, 'c');


编译器依据函数模板生成不同的模板函数
    模板为STL作铺垫
    声明时编译, 生成模板函数后再编译

```c++
// 编译器依据函数模板生成不同的模板函数
template<class T>
void test(T a) {
    cout << "template: " << typeid(T).name() << endl;
}


//test(6); 编译器生成以下函数 - 模板函数
void test(int a) {
    cout << "template" << endl;
}

//test(3.14); 编译器生成以下函数 - 模板函数
void test(double a) {
    cout << "template" << endl;
}
```



函数模板 - 局限性
    无法对任何类型进行比较之类的操作
    全局函数 -> 类中的比较运算符


07.cpp





类模板可以有默认类型
    template <class T1, class T2>
    template <class T1, class T2 = string>
    template <class T1 = int, class T2 = string>


函数模板 / 类模板
    template<class T>在函数上 - 函数模板
    template<class T>在类上 - 类模板

    1.类模板不支持自动类型推导

    2.显示指定类型

    3.存在默认类型时，可以不指定存在默认类型的参数

    08_class.cpp




成员函数的创建时机

    成员函数：一开始不会创建出来，而是在运行时才去创建

    09.cpp





类模板作为函数参数

```c++
template <class T1, class T2>
class Test {
public:
    Test(T1 id, T2 name) : id(id), name(name) {}
    void show() {
        cout << id << " - " << name << endl;
    }
    T1 id;
    T2 name;
};

// 1.指定传入参数的类型
void test00(Test<int, string> &p) {
    p.show();
}

// 2.参数模板化
template <class T1, class T2>
void test01(Test<T1, T2> &p) {
    // 如何查看类型
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
    p.show();
}

// 3.整体模板化
template <class T>
void test02(T &p) {
    cout << typeid(T).name() << endl;
    p.show();
}

/*
    类模板作为函数参数
*/
int main() {
    Test<int, string> t(6, "Java");
    test00(t);
    test01(t);
    test02(t);
    return 0;
}
```





类模板与继承

```c++
template <class T>
class A {
public:
    T a;
};

// 若B不是类模板，则必须指定T的具体类型，否则编译器无法分配内存
class B : public A<int> {};

// 若C是类模板，则可以不指定T的具体类型，而是用模板参数占位
template <class T1, class T2>
class C : public A<T2> {

}
```





类模板-类内/外成员函数的实现

```c++
// 类内形式
template <class T1, class T2>
class A {
public:
    A(T1 a, T2 b) : a(a), b(b) {}
    void show() {
        cout << a << "@" << b << endl;
    }
    T1 a;
    T2 b;
};

// 类外形式
template <class T1, class T2>
class B {
public:
    B(T1 a, T2 b);
    void show();
    T1 a;
    T2 b;
};

template <class T1, class T2>
B<T1, T2>::B(T1 a, T2 b) : a(a), b(b) {}

template <class T1, class T2>
void B<T1, T2>::show() {
    cout << a << "@" << b << endl;
}

/*
    类模板-类内/外成员函数的实现
*/
int main() {
    A<char, string> a('a', "hello");
    a.show();
    B<int, float> b(10, 3.14);
    b.show();
    return 0;
}
```
