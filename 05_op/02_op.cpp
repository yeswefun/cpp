#include <iostream>

using namespace std;

class Complex {

friend ostream& operator<<(ostream &cout, const Complex &o);

public:
    Complex() {}
    Complex(int real, int image) :real(real), image(image) {}
/*
    int getReal() {
        return this->real;
    }
    int getImage() {
        return this->image;
    }
*/
private:
    int real;
    int image;
};

/*
    若对象不在重载运算符的左侧，则无法写成成员函数的形式
*/
ostream& operator<<(ostream &cout, const Complex &o) {
    cout << o.real;
    if (o.image >= 0) {
        cout << '+';
    }
    cout << o.image << 'i';
    return cout;
}

/*
    将运算符重载函数声明为友元
*/
int main() {
    Complex c1(1, 2);
    //cout << c1;
    cout << c1 << endl;
    return 0;
}
