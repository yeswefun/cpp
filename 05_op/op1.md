


运算符重载



加 / 减 运算符重载
    
    成员函数 - 符号重载
        Complex operator+(Complex &o) {
            Complex c;
        }

    全局函数 - 符号重载
        Complex operator-(Complex &c1, Complex &c2) {
            Complex c;
        }


    以上两处返回值不能是引用呀，因为c是栈上的变量，
    而引用必须指向一场合法有效的内存空间



左移运算符重载
    若对象不在重载运算符的左侧，则无法写成成员函数的形式
    因此这种情况只能使用全局函数进行符号重载

```c++
    /*
        cout << c1;
        cout << c1 << endl;
    */
    ostream& operator<<(ostream &cout, Complex &o) {
        cout << o.getReal();
        if (o.getImage() >= 0) {
            cout << '+';
        }
        cout << o.getImage() << 'i';
        return cout;
    }
```



将运算符重载函数声明为友元
```c++
    class Complex {
        friend ostream& operator<<(ostream &cout, const Complex &o);
    }

    /*
        声明成友元函数可以在类外直接访问类的私有成员
    */
    ostream& operator<<(ostream &cout, const Complex &o) {
        cout << o.real;
        if (o.image >= 0) {
            cout << '+';
        }
        cout << o.image << 'i';
        return cout;
    }
```



前置自增 / 后置自增运算符重载

    在C语言里面++i和i++都是右值
    在C++里面i++依然是右值，不过++i可以作为左值

```c++
class Integer {
public:
    // ++i，前置返回引用,返回结构是左值
    Integer& operator++() {
        cout << "Integer prefix" << endl;
        ++this->i;  // ++i
        return *this;
    }
    // i++, 后置返回值，占位参数,返回结构是右值
    const Integer operator++(int) {
        cout << "Integer postfix" << endl;
        Integer tmp = *this;
        tmp.flag = -1;
        this->i++;  // i++
        // g++ x.cpp -fno-elide-constructors -o x && ./x
        return tmp;
    }
private:
    int i;
}

// 常对象 - 受到后置自增的影响，所以需要将下面函数参数声明为 const Integer &o
ostream& operator<<(ostream &cout, const Integer &o) {
    cout << o.i;
    return cout;
}
```




智能指针模拟
    04_ptr.cpp

    智能指针
        在栈上对象中存放堆内存对象，让栈上对象自动释放堆内存对象

        05_auto.cpp
            符号重载: ->, *





一个类默认创建: 无参构造，析构，拷贝构造，赋值运算符（简单值传递）

    无参构造
        也称为默认构造

    析构

    拷贝构造
        初始化时

    赋值运算符
        初始化后

        /*
            a = b = c;
        */
        Demo& operator=(const Demo &o) {

        }




自定义一个数组类
    08_main.cpp
    09_arr.h

    /*
        小括号()：Parentheses, bracket
        中括号[]：bracket
        大括号{}：brace
    */
    int& Arr::operator[](int index) {
        return this->p[index];
    }

