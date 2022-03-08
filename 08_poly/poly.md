


静态联编 - 编译阶段绑定
    静态多态：函数重载

动态联编 - 运行阶段绑定
    在继承结构中，基类A中将函数声明为虚函数



多态
    父类的指针或引用指向子类对象

    虚函数，虚继承
        父类的virtual必须写上，子类的virtual可写可不写



纯虚函数
    虚函数，父类中存在虚函数时，子类可写可不写
    virtual int getResult() {return 0;}

    纯虚函数，父类中存在纯虚函数时，子类中必须写
    virtual int getResult() = 0;
        java的抽象类


    存在纯虚函数的基类，称为"抽象类"
    抽象类不能实例化
    抽象类的子类只重写部分纯虚函数，那么子类也是抽象类
    抽象类的子类重写所有纯虚函数，那么子类不再是抽象类，而是一个普通类



虚析构
    多态析构问题引出
        在父类指针指向子类对象时，对父类指针进行delete并不会调用子类对象的析构

    多态析构问题解决 - 虚析构



纯虚析构
    虚析构 - 类可以实例化
    纯虚析构 - 类不可以实例化

```c++
class A {
public:
    virtual void test() {
        cout << "A::test()" << endl;
    }
    // 虚析构
    /*virtual ~A() {
        cout << "~A()" << endl;
    }*/

    // 纯虚析构, 类内声明，类外实现
    // 类中存在纯虚析构函数时，该类也是抽象类
    // 抽象类不可以实例化
    virtual ~A() = 0;
};

A::~A() {
    cout << "virtual ~A()" << endl;
}
```



子类转父类是自动的，是安全的 - 向上类型转换
父类转子类是强制的，是不安全的 - 向下类型转换

多态的条件: 
    1.存在继承结构
    2.父类声明虚函数或纯虚函数，子类重写虚函数或纯虚函数
    3.父类指针或引用指向子类对象



多态工作原理

