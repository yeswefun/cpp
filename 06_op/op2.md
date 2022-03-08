


关系运算符重载
    ==, !=

```c++
class User {
public:
    bool operator==(const User &u) {
        return this->id == u.id && this->name == u.name;
    }
    bool operator!=(const User &u) {
        return !(this->id == u.id && this->name == u.name);
    }
}
```




函数调用运算符()重载
    仿函数
    01_op.cpp

```c++
class Test {
public:
    void operator()() {
        cout << "()" << endl;
    }
    void operator()(int a) {
        cout << "(): " << a << endl;
    }
    void operator()(string s) {
        cout << "(): " << s << endl;
    }
};

class Add {
public:
    int operator()(int x, int y) {
        return x + y;
    }
};
```




实现自减运算符重载
    02_op.cpp




自定义一个String类
    03_str.cpp


