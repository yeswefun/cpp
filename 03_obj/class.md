

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
    User(u);    //变量定义，默认构造，前提是没有在初始化时赋值给任何变量
    User u();   //函数声明



malloc, free 与 new, delete 的区别
    new X
    会返回指向X的指针
    会自动调用构造函数, malloc不会自动调用构造函数
    会自动进行类型转换， malloc必须强制类型转换
    new是一个运算符

    delete X
    会释放堆内存空间
    会自动调用析构函数, free不会自动调用析构函数
    delete是一个运算符

