#include <iostream>

using namespace std;

class Complex {
public:
    Complex() {
        this->real = 0;
        this->image = 0;
    }
    Complex(int real, int image) :real(real), image(image) {
        cout << real << endl;
        cout << image << endl;
    }
    Complex(const Complex &o) {
        cout << "copy" << endl;
    }
    void show() {
        cout << real;
        if (image > 0)
            cout << "+";
        cout << image << "i" << endl;
    }
    int getReal() {
        return this->real;
    }
    void setReal(int real) {
        this->real = real;
    }
    int getImage() {
        return this->image;
    }
    void setImage(int image) {
        this->image = image;
    }
    /*
        成员函数 - 符号重载

        此处的返回值不能是引用呀，因为c是栈上的变量，
        而引用必须指向一场合法有效的内存空间
    */
    Complex operator+(Complex &o) {
        Complex c;
        c.real = this->real + o.real;
        c.image = this->image + o.image;
        return c;
    }
	Complex operator+(int real) {
        Complex c;
        c.real = this->real + real;
        c.image = this->image;
        return c;
    }
private:
    int real;
    int image;
};

/*
    全局函数 - 符号重载

    此处的返回值不能是引用呀，因为c是栈上的变量，
    而引用必须指向一场合法有效的内存空间
*/
Complex operator-(Complex &c1, Complex &c2) {
    Complex c;
    c.setReal(c1.getReal() - c2.getReal());
    c.setImage(c1.getImage() - c2.getImage());
    return c;
}
Complex operator-(Complex &c1, int real) {
    Complex c;
    c.setReal(c1.getReal() - real);
    c.setImage(c1.getImage());
    return c;
}

/*
    加 / 减 运算符重载

    $ g++ x.cpp -fno-elide-constructors -o x.out && ./x.out
*/
int main() {
    Complex c1(1, 2);
    c1.show();
    Complex c2(3, 4);
    c2.show();
    cout << "************************" << endl;

    Complex c3 = c1 + c2;
    c3.show();
    Complex c4 = c1 - c2;
    c4.show();
    cout << "************************" << endl;

    Complex c5 = c1 + 6;
    c5.show();
    Complex c6 = c1 - 2;
    c6.show();

    return 0;
}
