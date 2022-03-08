#include <iostream>

using namespace std;

class AbstractCalc {
public:
    AbstractCalc(int v1, int v2) : v1(v1), v2(v2) {}
    // 虚函数，父类中存在虚函数时，子类可写可不写
    //virtual int getResult() {return 0;}

    // 纯虚函数，父类中存在纯虚函数时，子类中必须写
    virtual int getResult() = 0;
public:
    int v1;
    int v2;
};

class AddCalc : public AbstractCalc {
public:
    AddCalc(int v1, int v2) : AbstractCalc(v1, v2) {}
    virtual int getResult() {
        return v1 + v2;
    }
};

class SubCalc : public AbstractCalc {
public:
    SubCalc(int v1, int v2) : AbstractCalc(v1, v2) {}
    virtual int getResult() {
        return v1 - v2;
    }
};

/*
    计算器-问题解决

    开闭原则：对扩展开放，对修改关闭

    // 虚函数，父类中存在虚函数时，子类可写可不写
    virtual int getResult() {return 0;}

    // 纯虚函数，父类中存在纯虚函数时，子类中必须写
    virtual int getResult() = 0;
*/
int main() {

    AbstractCalc *calc = new AddCalc(100, 10);
    cout << calc->getResult() << endl;
    delete calc;

    calc = new SubCalc(100, 10);
    cout << calc->getResult() << endl;
    delete calc;

    return 0;
}
