


c++与java的一些区别


bool
    c++支持隐式转换，0为假，非0为真
    java不支持隐式转换，必须是boolean或Boolean类型


类
    c++需要在类的右大括号加分号
    java不需要在类的右大括号加分号


this
    c++用法，this->name
    java用法，this.name


符号重载
    c++支持，java不支持


静态成员



继承
    c++支持多继承, java不支持多继承
        c++中的虚继承是为了解决菱形继承问题

    继承模式
        c++
            public, protected, private
        java
            public, protected, package, private


多态
    子类实例赋值给父类变量，并且子类重写父类的方法
    c++中需要使用虚函数实现动态多态，java中不需要额外的处理就可以实现多态


纯虚函数
    c++类中所有的方法都是纯虚函数 - java接口
    c++类中部分方法是纯虚函数 - java抽象类


模板
    c++中的模板
    java中的泛型


stl
    c++中的stl
    java中的collection

