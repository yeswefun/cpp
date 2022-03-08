



继承模式
    public(宽松) > protected(严格) > private(更严格)
    
    子类成员的访问权限都是在父类中访问权限与继承访问权限二者中比较严格的访问权限

    00_mode.cpp



继承模式深入
    01_size.cpp



子类对象实例化时自动调用父类无参构造
    子类实例化时，会先调用父类的无参构造，再调用本类构造
        若父类没有提供无参构造，则子类必须手动调用父的有参构造



子类会继承父类的成员属性，成员函数
    但不会继承父类的构造，析构，operator=, 只有父类知道如何构造它自己

    // 常用继承模式: public

    初始化顺序
        03_seq.cpp



子类非静态成员与父类非静态成员同名
    就近原则
    
    子类中存在与父类同名的成员，不会发生覆盖

    04_field.cpp

```c++
    // 存在与子类同名的方法，则直接调用
    b.show();
    b.A::show();

    // 不存在与子类同名的方法，则调用子类的
    b.test();
    b.A::test();
```




子类同名成员函数会让父类的所有同名成员函数隐藏conceal掉
    重载函数需要在同一作用域

    05_over.cpp




子类静态成员与父类静态成员同名
    
    静态成员属性可以被子类继承下来
        就近原则

    静态成员属性:类内声明，类外初始化

    06_static.cpp

```c++
    // 就近原则
    cout << B::a << endl;
    cout << A::a << endl;
    cout << B::A::a << endl;
```


    子类同名静态成员函数会让父类的所有同名静态成员函数隐藏conceal掉
        就近原则

    07_fun.cpp

```c++
    // 就近原则
    B::test();
    // error: no matching function for call to ‘B::test(int)’
    //B::test(6);
    A::test();
    A::test(6);
    B::A::test();
    B::A::test(6);
```



类中成员同名，都可以使用作用域运算符::来引用相应的成员
    默认同名情况，就近原则



多继承
    多继承的问题一：属性同名
        cout << c.A::a << endl;
        cout << c.B::a << endl;

    多继承的问题二：菱形继承
        菱形继承：基类A中的属性id在类B与类C中都保留了一份(浪费内存)

```c++
class A {
public:
    int id;
};

class B: public A {
};
class C: public A {
};

class D: public B, public C {
};
```

        菱形继承问题的解决：虚继承
        操作同一份共享数据

```c++
class A {
public:
    // 菱形继承：虚继承使属性id只在基类A中保存一份数据
    int id = -1;
};

class B: virtual public A {
};

class C: virtual public A {
};

class D: public B, public C {
};
```




虚基类原理


