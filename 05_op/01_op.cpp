#include <iostream>

using namespace std;

class Complex {
public:
    Complex() {}
    Complex(int real, int image) :real(real), image(image) {}
    int getReal() {
        return this->real;
    }
    int getImage() {
        return this->image;
    }
private:
    int real;
    int image;
};

/*
    若对象不在重载运算符的左侧，则无法写成成员函数的形式
*/
ostream& operator<<(ostream &cout, Complex &o) {
    cout << o.getReal();
    if (o.getImage() >= 0) {
        cout << '+';
    }
    cout << o.getImage() << 'i';
    return cout;
}

/*
    左移运算符重载
*/
int main() {
    Complex c1(1, 2);
    //cout << c1;
    cout << c1 << endl;
    return 0;
}
