#include <iostream>

using namespace std;

// 实现自减运算符重载
class Integer {

friend ostream& operator<<(ostream &cout, const Integer &o);

public:
    Integer() {
        this->i = 0;
        cout << "Integer#construct: " << i << endl;
    }
    Integer(int num) {
        this->i = num;
        cout << "Integer#construct: " << num << endl;
    }
    Integer(const Integer &o) {
        cout << "Integer copy: " << o.i << endl;
        this->i = o.i;
    }
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
    ~Integer() {
        cout << "Integer#destruct flag: " << flag << endl;
    }
private:
    int i;
    int flag = 0;
};

// 常对象 - 受到后置自增的影响，所以需要将下面函数参数声明为 const Integer &o
ostream& operator<<(ostream &cout, const Integer &o) {
    cout << o.i;
    return cout;
}
    
/*
    前置自增 / 后置自增运算符重载

    在C语言里面++i和i++都是右值
    在C++里面i++依然是右值，不过++i可以作为左值
*/
int main() {
    Integer i;
    cout << i << endl;      // 0
    cout << ++i << endl;    // 1
    cout << "************************************" << endl;
    cout << i << endl;      // 1
    cout << i++ << endl;    // 1, 匿名对象
    cout << "************************************" << endl;
    cout << i << endl;      // 2
    cout << "************************************" << endl;
    return 0;
}
