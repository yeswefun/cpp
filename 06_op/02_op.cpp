#include <iostream>

using namespace std;

class Integer {
    
friend ostream& operator<<(ostream &cout, const Integer &o);

public:
    Integer() {
        i = 0;
        cout << "Integer(): " << i << endl;
    }
    Integer(const Integer &o) {
        this->i = o.i;
        cout << "copy-Integer(): " << i << endl;
    }
    ~Integer() {
        cout << "~Integer(): " << i << endl;
    }

    // 前置, 返回的是左值
    Integer& operator--() {
        cout << "prefix" << endl;
        --this->i;  // --i
        return *this;
    }

    // 后置， 返回的是右值
    const Integer operator--(int) {
        Integer tmp(*this); // Integer tmp = *this;
        this->i--;  // i--
        return tmp;
    }

    int i;
};

ostream& operator<<(ostream &cout, const Integer &o) {
    cout << o.i;
    return cout;
}

/*
    实现自减运算符重载

    在C语言里面++i和i++都是右值
    在C++里面i++依然是右值，不过++i可以作为左值    
*/
int main() {
    Integer i;
    cout << i << endl;      // 0
    cout << --i << endl;    // -1
    cout << "************************************" << endl;
    cout << i << endl;      // -1
    cout << i-- << endl;    // -1, 匿名对象
    cout << "************************************" << endl;
    cout << i << endl;      // -2
    cout << "************************************" << endl;
    return 0;
}
