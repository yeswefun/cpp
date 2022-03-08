

less is more

slow is fast


指针、引用、数组、内存
    
    int a = 6; 
    int *p = &a;    // *p == a
    int &r = a;     // r  == a

    int b = 8;
    int *c = &b;
    int **p = &c;   // *p == c
    int *&r = c;    // r  == c

    int arr[] = {1, 2, 3};
    int (arrp*)[] = &arr;   // *arrp == arr
    arrp &arrRef = arr;     // arrRef == arr


引用与指针区别


C 和 C++ 的一些区别，比如 new、delete 和 malloc、free 的区别
    new 会自动调用类的构造方法，而 malloc 则不会
    delete 会自动调用类的析构方法，而 free 则不会


四种类型转换：static_cast, dynamic_cast, const_cast, reinterpret_cast
    static_cast
    dynamic_cast
    const_cast
    reinterpret_cast


一些关键字的作用：static、const、volatile、extern
    extern
    static
    const
    volatile


继承、虚继承、菱形继承等
    继承
        class A : public B {}
            public < protected < private
            子类成员的访问权限都是在父类中访问权限与继承访问权限二者中比较严格的访问权限

    菱形继承:
        class A {
            public:
                int id = -1;
        };
        class B : public A {};
        class C : public A {};
        class D : public B, public C {};

    菱形继承问题的解决: 虚继承
        class A {
        public:
            // 菱形继承：虚基类使属性id只在基类A中保存一份数据
            int id = -1;
        };

        class B: virtual public A {};

        class C: virtual public A {};

        class D: public B, public C {};


多态： 动态绑定，静态多态
    子类继承父类，并重写父类中声明的虚函数或纯虚函数
    子类实例赋值给父类变量


重写、重载

    重写发生在类的继承结构中
        要求:
            函数签名一致

    重载发生在同一个作用域中
        同一个类中或处于相同的全局作用域
        要求:
            函数同名


虚机制：虚函数、虚函数表、纯虚函数
    虚函数
        虚函数有函数体
        非抽象子类可重写，也可以不重写
        virtual void test() {}
    纯虚函数
        纯虚函数没有函数体
        非抽象子类必须重写
        virtual void test() = 0;
    虚函数表


STL部分容器的实现原理，如 vector、deque、map、hashmap
    vector
    deque
    map
    hashmap


模板特化、偏特化，萃取 traits 技巧


智能指针原理：引用计数、RAII（资源获取即初始化）思想


智能指针使用：shared_ptr、weak_ptr、unique_ptr等
    shared_ptr
    weak_ptr
    unique_ptr


编译链接机制、内存布局（memory layout）、对象模型。


C++11 部分新特性，比如右值引用、完美转发等

